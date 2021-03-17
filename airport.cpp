#include <iostream>
#include <list>
#include <cstring>

#include "airport.h"
//#include "ascii.cpp"  // include the ascii cpp file.

using namespace std;

// ============================================================
//
// >>>>>>>>>>>>          PUBLIC FUNCTIONS          <<<<<<<<<<<<
//
// ============================================================

Airport::Airport() {}

/**
 * ==========================================================
 * These functions below are meant to handle the linked-list
 *  pointers for our Airport linked-list function.
 * 
 * Because we set the *next and *prev pointers to PRIVATE,
 *  we need to access them from a PUBLIC function.
 * 
 *      // The SET functions
 *      - setNext()  ,  void
 *      - setPrev()  ,  void
 * 
 *      // The GET functions
 *      - getNext()  ,  Airport (class)
 *      - getPrev()  ,  Airport (class)
 * ==========================================================
 */
void Airport::nextNULL() {
    // This function sets *next to equal NULL
    next = NULL;
}

void Airport::prevNULL() {
    // This function sets *prev to equal NULL
    prev = NULL;
}

void Airport::setNext(Airport* n) {
    // This function sets the next airport pointer in the linked list
    next = n;
}

void Airport::setPrev(Airport* p) {
    // This fucntion sets the previous airport pointer in the linked list
    prev = p;
}

Airport* Airport::getNext(Airport* c) {
    // This function will return what *next pointer is pointing to
    c = next;
    return c;
}

Airport* Airport::getPrev(Airport* c) {
    // This function will return what the *prev pointer is pointing to
    c = prev;
    return c;
}


/**
 * ==========================================================
 * We want to set the values for the elements inside the
 * class here.
 * 
 * Same as the pointer elements handled above, we need to
 * utilize PUBLIC functions in order to access the Airport
 * elements that have been set to PRIVATE.
 * 
 *      // The SET functions
 *      - setName()   ,  void
 *      - setCity()   ,  void
 *      - setState()  ,  void
 *      - setIATA()   ,  void
 * 
 *      // The GET functions
 *      - getName()   ,  string
 *      - getCity()   ,  string
 *      - getState()  ,  string
 *      - getIATA()   ,  string
 * ==========================================================
 */
void Airport::setName(string name) {
    airportName = name;
}

void Airport::setCity(string city) {
    airportCity = city;
}

void Airport::setState(string state) {
    airportState = state;
}

void Airport::setIATA(string iata) {
    airportIATA = iata;
    setID();
}

string Airport::getName() {
    return airportName;
}

string Airport::getCity() {
    return airportCity;
}

string Airport::getState() {
    return airportState;
}

string Airport::getIATA() {
    return airportIATA;
}

int Airport::getID() {
    return airportID;
}


// =============================================================
//
// >>>>>>>>>>>>          PRIVATE FUNCTIONS          <<<<<<<<<<<<
//
// =============================================================
void Airport::setID() {

    // Local Variables:
    int num0;
    int num1;
    int num2;

    //ascii* tempID = new ascii;

    // Class Variables
    strncpy(IATA, airportIATA.c_str(), sizeof(IATA));
    IATA[sizeof(IATA) - 1] = 0;

    num0 = IATA[0];
    num1 = IATA[1];
    num2 = IATA[2];

    // Get the ASCII value of each char [0-2]
    //num0 = *IATA[0];  // We want to check this to see if it fits within ASCII values between 0 - 127
    /*
    if(!checkASCII(num0)) {
        cout << "ERROR: you have supplied an improper ASCII value" << endl;
        //return 0;
    }
    //num1 = *IATA[1];
    if(!checkASCII(num1)) {
        cout << "ERROR: you have supplied an improper ASCII value" << endl;
        //return 0;
    }
    //num2 = *IATA[2];
    if(!checkASCII(num2)) {
        cout << "ERROR: you have supplied an improper ASCII value" << endl;
        //return 0;
    }
    */
    // We add the sum of the three values to set our Airport ID.
    airportID = num0 + num1 + num2;  
}


/**
 * This function returns true if 0 <= int <= 127 and false otherwise.
 * 
 * PARAMETERS:
 *      - num (int) , this is an arbitrary integer value.
 */
bool Airport::checkASCII(int num) {
    if(num <= 127 && num >= 0) {
        return true;
    } else {
        return false;
    }
}
