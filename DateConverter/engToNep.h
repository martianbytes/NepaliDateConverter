#ifndef ENGTONEP_H
#define ENGTONEP_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>
#include <ctime>

#include "adDateData.h"
#include "dateData.h"

struct Date {
    int year;
    int month;
    int day;
};

//all function prototypes
int findDaysDifferenceInAD(int targetYear, int targetMonth, int targetDay);
Date convertEnglishDateToNepaliDate(int targetYear, int targetMonth, int targetDay);
int numberOfDaysIn(int year);



//function definations
//number of days in nepali year
int numberOfDaysIn(int year) {
    int totalDays = 0;
    if (dateData.find(year) != dateData.end()) {
        for (int days : dateData[year]) {
            totalDays += days;
        }
    }
    return totalDays;
}

//find the days difference in AD
int findDaysDifferenceInAD(int targetYear, int targetMonth, int targetDay) {
    /*
    remember that this is starting from the start of the year not from base english date
    you will have to subtract the days from these daysdifference for example if april 14 then add jan+feb+mar+13 and sub from days difference
    */
    int dayDifference = 0;

    for (int year = 1943; year < targetYear; year++) {

            if(isLeapYear(year)) {
                dayDifference += 366;
            } else {
                dayDifference += 365;
            }
    }

    for (int month = 0; month < targetMonth - 1; month++) {
        int daysInMonth = getDaysInMonth(targetYear, month);
        // std::cout << daysInMonth << std::endl;
        dayDifference += daysInMonth;
    }

    dayDifference += (targetDay - 1);
    // std::cout << dayDifference << std::endl;
    return dayDifference;
}

//convert english date to nepali date and returns a Date struct
Date convertEnglishDateToNepaliDate(int targetYear, int targetMonth, int targetDay) {
    std::tm baseEnglishDate = {};
    baseEnglishDate.tm_year = 1943 - 1900;
    baseEnglishDate.tm_mon = 4 - 1;
    baseEnglishDate.tm_mday = 14;

    int numberOfDaysBeforeBaseDate = 31 + 28 + 31 + 14 - 1; //jan feb march and 14 days of april
    int daysDifference = findDaysDifferenceInAD(targetYear, targetMonth, targetDay) - numberOfDaysBeforeBaseDate;
    // std::cout << daysDifference << std::endl;

    int baseNepaliYear = 2000;
    int baseNepaliMonth = 1;
    int baseNepaliDay = 1;

    int targetNepaliYear = baseNepaliYear;
    while (daysDifference >= numberOfDaysIn(targetNepaliYear)) {
        daysDifference -= numberOfDaysIn(targetNepaliYear);
        targetNepaliYear++;
    }

    // std::cout << targetNepaliYear << std::endl;

    if (dateData.find(targetNepaliYear) == dateData.end()) {
        std::cerr << "Error: Nepali year data not available for " << targetNepaliYear << std::endl;
        return {0, 0, 0};
    }

    int targetNepaliMonth = 0;
    while (daysDifference >= dateData[targetNepaliYear][targetNepaliMonth]) {
        daysDifference -= dateData[targetNepaliYear][targetNepaliMonth];
        targetNepaliMonth++;
    }

    int targetNepaliDay = daysDifference + 1;
    return {targetNepaliYear, targetNepaliMonth + 1, targetNepaliDay};
}

#endif