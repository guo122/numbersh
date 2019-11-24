
#include "mlLog.h"

int main()
{
    mlLog::Log("----------------------");
    
    mlLog::Log( "hello, %s", "world" );
    mlLog::Warning( "whhhhhh...., %f", 1.22 );
    mlLog::Error( "fatal error, type: %i", 22 );
    
    mlLog::Log("----------------------");
    return 0;
}
