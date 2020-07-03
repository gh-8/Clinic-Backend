/*
 * Patient.cpp
 *
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified.
 */

#include <string>
#include <iostream>
#include "Patient.h"
using namespace std;

// Parameterized constructor
Patient::Patient(string aCareCard)
{
    if ( aCareCard.size()==10){//10 digits
        name = "To be entered";
        address = "To be entered";
        phone = "To be entered";
        email = "To be entered";
        careCard = aCareCard;
    }
    else{
        name = "To be entered";
        address = "To be entered";
        phone = "To be entered";
        email = "To be entered";
        careCard = "0000000000";
    }
    
}
// Default constructor
Patient::Patient()
{
        name = "To be entered";
        address = "To be entered";
        phone = "To be entered";
        email = "To be entered";
        careCard = "0000000000";
}
// Getters
// Description: Returns patient's name.
string Patient::getName() const
{
    return name;
}
// Description: Returns patient's address.
string Patient::getAddress() const
{
    return address;
}
// Description: Returns patient's phone number.
string Patient::getPhone() const
{
    return phone;
}
// Description: Returns patient's email.
string Patient::getEmail() const
{
    return email;
}
// Description: Returns patient's care card number.
string Patient::getCareCard() const
{
    return careCard;
}
//Setters
// Description: Sets the patient's name.
void Patient::setName(const string aName)
{
    if (aName != "")
    {
        name=aName;
    }
}

// Description: Sets the patient's address.
void Patient::setAddress(const string anAddress)
{
    if (anAddress != "")
    {
        address=anAddress;
    }
}

// Description: Sets the patient's phone number.
void Patient::setPhone(const string aPhone)
{
    if (aPhone != "")
    {
        phone=aPhone;
    }
}

// Description: Sets the patient's email.
void Patient::setEmail(const string anEmail)
{
    if (anEmail != "")
    {
        email=anEmail;
    }
}
// Overloaded Operators
// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if both Patient objects have the same care card number.
bool Patient::operator==(const Patient & rhs){
    return (careCard == rhs.careCard);
}

// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is > the care card number of "rhs" Patient object.
bool Patient::operator>(const Patient & rhs){
    return (careCard > rhs.careCard);
}

// Description: Prints the content of "this" patient.
void Patient::printPatient( ){
    
    cout<< careCard <<", "<< "Patient: "<< name <<", "<< address <<", "<< phone <<", "<< email << endl;
}
/*
* Output format for printPatient():
* careCard, Patient: name, address, phone, email
*
* Example:
* 1234567890, Patient: To be entered, To be entered, To be entered, To be entered
* or
* 1234567890, Patient: John Doe, 123 Avenue Vancouver, 778-123-1234, John@addr.ca
*/
