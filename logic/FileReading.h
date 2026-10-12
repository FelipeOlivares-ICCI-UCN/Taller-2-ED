#include "../structures/Queue.h"
#include "../objects/Paciente.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

void readFileData(const std::string& filename, Queue<Paciente> &Atencion);
