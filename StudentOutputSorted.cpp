//
// Created by Jake Cronk on 4/17/24.
//

#include "StudentOutputSorted.h"
#include "StudentOutputSorted.h"
#include <algorithm> // For std::sort

// Function to sort students by their identifiers and write them to a file
void writeSortedStudentDataToFile(const std::string& filename, std::vector<Student> students) {
    // Sort the students by their identifiers
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a < b; // Assuming operator< is implemented to compare students by identifiers
    });

    // Write the sorted students to the file, using the function from StudentOutput.h
    writeStudentDataToFile(filename, students);
}