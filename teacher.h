#include <memory>
#include <iostream>
#include <sstream>

class Classroom;

class Teacher : public std::enable_shared_from_this<Teacher>
{
private:
    std::string name;
    std::weak_ptr<Classroom> myClassroom;
public:
    /**
     * @brief Конструктор класса учитель.
    */
    Teacher(const std::string& name);

    /** 
     * @brief Присоединяет учителя к аудитории.
     * @param classroom Указатель shared_ptr на аудиторию, к которой присоединяется учитель.
     */
    void currentClassroom(const std::shared_ptr<Classroom>& classroom);

    /** 
     * @brief Отображает информацию о учителе.
     */
    std::ostringstream displayInfo();
};
