#ifndef _DATETIME_
#define _DATETIME_

#include "../stdafx.h"
#include <ctime>
#include <stdexcept>

int *whatTime(const bool utc);
std::string dateFormat (int const *tmArr);
std::string timeFormat (int const *tmArr);
std::string tmFormat(bool const utc, bool const date, bool const time);

#endif // !_DATETIME_