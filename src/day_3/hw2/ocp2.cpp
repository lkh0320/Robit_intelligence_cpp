#include <iostream>

class Report {
public:
    virtual void generate() = 0;
    virtual ~Report() {}
};

class PDFReport : public Report {
public:
    void generate() override {
        std::cout << "Generating PDF report..." << std::endl;
    }
};

class HTMLReport : public Report {
public:
    void generate() override {
        std::cout << "Generating HTML report..." << std::endl;
    }
};

class XMLReport : public Report {
public:
    void generate() override {
        std::cout << "Generating XML report..." << std::endl;
    }
};

int main() {
    Report* pdfReport = new PDFReport();
    pdfReport->generate();

    Report* htmlReport = new HTMLReport();
    htmlReport->generate();

    Report* xmlReport = new XMLReport();
    xmlReport->generate();

    delete pdfReport;
    delete htmlReport;
    delete xmlReport;

    return 0;
}