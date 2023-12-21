#include <iostream>
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

std::string Classroom::displayClassInfo()
{
    std::ostringstream streamBuffer;
    streamBuffer << "Class Info:\n";
    if (teacher != nullptr)
    {
        streamBuffer << "\n";
        streamBuffer << teacher->displayInfo();
    }
    streamBuffer << "Students:";
    streamBuffer << "\n";

    for (std::vector<std::weak_ptr<Student>>::iterator temp = students.begin(); temp != students.end(); ++temp)
    {
        if (std::shared_ptr<Student> sharedStudent = temp->lock())
        {
            streamBuffer << sharedStudent->displayInfo();
            streamBuffer << "\n";
        }
    }
    return streamBuffer.str();
}
