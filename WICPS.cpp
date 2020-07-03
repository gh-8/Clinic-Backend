/* Assignments
 * WICPS.cpp
 *
 * Class Description: clinic patient system.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified.
 */


#include <iostream>
#include <string>

#include "Patient.h"
#include "List.h"

using namespace std;

// tests
void test();
void MenuInterface();

int main(int argc, const char * argv[]) {
    cout << "Test:  " << endl;
    test();
    return 0;
}

void test()
{
    int myinputformenu = -1;
    string inputchoice;
    string inputname;
    string inputaddress;
    string inputcarecard;
    string inputphone;
    string inputemail;
    
    List list2;
    
    while (myinputformenu != 8)
    {
        MenuInterface();
        getline(cin, inputchoice);
        myinputformenu = atoi(inputchoice.c_str());
        
        switch (myinputformenu)
        {
            case 1:
                cout << "\nEnter the carecard: ";
                getline(cin, inputcarecard);
                if (list2.insert(inputcarecard))
                    cout << "Patient inserted" << endl;
                break;
            case 2:
                cout << "\nEnter the carecard: ";
                getline(cin, inputcarecard);
                if (list2.remove(inputcarecard))
                    cout << "Patient removed from the list." << endl;
                else
                    cout << "Patient not found in list, please enter a patient the does exist in the list." << endl;
                break;
            case 3:
                cout << "List contains " << list2.getElementCount() << " elements." << endl;
                break;
            case 4:
                cout << "\nEnter the carecard: ";
                getline(cin, inputcarecard);
                
                if (list2.search(inputcarecard) != NULL)
                    cout << "element exists" << endl;
                else
                    cout << "element doesn't exist" << endl;
                break;
            case 5:
                list2.printList();
                break;

            case 6:
                list2.removeAll();
                break;
            case 7:
                cout << "\nEnter the carecard: ";
                getline(cin, inputcarecard);
                Patient *m= new Patient;
                m=list2.search(inputcarecard);
                
                cout << "\nEnter the name: ";
                getline(cin, inputname);
                m->setName(inputname);
                
                cout << "\nEnter the address: ";
                getline(cin, inputaddress);
                m->setAddress(inputaddress);
                
                cout << "\nEnter the phone: ";
                getline(cin, inputphone);
                m->setPhone(inputphone);
                
                cout << "\nEnter the email: ";
                getline(cin, inputemail);
                m->setEmail(inputemail);
                
                break;
        }
    }
}

void MenuInterface()
{
    cout << "************************************************************\n"
    << "* Please select an option:                                      *\n"
    << "* 1. Add a patient           5. Print all patients              *\n"
    << "* 2. Remove a patient        6. Remove all elements             *\n"
    << "* 3. Show the size of list   7. Modify a patients information   *\n"
    << "* 4. Find an element         8. Quit                            *\n"
    << "******************************************************\n" << endl;
    cout << "Enter a number corresponding to what you'd like to do: ";
}
