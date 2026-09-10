#include <iostream>
#include <string>

class ReportGenerator {
public:
    void generateReport(const std::string& type) {
        if (type == "PDF") {
            std::cout << "Generating PDF report..." << std::endl;
        } else if (type == "HTML") {
            std::cout << "Generating HTML report..." << std::endl;
        }
    }
};