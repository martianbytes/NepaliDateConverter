#ifndef VALIDITYCHECKS_H
#define VALIDITYCHECKS_H

#include <iostream>
#include <ctime>
#include <iomanip>
#include "nepToEng.h"
#include "engToNep.h"
#include "dateData.h"
#include "adDateData.h"



int getNumberOnly(){
    int number;
    std::cin >> number;
    //check if the input is an alphabet
    while(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Invalid input. Please enter a number: ";
        std::cin >> number;
    }
    std::cin.ignore(100, '\n');
    return number;
}



int getValidNepaliYear(){
    int NepaliYear;
    std::cout << "Enter Nepali Year: ";
    NepaliYear = getNumberOnly();
    while(NepaliYear < 2000 || NepaliYear > 2099){
        std::cout << "Invalid year. Please enter a year between 2000 and 2099: ";
        NepaliYear = getNumberOnly();
    }
    return NepaliYear;
}

int getValidNepaliDay(int year, int month){
    // month -= 1;
    int day;
    std::cout << "Enter Day: ";
    day = getNumberOnly();
    while(day < 1 || day > 32){
        std::cout << "Invalid day. Please enter a day between 1 and 32: ";
        day = getNumberOnly();
    }
    while(day > dateData[year][month - 1]){
        std::cout << "Invalid day. Please enter a day between 1 and " << dateData[year][month - 1] << ": ";
        day = getNumberOnly();
    }
    return day;
}


//this will work for both Nepali and English months
int getValidMonth(){
    int month;
    std::cout << "Enter Month: ";
    month = getNumberOnly();
    while(month < 1 || month > 12){
        std::cout << "Invalid month. Please enter a month between 1 and 12: ";
        month = getNumberOnly();
    }
    // month -= 1;
    return month;
}



int getValidEnglishYear(){
    int EnglishYear;
    std::cout << "Enter English Year: ";
    EnglishYear = getNumberOnly();
    while(EnglishYear < 1944 || EnglishYear > 2033){
        std::cout << "Invalid year. Please enter a year between 1944 and 2033: ";
        EnglishYear = getNumberOnly();
    }
    return EnglishYear;
}

int getValidEnglishDay(int year, int month){
    /*You will need month and year, to check for leap*/
   month -= 1;//month is 0 based
    int day;
    std::cout << "Enter Day: ";
    day = getNumberOnly();
    while(day < 1 || day > 32){
        std::cout << "Invalid day. Please enter a day between 1 and 32: ";
        day = getNumberOnly();
    }
    while(day > getDaysInMonth(year, month)){
        std::cout << "Invalid day. Please enter a day between 1 and " << getDaysInMonth(year, month) << ": ";
        day = getNumberOnly();
    }
    return day;
}

#endif // VALIDITYCHECKS_H