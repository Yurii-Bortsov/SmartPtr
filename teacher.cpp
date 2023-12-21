#include "teacher.h"
#include "classroom.h"

Teacher::Teacher(const std::string& name) : name(name) {}

void Teacher::currentClassroom(const std::shared_ptr<Classroom>& classroom) 
{
    myClassroom = classroom;
}

std::ostringstream Teacher::displayInfo()
{
    std::ostringstream streamBuffer;
    streamBuffer << "Teacher: " << name << "\n";
    return streamBuffer;
}
