#include "../include/report-generator.h"
#include "../include/location.h"

// Constructor
ReportGenerator::ReportGenerator(const std::string& outputFilePath)
    : outputFilePath_(outputFilePath) {}

// Agregar resultados de recolección
void ReportGenerator::addRecolectionResult(const std::vector<CollectionVehicle>& collectionVehicles) {
    reportStream_ << "|| VORAZ  -->  Recolection ||\n";
    reportStream_ << "==================================================================\n";
    reportStream_ << "VEHICLES      ZONES       ROUTE\n";
    for (const auto& vehicle : collectionVehicles) {
        reportStream_ << "Vehicle " << vehicle.getId() << "        "
                      << vehicle.getNumberOfZones() << "            "
                      << formatRoute(vehicle.getRoute()) << "\n";
    }
    reportStream_ << "==================================================================\n\n\n";
}

// Agregar resultados de transporte
void ReportGenerator::addTransportResult(const std::vector<TransportVehicle*>& transportVehicles) {
    reportStream_ << "|| VORAZ  -->  Transport ||\n";
    reportStream_ << "==================================================================\n";
    reportStream_ << "VEHICLES      ZONES       ROUTE\n";
    for (const auto& vehicle : transportVehicles) {
        reportStream_ << "Vehicle " << vehicle->getId() << "        "
                      << vehicle->getRoute().size() << "            "
                      << formatRoute(vehicle->getRoute()) << "\n";
    }
    reportStream_ << "==================================================================\n\n\n";
}

// Agregar resultados de GRASP
void ReportGenerator::addGRASPResult(const std::string& instanceName, int zones, int lrcSize, int collectionVehicles, int transportVehicles, double cpuTime) {
    reportStream_ << "|| GRASP  -->  " << instanceName << " ||\n";
    reportStream_ << "==================================================================\n";
    reportStream_ << "INSTANCE        ZONES         |LRC|         CV        TV        CPU_TIME\n";
    reportStream_ << instanceName << "       " << zones << "             "
                  << lrcSize << "           " << collectionVehicles << "         "
                  << transportVehicles << "       " << std::fixed << std::setprecision(6) << cpuTime << "\n";
    reportStream_ << "==================================================================\n\n";
}

// Escribir los resultados al archivo
void ReportGenerator::writeToFile() {
    std::ofstream outFile(outputFilePath_);
    if (!outFile.is_open()) {
        throw std::runtime_error("Error: No se pudo abrir el archivo " + outputFilePath_ + " para escribir los resultados.");
    }
    outFile << reportStream_.str();
    outFile.close();
}

// Formatear la ruta
std::string ReportGenerator::formatRoute(const std::vector<std::shared_ptr<Location>>& route) {
    std::ostringstream routeStr;
    for (const auto& loc : route) {
        routeStr << loc->getId() << " ";
    }
    return routeStr.str();
}