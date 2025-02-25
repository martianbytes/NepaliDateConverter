#include <iostream>
#include <ctime>
#include <iomanip>
#include "nepToEng.h"
#include "engToNep.h"


/*
Read: this
These are the right way to define these
1. convertNepaliDateToEnglish returns a std::tm object from ctime library
use this method to get the dates
>>>>
std::tm englishDate = convertNepaliDateToEnglish(NepaliYear, NepaliMonth, NepaliDay);

so to print the date you will use
>>>> 
std::put_time(&englishDate, "%Y-%m-%d") << " in AD." << std::endl;

put_time is from iomanip


2. convertEnglishDateToNepaliDate returns a Date structure
use this method to get the dates
>>>>
Date nepaliDate = convertEnglishDateToNepaliDate(EnglishYear, EnglishMonth, EnglishDay);

to print the date you will use
>>>>
std::cout << nepaliDate.year << " - " << nepaliDate.month << " - " << nepaliDate.day << " in BS." << std::endl;

as this is just a structure
*/

void display(){
    std::cout << "1. Convert Nepali Date to English Date" << std::endl;
    std::cout << "2. Convert English Date to Nepali Date" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}


int main() {

    display();
    int NepaliYear = 2081;
    int NepaliMonth = 11;
    int NepaliDay = 13;

    int EnglishYear = 2025;
    int EnglishMonth = 2;
    int EnglishDay = 25;

    std::tm englishDate = convertNepaliDateToEnglish(NepaliYear, NepaliMonth, NepaliDay);
    Date nepaliDate = convertEnglishDateToNepaliDate(EnglishYear, EnglishMonth, EnglishDay);
    
    std::cout <<'\n';
    std::cout << NepaliYear << "-" << NepaliMonth << "-" << NepaliDay << " in BS is "
              << std::put_time(&englishDate, "%Y-%m-%d") << " in AD." << std::endl;
    std::cout << EnglishYear << "-" << EnglishMonth << "-" << EnglishDay << " in AD is "
              << nepaliDate.year << "-" << nepaliDate.month << "-" << nepaliDate.day << " in BS." << std::endl;

    return 0;
}