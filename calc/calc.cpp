#include "calc.h"
#include "../file_manager/file_manager.h"

#include <vector>
#include <algorithm>
#include <unordered_map>

std::vector<int> responseNum(32);
std::vector<int> fibVec;
std::unordered_map<int, std::vector<std::string>> result;

void create_fib(std::vector<int> v) { fibVec = v; }
void send_write_file() { write_file(result); }
bool find_char(char v) { return not v; }

std::string create_number(std::vector<int> vecNum, int num) {
    std::string strNum;
    for (int i = 0; i < vecNum.size(); i++) {
        strNum += std::to_string(vecNum[i]);
    }
    result[num].push_back(strNum);
    return strNum;
}

int calc(int n, int i, int d, int key) {
    if (!i) {
        std::vector<int> a;
        if (!n) {
            auto lhs = std::find_if_not(responseNum.begin(), responseNum.end(), find_char);
            std::copy(lhs, responseNum.begin() + d, std::back_inserter(a));
            create_number(a, key);
        }
        return 0;
    }

    responseNum[d] = 0;
    calc(n, i - 1, d + 1, key);
    if (n >= fibVec[i]) {
        responseNum[d] = 1;
        calc(n - fibVec[i], i - 1, d + 1, key);
    };
    return 0;
}