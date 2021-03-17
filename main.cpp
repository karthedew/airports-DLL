/*
*
* File:   main.cpp
* Author: Karl Schmidt
*
*/
#include <iostream>
#include <string>
#include <list>

#include "airports.cpp"

using namespace std;

int main() {

    Airports a_list;

    a_list.display();

    string name= "Portland International Airport";
    string city = "Portland";
    string state = "OR";
    string iata = "PDX";

    a_list.addHead(name, city, state, iata);
    cout << "Display full list with the first item in list:  " << endl;
    a_list.display();

    string name1= "Dallas Fort Worth International Airport";
    string city1 = "Dallas";
    string state1 = "TX";
    string iata1 = "DFW";

    a_list.addHead(name1, city1, state1, iata1);
    cout << "Display full list with the second item in list:  " << endl;
    a_list.display();

    string name2 = "Eugene Airport";
    string city2 = "Eugene";
    string state2 = "OR";
    string iata2 = "EUG";

    a_list.addTail(name2, city2, state2, iata2);
    cout << "Display full list with the third item in list:  " << endl;
    a_list.display();

    string name3 = "Los Angeles International Airport";
    string city3 = "Los Angeles";
    string state3 = "CA";
    string iata3 = "LAX";

    a_list.addTail(name3, city3, state3, iata3);
    cout << "Display full list with the fourth item in list:  " << endl;
    a_list.display();

    a_list.deleteNode(iata2);
    cout << "Display full list with the fifth item in list:  " << endl;
    a_list.display();

    Airport* newHead = a_list.getHead();
    Airport* newTail = a_list.getTail();

    cout << "This is the HEAD node IATA:   " << newHead->getIATA() << endl;
    cout << "This is the TAIL node IATA:   " << newTail->getIATA() << endl << endl;

    bool result = a_list.find(iata3);
    cout << "Is the LAX airport in the list?  " << result << endl;

    bool result1 = a_list.find(iata2);
    cout << "Is the EUG airport in the list?  " << result1 << endl << endl;

    string name4 = "Orlando International Airport";
    string city4 = "Orlando";
    string state4 = "FL";
    string iata4 = "MCO";

    string name5 = "Kansas City International Airport";
    string city5 = "Kansas City";
    string state5 = "KS";
    string iata5 = "MCI";

    Airport* orl = new Airport;
    Airport* kns = new Airport;

    orl->setName(name4);
    orl->setCity(city4);
    orl->setState(state4);
    orl->setIATA(iata4);

    kns->setName(name5);
    kns->setCity(city5);
    kns->setState(state5);
    kns->setIATA(iata5);

    a_list.AddBefore(orl, iata3);
    a_list.AddAfter(kns,iata);
    a_list.display();

    return 0;
}
