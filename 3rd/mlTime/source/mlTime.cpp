
#include <cstring>
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

//-------------------------------------------------------------------------
bool Date2Timestamp( const char * date_, long & timestamp_ )
{
    if ( strlen(date_) == 8 )
    {
        // todo(gzy): again allocator???
        char cDatetime[18];
        strcpy(cDatetime, date_);
        strcat(cDatetime, " 00:00:00");
        String2Timestamp(cDatetime, "%Y%m%d %H:%M:%S", timestamp_);
        
        return timestamp_ >= 0;
    }
    else if ( strlen(date_) == 6 )
    {
        char cDatetime[18];
        strcpy(cDatetime, date_);
        strcat(cDatetime, "01 00:00:00");
        String2Timestamp(cDatetime, "%Y%m%d %H:%M:%S", timestamp_);
        
        return timestamp_ >= 0;
    }
    else if ( strlen(date_) == 4 )
    {
        char cDatetime[18];
        strcpy(cDatetime, date_);
        strcat(cDatetime, "0101 00:00:00");
        String2Timestamp(cDatetime, "%Y%m%d %H:%M:%S", timestamp_);
        
        return timestamp_ >= 0;
    }
    return false;
}
//-------------------------------------------------------------------------
void MonthOffset( int offset_, long & timestamp_ )
{
    struct tm *tmpTm;
    time_t lt;
    
    lt = timestamp_;
    // todo(gzy): ? memory leak?
    tmpTm = localtime( &lt );
    
    tmpTm->tm_mon += offset_;
    
    timestamp_ = mktime(tmpTm);
}

//-------------------------------------------------------------------------
void SetYear( int year_, long & timestamp_ )
{
    struct tm *tmpTm;
    time_t lt;
    
    lt = timestamp_;
    // todo(gzy): ? memory leak?
    tmpTm = localtime( &lt );
    
    tmpTm->tm_year = year_ - 1900;
    
    timestamp_ = mktime(tmpTm);
}

//-------------------------------------------------------------------------
void SetMonth( int month_, long & timestamp_ )
{
    struct tm *tmpTm;
    time_t lt;
    
    lt = timestamp_;
    // todo(gzy): ? memory leak?
    tmpTm = localtime( &lt );
    
    tmpTm->tm_mon = month_ - 1;
    
    timestamp_ = mktime(tmpTm);
}

//-------------------------------------------------------------------------
void SetDay( int day_, long & timestamp_ )
{
    struct tm *tmpTm;
    time_t lt;
    
    lt = timestamp_;
    // todo(gzy): ? memory leak?
    tmpTm = localtime( &lt );
    
    tmpTm->tm_mday = day_;
    
    timestamp_ = mktime(tmpTm);
}
//-------------------------------------------------------------------------
void SetHour( int hour_, long & timestamp_ )
{
    struct tm *tmpTm;
    time_t lt;
    
    lt = timestamp_;
    // todo(gzy): ? memory leak?
    tmpTm = localtime( &lt );
    
    tmpTm->tm_hour = hour_;
    
    timestamp_ = mktime(tmpTm);
}

//-------------------------------------------------------------------------
void SetMinute( int min_, long & timestamp_ )
{
    struct tm *tmpTm;
    time_t lt;
    
    lt = timestamp_;
    // todo(gzy): ? memory leak?
    tmpTm = localtime( &lt );
    
    tmpTm->tm_min = min_;
    
    timestamp_ = mktime(tmpTm);
}

//-------------------------------------------------------------------------
void SetSecond( int sec_, long & timestamp_ )
{
    struct tm *tmpTm;
    time_t lt;
    
    lt = timestamp_;
    // todo(gzy): ? memory leak?
    tmpTm = localtime( &lt );
    
    tmpTm->tm_sec = sec_;
    
    timestamp_ = mktime(tmpTm);
}

//-------------------------------------------------------------------------
long Now()
{
    time_t curTime = 0;
    return time(&curTime);
}

};
