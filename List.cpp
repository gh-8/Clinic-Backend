/*
 * List.cpp ass2
 *
 *
 * Class Description: A value-oriented List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - It is sorted by ascending sort order of its elements.
 *                   - Its data structure is expandable: when full, it expands to accomodate new clients
 *
 */
#include <string>
#include <iostream>
#include <algorithm>    // std::min_element, std::max_element
#include "List.h"
using namespace std;

List::List(const List &copyElement){
    int maxcop = elementCount[0];
    for (int i = 1; i < 10; i++) {
        if (maxcop < elementCount[i]) {
            maxcop = elementCount[i];
        }
    }
    Patient **elementstoCopy;
    elementstoCopy = new Patient*[10];
    for(int i=0; i<10 ;i++)
    {
        elementstoCopy[i]=new Patient[maxcop+2];
    }
    for( int i = 0; i < 10; i++)
    {
        for( int j = 0; j <elementCount[i]; j++)
        {
            elementstoCopy[i][j]= copyElement.elements[i][j];
            
        }
    }
}

// Default constructor
List::List(){
    colindex=0;
    for(int i = 0; i < 10; i++)
    {
        elementCount[i]=0;                  // Current element count in element array
        maxsize[i]=10;
    }
    elements = new Patient*[10];
    for(int i=0; i<10 ;i++)
    {
        elements[i]=new Patient[maxsize[i]];
    }
}

List::~List(){
for(int i = 0; i < 10; i++) {
    delete [] elements[i];
}
delete [] elements;
}

// Description: Returns the total element count currently stored in List.
int  List::getElementCount() const{
    int allElements=0;
    for(int i=0; i<10 ;i++)
    {
        allElements=elementCount[i]+allElements;
    }
    return allElements;
}

// Description: Insert an element.
//              When "this" List is full, its data structure is expanded to accommodate
//              a new element. This is done unbeknown to the client code.
//              If the insertion is successful, true is returned otherwise, false is returned.
// Precondition: newElement must not already be in data collection.
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.
bool List::insert(const Patient& newElement){
    colindex=getIndex(newElement);
    bool inserted = true;
    
    // search if element already exists

            if (search(newElement) != NULL)
            {
                inserted = false;
                cout<<"Patient already exists. Please enter a different patient."<<endl;
                return inserted;
            }
    
    int maxins = elementCount[0];
    for (int i = 1; i < 10; i++) {
        if (maxins < elementCount[i]) {
            maxins = elementCount[i];
        }
    }
    //insert element
    if(inserted == true)
    {
       
        
        if(elementCount[colindex] >= (11))
        {
            Patient **oldElements=elements;
            elements = new Patient*[10];
            for(int i=0; i<10 ;i++)
            {
                elements[i]=new Patient[maxins*2];
            }
            for( int i = 0; i < 10; i++)
            {
                for( int j = 0; j <elementCount[i]; j++)
                {
                    elements[i][j]= oldElements[i][j];
                    
                }
            }
            delete[] oldElements;

        
            //insert the element
            elements[colindex][(elementCount[colindex])] = newElement;
            elementCount[colindex]++;
            
            //sorting the array
            Patient temp[MAX_ELEMENTS];
            for(int i=0;i<=elementCount[colindex];i++)
            {
                for(int j=0;j<(elementCount[colindex]-1)-i;j++)
                {
                    if(elements[colindex][j]>elements[colindex][j+1])
                    {
                        temp[1]=elements[colindex][j];
                        elements[colindex][j]=elements[colindex][j+1];
                        elements[colindex][j+1]=temp[1];
                    }
                }
            }
            return true;
            }
        }
        else
        {
            //insert the element
            elements[colindex][(elementCount[colindex])] = newElement;
            elementCount[colindex]++;
                //sorting the array
                Patient temp[MAX_ELEMENTS];
                for(int i=0;i<=elementCount[colindex];i++)
                {
                    for(int j=0;j<(elementCount[colindex]-1)-i;j++)
                    {
                        if(elements[colindex][j]>elements[colindex][j+1])
                        {
                            temp[1]=elements[colindex][j];
                            elements[colindex][j]=elements[colindex][j+1];
                            elements[colindex][j+1]=temp[1];
                        }
                    }
                }

        }
        return inserted;
}

// Description: Remove an element.
// Postcondition: toBeRemoved is removed and elementCount has been decremented.
bool List::remove( const Patient& toBeRemoved ){
    if (getElementCount() == 0)
    {
        cout << "List is already empty." << endl;
        return false;
    }
    else{
        int ii =0;
        while ( ii < elementCount[colindex]){
            if(elements[colindex][ii].operator==(toBeRemoved))
            {
                while(ii<(elementCount[colindex]-1)){
                    elements[colindex][ii]= elements[colindex][ii+1];
                    ii++;
                }
                cout << "The patient with carecard number: "<<toBeRemoved.getCareCard()<<" was removed" << endl;
                elementCount[colindex]--;
                return true;	
            }
            ii++;
        }
        cout << "The patient with carecard number: "<< toBeRemoved.getCareCard() << " was not found" << endl;
        return false;
    }
}

// Description: Remove all elements.
void List::removeAll(){
    
    if (getElementCount() == 0)
    {
        cout << "List is already empty." << endl;
    }
    else
    {
        for(int i = 0; i < 10; i++)
        {
            elementCount[i]=0;
        }
        cout << "All elements have been removed." << endl;
    }
    
}

// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Patient* List::search(const Patient& target){
    colindex=getIndex(target);

    for( int i = 0; i < 10; i++)
    {
        if( (elements[colindex][i]) == target)
        {
            return &(elements[colindex][i]);
            break;
        }
    }
    return NULL;
}

// Description: Prints all n elements stored in List in sort order and does so in O(n).
void List::printList( ){

    if (getElementCount()==0)
    {
        cout << "There are 0 patients in the list" << endl;
    }
    
    else
    {
    for( int i = 0; i < 10; i++)
        {
            for( int j = 0; j <elementCount[i]; j++)
            {
                cout<< elements[i][j].getCareCard() <<", "<< "Patient: "<< elements[i][j].getName() <<", "<< elements[i][j].getAddress() <<", "<< elements[i][j].getPhone() <<", "<< elements[i][j].getEmail() << endl;
        
            }
        }
    }
}

// Private Utility Method
// Description: Computes an array index from the first digit of the CareCard number.
int List::getIndex(const Patient& newElement) {
    
    string mystring= newElement.getCareCard();
    int myinteger = static_cast<int>(mystring[0]);
    myinteger=myinteger-48;
    return myinteger;
    
} // end getIndex

