cmake_minimum_required(VERSION 3.27)
project(Assignment2)

set(CMAKE_CXX_STANDARD 17)


add_executable(StudentTest Student.cpp
        StudentDriver.cpp
        TestStudent.h
        deltext1.cpp
        fixtext1.cpp
        lentext1.cpp)

add_executable(CourseRegistrationTest deltext1.cpp fixtext1.cpp lentext1.cpp CourseRegistration.cpp CourseRegistration.h
        CourseRegistrationDriver.cpp)
