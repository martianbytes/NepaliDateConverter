#ifndef NEPTOENG_H
#define NEPTOENG_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>
#include <ctime>
#include "adDateData.h"
#include "dateData.h"

// Function prototypes
int findDaysDifference(int targetYear, int targetMonth, int targetDay);
std::tm convertNepaliDateToEnglish(int NepaliYear, int NepaliMonth, int NepaliDay);
int getDaysInMonth(int year, int month);
bool isLeapYear(int year);  // Declare isLeapYear here




std::tm convertNepaliDateToEnglish(int NepaliYear, int NepaliMonth, int NepaliDay) {
    // Initialize the base English date: 1943-04-14
    std::tm baseEnglishDate = {};
    baseEnglishDate.tm_year = 1943 - 1900;  // tm_year is years since 1900 as epoch start from 1900
    baseEnglishDate.tm_mon = 4 - 1;         // tm_mon is 0-based (0 = January)
    baseEnglishDate.tm_mday = 14;

    // Calculate the difference in days
    int daysDifference = findDaysDifference(NepaliYear, NepaliMonth, NepaliDay);

    // Add the days difference to the base date
    baseEnglishDate.tm_mday += daysDifference;

    // Handle overflow of days (e.g., 32nd day in a month)
    while (baseEnglishDate.tm_mday > getDaysInMonth(baseEnglishDate.tm_year + 1900, baseEnglishDate.tm_mon)) {
        baseEnglishDate.tm_mday -= getDaysInMonth(baseEnglishDate.tm_year + 1900, baseEnglishDate.tm_mon);
        baseEnglishDate.tm_mon++;

        // Handle overflow of months (i.e., going past December)
        if (baseEnglishDate.tm_mon >= 12) {
            baseEnglishDate.tm_mon = 0;
            baseEnglishDate.tm_year++;
        }
    }

    // Normalize the date (to handle cases like 32nd day or overflow months)
    std::mktime(&baseEnglishDate);
    
    return baseEnglishDate;
}

int findDaysDifference(int targetYear, int targetMonth, int targetDay) {
    int dayDifference = 0;

    // Calculate the days difference from base year to target year
    for (int year = 2000; year < targetYear; year++) {
        if (dateData.find(year) != dateData.end()) {  // Check if year exists in map
            for (int month = 0; month < 12; month++) {
                dayDifference += dateData[year][month];
            }
        }
    }

    // Accumulate the days for months in the target year
    if (dateData.find(targetYear) != dateData.end()) {
        for (int month = 0; month < targetMonth - 1; month++) {
            dayDifference += dateData[targetYear][month];
        }
    }

    // Add the days in the current month (excluding the first day)
    dayDifference += (targetDay - 1);

    return dayDifference;
}

#endif