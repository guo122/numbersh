
#include <cstring>

#include "mlChar.h"

namespace mlChar
{

//-------------------------------------------------------------------------
char * Strcpy( char * dst_, const int dst_size_, const char * src_ )
{
    if ( ::strlen(src_) < dst_size_ )
    {
        return ::strcpy( dst_, src_ );
    }
    return NULL;
}

};
