/**
 * @file Event.cpp
 * @author DECSAI
 * @note To be implemented by students 
 * 
 */

#include <string>
#include <iostream>
#include "Event.h"
#include "DateTime.h"
using namespace std;

Event::Event() {
    initDefault();
}

void Event::initDefault() {
    //const std::string EVENT_DEFAULT = (((std::string)"1971-01-01 00:00:00 UTC,view,")+EMPTY_FIELD+",,,,-1.000000,"+ EMPTY_FIELD+ ","+ EMPTY_FIELD);

    DateTime time;
    _dateTime = time;
    
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
    char separator = ',';
    int c=0;
    string values[9];
    
    for (size_t p=0, q=0; p!=line.npos;p=q){
        values[c]=line.substr(p+(p!=0),(q=line.find(separator,p+1))-p-(p!=0));
        c++;
    }
    
    DateTime time(values[0]);
    _dateTime = time;
    _type=values[1];
    _prod_id=values[2];
    _cat_id=values[3];
    _cat_cod=values[4];
    _brand=values[5];
    _price=stod(values[6]);
    _user_id=values[7];
    _session=values[8];
}

DateTime Event::getDateTime()  {
}

string Event::getType()  { return _type; }

string Event::getProductID()  { return _prod_id; }

string Event::getCategoryID()  { return _cat_id; }

string Event::getCategoryCode()  { return _cat_cod; }

string Event::getBrand()  { return _brand; }

double Event::getPrice()  { return _price; }

string Event::getUserID()  { return _user_id; }

string Event::getSession()  { return _session; }

void Event::setDateTime( string  time) {
}

void Event::setType( std::string  type) {

}

void Event::setProductID( std::string  prod_id) {
 }

void Event::setCategoryID( std::string  cat_id) {
}

void Event::setCategoryCode( std::string  cat_cod) {
}

void Event::setBrand( std::string  brand) {
}

void Event::setPrice(double price) {

}

void Event::setUserID( std::string  user_id) {

}

void Event::setSession( std::string  session) {

}

void Event::set( std::string line) {

}

bool Event::isEmpty()  {

}

string Event::to_string() const {
    string salida;
    salida += _dateTime.to_string();
    salida += "," + _type;
    salida += "," + _prod_id;
    salida += "," + _cat_id;
    salida += "," + _cat_cod;
    salida += "," + _brand;
    salida += "," + std::to_string(_price);
    salida += "," + _user_id;
    salida += "," + _session;
    return salida;
}
