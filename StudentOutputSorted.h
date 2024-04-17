//
// Created by Jake Cronk on 4/17/24.
//

#ifndef ASSIGNMENT2_STUDENTOUTPUTSORTED_H
#define ASSIGNMENT2_STUDENTOUTPUTSORTED_H


#include "StudentOutput.h" // Include the header for writing student data to a file
#include <vector>
#include <string>

// Declaration of the function to sort student data by identifiers and write to a file
void writeSortedStudentDataToFile(const std::string& filename, std::vector<Student> students);


#endif //ASSIGNMENT2_STUDENTOUTPUTSORTED_H
