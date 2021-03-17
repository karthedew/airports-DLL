#ifndef AIRPORTS_H_
#define AIRPORTS_H_

#include <iostream>
#include <string>

#include "airport.h"

class Airports {
    
    private:

        Airport* head;  //Airport* head = new Airport;
        Airport* tail;  //Airport* tail = new Airport;

        void setHead();
        void setTail();
        bool isEmpty();        // This function will return "TRUE" if list is empty and "FALSE" if it is not

    public:

        void addHead(std::string name, std::string city, std::string state, std::string iata);      // This is the "         PushFront()" function
        void addTail(std::string name, std::string city, std::string state, std::string iata);      // This is the "          PushBack()" function
        void deleteHead();                                                                          // This is the "          PopFront()" function
        void deleteTail();                                                                          // This is the "           PopBack()" function
        bool empty();                                                                               // This is the "             Empty()" function
        void deleteNode(std::string key);   // This is the "          Erase(Key)" function
        void display();                     // This function displays the whole linked list.
        Airport* getHead();                 // This is the "  Airport TopFront()" function
        Airport* getTail();                 // This is the "   Airport TopBack()" function
        bool find(std::string key);         // This is the "           Find(Key)" function
        
        /* NEED TO FINISH */
        void AddBefore(Airport* a, std::string key);                // This is the "AddBefore(Node, Key)" function
        void AddAfter(Airport* a, std::string key);                 // This is the " AddAfter(Node, Key)" function
        /* ------------------------------------------------------------------------------------------------------------------------------------ */    
        

        /*
        |-----------------------------------------|
        |  Doubly-Linked List  | no-tail  | tail  |
        |-----------------------------------------|
        |       PushFront(Key) | O(1)     |       |
        |           TopFront() | O(1)     |       |
        |           PopFront() | O(1)     |       |
        |        PushBack(Key) | O(n)     | O(1)  |
        |            TopBack() | O(n)     | O(1)  |
        |            PopBack() | O(1)     |       |
        |            Find(Key) | O(n)     |       |
        |           Erase(Key) | O(n)     |       |
        |              Empty() | O(1)     |       |
        | AddBefore(Node, Key) | O(1)     |       |
        |  AddAfter(Node, Key) | O(1)     |       |
        |-----------------------------------------|

        |-----------------------------------------|
        |  Singly-Linked List  | no-tail  | tail  |
        |-----------------------------------------|
        |       PushFront(Key) | O(1)     |       |
        |           TopFront() | O(1)     |       |
        |           PopFront() | O(1)     |       |
        |        PushBack(Key) | O(n)     | O(1)  |
        |            TopBack() | O(n)     | O(1)  |
        |            PopBack() | O(n)     |       |
        |            Find(Key) | O(n)     |       |
        |           Erase(Key) | O(n)     |       |
        |              Empty() | O(1)     |       |
        | AddBefore(Node, Key) | O(n)     |       |
        |  AddAfter(Node, Key) | O(1)     |       |
        |-----------------------------------------|

        Operations (List API):

        PushFront(Key)              add to front
        Key TopFront()              return front item
        PopFront()                  remove front item
        PushBack(Key)               add to back
        Key TopBack()               return back item
        PopBack()                   remove back item
        Boolean Find(Key)           is key in list?
        Erase(Key)                  remove key from list
        Boolean Empty()             empty list?
        AddBefore(Node, Key)        adds key before node
        AddAfter(Node, Key)         adds key after node

        */

};

#endif
