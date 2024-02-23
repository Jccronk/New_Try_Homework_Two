//
// Created by Jake Cronk on 2/23/24.
//

#include "Student.h"
#include "deltext1.h"


Student::Student() {
    clear();
}

void Student::clear() {
    identifier[0] = 0;
    firstName[0] = 0;
    lastName[0] = 0;
    address[0] = 0;
    enrollDate[0] = 0;
    creditHours[0] = 0;
}

int Student::Pack(FixedTextBuffer & Buffer) const {
    int result;
    Buffer . Clear ();
    result = Buffer . Pack (lastName);
    result = result && Buffer . Pack (firstName);
    result = result && Buffer . Pack (address);
    result = result && Buffer . Pack (identifier);
    result = result && Buffer . Pack (enrollDate);
    result = result && Buffer . Pack (creditHours);
    return result;
}

int Student::Unpack(FixedTextBuffer & Buffer) {
    clear ();
    int result;
    result = Buffer . Unpack (lastName);
    result = result && Buffer . Unpack (firstName);
    result = result && Buffer . Unpack (address);
    result = result && Buffer . Unpack (identifier);
    result = result && Buffer . Unpack (enrollDate);
    result = result && Buffer . Unpack (creditHours);
    return result;
}

int Student::InitBuffer(FixedTextBuffer & Buffer) {
    // initialize a FixedTextBuffer to be used for Persons
    {
        int result;
        result = Buffer . AddField (10); // LastName [11];
        result = result && Buffer . AddField (10); // FirstName [11];
        result = result && Buffer . AddField (15); // Address [16];
        result = result && Buffer . AddField (15); // identifier [16];
        result = result && Buffer . AddField (11);  // enrollDate [10];
        result = result && Buffer . AddField (5); // creditHours [4];
        return result;
    }
}



int Student::Pack(LengthTextBuffer & Buffer) const {
    int result;
    Buffer . Clear ();
    result = Buffer . Pack (lastName);
    result = result && Buffer . Pack (firstName);
    result = result && Buffer . Pack (address);
    result = result && Buffer . Pack (identifier);
    result = result && Buffer . Pack (enrollDate);
    result = result && Buffer . Pack (creditHours);
    return result;
}

int Student::Unpack(LengthTextBuffer & Buffer) {
    clear ();
    int result;
    result = Buffer . Unpack (lastName);
    result = result && Buffer . Unpack (firstName);
    result = result && Buffer . Unpack (address);
    result = result && Buffer . Unpack (identifier);
    result = result && Buffer . Unpack (enrollDate);
    result = result && Buffer . Unpack (creditHours);
    return result;
}



int Student::InitBuffer(LengthTextBuffer &) {
    return TRUE;
}

int Student::Unpack(DelimTextBuffer & Buffer) {
    clear ();
    int result;
    result = Buffer . Unpack (lastName);
    result = result && Buffer . Unpack (firstName);
    result = result && Buffer . Unpack (address);
    result = result && Buffer . Unpack (identifier);
    result = result && Buffer . Unpack (enrollDate);
    result = result && Buffer . Unpack (creditHours);
    return result;
}

int Student::Pack(DelimTextBuffer & Buffer) const {
    int result;
    Buffer . Clear ();
    result = Buffer . Pack (lastName);
    result = result && Buffer . Pack (firstName);
    result = result && Buffer . Pack (address);
    result = result && Buffer . Pack (identifier);
    result = result && Buffer . Pack (enrollDate);
    result = result && Buffer . Pack (creditHours);
    return result;
}

int Student::InitBuffer(DelimTextBuffer &) {
    return TRUE;
}

void Student::Print(ostream & stream)
{
    stream << "Student:"
           << "\t Last Name '"<<lastName<<"'\n"
           << "\tFirst Name '"<<firstName<<"'\n"
           << "\t   Address '"<<address<<"'\n"
           << "\t      Student ID '"<<identifier<<"'\n"
           << "\t     Enroll Date '"<<enrollDate<<"'\n"
           << "\t  Completed Credit Hours '"<<creditHours<<"'\n" <<flush;
}


