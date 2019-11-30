
#include <iostream>

#include "mlTime.h"

const char * PrintTimstampToString( const long & timestamp_ )
{
    static char buffer[20];
    mlTime::Timestamp2String(timestamp_, "%Y-%m-%d %H:%M:%S", buffer, 20);
    return buffer;
}

int main()
{
    std::cout << "----------------------" << std::endl;
    
    int time = 1574566918;
    char c[100];
    mlTime::Timestamp2String(time, "%Y-%m-%d %H:%M:%S", c, 100);
    
    std::cout << c << std::endl;
    
    long lTime = 0;
    mlTime::String2Timestamp(c, "%Y-%m-%d %H:%M:%S", lTime);
    std::cout << lTime << " -> " << PrintTimstampToString(lTime) << std::endl;
    
    if ( mlTime::Date2Timestamp("20190804", lTime) )
    {
        std::cout << lTime << " -> " << PrintTimstampToString(lTime) << std::endl;
    }
    else
    {
        std::cout << "..." << std::endl;
    }
    
    if ( mlTime::Date2Timestamp("201908", lTime) )
    {
        std::cout << lTime << " -> " << PrintTimstampToString(lTime) << std::endl;
    }
    else
    {
        std::cout << "..." << std::endl;
    }
    
    if ( mlTime::Date2Timestamp("2019", lTime) )
    {
        std::cout << lTime << " -> " << PrintTimstampToString(lTime) << std::endl;
    }
    else
    {
        std::cout << "..." << std::endl;
    }
    
    if ( mlTime::Date2Timestamp("201", lTime) )
    {
        std::cout << lTime << " -> " << PrintTimstampToString(lTime) << std::endl;
    }
    else
    {
        std::cout << "..." << std::endl;
    }
    
    std::cout << "++++++++++" << std::endl;
    mlTime::SetDay(30, lTime);
    std::cout << lTime << " -> " << PrintTimstampToString(lTime) << std::endl;
    
    mlTime::MonthOffset(2, lTime);
    std::cout << lTime << " -> " << PrintTimstampToString(lTime) << std::endl;
    
    mlTime::MonthOffset(-1, lTime);
    std::cout << lTime << " -> " << PrintTimstampToString(lTime) << std::endl;
    
    mlTime::MonthOffset(-2, lTime);
    std::cout << lTime << " -> " << PrintTimstampToString(lTime) << std::endl;
    
    mlTime::MonthOffset(1, lTime);
    std::cout << lTime << " -> " << PrintTimstampToString(lTime) << std::endl;
    
    mlTime::MonthOffset(1, lTime);
    std::cout << lTime << " -> " << PrintTimstampToString(lTime) << std::endl;
    
    mlTime::MonthOffset(-1, lTime);
    std::cout << lTime << " -> " << PrintTimstampToString(lTime) << std::endl;
    
    mlTime::MonthOffset(-3, lTime);
    std::cout << lTime << " -> " << PrintTimstampToString(lTime) << std::endl;
    
    mlTime::SetMonth(1, lTime);
    std::cout << lTime << " -> " << PrintTimstampToString(lTime) << std::endl;
    mlTime::SetMonth(12, lTime);
    std::cout << lTime << " -> " << PrintTimstampToString(lTime) << std::endl;
    
    mlTime::SetYear(2006, lTime);
    std::cout << lTime << " -> " << PrintTimstampToString(lTime) << std::endl;
    
    std::cout << "++++++++++" << std::endl;
    lTime = mlTime::Now();
    std::cout << lTime << " -> " << PrintTimstampToString(lTime) << std::endl;
    
    mlTime::SetHour(24, lTime);
    std::cout << lTime << " -> " << PrintTimstampToString(lTime) << std::endl;
    
    mlTime::SetMinute(0, lTime);
    std::cout << lTime << " -> " << PrintTimstampToString(lTime) << std::endl;
    
    mlTime::SetSecond(0, lTime);
    std::cout << lTime << " -> " << PrintTimstampToString(lTime) << std::endl;
    
    std::cout << "----------------------" << std::endl;
    return 0;
}
