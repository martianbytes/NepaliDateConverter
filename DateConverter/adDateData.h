#ifndef ADDATEDATA_H
#define ADDATEDATA_H

#include <iostream>

bool isLeapYear(int year) {
    // A leap year is divisible by 4, but not by 100 unless it's also divisible by 400
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}


int getDaysInMonth(int year, int month) {
    // Days in each month, except February which will be handled based on leap years
    //it is 0 based make sure you already subtracted the month by 1
    switch (month) {
        case 0: // January
        case 2: // March
        case 4: // May
        case 6: // July
        case 7: // August
        case 9: // October
        case 11: // December
            return 31;
        case 1: // February
            return (isLeapYear(year) ? 29 : 28); // Check for leap year
        case 3: // April
        case 5: // June
        case 8: // September
        case 10: // November
            return 30;
        default:
            return 30; // Default fallback
    }
}

#endif