#include "student.h"
#include "classroom.h"

Student::Student(const std::string& name, const int age) : name(name), age(age) {}

/** @brief Присоединяет студента к аудитории.
 *  @param classroom Указатель shared_ptr на аудиторию, к которой присоединяется студент.
 */
void Student::currentClassroom(const std::shared_ptr<Classroom>& classroom) 
{
    myClassroom = classroom;
}

/** @brief Отображает информацию о студенте.
 */
std::ostringstream Student::displayInfo()
{
    std::ostringstream streamBuffer;
    streamBuffer << "Name: " << name << ", Age: " << age << "\n";
    return streamBuffer;
}
