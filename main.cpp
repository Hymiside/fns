#include <iostream>
#include "file_manager/file_manager.h";

int main()
{
    std::pair<std::vector<int>, bool> res = read_file();
    if (res.second) {
        std::cout<<"invalid data in file"<<std::endl;
        return 0;
    }
    std::cout<<res.first.front()<<std::endl;

}