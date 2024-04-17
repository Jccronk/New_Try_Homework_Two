//
// Created by Jake Cronk on 4/17/24.
//

#ifndef ASSIGNMENT2_STUDENTOUTPUT_H
#define ASSIGNMENT2_STUDENTOUTPUT_H


#ifndef STUDENTOUTPUT_H
#define STUDENTOUTPUT_H

#include "Student.h" // Include the path to your Student class definition
#include <vector>
#include <string>

// Declaration of the function to write student data to a file
void writeStudentDataToFile(const std::string& filename, const std::vector<Student>& students);

#endif // STUDENTOUTPUT_H


#endif //ASSIGNMENT2_STUDENTOUTPUT_H
