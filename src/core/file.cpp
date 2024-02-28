#include "file.hpp"
#include <fstream>

std::string readFile(const std::string& path) {
    std::ifstream file;
    file.open(path);

    if (!file.is_open()) return "";

    std::string content;
    char cur;
    while(file && (cur = file.get())) content += cur;

    return content;
}