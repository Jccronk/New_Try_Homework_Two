//
// Created by Jake Cronk on 2/23/24.
//

#ifndef ASSIGNMENT2_STUDENT_H
#define ASSIGNMENT2_STUDENT_H

#include "fixtext1.h"
#include "lentext1.h"
#include "deltext1.h"



class Student {


public:
    Student();

    char identifier[16]{};
    char firstName[11]{};
    char lastName[11]{};
    char address[16]{};
    char enrollDate[10]{};
    char creditHours[4]{};

    void clear();

    static int InitBuffer(FixedTextBuffer &);

    int Unpack(FixedTextBuffer &);

    int Pack(FixedTextBuffer &) const;

    static int InitBuffer(LengthTextBuffer &);

    int Unpack(LengthTextBuffer &);

    int Pack(LengthTextBuffer &) const;

    static int InitBuffer(DelimTextBuffer &);

    int Unpack(DelimTextBuffer &);

    int Pack(DelimTextBuffer &) const;

    void Print(ostream &);
};


#endif //ASSIGNMENT2_STUDENT_H
