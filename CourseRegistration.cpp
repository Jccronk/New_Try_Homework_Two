#include "CourseRegistration.h"

/**
 * @brief Construct a new Course Registration:: Course Registration object
 * 
 * Initializes the CourseRegistration object by clearing its data members.
 */
CourseRegistration::CourseRegistration() {
    Clear();
}

/**
 * @brief Clears all data members of the CourseRegistration object.
 * 
 */
void CourseRegistration::Clear() {
    courseID[0]=0;
    studentID[0]=0;
    numOfCredits[0]=0;
    courseGrade[0]=0;
    courseDescription[0] = 0; // Initialize course description as empty
}

/**
 * @brief Packs the fields of CourseRegistration into a FixedTextBuffer.
 * 
 * @param Buffer The FixedTextBuffer to pack into.
 * @return int Returns TRUE if all fields are successfully packed, FALSE otherwise.
 */
int CourseRegistration::Pack (FixedTextBuffer & Buffer) const
{
    int result;
    Buffer . Clear ();
    result = Buffer . Pack (courseID);
    result = result && Buffer . Pack (studentID);
    result = result && Buffer . Pack (numOfCredits);
    result = result && Buffer . Pack (courseGrade);
    result = result && Buffer.Pack(courseDescription); // Pack the course description
    return result;
}

/**
 * @brief Unpacks data from a FixedTextBuffer into the CourseRegistration object.
 * 
 * @param Buffer The FixedTextBuffer to unpack.
 * @return int Returns TRUE if all fields are successfully unpacked, FALSE otherwise.
 */
int CourseRegistration::Unpack (FixedTextBuffer & Buffer)
{
    Clear ();
    int result;
    result = Buffer . Unpack (courseID);
    result = result && Buffer . Unpack (studentID);
    result = result && Buffer . Unpack (numOfCredits);
    result = result && Buffer . Unpack (courseGrade);
    result = result && Buffer.Unpack(courseDescription); // Unpack the course description
    return result;
}

/**
 * @brief Initializes a FixedTextBuffer to be used for CourseRegistration objects.
 * 
 * @param Buffer The FixedTextBuffer to initialize.
 * @return int Returns TRUE if the buffer is successfully initialized, FALSE otherwise.
 */
int CourseRegistration::InitBuffer (FixedTextBuffer & Buffer){
    int result;
    result = Buffer . AddField (3); // courseID[4];
    result = result && Buffer . AddField (6); // studentID[7];
    result = result && Buffer . AddField (1); // numOfCredits[2];
    result = result && Buffer . AddField (1); // courseGrade[2];
    result = result && Buffer . AddField(49); // courseDescription[50];
    return result;
}

/**
 * @brief Packs the fields of CourseRegistration into a LengthTextBuffer.
 * 
 * @param Buffer The LengthTextBuffer to pack into.
 * @return int Returns TRUE if all fields are successfully packed, FALSE otherwise.
 */
int CourseRegistration::Pack (LengthTextBuffer & Buffer) const
{
    int result;
    Buffer . Clear ();
    result = Buffer . Pack (courseID);
    result = result && Buffer . Pack (studentID);
    result = result && Buffer . Pack (numOfCredits);
    result = result && Buffer . Pack (courseGrade);
    result = result && Buffer.Pack(courseDescription); // Pack the course description
    return result;
}

/**
 * @brief Unpacks data from a LengthTextBuffer into the CourseRegistration object.
 * 
 * @param Buffer The LengthTextBuffer to unpack.
 * @return int Returns TRUE if all fields are successfully unpacked, FALSE otherwise.
 */
int CourseRegistration::Unpack (LengthTextBuffer & Buffer)
{
    int result;
    result = Buffer . Unpack (courseID);
    result = result && Buffer . Unpack (studentID);
    result = result && Buffer . Unpack (numOfCredits);
    result = result && Buffer . Unpack (courseGrade);
    result = result && Buffer.Unpack(courseDescription); // Unpack the course description
    return result;
}

/**
 * @brief Initializes a LengthTextBuffer to be used for CourseRegistration objects.
 * 
 * @param Buffer The LengthTextBuffer to initialize.
 * @return int Returns TRUE if the buffer is successfully initialized, FALSE otherwise.
 */
int CourseRegistration::InitBuffer (LengthTextBuffer & Buffer)
{
    return TRUE;
}

