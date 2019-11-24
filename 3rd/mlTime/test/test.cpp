
#include <iostream>

#include "mlTime.h"

int main()
{
    std::cout << "----------------------" << std::endl;
    
    int time = 1574566918;
    char c[100];
    mlTime::Timestamp2String(time, "%Y-%m-%d %H:%M:%S", c, 100);
    
    std::cout << c << std::endl;
    
    int nTime = 0;
    mlTime::String2Timestamp(c, "%Y-%m-%d %H:%M:%S", nTime);
    
    std::cout << nTime << std::endl;
    
    std::cout << "----------------------" << std::endl;
    return 0;
}
