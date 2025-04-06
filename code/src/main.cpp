#include <iostream>
#include <vector>
#include "../include/instance-processor.h"
#include "../include/summary-generator.h"

int main() {
    int option;
    std::cout << "Seleccione una opción:\n";
    std::cout << "1. Procesar un archivo de instancia\n";
    std::cout << "2. Generar resumen de resultados\n";
    std::cout << "3. Generar tablas para todas las instancias\n";
    std::cin >> option;

    if (option == 1) {
        std::string inputFile, outputFile;
        std::cout << "Ingrese el nombre del archivo de instancia: ";
        std::cin >> inputFile;
        std::cout << "Ingrese el nombre del archivo de salida: ";
        std::cin >> outputFile;

        InstanceProcessor processor("../../data/" + inputFile, "../../results/" + outputFile);
        processor.process();
    } else if (option == 2) {
        std::vector<std::string> instanceFiles;
        for (int i = 1; i <= 20; ++i) {
            instanceFiles.push_back("../../data/instance" + std::to_string(i) + ".txt");
        }
        SummaryGenerator summary("../../results/summary.txt", instanceFiles);
        summary.generate();
    } else if (option == 3) {
        std::vector<std::string> instanceFiles;
        for (int i = 1; i <= 20; ++i) {
            instanceFiles.push_back("../../data/instance" + std::to_string(i) + ".txt");
        }
        for (const auto& instanceFile : instanceFiles) {
            // Generar un nombre de archivo de salida basado en el nombre de la instancia
            std::string outputFile = "../../results/" + instanceFile.substr(instanceFile.find_last_of("/") + 1);
            outputFile.replace(outputFile.find(".txt"), 4, "_result.txt");

            InstanceProcessor processor(instanceFile, outputFile);
            processor.process();
        }
    } else {
        std::cerr << "Opción no válida.\n";
    }

    return 0;
}