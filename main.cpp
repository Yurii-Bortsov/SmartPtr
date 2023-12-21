#include <iostream>
#include <string>
#include "classroom.h"
#include "student.h"
#include "teacher.h"

int main() 
{
    std::shared_ptr<Teacher> teacher = std::make_shared<Teacher>("Mr. Smith");
    std::shared_ptr<Student> student1 = std::make_shared<Student>("Alice", 16);
    std::shared_ptr<Student> student2 = std::make_shared<Student>("Bob", 17);

    std::shared_ptr<Classroom> classroom = std::make_shared<Classroom>();

    classroom->addStudent(student1);
    classroom->addStudent(student2);
    classroom->addTeacher(teacher);
    
    std::ostringstream streamBuffer;
    streamBuffer << classroom->displayClassInfo();
    std::cout << streamBuffer.str();

    return 0;
}
