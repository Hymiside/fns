#include "file_manager/file_manager.h";
#include "calc/calc.h";

#include <iostream>
#include <vector>
#include <algorithm>



int main() {
    std::vector<int> fibVec1 = {1, 1};

    while (fibVec1.back() < 1000000) { fibVec1.push_back(*(fibVec1.end() - 1) + *(fibVec1.end() - 2)); }
    create_fib(fibVec1);

    std::pair<std::vector<int>, bool> response = read_file();
    if (response.second || response.first.empty()) {
        std::cout<<"invalid data in file"<<std::endl;
        return 0;
    }
    std::vector<int> numbers = response.first;

    std::vector<std::string> result;
    for (std::vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); ++iter) {
        auto lb = std::upper_bound(fibVec1.begin(), fibVec1.end(), *iter);
        calc(*iter, lb - fibVec1.begin() - 1, 0, *iter);
    }

    send_write_file();
    return 0;
}