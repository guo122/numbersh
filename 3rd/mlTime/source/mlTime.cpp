
#include <ctime>

#include "mlTime.h"

namespace mlTime
{

//-------------------------------------------------------------------------
void Timestamp2String( const long & timestamp_, const char * format_, char * str_, int str_size_  )
{
    struct tm *tmpTm;
    time_t lt;
    
    lt = timestamp_;
    // todo(gzy): ? memory leak?
    tmpTm = localtime( &lt );
    
    strftime(str_, str_size_, format_, tmpTm);
}

//-------------------------------------------------------------------------
void String2Timestamp( const char * str_, const char * format_, long & timestamp_ )
{
    struct tm tmpTm;
    strptime(str_, format_, &tmpTm);
    
    timestamp_ = mktime(&tmpTm);
}

};
