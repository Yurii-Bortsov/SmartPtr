#include "classroom.h"
#include "student.h"
#include "teacher.h"

void Classroom::addStudent(const std::shared_ptr<Student>& student)
{
    students.push_back(student);
    student->currentClassroom(shared_from_this());
}

void Classroom::addTeacher(const std::shared_ptr<Teacher>& teacher)
{
    this->teacher = teacher;
}

void Classroom::displayClassInfo()
{
    std::cout << "Class Info:\n";
    if (teacher != nullptr)
    {
        std::cout << "\n";
        teacher->displayInfo();
    }
    std::cout << "Students:";
    std::cout << "\n";

    for (std::vector<std::weak_ptr<Student>>::iterator temp = students.begin(); temp != students.end(); ++temp)
    {
        if (std::shared_ptr<Student> sharedStudent = temp->lock())
        {
            sharedStudent->displayInfo();
            std::cout << "\n";
        }
    }
}
