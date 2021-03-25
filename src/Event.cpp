/**
 * @file Event.cpp
 * @author DECSAI
 * @note To be implemented by students 
 * 
 */

#include <string>
#include <iostream>
#include <string.h>
#include "Event.h"
#include "DateTime.h"
using namespace std;

Event::Event() {
    initDefault();
}

void Event::initDefault() {
    //const std::string EVENT_DEFAULT = (((std::string)"1971-01-01 00:00:00 UTC,view,")+EMPTY_FIELD+",,,,-1.000000,"+ EMPTY_FIELD+ ","+ EMPTY_FIELD);
    
    DateTime objectTime();
    _type = "view";
    _prod_id = "00000000"; // NOTNULL
    _cat_id = "";
    _cat_cod = "";
    _brand = "";
    _price = -1;
    _user_id = "00000000"; //NOTNULL
    _session = "00000000"; //NOTNULL
}

Event::Event( string line) {
    set(line);
}

DateTime Event::getDateTime() const  { return _dateTime.to_string();}

string Event::getType()  { return _type; }

string Event::getProductID()  { return _prod_id; }

string Event::getCategoryID()  { return _cat_id; }

string Event::getCategoryCode()  { return _cat_cod; }

string Event::getBrand()  { return _brand; }

double Event::getPrice()  { return _price; }

string Event::getUserID()  { return _user_id; }

string Event::getSession()  { return _session; }

void Event::setDateTime( string  time) {
    //DateTime _dateTime (time);
    DateTime objectTime(time);
    _dateTime= objectTime;
}

void Event::setType( std::string type) {
    if (type != VALID_TYPES[0] && type != VALID_TYPES[1] && type != VALID_TYPES[2] && type != VALID_TYPES[3]){
        _type = VALID_TYPES[0];
    } else {
        _type = type;
    }
    
}

void Event::setProductID( std::string  prod_id) {
    if(prod_id=="")
        _prod_id=EMPTY_FIELD;
    
    else _prod_id=prod_id;
}

void Event::setCategoryID( std::string  cat_id) {
    _cat_id=cat_id;
}

void Event::setCategoryCode( std::string  cat_cod) {
    _cat_cod=cat_cod;
}

void Event::setBrand( std::string  brand) {
    _brand=brand;
}

void Event::setPrice(double price) {
    if(price >= 0)
        _price=price;
}

void Event::setUserID( std::string  user_id) {
    if(user_id=="")
        _user_id=EMPTY_FIELD;
    
    else _user_id=user_id;
}

void Event::setSession( std::string  session) {
    if(session == "")
        _session=EMPTY_FIELD;
    
    else _session=session;
}

void Event::set( std::string line) {
    char separator = ',';
    int c=0;
    string values[9];
    
    for (size_t p=0, q=0; p!=line.npos;p=q){
        values[c]=line.substr(p+(p!=0),(q=line.find(separator,p+1))-p-(p!=0));
        c++;
    }
      
    setDateTime(values[0]);
    setType(values[1]);
    setProductID(values[2]);
    setCategoryID(values[3]);
    setCategoryCode(values[4]);
    setBrand(values[5]);
    setPrice(stod(values[6]));
    setUserID(values[7]);
    setSession(values[8]);
}

bool Event::isEmpty()  {
}

string Event::to_string() const {
    string output;
    output += _dateTime.to_string();
    output += "," + _type;
    output += "," + _prod_id;
    output += "," + _cat_id;
    output += "," + _cat_cod;
    output += "," + _brand;
    output += "," + std::to_string(_price);
    output += "," + _user_id;
    output += "," + _session;
    return output;
}
