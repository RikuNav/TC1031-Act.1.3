// =================================================================
//
// File: ship.h
// Author: Fernando Matute - A00833375
// Date: 11/09/2022
//
// =================================================================
#ifndef SHIP_H_
#define SHIP_H_

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Ship{
    public:
        char entry;
        int minute, hour, day, month, year;
        //string day, month, year, hour, minute;
        string ubi;

        //Default Constructor
        Ship(string date, string time, char entry, string ubi);
        Ship();
        Ship(const Ship &ship);

        bool first_than(const Ship &);

        void set_time(string);
        void set_date(string);
        void set_entry(char);
        void set_ubi(string);
};
        
Ship::Ship(string date, string time, char entry_a, string ubi_a){
    day = (date[0] - '0') * 10 + (date[1] - '0');
    month = (date[3] - '0') * 10 + (date[4] - '0');
    year = (date[6] - '0') * 10 + (date[7] - '0');

    hour = (time[0] - '0') * 10 + (time[1] - '0');
    minute = (time[3] - '0') * 10 + (time[4] - '0');

    entry = entry_a; 
    ubi = ubi_a;
} 
        
Ship::Ship(){
    day = 0;
    month = 0;
    year = 0;

    hour = 0;
    minute = 0;

    entry = ' ';
    day = 0;

    ubi = " ";
}

Ship::Ship(const Ship &ship){
    day = ship.day;
    month = ship.month;
    year = ship.year;

    hour = ship.hour;
    minute = ship.minute;

    entry = ship.entry;
    ubi = ship.ubi;
}


//Compare between ships
bool Ship::first_than(const Ship &ship){

    if(month < ship.month){
        return true;
    }
    else if(month > ship.month){
            return false;
        }

    else{
        if(day < ship.day){
            return true;
        }
        else if (day > ship.day){
            return false;
        }
    }
    return false;
}

#endif //SHIP_H_
