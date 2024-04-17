//
// Created by Jake Cronk on 2/23/24.
//

#ifndef ASSIGNMENT2_STUDENT_H
#define ASSIGNMENT2_STUDENT_H

#include "fixtext1.h"
#include "lentext1.h"
#include "deltext1.h"


/**
 * @brief Represents a student with basic information.
 *
 * This class provides a simple representation of a student
 * including their identifier, name, address, enrollment date,
 * and credit hours.
 */
class Student {


public:
    /**
     * @brief Default constructor.
     */
    Student();

    char identifier[16]{};
    char firstName[11]{};
    char lastName[11]{};
    char address[16]{};
    char enrollDate[10]{};
    char creditHours[4]{};

    /**
     * @brief Clears all data members of the student.
     */
    void clear();

    /**
     * @brief Initializes a FixedTextBuffer with student data.
     * @param buffer The FixedTextBuffer to initialize.
     * @return 0 on success, -1 on failure.
     */
    static int InitBuffer(FixedTextBuffer &);

    /**
     * @brief Unpacks data from a FixedTextBuffer into the student object.
     * @param buffer The FixedTextBuffer to unpack.
     * @return 0 on success, -1 on failure.
     */
    int Unpack(FixedTextBuffer &);

    /**
     * @brief Packs student data into a FixedTextBuffer.
     * @param buffer The FixedTextBuffer to pack into.
     * @return 0 on success, -1 on failure.
     */
    int Pack(FixedTextBuffer &) const;

    static int InitBuffer(LengthTextBuffer &);

    int Unpack(LengthTextBuffer &);

    int Pack(LengthTextBuffer &) const;

    static int InitBuffer(DelimTextBuffer &);

    int Unpack(DelimTextBuffer &);

    int Pack(DelimTextBuffer &) const;

    /**
     * @brief Prints the student information to the specified output stream.
     * @param out The output stream to print to.
     */
    void Print(ostream &);

    friend std::ostream& operator<<(std::ostream& os, const Student& student);

    friend bool operator<(const Student& lhs, const Student& rhs);
    friend bool operator==(const Student& lhs, const Student& rhs);
    friend bool operator>(const Student& lhs, const Student& rhs);
};


#endif //ASSIGNMENT2_STUDENT_H
