#include <memory>
#include <vector>
#include <iostream>

class Student;
class Teacher;

class Classroom : public std::enable_shared_from_this<Classroom>
{
    private:
        std::vector<std::weak_ptr<Student>> students; 
        std::shared_ptr<Teacher> teacher;             
    public:
        /** 
         * @brief Добавляет студента в класс.
         * @param student Указатель shared_ptr на добавляемого студента.
         */
        void addStudent(const std::shared_ptr<Student>& student);

        /** 
         * @brief Добавляет учителя в аудиторию.
         * @param teacher Указатель shared_ptr на добавляемого учителя.
         */
        void addTeacher(const std::shared_ptr<Teacher>& teacher);

        /** 
         * @brief Отображает информацию об аудитории, включая учителя и студентов.
         */
        void displayClassInfo();
};