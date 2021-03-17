#include <iostream>
#include <string>

#include "airports.h"
#include "airport.cpp"


using namespace std;



// ============================================================
//
// >>>>>>>>>>>>          PUBLIC FUNCTIONS          <<<<<<<<<<<<
//
// ============================================================


/**
 * 
 * 
 */
void Airports::AddBefore(Airport* a, string key) {
    Airport* current = new Airport;
    Airport* prevNode = new Airport;

    if(head->getIATA()==key) {
        current = head;
        current->setPrev(a);
        a->setNext(current);
        a->prevNULL();       
        head = a;            
        return;
    } else {
        current = head;
        while(current) {

            if(current->getIATA() == key) {

                // Set the previous Airport to the new Airport and the current Airport to the new Airport
                prevNode = current->getPrev(current);
                prevNode->setNext(a);
                current->setPrev(a);

                // Set the *next and *prev pointers of the Airport parameter
                a->setNext(current);
                a->setPrev(prevNode);
                return;
            } else if(current->getNext(current) == NULL) {
                cout << "The Airport " << key << " does not exist in your list of Airports." << endl;
                return;
            } else {
                current = current->getNext(current);
            }
        }
    }
}


/**
 * 
 * 
 */
void Airports::AddAfter(Airport* a, string key) {
    Airport* current = new Airport;
    Airport* nextNode = new Airport;

     if(tail->getIATA()==key) {
        current = tail;
        current->setNext(a);
        a->setPrev(current);
        a->nextNULL();       // This sets the previous of Airport to NULL.
        tail = a;            // This sets the last tail node to the new tail node.
        return;
    } else {
        current = head;
        while(current) {

            if(current->getIATA() == key) {

                // Set the previous Airport to the new Airport and the current Airport to the new Airport
                nextNode = current->getNext(current);
                nextNode->setPrev(a);
                current->setNext(a);

                // Set the *next and *prev pointers of the Airport parameter
                a->setNext(nextNode);
                a->setPrev(current);
                return;
            } else if(current->getNext(current) == NULL) {
                cout << "The Airport " << key << " does not exist in your list of Airports." << endl;
                return;
            } else {
                current = current->getNext(current);
            }
        }
    }
}


/**
 * 
 * 
 */
bool Airports::find(string key) {
    // This returnes the head node.
    Airport* current = new Airport;
    current = head;

    while(current) {
        if(current->getIATA() == key) {
            // When KEY is in list, delete the current node and return TRUE
            return true;
        } else if(current->getNext(current) == NULL) {
            // When KEY is not in list, delete the current node and return FALSE
            return false;
        } else {
            // If KEY has not been found yet, get the next node.
            current = current->getNext(current);
        }
    }
    return false;
}


/**
 * 
 * 
 */
Airport* Airports::getHead() {
    // This returnes the head node.
    return head;
}


/**
 * 
 * 
 */
Airport* Airports::getTail() {
    // This returnes the head node.
    return tail;
}


/**
 * 
 */
bool Airports::empty() {

    if (head == NULL || head == 0) {
        return true;
    } else {
        return false;
    }
}


/**
 * This function deletes the node with the same IATA number as it's given.
 * 
 * Parameters:
 *      -  KEY (string) , this is meant to be the IATA of the airport
 */
void Airports::deleteNode(string key) {

    if (empty()) {
        return;

    // } else if {} // may need to add in statement to see if beginning of node or end of node
    } else {
        Airport* current = new Airport;

       if (head->getIATA()==key) {
            // Chop off the head node.
            current = head;
            head = current->getNext(current);
            head->prevNULL();
            delete current;
            current = NULL;

            return;

       } else if (tail->getIATA()==key) {
            // Chop off the tail node.
            current = tail;
            tail = current->getPrev(current);
            tail->nextNULL();
            delete current;
            current = NULL;            
            return;

       } else {
            // Set the current to the head.
            current = head;

            while(current) {

                if (current->getIATA()==key) {
                    // We want to get the adjacent nodes of the current node to be deleted.
                    Airport* nextFoo = new Airport;
                    Airport* prevFoo = new Airport;
                    nextFoo = current->getNext(current);  // stores the value of the next node
                    prevFoo = current->getPrev(current);  // stores the value of the previous node

                    // Want to set the next pointer of the previous node
                    prevFoo->setNext(nextFoo); // faulted here. "segmentation fault"

                    // Want to set the previous pointer of the next node
                    nextFoo->setPrev(prevFoo);

                    delete current;
                    current = NULL;

                } else if (current->getNext(current) == NULL) {

                    cout << "This Airport does not exist." << endl;
                    delete current;
                    current = NULL;

                } else {
                    current = current->getNext(current);
                }
            }
       }
    }
}


/**
 * This function adds a new Airport node to the end of the 
 * linked list data structure.
 * 
 * PARAMETERS:
 *      - NAME (string) , this is the name of the airport
 *      - CITY (string) , this is the city of the airport
 *      - STATE (string) , this is the state of the airport
 *      - IATA (string) , this is the airppot identifier
 */
