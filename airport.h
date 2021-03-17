#ifndef AIRPORT_H_
#define AIRPORT_H_

#include <iostream>
#include <string>

class Airport {
    private:

        std::string airportName;
        std::string airportCity;
        std::string airportState;
        std::string airportIATA;
        
        // This is used to create the ID.
        // Because the IATA is unique, the Airport ID should also be unique.
        char IATA[1024];
        int airportID;                      // This is the "Key"

        Airport* next;
        Airport* prev;

        // === PRIVATE functions ===
        void setID();                       // Sets the ID values based on IATA ASCII.
        bool checkASCII(int ID);            // Checks if ASCII value is valid.


    public:

        // Constructor
        Airport();

        void setName(std::string name);     // Sets the Airport name.
        void setCity(std::string city);     // Sets the Airport city location.
        void setState(std::string state);   // Sets the Airport state location.
        void setIATA(std::string iata);     // Sets the Airport IATA ASCII.
        
        void setNext(Airport* n);
        void setPrev(Airport* p);

        void nextNULL();
        void prevNULL();
        
        Airport* getNext(Airport* c);
        Airport* getPrev(Airport* c);

        std::string getName();
        std::string getCity();
        std::string getState();
        std::string getIATA();
        int getID();
};

#endif
