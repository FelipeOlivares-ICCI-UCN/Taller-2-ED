#pragma once
#include <string>
#include <iostream>

class Paciente
{
private:
    int ID;
    std::string name;
    int age;
    float temperature;
    int sistBloodPressure, diasBloodPressure, pain;
    std::string kindOfPain;
    int hasTrauma;
    int neuroSintoms, requiresSurgery, estimedStay;
public:
    Paciente() = default;
    Paciente(int ID, std::string name, int age = 18, float temperature = 35.5,
             int sistBloodPressure = 100, int diasBloodPressure = 70, int pain = 0, std::string kindOfPain = "Otro", int hasTrauma = 0, int neuroSintoms = 0,
             int requiresSurgery = 0, int estimedStay = 0):
            ID(ID), name(name), age(age), temperature(temperature), sistBloodPressure(sistBloodPressure), diasBloodPressure(diasBloodPressure), pain(pain), kindOfPain(kindOfPain),
            hasTrauma(hasTrauma), neuroSintoms(neuroSintoms), requiresSurgery(requiresSurgery), estimedStay(estimedStay)
        {};

    ~Paciente(){}

    int getID() const
    {
        return this->ID;
    }

    const std::string& getName() const
    {
        return this->name;
    }

    int getAge() const
    {
        return this->age;
    }

    float getTemperature() const
    {
        return this->temperature;
    }

    int getSistBloodPressure() const
    {
        return this->sistBloodPressure;
    }

    int getDiasBloodPressure() const
    {
        return this->diasBloodPressure;
    }

    int getPain() const
    {
        return this->pain;
    }



    const std::string& getKindOfPain() const
    {
        return kindOfPain;
    }

    bool getHasTrauma() const
    {
        if (hasTrauma == 0)
            {
                return false;
            }
        return true;
    }

    bool getHasNeuroSyntoms() const
    {
        if (neuroSintoms == 0)
            {
                return false;
            }
        return true;

    }

    bool getRequiresSurgery() const
    {
        if (requiresSurgery == 0)
            {
                return false;
            }
        return true;
    }

    int getEstimedStay() const
    {
        return this->estimedStay;
    }

    void showInfo() const
    {
        std::cout << this->name << "(" << this->ID << ")" << std::endl;
    }


    //String comparator
    friend bool operator<(const Paciente &p ,const std::string &str)
    {
        return p.name < str;
    }

    friend bool operator<(const std::string &str, const Paciente &p )
    {
        return str < p.name;
    }

    friend bool operator>(const std::string &str, const Paciente &p )
    {
        return str > p.name;
    }

    friend bool operator>(const Paciente &p, const std::string &str)
    {
        return p.name < str;
    }

    friend bool operator==(const Paciente &p, const std::string &str)
    {
        return p.name == str;
    }

    friend bool operator==(const std::string& str, const Paciente& p)
    {
        return p.name == str;
    }

    friend bool operator<(const Paciente &p , int ID)
    {
        return p.ID < ID;
    }

    friend bool operator<(int ID, const Paciente &p )
    {
        return ID < p.ID;
    }

    friend bool operator>(int ID, const Paciente &p )
    {
        return ID > p.ID;
    }

    friend bool operator>(const Paciente &p, int ID)
    {
        return p.ID < ID;
    }

    friend bool operator==(const Paciente &p, int ID)
    {
        return p.ID == ID;
    }

    friend bool operator==(int ID, const Paciente& p)
    {
        return p.ID == ID;
    }

    friend bool operator<(const Paciente& p1, const Paciente& p2)
    {
        return p1.ID < p2.ID;
    }

    friend bool operator>(const Paciente& p1, const Paciente& p2)
    {
        return p1.ID > p2.ID;
    }

    friend bool operator==(const Paciente& p1, const Paciente& p2)
    {
        return p1.ID == p2.ID;
    }

    friend std::ostream& operator<<(std::ostream& os, const Paciente& p)
    {
        os
        << "ID: " << p.ID << std::endl
        << "Nombre: " << p.name << std::endl
        << "Edad: " << p.age << std::endl
        << "Temperatura: " << p.temperature << std::endl
        << "Presion Arterial: " << p.sistBloodPressure << "/" << p.diasBloodPressure << std::endl
        << "Dolor: " << p.pain << std::endl
        << "Tipo de Dolor: " << p.kindOfPain << std::endl
        << "Tiene Trauma?: " << (p.hasTrauma == 0 ? "No" : "Si") << std::endl
        << "Tiene Sintomas Neurologicos?: " << (p.neuroSintoms == 0 ? "No" : "Si") << std::endl
        << "Requiere Cirugia?: "  << (p.requiresSurgery == 0 ? "No" : "Si") << std::endl
        << "Dias estimados Hospitalizacion: " << p.estimedStay;
        return os;
    }
};
