#include <memory>
#include <string>

class Classroom;

class Student : public std::enable_shared_from_this<Student>
{
private:
    std::string name;
    const int age;
    std::shared_ptr<Classroom> myClassroom;
public:
    Student(const std::string& name, int age);

    /** 
     * @brief Определяет студенту аудиторию.
     * @param classroom Указатель shared_ptr на аудиторию, к которой присоединяется студент.
    */
    void currentClassroom(const std::shared_ptr<Classroom>& classroom);

    /** 
     * @brief Отображает информацию о студенте.
     */
    std::ostringstream displayInfo();
};
