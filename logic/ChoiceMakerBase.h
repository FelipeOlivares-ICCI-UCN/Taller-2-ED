#pragma once
class BaseChoiceMaker {
public:
    virtual ~BaseChoiceMaker() = default; // Destructor virtual para asegurar una limpieza correcta
    virtual bool compare() = 0;
};
