#ifndef INSTANCE_PROCESSOR_H
#define INSTANCE_PROCESSOR_H

#include <string>
#include <iostream>
#include "../include/data-parser.h"
#include "../include/recolection-greedy-strategy.h"
#include "../include/recolection-grasp-strategy.h"
#include "../include/transport-greedy-strategy.h"
#include "../include/report-generator.h"

class InstanceProcessor {
public:
    InstanceProcessor(const std::string& inputFile, const std::string& outputFile);

    // Procesar la instancia
    void process();

private:
    std::string inputFile_;
    std::string outputFile_;
};

#endif // INSTANCE_PROCESSOR_H