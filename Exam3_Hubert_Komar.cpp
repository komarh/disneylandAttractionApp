/*
  CSC140 EXAM 3 - Disneyland Attraction App
  Hubert Komar
  12-10-2020
*/

//necessary libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{

    //core program variables
    const int MAX_RIDES = 5;
    string rideNames[MAX_RIDES];
    int rideWaitTime[MAX_RIDES];
    int currentArrtractionIndex = 0;
    int indexOfShortestWaitTime = 0;
    char again = 'n'; //for user-controlled do loop
    int totalWaitTime = 0; //accumulator variable for computing the average
    int avgWaitTime = 0;

    //wecome message
    cout << "Welcome to Disneyland!" << endl
        << "Please enter the attractions you plan to visit and their wait times: \n\n";

    //DO loop & check for user inputs
    do 
    {
        cout << "Ride " << (currentArrtractionIndex + 1) << " info:" << endl;
        cout << "Attraction Name: ";
        getline(cin, rideNames[currentArrtractionIndex]);
        //cin >> rideNames[currentArrtractionIndex];

        cout << "Wait time (in minutes): ";
        cin >> rideWaitTime[currentArrtractionIndex];
        while (rideWaitTime[currentArrtractionIndex] < 0 || rideWaitTime[currentArrtractionIndex] > 250) 
        {
            cout << "Wait times must be between 0 and 250 minutes. Please re-enter: ";
            cin >> rideWaitTime[currentArrtractionIndex];
        }
        
        cout << "Enter another attraction (y/n): ";
        cin >> again;
        cin.ignore(100, '\n');
        cout << endl;
        currentArrtractionIndex++;
        
        
    } while (currentArrtractionIndex < MAX_RIDES && again == 'y');

    //console display
    cout << endl;
    cout << setw(30) << left << "ATTRACTIONS" << " WAIT TIME" << endl;
    cout << "----------------------------------------" << endl;
   
    //loop over the items in the array
    for (int i = 0; i < currentArrtractionIndex; i++) {
        
        cout << setw(30) << left << rideNames[i] << setw(10) << right << rideWaitTime[i] << endl;
        
        totalWaitTime += rideWaitTime[i];
        
        if (rideWaitTime[i] < rideWaitTime[indexOfShortestWaitTime]) {
            
            indexOfShortestWaitTime = i;
        }
    }

    //calculate the average
    avgWaitTime = totalWaitTime / currentArrtractionIndex;
    
    cout << "\nThe shortest wait time is for " << rideNames[indexOfShortestWaitTime]
        << " (" << rideWaitTime[indexOfShortestWaitTime] << " minutes)." << endl;

    cout << "\nAverage wait time for all attractions is " << avgWaitTime << " minutes." << endl;

    cout << "\nEnjoy your day at Disneyland, the happiest place on earth! \02" << endl;
    
   
}

