//
// Created by Jake Cronk on 4/17/24.
//

#include "StudentOutput.h"

#include <fstream>
#include <vector>
#include "Student.h" // Ensure this is the correct path to your Student class definition

// Function to write student data to a file
void writeStudentDataToFile(const std::string& filename, const std::vector<Student>& students) {
    // Open a file in write mode
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Failed to open file for writing." << std::endl;
        return;
    }

    // Write the students to the file
    for (const auto& student : students) {
        outFile << student << std::endl;
    }

    // Close the file
    outFile.close();

    std::cout << "Student records have been written to '" << filename << "'." << std::endl;
}