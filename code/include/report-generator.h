#ifndef REPORT_GENERATOR_H
#define REPORT_GENERATOR_H

#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "collection-vehicle.h"
#include "transport-vehicle.h"

class ReportGenerator {
public:
    // Constructor
    ReportGenerator(const std::string& outputFilePath);

    // Métodos para agregar resultados
    void addRecolectionResult(const std::vector<CollectionVehicle>& collectionVehicles);
    void addTransportResult(const std::vector<TransportVehicle*>& transportVehicles);
    void addGRASPResult(const std::string& instanceName, int zones, int lrcSize, int collectionVehicles, int transportVehicles, double cpuTime);

    // Método para escribir los resultados al archivo
    void writeToFile();

private:
    std::string outputFilePath_;
    std::ostringstream reportStream_;

    // Métodos auxiliares
    std::string formatRoute(const std::vector<std::shared_ptr<Location>>& route);
};

#endif // REPORT_GENERATOR_H