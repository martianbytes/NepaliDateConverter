#include <iostream>
#include <ctime>
#include <iomanip>
#include "nepToEng.h"
#include "engToNep.h"
#include "validityChecks.h"

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



int getChoice(){
    int choice = getNumberOnly();
    return choice;
}

void performAction(int choice){
    switch(choice){
        case 1:
        {
            int NepaliYear, NepaliMonth, NepaliDay;
            // std::cout << "Enter Nepali Year: ";
            NepaliYear = getValidNepaliYear();
            // std::cout << "Enter Nepali Month: ";
            NepaliMonth = getValidMonth();
            // std::cout << "Enter Nepali Day: ";
            NepaliDay = getValidNepaliDay(NepaliYear, NepaliMonth);
            std::tm englishDate = convertNepaliDateToEnglish(NepaliYear, NepaliMonth, NepaliDay);

            std::cout << NepaliYear << "-" << NepaliMonth << "-" << NepaliDay << " in BS is "
                      << std::put_time(&englishDate, "%Y-%m-%d") << " in AD." << std::endl;
            break;
        }
        case 2:
        {
            int EnglishYear, EnglishMonth, EnglishDay;
            // std::cout << "Enter English Year: ";
            EnglishYear = getValidEnglishYear();
            // std::cout << "Enter English Month: ";
            EnglishMonth = getValidMonth();
            // std::cout << "Enter English Day: ";
            EnglishDay = getValidEnglishDay(EnglishYear, EnglishMonth);
            Date nepaliDate = convertEnglishDateToNepaliDate(EnglishYear, EnglishMonth, EnglishDay);
            std::cout << EnglishYear << "-" << EnglishMonth << "-" << EnglishDay << " in AD is "
                      << nepaliDate.year << "-" << nepaliDate.month << "-" << nepaliDate.day << " in BS." << std::endl;
            break;
        }
        case 3:
        {
            std::cout << "Exiting..." << std::endl;
            exit(0);
            break;
        }
        default:
        {
            std::cout << "Invalid choice" << std::endl;
            break;
        }
    }
}

int main() {

    // display();
    // int NepaliYear = 2081;
    // int NepaliMonth = 11;
    // int NepaliDay = 13;

    // int EnglishYear = 2025;
    // int EnglishMonth = 2;
    // int EnglishDay = 25;

    // std::tm englishDate = convertNepaliDateToEnglish(NepaliYear, NepaliMonth, NepaliDay);
    // Date nepaliDate = convertEnglishDateToNepaliDate(EnglishYear, EnglishMonth, EnglishDay);
    
    // std::cout <<'\n';
    // std::cout << NepaliYear << "-" << NepaliMonth << "-" << NepaliDay << " in BS is "
    //           << std::put_time(&englishDate, "%Y-%m-%d") << " in AD." << std::endl;
    // std::cout << EnglishYear << "-" << EnglishMonth << "-" << EnglishDay << " in AD is "
    //           << nepaliDate.year << "-" << nepaliDate.month << "-" << nepaliDate.day << " in BS." << std::endl;

    while (true){
        display();
        int choice = getChoice();
        performAction(choice);
    }
    

    return 0;
}