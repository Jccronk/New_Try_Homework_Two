//
// Created by Jake Cronk on 2/23/24.
//

#include "Student.h"
#include "deltext1.h"

/**
 * @brief Default constructor for the Student class.
 * Initializes a Student object with empty data.
 */
Student::Student() {
    clear();
}

/**
 * @brief Clears all data members of the Student object.
 */
void Student::clear() {
    identifier[0] = 0;
    firstName[0] = 0;
    lastName[0] = 0;
    address[0] = 0;
    enrollDate[0] = 0;
    creditHours[0] = 0;
}

/**
 * @brief Packs Student data into a FixedTextBuffer.
 * @param Buffer The FixedTextBuffer to pack into.
 * @return 0 on success, -1 on failure.
 */
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

/**
 * @brief Unpacks data from a FixedTextBuffer into the Student object.
 * @param Buffer The FixedTextBuffer to unpack.
 * @return 0 on success, -1 on failure.
 */
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

/**
 * @brief Initializes a FixedTextBuffer to be used for Student objects.
 * @param Buffer The FixedTextBuffer to initialize.
 * @return 0 on success, -1 on failure.
 */
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


/**
 * @brief Packs Student data into a LengthTextBuffer.
 * @param Buffer The LengthTextBuffer to pack into.
 * @return 0 on success, -1 on failure.
 */
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

/**
 * @brief Unpacks data from a LengthTextBuffer into the Student object.
 * @param Buffer The LengthTextBuffer to unpack.
 * @return 0 on success, -1 on failure.
 */
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


/**
 * @brief Initializes a LengthTextBuffer to be used for Student objects.
 * @param Buffer The LengthTextBuffer to initialize.
 * @return 0 on success, -1 on failure.
 */
int Student::InitBuffer(LengthTextBuffer &) {
    return TRUE;
}

/**
 * @brief Unpacks data from a DelimTextBuffer into the Student object.
 * @param Buffer The DelimTextBuffer to unpack.
 * @return 0 on success, -1 on failure.
 */
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

/**
 * @brief Packs Student data into a DelimTextBuffer.
 * @param Buffer The DelimTextBuffer to pack into.
 * @return 0 on success, -1 on failure.
 */
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

/**
 * @brief Initializes a DelimTextBuffer to be used for Student objects.
 * @param Buffer The DelimTextBuffer to initialize.
 * @return 0 on success, -1 on failure.
 */
int Student::InitBuffer(DelimTextBuffer &) {
    return TRUE;
}

/**
 * @brief Prints the student information to the specified output stream.
 * @param stream The output stream to print to.
 */
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


