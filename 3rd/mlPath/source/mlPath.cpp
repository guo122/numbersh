
#include <cstring>
#include <cstdlib>

#include "mlPath.h"

namespace mlPath
{

//-------------------------------------------------------------------------
void HomeDash2Absolute( const char * homeDash_, char * absolute_ )
{
    bool bJustCopy = true;
#if defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__) || defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__)
    if ( homeDash_[0] == '~' )
    {
        bJustCopy = false;
        char * cHome = getenv("HOME");
        strcpy(absolute_, cHome);
        strcat(absolute_, homeDash_ + 1);
    }
#elif defined(_WIN32) || defined(_WIN64)
    bJustCopy = true;
#endif

    if ( bJustCopy )
    {
        // todo(gzy): char size
        strcpy(absolute_, homeDash_);
    }
}

};
