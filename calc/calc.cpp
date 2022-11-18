#include "calc.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

std::ofstream os("../data/output.txt");
std::vector<uint8_t> res(32);
std::vector<int> fibVec = {1, 1};


bool findChar(char v) {
    return not v;
}

int create_number(std::vector<int> vecNum) {
    std::string strNum;
    for (std::vector<int>::iterator iter = vecNum.begin(); iter != vecNum.end(); ++iter) {
        strNum += std::to_string(*iter);
    }
    return std::stoi(strNum);
}

void createFib() {
    while (fibVec.back() < 1000000)
        fibVec.push_back(*(fibVec.end() - 1) + *(fibVec.end() - 2));
    std::copy(fibVec.begin(), fibVec.end(), std::ostream_iterator<int>(std::cout, " "));
}


std::vector<int> calc(int n, int i, int d)
{
    std::vector<int> response;
    if (!i) {
        std::vector<int> a;
        if (!n) {

            auto lhs = std::find_if_not(res.begin(), res.end(), findChar);
            std::copy(lhs, res.begin() + d, std::ostream_iterator<int>(os, ""));

            std::copy(lhs, res.begin() + d, std::back_inserter(a));
            int number = create_number(a);
            response.push_back(number);

            os << ' ';

        }
        return std::vector<int>();
    }

    res[d] = 0;
    calc(n, i - 1, d + 1);
    if (n >= fibVec[i]) {
        res[d] = 1;
        calc(n - fibVec[i], i - 1, d + 1);
    };

    return response;
}