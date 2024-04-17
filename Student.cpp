//
// Created by Jake Cronk on 2/23/24.
//

#include "Student.h"
#include "deltext1.h"
#include <sstream>
#include <cstring> // For std::strncpy
#include <cstring> // For strcmp

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

// Overload the output operator << for the Student class
std::ostream& operator<<(std::ostream& os, const Student& student) {
    // Output the student information separated by semicolons
    os << student.identifier << "; "
       << student.firstName << "; "
       << student.lastName << "; "
       << student.address << "; "
       << student.enrollDate << ";"
       << student.creditHours;
    return os;
}

// Helper function to trim whitespace from the start and end of a string
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

// Overload the input operator >> for the Student class
std::istream& operator>>(std::istream& is, Student& student) {
    std::string line;
    if (std::getline(is, line)) {
        std::istringstream iss(line);
        std::string token;

        // Temporary buffer to hold the string data before copying
        char tempBuffer[16]; // Adjust the size based on the largest char array among the fields

        // Identifier
        std::getline(iss, token, ';');
        std::strncpy(student.identifier, trim(token).c_str(), sizeof(student.identifier) - 1);
        student.identifier[sizeof(student.identifier) - 1] = '\0'; // Ensuring null-termination

        // FirstName
        std::getline(iss, token, ';');
        std::strncpy(student.firstName, trim(token).c_str(), sizeof(student.firstName) - 1);
        student.firstName[sizeof(student.firstName) - 1] = '\0'; // Ensuring null-termination

        // LastName
        std::getline(iss, token, ';');
        std::strncpy(student.lastName, trim(token).c_str(), sizeof(student.lastName) - 1);
        student.lastName[sizeof(student.lastName) - 1] = '\0'; // Ensuring null-termination

        // Address
        std::getline(iss, token, ';');
        std::strncpy(student.address, trim(token).c_str(), sizeof(student.address) - 1);
        student.address[sizeof(student.address) - 1] = '\0'; // Ensuring null-termination

        // EnrollDate
        std::getline(iss, token, ';');
        std::strncpy(student.enrollDate, trim(token).c_str(), sizeof(student.enrollDate) - 1);
        student.enrollDate[sizeof(student.enrollDate) - 1] = '\0'; // Ensuring null-termination

        // CreditHours
        std::getline(iss, token, ';');
        std::strncpy(student.creditHours, trim(token).c_str(), sizeof(student.creditHours) - 1);
        student.creditHours[sizeof(student.creditHours) - 1] = '\0'; // Ensuring null-termination
    }
    return is;
}

// Overload the < operator to compare two Student objects by their identifier
bool operator<(const Student& lhs, const Student& rhs) {
    return std::strcmp(lhs.identifier, rhs.identifier) < 0;
}

// Overload the == operator to compare two Student objects by their identifier
bool operator==(const Student& lhs, const Student& rhs) {
    return std::strcmp(lhs.identifier, rhs.identifier) == 0;
}

// Overload the > operator to compare two Student objects by their identifier
bool operator>(const Student& lhs, const Student& rhs) {
    return std::strcmp(lhs.identifier, rhs.identifier) > 0;
}