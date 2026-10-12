#pragma once
#include <string>
#include <iostream>

class Paciente
{
private:
    int ID, age, pain, hasTrauma, neuroSintoms, requiresSurgery, estimedStay, sistBloodPressure, diasBloodPressure;
    float temperature;
    std::string name, kindOfPain;
public:
    Paciente(int ID, std::string name, int age, float temperature,
             int sistBloodPressure, int diasBloodPressure, int pain, std::string kindOfPain, int hasTrauma, int neuroSintoms,
             int requiresSurgery, int estimedStay):
            ID(ID), name(name), age(age), temperature(temperature), sistBloodPressure(sistBloodPressure), diasBloodPressure(diasBloodPressure), pain(pain), kindOfPain(kindOfPain),
            hasTrauma(hasTrauma), neuroSintoms(neuroSintoms), requiresSurgery(requiresSurgery), estimedStay(estimedStay)
        {};

    int getID()
    {
        return this->ID;
    }

    const std::string& getName() const
    {
        return this->name;
    }

    int getAge()
    {
        return this->age;
    }

    float getTemperature()
    {
        return this->temperature;
    }

    int getSistBloodPressure()
    {
        return this->sistBloodPressure;
    }

    int getDiasBloodPressure()
    {
        return this->diasBloodPressure;
    }

    int getPain()
    {
        return this->pain;
    }



    const std::string& getKindOfPain() const
    {
        return kindOfPain;
    }

    bool getHasTrauma()
    {
        if (hasTrauma == 0)
            {
                return false;
            }
        return true;
    }

    bool getHasNeuroSyntoms()
    {
        if (neuroSintoms == 0)
            {
                return false;
            }
        return true;

    }

    bool getRequiresSurgery()
    {
        if (requiresSurgery == 0)
            {
                return false;
            }
        return true;
    }

    int getEstimedStay()
    {
        return this->estimedStay;
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
