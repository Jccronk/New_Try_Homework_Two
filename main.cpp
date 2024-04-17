//
// Created by Jake Cronk on 4/17/24.
//

#include "Student.h"
#include "StudentOutput.h"
#include "StudentOutputSorted.h"
#include <vector>

int main() {
    // Create an empty vector of Student objects
    std::vector<Student> students;

    // Temporarily create Student objects
    Student tempStudent;

    // Initialize first student
    std::strcpy(tempStudent.identifier, "12272140");
    std::strcpy(tempStudent.firstName, "Mary");
    std::strcpy(tempStudent.lastName, "Clay");
    std::strcpy(tempStudent.address, "21 8th Street, St Cloud, MN 56301");
    std::strcpy(tempStudent.enrollDate, "4/20/2019");
    std::strcpy(tempStudent.creditHours, "7");
    students.push_back(tempStudent);

    // Initialize second student
    std::strcpy(tempStudent.identifier, "12310211");
    std::strcpy(tempStudent.firstName, "John");
    std::strcpy(tempStudent.lastName, "Smith");
    std::strcpy(tempStudent.address, "123 16th Street, St Cloud, MN 56301");
    std::strcpy(tempStudent.enrollDate, "8/23/2022");
    std::strcpy(tempStudent.creditHours, "9");
    students.push_back(tempStudent);

    // Initialize third student
    std::strcpy(tempStudent.identifier, "12262100");
    std::strcpy(tempStudent.firstName, "Joe");
    std::strcpy(tempStudent.lastName, "Anderson");
    std::strcpy(tempStudent.address, "1101 6th Avenue, Sartell, MN 56377");
    std::strcpy(tempStudent.enrollDate, "12/20/2020");
    std::strcpy(tempStudent.creditHours, "6");
    students.push_back(tempStudent);

    // Write student data to a file without sorting
    writeStudentDataToFile("unsorted_students.txt", students);
    std::cout << "Unsorted student data written to 'unsorted_students.txt'." << std::endl;

    // Write student data to another file, this time sorted by identifiers
    writeSortedStudentDataToFile("sorted_students.txt", students);
    std::cout << "Sorted student data written to 'sorted_students.txt'." << std::endl;

    return 0;
}
