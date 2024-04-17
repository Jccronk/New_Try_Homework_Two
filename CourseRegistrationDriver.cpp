#include "CourseRegistration.h"
#include <iostream>
#include <sstream>
#include "CourseRegistrationOutput.h"
#include "CourseRegistrationOutputSorted.h"


int main() {

    std::string reg1Input = "12310211;33164;CHEM 210 General Chemistry 1;3;B";
    std::string reg2Input = "12272140;33164;CHEM 210 General Chemistry 1;3;B";
    std::string reg3Input = "12310211;11897;MATH 221 Survey of Calculus I;3;C";

    CourseRegistration reg1, reg2, reg3;
    std::istringstream issReg1(reg1Input), issReg2(reg2Input), issReg3(reg3Input);


    issReg1 >> reg1;
    issReg2 >> reg2;
    issReg3 >> reg3;


    std::cout << "Comparing reg1 and reg2 by studentID:" << std::endl;
    std::cout << "reg1 < reg2: " << (reg1 < reg2) << std::endl;
    std::cout << "reg1 == reg2: " << (reg1 == reg2) << std::endl;
    std::cout << "reg1 > reg2: " << (reg1 > reg2) << std::endl;

    std::cout << "\nComparing reg1 and reg3 (same studentID):" << std::endl;
    std::cout << "reg1 < reg3: " << (reg1 < reg3) << std::endl;
    std::cout << "reg1 == reg3: " << (reg1 == reg3) << std::endl; // This should be true
    std::cout << "reg1 > reg3: " << (reg1 > reg3) << std::endl;

    std::cout << "reg1 studentID: " << reg1.studentID << std::endl;
    std::cout << "reg2 studentID: " << reg2.studentID << std::endl;
    std::cout << "reg3 studentID: " << reg3.studentID << std::endl;

    createCourseRegistrationOutput();
    createSortedCourseRegistrationOutput();




    return 0;
}
