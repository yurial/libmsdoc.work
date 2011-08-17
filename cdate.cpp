#include <sstream>
#include <iomanip>
#include "cdate.h"

CDate::CDate(int uts):
    m_uts( uts )
{
}

TString CDate::c_str() const
{
struct tm l_tm;
time_t uts = m_uts;
localtime_r( &uts, &l_tm );

int sec = l_tm.tm_sec;
int min = l_tm.tm_min;
int hour = l_tm.tm_hour;
int mday = l_tm.tm_mday;
int mon = l_tm.tm_mon + 1;
int year = l_tm.tm_year + 1900;

std::stringstream date;
date <<        std::setw(4) << std::setfill('0') << year;
date << '-' << std::setw(2) << std::setfill('0') << mon;
date << '-' << std::setw(2) << std::setfill('0') << mday;
date << 'T';
date <<        std::setw(2) << std::setfill('0') << hour;
date << ':' << std::setw(2) << std::setfill('0') << min;
//date << ':' << std::setw(2) << std::setfill('0') << sec;
date << 'Z';
return date.str();
}

