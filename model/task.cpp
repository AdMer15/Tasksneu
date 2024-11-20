#include "task.h"

  // Klassen werden verwendet, um Objekte zu erstellen
    // Konstruktor
    Task::Task(int id, const std::string& desc, const std::string& state, const std::string& assignee) {
        this->id = id;
        this->desc = desc;
        this->state = state;
        this->assignee = assignee;
        this->priority = 3; // Weil es nicht in der Liste steht, wird es auf 3 gesetzt

        std::time_t now = std::time(nullptr); // Aktuelle Zeit
        this->due = *std::localtime(&now); // Setze das aktuelle Datum in due
        //* = pointer oder zeiger
    }

    void Task::print() {
        // Wenn Funktion in Klasse, dann ist es eine Methode
        std::cout << "Id:  " << this->id << std::endl;
        std::cout << "Description: " << this-> desc << std::endl;
        std::cout << "Due: " << due.tm_mday << "." << due.tm_mon + 1 << "." << due.tm_year + 1900 << std::endl;
        std::cout << "State: " << this->state << std::endl;
        std::cout << "Assignee: " << this->assignee << std::endl;
        std::cout << "Priorität: " << this->priority << std::endl;
    }
    int Task::getId() {
        return this->id;
    }

    void Task::setDesc(std::string desc) { // ich verwende getter und setter wenn ich möchte das die Description gelsesn und geändert werden kann
        this->desc = desc;
    }

    std::string Task::getDesc() {
        return this->desc;
    }

    std::tm Task::getDue() {
        return this->due;
    }

    void Task::setDue(std::tm due) {
        this->due = due;
    }

    void Task::setState(std::string state) {
        this->state = state;
    }

    std::string Task::getState() {
        return this->state;
    }

    void Task::setAssignee(std::string assignee) {
        this->assignee = assignee;
    }

    std::string Task::getAssignee() {
        return this->assignee;
    }

    void Task::setPriority(int priority) {
        if (priority <= 0 || priority >= 5) {
            throw std::invalid_argument("priority < 0 || priority > 5, ist" + std::to_string(priority));
        }

        this->priority = priority;
    }

    int Task::getPriority() {
        return this->priority;
    }
