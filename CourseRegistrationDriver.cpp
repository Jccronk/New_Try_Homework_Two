//
// Created by Jake Cronk on 2/23/24.
//

#include "CourseRegistration.h"
#include <cstring>
#include <fstream>
#include "fixtext1.h"

void testFixText(){
    cout << "\nTesting FixedTextBuffer with CourseRegistration" << endl;

    // Create a CourseRegistration object and set its fields
    CourseRegistration registration;
    strcpy(registration.courseID, "CIS200   "); // Assuming field sizes including padding
    strcpy(registration.studentID, "654321  "); // Adjust sizes as needed for your actual field definitions
    strcpy(registration.numOfCredits, "4 "); // Assuming single digit number and a space for padding
    strcpy(registration.courseGrade, "B "); // Assuming single letter grade and a space for padding

    // Initialize FixedTextBuffer
    FixedTextBuffer Buff (4);
    CourseRegistration::InitBuffer(Buff);

    // Print, Pack, and I/O operations
    registration.Print(cout);
    registration.Pack(Buff);
    Buff.Print(cout);

    // Write the buffer to a file, using a unique filename to avoid overwriting
    ofstream TestOut("course_registration_fixtext.dat", ios::out | ios::binary);
    Buff.Write(TestOut);
    TestOut.close();

    // Open the file for reading
    ifstream TestIn("course_registration_fixtext.dat", ios::in | ios::binary);
    FixedTextBuffer InBuff (4);
    CourseRegistration::InitBuffer(InBuff);

    // Create a new CourseRegistration object for loading data
    CourseRegistration loadedRegistration;

    // Read the buffer from the file and unpack it into the new CourseRegistration object
    InBuff.Read(TestIn);
    loadedRegistration.Unpack(InBuff);
    loadedRegistration.Print(cout);

    TestIn.close();
}

void testLenText() {
    cout << "\nTesting LengthTextBuffer with CourseRegistration" << endl;

    // Create a CourseRegistration object and set its fields
    CourseRegistration registration;
    strcpy(registration.courseID, "CIS101");
    strcpy(registration.studentID, "123456");
    strcpy(registration.numOfCredits, "3");
    strcpy(registration.courseGrade, "A");

    // Initialize LengthTextBuffer
    LengthTextBuffer Buff;
    CourseRegistration::InitBuffer(Buff);

    // Demonstrate packing, printing, and writing to a file
    registration.Print(cout);
    Buff.Print(cout);
    cout << "pack CourseRegistration " << (registration.Pack(Buff) ? "Success" : "Failure") << endl;
    Buff.Print(cout);

    ofstream TestOut("course_registration_lentext.dat", ios::out | ios::binary);
    Buff.Write(TestOut);
    // Demonstrate changing a field and repacking
    strcpy(registration.courseGrade, "B");
    registration.Print(cout);
    registration.Pack(Buff);
    Buff.Write(TestOut);
    TestOut.close();

    // Demonstrate reading and unpacking from a file
    ifstream TestIn("course_registration_lentext.dat", ios::in | ios::binary);
    LengthTextBuffer InBuff;
    CourseRegistration::InitBuffer(InBuff);

    // Read and unpack the first record
    cout << "read " << Buff.Read(TestIn) << endl;
    cout << "unpack " << registration.Unpack(Buff) << endl;
    registration.Print(cout);

    // Attempt to read and unpack a second record
    cout << "read " << Buff.Read(TestIn) << endl;
    if (registration.Unpack(Buff)) {
        cout << "unpack Success" << endl;
        registration.Print(cout);
    } else {
        cout << "unpack Failure" << endl;
    }

    TestIn.close();
}

void testDelText() {
    cout << "\nTesting DelimTextBuffer with CourseRegistration" << endl;

    // Create a CourseRegistration object and set its fields
    CourseRegistration registration;
    strcpy(registration.courseID, "CIS101");
    strcpy(registration.studentID, "123456");
    strcpy(registration.numOfCredits, "3");
    strcpy(registration.courseGrade, "A");

    // Initialize DelimTextBuffer
    DelimTextBuffer Buff;
    CourseRegistration::InitBuffer(Buff);

    // Demonstrate packing, printing, and writing to a file
    registration.Print(cout);
    Buff.Print(cout);
    cout << "pack CourseRegistration " << (registration.Pack(Buff) ? "Success" : "Failure") << endl;
    Buff.Print(cout);

    ofstream TestOut("course_registration_deltext.dat", ios::out | ios::binary);
    Buff.Write(TestOut);
    // Demonstrate changing a field and repacking
    strcpy(registration.courseGrade, "B");
    registration.Print(cout);
    registration.Pack(Buff);
    Buff.Write(TestOut);
    TestOut.close();

    // Demonstrate reading and unpacking from a file
    ifstream TestIn("course_registration_deltext.dat", ios::in | ios::binary);
    DelimTextBuffer InBuff;
    CourseRegistration::InitBuffer(InBuff);

    // Read and unpack the first record
    cout << "read " << Buff.Read(TestIn) << endl;
    cout << "unpack " << registration.Unpack(Buff) << endl;
    registration.Print(cout);

    // Attempt to read and unpack a second record
    cout << "read " << Buff.Read(TestIn) << endl;
    if (registration.Unpack(Buff)) {
        cout << "unpack Success" << endl;
        registration.Print(cout);
    } else {
        cout << "unpack Failure" << endl;
    }

    TestIn.close();
}

int main(){
    testFixText ();
    testLenText ();
    testDelText ();
}