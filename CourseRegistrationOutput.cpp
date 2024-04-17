//
// Created by Jake Cronk on 4/17/24.
//
#include "CourseRegistration.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>

void createCourseRegistrationOutput() {
    // Create a vector of CourseRegistration objects
    std::vector<CourseRegistration> registrations;

    // Sample data for course registrations
    std::vector<std::string> data = {
            "12310211;33164;CHEM 210 General Chemistry 1;3;B",
            "12272140;33164;CHEM 210 General Chemistry 1;3;B",
            "12262100;11897;MATH 221 Survey of Calculus I;3;C",
            "12272140;21033;CSCI 301 Computer Science 2;4;B",
            "12310211;11897;MATH 221 Survey of Calculus I;3;C",
            "12262100;33164;CHEM 210 General Chemistry 1;3;B",
            "12310211;34120;CSCI 331 Software Systems;3;A"
    };

    // Populate the registrations vector
    for (const auto& entry : data) {
        std::istringstream iss(entry);
        CourseRegistration reg;
        iss >> reg;
        registrations.push_back(reg);
    }

    // Open a file in write mode
    std::ofstream outFile("course_registrations.txt");
    if (!outFile) {
        std::cerr << "Failed to open file for writing." << std::endl;
        return;
    }

    // Write the course registrations to the file
    for (const auto& reg : registrations) {
        outFile << reg << std::endl;
    }

    std::cout << "Course registration records have been written to 'course_registrations.txt'." << std::endl;

    // Close the file
    outFile.close();
}