/**
 * @brief Packs the fields of CourseRegistration into a DelimTextBuffer.
 * 
 * @param Buffer The DelimTextBuffer to pack into.
 * @return int Returns TRUE if all fields are successfully packed, FALSE otherwise.
 */
int CourseRegistration::Pack (DelimTextBuffer & Buffer) const
{
    int result;
    Buffer . Clear ();
    result = Buffer . Pack (courseID);
    result = result && Buffer . Pack (studentID);
    result = result && Buffer . Pack (numOfCredits);
    result = result && Buffer . Pack (courseGrade);
    result = result && Buffer.Pack(courseDescription); // Pack the course description
    return result;
}

/**
 * @brief Unpacks data from a DelimTextBuffer into the CourseRegistration object.
 * 
 * @param Buffer The DelimTextBuffer to unpack.
 * @return int Returns TRUE if all fields are successfully unpacked, FALSE otherwise.
 */
int CourseRegistration::Unpack (DelimTextBuffer & Buffer)
{
    int result;
    result = Buffer . Unpack (courseID);
    result = result && Buffer . Unpack (studentID);
    result = result && Buffer . Unpack (numOfCredits);
    result = result && Buffer . Unpack (courseGrade);
    result = result && Buffer.Unpack(courseDescription); // Unpack the course description
    return result;
}

/**
 * @brief Initializes a DelimTextBuffer to be used for CourseRegistration objects.
 * 
 * @param Buffer The DelimTextBuffer to initialize.
 * @return int Returns TRUE if the buffer is successfully initialized, FALSE otherwise.
 */
int CourseRegistration::InitBuffer (DelimTextBuffer & Buffer)
{
    return TRUE;
}

/**
 * @brief Prints the course registration information to the specified output stream.
 * 
 * @param stream The output stream to print to.
 */
void CourseRegistration::Print (ostream & stream)
{
    stream << "Course Registration:"
           << "\t   Course ID '"<<courseID<<"'\n"
           << "\t  Student ID '"<<studentID<<"'\n"
           << "\tNumber of Credits '"<<numOfCredits<<"'\n"
           << "\t  Course Grade '"<<courseGrade<<"'\n"
           << "\tCourse Description: '" << courseDescription << "'\n"
           <<flush;
}

// Overload the output operator << for the CourseRegistration class
std::ostream& operator<<(std::ostream& os, const CourseRegistration& reg) {
    // Output the course registration information separated by semicolons
    os << reg.studentID << "; " << reg.courseID << "; "
       << reg.courseDescription << "; " << reg.numOfCredits << "; "
       << reg.courseGrade;
    return os;
}

// Overload the input operator >>
std::istream& operator>>(std::istream& is, CourseRegistration& reg) {
    std::string temp;

    // Student ID
    std::getline(is, temp, ';');
    std::strncpy(reg.studentID, temp.c_str(), sizeof(reg.studentID) - 1);
    reg.studentID[sizeof(reg.studentID) - 1] = '\0';

    // Course ID
    std::getline(is, temp, ';');
    std::strncpy(reg.courseID, temp.c_str(), sizeof(reg.courseID) - 1);
    reg.courseID[sizeof(reg.courseID) - 1] = '\0';

    // Course Description
    std::getline(is, temp, ';');
    std::strncpy(reg.courseDescription, temp.c_str(), sizeof(reg.courseDescription) - 1);
    reg.courseDescription[sizeof(reg.courseDescription) - 1] = '\0';

    // Number of Credits
    std::getline(is, temp, ';');
    std::strncpy(reg.numOfCredits, temp.c_str(), sizeof(reg.numOfCredits) - 1);
    reg.numOfCredits[sizeof(reg.numOfCredits) - 1] = '\0';

    // Course Grade
    std::getline(is, temp);
    std::strncpy(reg.courseGrade, temp.c_str(), sizeof(reg.courseGrade) - 1);
    reg.courseGrade[sizeof(reg.courseGrade) - 1] = '\0';

    return is;
}

bool operator<(const CourseRegistration& lhs, const CourseRegistration& rhs) {
    return std::strcmp(lhs.studentID, rhs.studentID) < 0;
}

bool operator==(const CourseRegistration& lhs, const CourseRegistration& rhs) {
    return std::strcmp(lhs.studentID, rhs.studentID) == 0;
}

bool operator>(const CourseRegistration& lhs, const CourseRegistration& rhs) {
    return std::strcmp(lhs.studentID, rhs.studentID) > 0;
}
