
#include <cstdio>
#include <cstdarg>
#include <cstring>

#include "mlLog.h"

namespace mlLog
{

//-------------------------------------------------------------------------
void _LogImpl( const char * fmt_, const char * type_, va_list & list_ )
{
    char buffer[255];
    vsprintf( buffer, fmt_, list_ );
    
    printf("[%s] %s \n", type_, buffer);
}

//-------------------------------------------------------------------------
void Print( const char * fmt_, ... )
{
    va_list list;
    va_start(list, fmt_);
    
    char buffer[255];
    vsprintf( buffer, fmt_, list );
    
    printf("%s", buffer);
    
    va_end(list);
}

//-------------------------------------------------------------------------
void Log( const char * fmt_, ... )
{
    va_list list;
    va_start(list, fmt_);
    
    _LogImpl( fmt_, "Log", list );
    
    va_end(list);
}

//-------------------------------------------------------------------------
void Warning( const char * fmt_, ... )
{
    va_list list;
    va_start(list, fmt_);
    
    _LogImpl( fmt_, "Warning", list );
    
    va_end(list);
}

//-------------------------------------------------------------------------
void Error( const char * fmt_, ... )
{
    va_list list;
    va_start(list, fmt_);
    
    _LogImpl( fmt_, "Error", list );
    
    va_end(list);
}

};
