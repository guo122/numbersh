
#include <iostream>

#include "mlChar.h"

int main()
{
    std::cout << "----------------------" << std::endl;
    
    char c1[5] = "";
    char c2[10] = "";
    char c3[20] = "ABCDEFGH";
    
    mlChar::Strcpy(c1, 5, c3);
    mlChar::Strcpy(c2, 10, c3);
    
//    strcpy(c1, c3);
//    strcpy(c2, c3);
    
    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;
    std::cout << c3 << std::endl;
    
    std::cout << "----------------------" << std::endl;
    return 0;
}
