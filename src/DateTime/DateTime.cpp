#include "DateTime.h"

std::string tmFormat(bool const utc, bool const date, bool const time)
{
    int *tmArr;
    // recall local time; 0~2 date info; 3~5 time info
    tmArr = whatTime(utc);
    std::string tmpDT;
    // recalling function to format the date and/or time by request
    if (date && time)
        tmpDT = dateFormat(tmArr) + " " + timeFormat(tmArr);
    else if (date && !time)
        tmpDT = dateFormat(tmArr);
    else if (!date && time)
        tmpDT = timeFormat(tmArr);
    else
        // throw error messgae if ther is no maching case
        throw std::logic_error("Check function option list");
    // delect array from memory
    delete[] tmArr;
    return tmpDT;
}

int *whatTime(const bool utc)
{
    // current date/time based on current system
    time_t now = time(0);
    int *dateTime = new int[6];
    tm *tmLG;
    try
    {
        if (!utc)
            // local time struct
            tmLG = localtime(&now);
        else
            // convert now to tm struct for UTC
            tmLG = gmtime(&now);
    }
    catch (const std::invalid_argument &ia)
    {
        std::cerr << "Invalid argument: " << ia.what() << '\n';
    }
    // pure time and date information into array
    dateTime[0] = 1900 + tmLG->tm_year;
    dateTime[1] = 1 + tmLG->tm_mon;
    dateTime[2] = tmLG->tm_mday;
    dateTime[3] = 1 + tmLG->tm_hour;
    dateTime[4] = 1 + tmLG->tm_min;
    dateTime[5] = 1 + tmLG->tm_sec;
    return dateTime;
}

std::string dateFormat(int const *tmArr)
{
    std::string tmp;
    // formatting date

    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
            tmp = std::to_string(tmArr[i]);
        else
            tmp = tmp + "/" + std::to_string(tmArr[i]);
    }

    return tmp;
}

std::string timeFormat(int const *tmArr)
{
    std::string tmp;
    // formattinf time
    for (int i = 3; i < 6; i++)
    {
        if (i == 3)
            tmp = std::to_string(tmArr[i]);
        else
            tmp = tmp + ":" + std::to_string(tmArr[i]);
    }
    return tmp;
}