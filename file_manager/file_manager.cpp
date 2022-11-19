#include "file_manager.h"

#include <fstream>
#include <unordered_map>


std::pair<std::vector<int>, bool> read_file()
{
    std::vector<int> numbers;
    std::string line;
    std::ifstream in("../data/input.txt");

    if (in.is_open()) {
        while (getline(in, line)) {
            try {
                int number = std::stoi(line);
                if (number < 1 || number > 1000000) { return std::make_pair(std::vector<int>(), true); }
                numbers.push_back(number);
            }
            catch (std::invalid_argument) { return std::make_pair(std::vector<int>(), true); }
        }
    }
    in.close();
    return std::make_pair(numbers, false);
}

void write_file(std::unordered_map<int, std::vector<std::string>> resMap) {
    std::ofstream out("../data/output.txt");

    std::unordered_map<int, std::vector<std::string>> reversResMap;
    for(std::unordered_map<int, std::vector<std::string>>::iterator iterMap = resMap.begin(); iterMap != resMap.end(); ++iterMap)
        reversResMap[iterMap->first] = iterMap->second;

    if(out.is_open()) {
        for(std::unordered_map<int, std::vector<std::string>>::iterator iterRevMap = reversResMap.begin(); iterRevMap != reversResMap.end(); ++iterRevMap)
        {
            for (int i = 0; i < iterRevMap->second.size(); i++) {
                std::cout << "kek" << std::endl;
                out << iterRevMap->second[i];
                out << " ";
            }
            out << "\n";
            std::cout << "kek1" << std::endl;
        }
    }
    out.close();
}