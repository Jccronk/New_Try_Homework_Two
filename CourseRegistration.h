//
// Created by Jake Cronk on 2/23/24.
//

#ifndef ASSIGNMENT2_COURSEREGISTRATION_H
#define ASSIGNMENT2_COURSEREGISTRATION_H

#include "fixtext1.h"
#include "lentext1.h"
#include "deltext1.h"

/**
 * @brief Represents a course registration with basic information.
 *
 * This class provides a simple representation of a course registration
 * including course ID, student ID, number of credits, and course grade.
 */
class CourseRegistration {
public:
    char courseID[4];
    char studentID[7];
    char numOfCredits[2];
    char courseGrade[2];

    /**
     * @brief Default constructor for CourseRegistration.
     */
    CourseRegistration();

    /**
     * @brief Clears all data members of the CourseRegistration object.
     */
    void Clear();

    /**
     * @brief Initializes a FixedTextBuffer to be used for CourseRegistration objects.
     * @param buffer The FixedTextBuffer to initialize.
     * @return 0 on success, -1 on failure.
     */
    static int InitBuffer (FixedTextBuffer &);

    /**
     * @brief Unpacks data from a FixedTextBuffer into the CourseRegistration object.
     * @param buffer The FixedTextBuffer to unpack.
     * @return 0 on success, -1 on failure.
     */
    int Unpack (FixedTextBuffer &);

    /**
     * @brief Packs CourseRegistration data into a FixedTextBuffer.
     * @param buffer The FixedTextBuffer to pack into.
     * @return 0 on success, -1 on failure.
     */
    int Pack (FixedTextBuffer &) const;

    /**
     * @brief Initializes a LengthTextBuffer to be used for CourseRegistration objects.
     * @param buffer The LengthTextBuffer to initialize.
     * @return 0 on success, -1 on failure.
     */
    static int InitBuffer (LengthTextBuffer &);

    /**
     * @brief Unpacks data from a LengthTextBuffer into the CourseRegistration object.
     * @param buffer The LengthTextBuffer to unpack.
     * @return 0 on success, -1 on failure.
     */
    int Unpack (LengthTextBuffer &);

    /**
     * @brief Packs CourseRegistration data into a LengthTextBuffer.
     * @param buffer The LengthTextBuffer to pack into.
     * @return 0 on success, -1 on failure.
     */
    int Pack (LengthTextBuffer &) const;

    /**
     * @brief Initializes a DelimTextBuffer to be used for CourseRegistration objects.
     * @param buffer The DelimTextBuffer to initialize.
     * @return 0 on success, -1 on failure.
     */
    static int InitBuffer (DelimTextBuffer &);

    /**
     * @brief Unpacks data from a DelimTextBuffer into the CourseRegistration object.
     * @param buffer The DelimTextBuffer to unpack.
     * @return 0 on success, -1 on failure.
     */
    int Unpack (DelimTextBuffer &);

    /**
     * @brief Packs CourseRegistration data into a DelimTextBuffer.
     * @param buffer The DelimTextBuffer to pack into.
     * @return 0 on success, -1 on failure.
     */
    int Pack (DelimTextBuffer &) const;

    /**
     * @brief Prints the course registration information to the specified output stream.
     * @param out The output stream to print to.
     */
    void Print (ostream &);
};


#endif //ASSIGNMENT2_COURSEREGISTRATION_H
