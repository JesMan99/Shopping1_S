/**
 * @file main.cpp
 * @author DECSAI
 * @note To be implemented by students 
 * 
 */


#include <string>
#include <cassert>
#include <iostream>
#include "Event.h"

#include "MPTests.h"

using namespace std;


/**
 * @brief displays the content of the array by using the method to_string that easy to transfer data to stream.  The content remains constant
 * @param array of the Events
 * @param nEvent number of events in the array
 */
void print(const Event array[], int & nEvent){
    for(int i=0; i<nEvent; i++)
        cout << array[i].to_string() <<endl;

}

/**
 * @brief Update the counter per week day (value in 0..6) for every event found . 
 * It also shows the computed values on the screen in the following format
 * ~~~~
 *      SUNDAY(0) MONDAY(0) TUESDAY(0) WEDNESDAY(0) THURSDAY(0) FRIDAY(0) SATURDAY(0)
 *      +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+ 
 *      |    |    |    |    |    |
 *      0    5    10   15   20   25
 * ~~~~
 * 
 * @param arrayE an Event input array
 * @param nEvents number of events in arrayE
 * @param arrayA an int output array
 */
void computeActivity(const Event arrayE[], int  nEvents,  int arrayA[]){
    int day = 0;
    for (int i = 0; i<nEvents;i++){
        
        day = arrayE[i].getDateTime().weekDay();
        arrayA[day]++;
        cout << day;
    }
   
    CVAL << "Activity found:";
    for (int day=0; day<7; day++) {
        CVAL << " " << DAYNAME[day]<<"("<<arrayA[day]<<")";
    }
    CVAL << endl;
}

/**
 * @brief Compute the  max number of activity events, and the day on which is produced
 * @param arrayA the counter of activities, an input array
 * @param ndays number of days
 * @param maxDay
 * @return maxActivity the counter of events of 
 */
int computeMaxActivityDay(const int arrayA[], int &maxDay, int ndays=7){
    int max_Activity =-1;
    maxDay=-1;
    for(int i=0; i<ndays; i++){
        if(arrayA[i]>max_Activity){
            max_Activity = arrayA[i];
            maxDay=i;
        }
    }
    return max_Activity;
}



/**
 * @brief The main function of the program carries out the following procedure
 *   - It uses a static array of Events to store a sequence of events read from 
 * keyboard (likely to be redirected from a data file in the ./tests folder)
 *   - It reads the maximum number of valid records to be stored in the array.
 *   - If the event read is right (use the method isEmpty() to detect non-valid
 * records), it is stored in the array, otherwise, it is dismissed. Only valid records count.
 *   - Next, it computes the number of events found at each day of the week (complete the implementation
 * of the local function computeActivity() which also shows the result)
 *   - Next, it finds which is the day of highest activity recorded and show it on screen
 */
int main(int argc, char** argv) {
    int valid_Events=0, counter=0;
    string line;
    int arrayA[] = {0,0,0,0,0,0,0};
    int max_activity, maxDay;
    
    cout << "Introduce the number of valid events to read:" <<endl;
    cin >> valid_Events;
    
    Event Valid_Events[valid_Events];
    Event to_try;
    
    for(int i=0; i>valid_Events;){
        cout << "Introduce a string:" <<endl;
        getline(cin, line);
        to_try.set(line);
        counter++;
        
        if(!to_try.isEmpty()){
            Valid_Events[i] = to_try;
            i++;
        }
    }
    
    CVAL << "Events readed: " << counter <<endl;
    CVAL << "Valid events readed: " << valid_Events <<endl;
    
    print(Valid_Events, valid_Events);
    
    computeActivity(Valid_Events, valid_Events, arrayA);
    
    max_activity = computeMaxActivityDay(arrayA, maxDay);
}