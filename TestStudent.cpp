//
// Created by Jake Cronk on 2/23/24.
//

#include "TestStudent.h"
#include "fixtext1.h"
#include "Student.h"
#include <cstring>
#include <fstream>

void testDelText (){
    cout << "\nTesting DelimTextBuffer" << endl;
    Student student;
    // Set student properties
    strcpy(student.identifier, "1234567890");
    strcpy(student.firstName, "John");
    strcpy(student.lastName, "Doe");
    strcpy(student.address, "456 Elm St");
    strcpy(student.enrollDate, "2024-02-23");
    strcpy(student.creditHours, "15");

    student.Print(cout);
    DelimTextBuffer Buff;
    Student::InitBuffer(Buff);
    Buff.Print(cout);
    cout << "pack student " << student.Pack(Buff) << endl;
    Buff.Print(cout);

    ofstream TestOut("deltext.dat", ios::out | ios::binary); // Note the binary flag for binary write
    Buff.Write(TestOut);
    Buff.Write(TestOut);
    strcpy(student.firstName, "Dave");
    student.Print(cout);
    student.Pack(Buff);
    Buff.Write(TestOut);
    TestOut.close();

    ifstream TestIn("deltext.dat", ios::in | ios::binary); // Note the binary flag for binary read
    DelimTextBuffer InBuff;
    Student::InitBuffer(InBuff);
    cout << "read " << Buff.Read(TestIn) << endl;
    cout << "unpack " << student.Unpack(Buff) << endl;
    student.Print(cout);
    cout << "read " << Buff.Read(TestIn) << endl;
    cout << "unpack " << student.Unpack(Buff) << endl;
    student.Print(cout);
    cout << "read " << Buff.Read(TestIn) << endl;
    cout << "unpack " << student.Unpack(Buff) << endl;
    student.Print(cout);
}


void testLenText (){
    cout << "\nTesting LengthTextBuffer" << endl;
    Student student;
    LengthTextBuffer Buff;
    Student::InitBuffer(Buff);

    // Set student properties
    strcpy(student.identifier, "1234567890");
    strcpy(student.firstName, "John");
    strcpy(student.lastName, "Doe");
    strcpy(student.address, "456 Elm St");
    strcpy(student.enrollDate, "2024-02-23");
    strcpy(student.creditHours, "15");

    // Print, Pack, and I/O operations
    student.Print(cout);
    Buff.Print(cout);
    cout << "pack student " << student.Pack(Buff) << endl;
    Buff.Print(cout);

    ofstream TestOut("lentext.dat", ios::out | ios::binary); // Note the binary flag for binary write
    Buff.Write(TestOut);
    Buff.Write(TestOut);
    strcpy(student.firstName, "Dave");
    student.Print(cout);
    student.Pack(Buff);
    Buff.Write(TestOut);
    TestOut.close();

    ifstream TestIn("lentext.dat", ios::in | ios::binary); // Note the binary flag for binary read
    LengthTextBuffer InBuff;
    Student::InitBuffer(InBuff);
    cout << "read " << Buff.Read(TestIn) << endl;
    cout << "unpack " << student.Unpack(Buff) << endl;
    student.Print(cout);
    cout << "read " << Buff.Read(TestIn) << endl;
    cout << "unpack " << student.Unpack(Buff) << endl;
    student.Print(cout);
    cout << "read " << Buff.Read(TestIn) << endl;
    cout << "unpack " << student.Unpack(Buff) << endl;
    student.Print(cout);

}

void testFixText (){
    Student student;
    FixedTextBuffer Buff(5); // Adjust the number of fields according to Student's properties
    Student::InitBuffer(Buff);

    // Use strcpy to set values for Student properties
    strcpy(student.identifier, "1234567890");
    strcpy(student.firstName, "John");
    strcpy(student.lastName, "Doe");
    strcpy(student.address, "456 Elm St");
    strcpy(student.enrollDate, "2024-02-23");
    strcpy(student.creditHours, "15");

    // Print, Pack, and I/O operations
    student.Print(cout);
    student.Pack(Buff);
    Buff.Print(cout);

    ofstream TestOut("fixtext.dat", ios::out | ios::binary); // Note the binary flag for binary write
    Buff.Write(TestOut);
    TestOut.close();

    ifstream TestIn("fixtext.dat", ios::in | ios::binary); // Note the binary flag for binary read
    FixedTextBuffer InBuff(5); // Ensure matching buffer size
    Student::InitBuffer(InBuff);
    InBuff.Read(TestIn);
    student.Unpack(InBuff);
    student.Print(cout);
}

int main(){
    testFixText ();
    testLenText ();
    testDelText ();
    return 1;
}