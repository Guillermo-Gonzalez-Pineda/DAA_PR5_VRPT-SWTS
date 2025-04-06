#ifndef SUMMARY_GENERATOR_H
#define SUMMARY_GENERATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class SummaryGenerator {
public:
    SummaryGenerator(const std::string& summaryFile, const std::vector<std::string>& instanceFiles);

    // Generar el resumen
    void generate();

private:
    std::string summaryFile_;
    std::vector<std::string> instanceFiles_;
};

#endif // SUMMARY_GENERATOR_H