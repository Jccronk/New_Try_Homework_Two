//
// Created by Jake Cronk on 2/23/24.
//

#include "CourseRegistration.h"

CourseRegistration::CourseRegistration() {
    Clear();
}

void CourseRegistration::Clear() {
    courseID[0]=0;
    studentID[0]=0;
     numOfCredits[0]=0;
     courseGrade[0]=0;
}

int CourseRegistration::Pack (FixedTextBuffer & Buffer) const
{// pack the fields into a FixedTextBuffer, return TRUE if all succeed, FALSE o/w
    int result;
    Buffer . Clear ();
    result = Buffer . Pack (courseID);
    result = result && Buffer . Pack (studentID);
    result = result && Buffer . Pack (numOfCredits);
    result = result && Buffer . Pack (courseGrade);
    return result;
}

int CourseRegistration::Unpack (FixedTextBuffer & Buffer)
{
    Clear ();
    int result;
    result = Buffer . Unpack (courseID);
    result = result && Buffer . Unpack (studentID);
    result = result && Buffer . Unpack (numOfCredits);
    result = result && Buffer . Unpack (courseGrade);
    return result;
}

int CourseRegistration::InitBuffer (FixedTextBuffer & Buffer){
    int result;
    result = Buffer . AddField (3); // courseID[4];
    result = result && Buffer . AddField (6); // studentID[7];
    result = result && Buffer . AddField (1); // numOfCredits[2];
    result = result && Buffer . AddField (1); // courseGrade[2];
    return result;
}

int CourseRegistration::Pack (LengthTextBuffer & Buffer) const
{// pack the fields into a FixedTextBuffer, return TRUE if all succeed, FALSE o/w
    int result;
    Buffer . Clear ();
    result = Buffer . Pack (courseID);
    result = result && Buffer . Pack (studentID);
    result = result && Buffer . Pack (numOfCredits);
    result = result && Buffer . Pack (courseGrade);
    return result;
}

int CourseRegistration::Unpack (LengthTextBuffer & Buffer)
{
    int result;
    result = Buffer . Unpack (courseID);
    result = result && Buffer . Unpack (studentID);
    result = result && Buffer . Unpack (numOfCredits);
    result = result && Buffer . Unpack (courseGrade);
    return result;
}

int CourseRegistration::InitBuffer (LengthTextBuffer & Buffer)
// initialize a LengthTextBuffer to be used for Persons
{
return TRUE;
}

int CourseRegistration::Pack (DelimTextBuffer & Buffer) const
{// pack the fields into a FixedTextBuffer, return TRUE if all succeed, FALSE o/w
    int result;
    Buffer . Clear ();
    result = Buffer . Pack (courseID);
    result = result && Buffer . Pack (studentID);
    result = result && Buffer . Pack (numOfCredits);
    result = result && Buffer . Pack (courseGrade);
    return result;
}

int CourseRegistration::Unpack (DelimTextBuffer & Buffer)
{
    int result;
    result = Buffer . Unpack (courseID);
    result = result && Buffer . Unpack (studentID);
    result = result && Buffer . Unpack (numOfCredits);
    result = result && Buffer . Unpack (courseGrade);
    return result;
}

int CourseRegistration::InitBuffer (DelimTextBuffer & Buffer)
// initialize a DelimTextBuffer to be used for Persons
{
return TRUE;
}

void CourseRegistration::Print (ostream & stream)
{
    stream << "Person:"
           << "\t   Course ID '"<<courseID<<"'\n"
           << "\t  Student ID '"<<studentID<<"'\n"
           << "\tnumOfCredits '"<<numOfCredits<<"'\n"
           << "\tCourse Grade '"<<courseGrade<<"'\n"
            <<flush;
}