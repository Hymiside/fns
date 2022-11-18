#include <iostream>
#include "map"
#include "file_manager/file_manager.h";
#include "calc/calc.h";

#include <vector>
#include <algorithm>
#include <iterator>

std::vector<uint32_t> fibVec1 = {1, 1};

int main()
{
    createFib();
    while (fibVec1.back() < 1000000)
        fibVec1.push_back(*(fibVec1.end() - 1) + *(fibVec1.end() - 2));
    std::copy(fibVec1.begin(), fibVec1.end(), std::ostream_iterator<int>(std::cout, " "));

    std::pair<std::vector<int>, bool> res = read_file();
    if (res.second || res.first.empty()) {
        std::cout<<"invalid data in file"<<std::endl;
        return 0;
    }
    std::vector<int> numbers = res.first;
    std::map<int, std::vector<int>> result;

    for (std::vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); ++iter) {
        std::cout<<*iter<<std::endl;

        auto lb = std::upper_bound(fibVec1.begin(), fibVec1.end(), *iter);
        std::vector<int> a = calc(*iter, lb - fibVec1.begin() - 1, 0);

        result[*iter] = a;
    }

    for(const auto& elem : result)
    {
        std::cout << elem.first << " " << &elem.second << "\n";
    }
    return 0;
}