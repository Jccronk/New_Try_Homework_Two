//
// Created by Jake Cronk on 2/23/24.
//

#ifndef ASSIGNMENT2_COURSEREGISTRATION_H
#define ASSIGNMENT2_COURSEREGISTRATION_H

#include "fixtext1.h"
#include "lentext1.h"
#include "deltext1.h"


class CourseRegistration {
public:
    char courseID[4];
    char studentID[7];
    char numOfCredits[2];
    char courseGrade[2];

    CourseRegistration();
    void Clear();
    static int InitBuffer (FixedTextBuffer &);
    int Unpack (FixedTextBuffer &);
    int Pack (FixedTextBuffer &) const;
    static int InitBuffer (LengthTextBuffer &);
    int Unpack (LengthTextBuffer &);
    int Pack (LengthTextBuffer &) const;
    static int InitBuffer (DelimTextBuffer &);
    int Unpack (DelimTextBuffer &);
    int Pack (DelimTextBuffer &) const;
    void Print (ostream &);
};


#endif //ASSIGNMENT2_COURSEREGISTRATION_H
