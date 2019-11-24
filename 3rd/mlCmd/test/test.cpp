
#include <iostream>

#include "mlCmd.h"

int main( int argc, const char * argv[] )
{
    std::cout << "----------------------" << std::endl;
    
    mlCmd::Phrase phrase( argc, argv );
    
    for ( int i = 0; i < argc; ++i )
    {
        std::cout << phrase.next() << std::endl;
    }
    
    std::cout << "----------------------" << std::endl;
    return 0;
}
