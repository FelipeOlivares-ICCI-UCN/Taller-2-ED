#include "AVLTree.h"

template <typename T>
int AVLTree<T>::height(AVLNode<T>* node)
{
    if (node == nullptr) return 0; return node->getHeight();
};

template <typename T>
int AVLTree<T>::balanceFactor(AVLNode<T>* node){
        if (node ==nullptr) return 0;
        return height(node->getLeft()) - height(node->getRight());
    };

template <typename T>
AVLNode<T>* AVLTree<T>::rotateRight(AVLNode<T>* y)
    {
        AVLNode<T>* x = y->getLeft();
        AVLNode<T>* temp = x->getRight();

        x->setRight(y);
        y->setLeft(temp);

        y->setHeight(1 + std::max(height(y->getLeft()),
                                  height(y->getRight()))
                     );
        x->setHeight(1 + std::max(height(x->getLeft()),
                                  height(x->getRight())));

        return x;
    }

template <typename T>
AVLNode<T>* AVLTree<T>::rotateLeft(AVLNode<T>* x)
    {
        AVLNode<T>* y = x->getRight();
        AVLNode<T>* temp = y->getLeft();

        y->setLeft(x);
        x->setRight(temp);

        x->setHeight(1 + std::max(height(x->getLeft()),
                                  height(x->getRight()))
                     );
        y->setHeight(1 + std::max(height(y->getLeft()),
                                  height(y->getRight())));
        return y;
    }

template <typename T>
AVLNode<T>* AVLTree<T>::insert(AVLNode<T>* node, const T& value)
    {
        if (node == nullptr)
            {
                return new AVLNode<T>(value);
            }

        if (value < node->getValue())
            {
                node->setLeft(insert(node->getLeft(), value));
            }

        else if (node->getValue() < value)
            {
                node->setRight(insert(node->getRight() ,value));
            }

        else
            {
                return node;
            }

        node->setHeight(1 + std::max(height(node->getLeft()),
                                     height(node->getRight())
                                     ));
        int balance = balanceFactor(node);

        if (balance > 1)
            {
                if (balanceFactor(node->getLeft()) >= 0)
                    {
                        return rotateRight(node);
                    }
                else
                    {
                        node->setLeft(rotateLeft(node->getLeft()));
                        return rotateRight(node);
                    }
            }
        if (balance < -1)
            {
                if (balanceFactor(node->getRight()) <= 0)
                    {
                        return rotateLeft(node);
                    }
                else
                    {
                        node->setRight(rotateRight(node->getRight()));
                        return rotateLeft(node);
                    }
            }


        return node;
    }

template <typename T>
AVLNode<T>* AVLTree<T>::search(AVLNode<T>* node, T value)
    {
        if (node == nullptr) return nullptr;

        if (node->getValue() == value) return node;

        if (value < node->getValue()) return search(node->getLeft(), value);

        return search(node->getRight(), value);
    }

template <typename T>
void AVLTree<T>::preorder(AVLNode<T>* node)
    {
        if (node == nullptr)
            {
                return;
            }

        std::cout << node->getValue() << " ";

        preorder(node->getLeft());
        preorder(node->getRight());
    }

template <typename T>
void AVLTree<T>::inorder(AVLNode<T>* node)
    {
        if (node == nullptr)
            {
                return;
            }


        inorder(node->getLeft());

        std::cout << node->getValue() << " ";

        inorder(node->getRight());
    }

template <typename T>
void AVLTree<T>::postorder(AVLNode<T>* node)
    {
        if (node == nullptr)
            {
                return;
            }

        postorder(node->getLeft());
        postorder(node->getRight());
        std::cout << node->getValue() << " ";
    }

template <typename T>
AVLTree<T>::AVLTree(): root(nullptr){};

template <typename T>
void AVLTree<T>::insert(const T& value)
    {
        root = insert(root, value);
    }

template <typename T>
void AVLTree<T>::printPreOrder()
    {
        preorder(root);
        std::cout << std::endl;
    }

template <typename T>
void AVLTree<T>::printInOrder()
    {
        inorder(root);
        std::cout << std::endl;
    }

template <typename T>
void AVLTree<T>::printPostOrder()
    {
        postorder(root);
        std::cout << std::endl;
    }

template <typename T>
void AVLTree<T>::search(const T& value)
    {
        AVLNode<T>* node = search(root, value);
        if (node == nullptr)
            {
                std::cout << "Value doesnt exists" << std::endl;
            }
        else
            {
                std::cout << node->getValue() << std::endl;
            }
    }

template <class T>
void AVLTree<T>::printTreeInfo()
    {
        std::cout<< "Balance Factor: "<< balanceFactor(root) << " ";
        std::cout<< "Height: "<< height(root) << std::endl;
    }

template class AVLTree<int>;
template class AVLTree<std::string>;

