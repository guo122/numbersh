
#include <iostream>

#include "mlPath.h"

int main()
{
    std::cout << "----------------------" << std::endl;

    char cPath[100];
    
    mlPath::HomeDash2Absolute("~/Documents", cPath);
    
    std::cout << cPath << std::endl;
    
    std::cout << "----------------------" << std::endl;
    return 0;
}
