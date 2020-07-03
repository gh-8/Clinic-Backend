/*
 * List.h
 *
 * Class Description: A value-oriented List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - It is sorted by ascending sort order of its elements.
 *                   - Its data structure is expandable: when full, it expands to accommodate
 *                     new insertion. This is done unbeknown to the client code.
 */
#pragma once
#include <string>
#include "Patient.h"
using namespace std;

class List  {

private:
	static const int MAX_ELEMENTS = 3;
    int maxsize[10];
    Patient **elements;
    int colindex;
	int elementCount[10];                  // Current element count in element array
    int getIndex(const Patient& newElement);
    
public:
	// Default constructor
	List();
    
    //Destructor
    ~List();
    
    //Copy constructor
    List(const List &copyElement);

    
// *** Start of Public Interface ***
// Note: Public Interface must not be modified.

	// Description: Returns the total element count currently stored in List.
	int  getElementCount() const;
    
    // Description: Insert an element.
    //              When "this" List is full, its data structure is expanded to accommodate
    //              a new element. This is done unbeknown to the client code.
    //              If the insertion is successful, true is returned otherwise, false is returned.
    // Precondition: newElement must not already be in data collection.
    // Postcondition: newElement inserted and the appropriate elementCount has been incremented.
    bool insert(const Patient& newElement);

	// Description: Remove an element. 
	// Postcondition: toBeRemoved is removed and elementCount has been decremented.	
	bool remove( const Patient& toBeRemoved );
	
	// Description: Remove all elements.
	void removeAll();
   
	// Description: Search for target element.
	//              Returns a pointer to the element if found,
	//              otherwise, returns NULL.
	Patient* search(const Patient& target);
   
    // Description: Prints all n elements stored in List in sort order and does so in O(n).
	void printList( );

// *** End of Public Interface ***

    
};
