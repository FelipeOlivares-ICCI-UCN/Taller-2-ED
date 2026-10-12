#include "FileReading.h"

void readFileData(const std::string& filename, Queue<Paciente>& pacientes) {
    std::cout << "Searching " << filename << std::endl;

    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << filename << " not found!" << std::endl;
        return;
    }

    std::cout << filename << " was found!" << std::endl;




    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);

        int ID, age, pain, hasTrauma, neuroSintoms, requiresSurgery, estimedStay, sistBloodPressure, diasBloodPressure;
        float temperature;
        std::string name, kindOfPain, temp;
        std::stringstream extractor;
        try {
            // ID
            std::getline(ss, temp, ';'); ID = std::stoi(temp);

            // name
            std::getline(ss, name, ';');

            // age
            std::getline(ss, temp, ';'); age = std::stoi(temp);

            // temperature
            std::getline(ss, temp, ';'); temperature = std::stof(temp);

            // systolic blood pressure
            std::getline(ss, temp, '/'); sistBloodPressure = std::stoi(temp);

            // diastolic blood pressure
            std::getline(ss, temp, ';'); diasBloodPressure = std::stoi(temp);

            // pain
            std::getline(ss, temp, ';'); pain = std::stoi(temp);

            // kind of pain
            std::getline(ss, kindOfPain, ';');

            // has trauma?
            std::getline(ss, temp, ';'); hasTrauma = std::stoi(temp);

            // Neurological symptoms
            std::getline(ss, temp, ';'); neuroSintoms = std::stoi(temp);

            // Does they need surgery?
            std::getline(ss, temp, ';'); requiresSurgery = std::stoi(temp);

            // Estimated stay
            std::getline(ss, temp);
            estimedStay = std::stoi(temp);

        } catch (const std::exception& e) {
            std::cerr << "Error processing line: " << line << ", Origin: " << e.what() << std::endl;
        }

        Paciente p = Paciente(ID, name, age, temperature, sistBloodPressure, diasBloodPressure, pain, kindOfPain, hasTrauma, neuroSintoms, requiresSurgery, estimedStay);
        pacientes.push(p);
    }
}
