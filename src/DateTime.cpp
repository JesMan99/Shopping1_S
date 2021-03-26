/**
 * @file DateTime.cpp
 * @author DECSAI
 * @note To be implemented by students 
 * 
 */

#include <iostream>
#include <sstream>
#include "DateTime.h"
using namespace std;

/**
 * @brief auxiliary function to check if the date and the time are in correct 
 * format, taking into account, leap year etc.
 * @param year input
 * @param month input
 * @param day input
 * @param hour input
 * @param min input
 * @param sec input
 * @return true if is correct, false if not
 */
bool isCorrect(int year, int month, int day, int hour, int min, int sec){
    int days_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    month--;
    
    if(month > 11 || month < 0)
        return false;
    
    if (hour > 23 ||hour < 0 || min > 59 || min < 0 || sec < 0 || sec > 59)
        return false;
    
    if ((year % 4 == 0 && year % 100 != 0) || year %  400 == 0)
        days_month[1]++;
    
    if (day < 1 || day > days_month[month])
        return false;  
    
    
   return true; 
}

/**
 * @brief split the first field in 6 components of the data time.
 * Please consider using string::substr(int, int)[https://en.cppreference.com/w/cpp/string/basic_string/substr] to cut the line
 * into the appropriate substrings and then convert it into integer values with 
 * the function stoi(string) [https://en.cppreference.com/w/cpp/string/basic_string/stol]
 * ~~~~
 *      YYYY-MM-dd hh:mm:ss UTC 
 *      +----+----+----+----+----+ 
 *      |    |    |    |    |    |
 *      0    5    10   15   20   25
 * ~~~~
 *  * @param line input string
 * @param y output int
 * @param m output int
 * @param d output int
 * @param h output int
 * @param mn output int
 * @param s output int
 */
void split( std::string line, int &y, int  &m, int  &d, int  &h, int &mn, int &s){
    string number="";
    int arrayNumber[6] = {0,0,0,0,0,0};
    int index = 0;
    bool correct = true;
    for (int i = 0; i<=line.length();i++){
        //48 (0) - 57 (9)
        if (line[i]<= '9' && line[i]>='0'){
            number = number + line[i];
        } else {
            if(number!=""){
                if ((index == 1 || index == 2) && number.length()<2 ) { correct = false; }
                arrayNumber[index]=stoi(number);
                index++;
            }
            number="";
        }   
    }
       
    
    if ((isCorrect(arrayNumber[0],arrayNumber[1],arrayNumber[2],arrayNumber[3],arrayNumber[4],arrayNumber[5]) && correct)){
        y = arrayNumber[0];
        m = arrayNumber[1];
        d = arrayNumber[2];
        h = arrayNumber[3];
        mn = arrayNumber[4];
        s = arrayNumber[5];
    } else {
        y = 1971;
        m = 1;
        d = 1;
        h = 00;
        mn = 00;
        s = 00;
    };
};

DateTime::DateTime() {
    initDefault();
}

void DateTime::initDefault() {
    /*_year = 1971;
    _month = 1;
    _day = 1;
    _hour = 00;
    _min = 00;
    _sec = 00;*/
    set("1971-01-01 00:00:00 UTC");
}

void DateTime::set(string  line) {
    
    int y=0,m=0,d=0,h=0,mn=0,s=0;
    split(line,y,m,d,h,mn,s);
   
    _year = y;
    _month = m;
    _day = d;
    _hour = h;
    _min = mn;
    _sec = s;
    
    /*_year = stoi(line.substr(0,4));
    _month = stoi(line.substr(5,2));
    _day = stoi(line.substr(8,2));
    _hour = stoi(line.substr(11,2));
    _min = stoi(line.substr(14,2));
    _sec = stoi(line.substr(17,2));*/
}

DateTime::DateTime( string line) {
    set(line);
}

int DateTime::year()  {
    return _year;
}

int DateTime::month()  {
    return _month;
}

int DateTime::day()  {
    return _day;
}

int DateTime::hour()  {
    return _hour;
}

int DateTime::min()  {
    return _min;
}

int DateTime::sec()  {
    return _sec;
}

bool DateTime::isBefore( DateTime  one)  {
     return to_string() < one.to_string();
}

int DateTime::weekDay(){
    int a = (14 - _month) / 12;
    int y = _year - a;
    int m = _month + 12 * a -2;
    int wDay;
    wDay = (_day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
    return wDay;
}

string DateTime::to_string() const {
    char local[64];
    sprintf(local, "%04i-%02i-%02i %02i:%02i:%02i UTC", _year, _month, _day, _hour, _min, _sec);
    return local;
}