#include <fstream>
#include "file_manager.h"

std::pair<std::vector<int>, bool> read_file()
{
    std::string line;
    std::ifstream in("input.txt");

    std::vector<int> numbers;

    if (in.is_open()) {
        while (getline(in, line)) {
            try {
                int number = std::stoi(line);
                numbers.push_back(number);
            }
            catch (std::invalid_argument) {
                return std::make_pair(std::vector<int>(), true);
            }
        }
    }
    in.close();
    return std::make_pair(numbers, false);
}

bool write_file(std::vector<int> res) {}