void Airports::addTail(string name, string city, string state, string iata) {

    Airport* current = new Airport;

    current->setName(name);
    current->setCity(city);
    current->setState(state);
    current->setIATA(iata);

    if (tail==NULL) {
        /* This conditional statement should only be accessed when
           no list exists.

           When the list is created, we set the head and tail to
           the same node. Next we assign the next and previous
           to null since there are no other nodes.
        */
        head = current;  // set head to the only current node
        tail = current;  // set tail to the only current node
        current->nextNULL();
        current->prevNULL();
    } else {
        /* We do not need to set the prev* because it is initially 
           set to NULL in the Airport node. */
        current->setPrev(tail);    // This sets the new node to the previously set tail node.
        current->nextNULL();       // This sets the previous of Airport to NULL.
        tail->setNext(current);    // This sets the *prev of the old tail node to the new node.
        tail = current;            // This sets the last tail node to the new tail node.
    }

    // Set the parameter values to the new Airport
}

/**
 * This function adds a new Airport node to the beginning of the
 * linked list data strcucture.
 * 
 * PARAMETERS:
 *      - NAME (string) , this is the name of the airport
 *      - CITY (string) , this is the city of the airport
 *      - STATE (string) , this is the state of the airport
 *      - IATA (string) , this is the airppot identifier
 */
void Airports::addHead(string name, string city, string state, string iata) {
    
    Airport* current = new Airport;
    
    // We may need to make sure that these values are pass-by-reference or pass-by-value
    current->setName(name);
    current->setCity(city);
    current->setState(state);
    current->setIATA(iata);

    if(head==NULL) {
        /* This conditional statement should only be accessed when
           no list exists.

           When the list is created, we set the head and tail to
           the same node. Next we assign the next and previous
           to null since there are no other nodes.
        */
        head = current;  // set head to the only current node
        tail = current;  // set tail to the only current node
        current->nextNULL();
        current->prevNULL();
    }
    else {
        /* We do not need to set the prev* because it is initially 
           set to NULL in the Airport node. */
        current->setNext(head);    // This sets the new node to the previously set head node.
        current->prevNULL();       // This sets the previous of Airport to NULL.
        head->setPrev(current);    // This sets the *prev of the old head node to the new node.
        head = current;            // This sets the last head node to the new head node.
    }

}


/**
 * This function deletes the node at the head of the linked-list.
 * 
 *  * PARAMETERS:
 *      None
 * 
 * DESCRIPTION:
 *      This function checks to see if the list is empty. If empty,
 *      it prints a message. If the list is not empty, it deletes
 *      the node at the head of the linked-list then deallocates
 *      the temporary Airport pointer used to reassign the head
 *      node to the next.
 */
void Airports::deleteHead() {
    // This function deletes the head node.

    if(head==NULL) {
        cout << "The list is empty" << endl;
    } else {
        Airport *current = head;
        head = current->getNext(current);
        delete current;
        current = NULL;
        //free(temp);
    }
}


/**
 * This function deletes the node at the tail of the linked-list.
 * 
 *  * PARAMETERS:
 *      None
 * 
 * DESCRIPTION:
 *      This function checks to see if the list is empty. If empty,
 *      it prints a message. If the list is not empty, it deletes
 *      the node at the tail of the linked-list then deallocates
 *      the temporary Airport pointer used to reassign the tail
 *      node to the next.
 */
void Airports::deleteTail() {
    // This function deletes the head node.

    if(tail==NULL) {
        cout << "The list is empty" << endl;
    } else {
        Airport *current = tail;
        tail = current->getPrev(current);
        delete current;
        current = NULL;
        //free(temp);
    }
}


/**
 * This function currently displays (prints out) the elements of
 * the current Airports in the linked-list.
 * 
 * PARAMETERS:
 *      None
 * 
 * DESCRIPTION:
 *      This function 
 */
void Airports::display() {
    Airport* current = new Airport;
    current = head;

    if(!current) {
        cout << "This list is empty" << endl;
    } else {
        // Loop through and print out linked list
        while(current != NULL) {

            cout << endl;

            cout << " NAME: \t" << current->getName() << endl;
            cout << " CITY: \t" << current->getCity() << endl;
            cout << "STATE: \t" << current->getState() << endl;
            cout << " IATA: \t" << current->getIATA() << endl;
            cout << "   ID: \t" << current->getID() << endl;

            cout << endl;

            current = current->getNext(current);

        }
    }
    // deallocates the temp object.
    free(current);
}


// =============================================================
//
// >>>>>>>>>>>>          PRIVATE FUNCTIONS          <<<<<<<<<<<<
//
// =============================================================

/**
 * This function returns a boolean if the linked-list
 * is populated or empty
 * 
 * PARAMETERS:
 *      - Airport* pnt ; this is the object Airport
 * 
 * DESCRIPTION:
 *      This function will return TRUE if the *next pointer is empty
 *      and FALSE if it is populated.
 */
bool isEmpty(Airport* pnt) {

    if(pnt->getNext(pnt) == 0) {
        return true;
    } else {
        return false;
    }

}

void Airports::setHead() {
    // This function sets the head node value.
}

void Airports::setTail() {
    // This function sets the head node value.
}
