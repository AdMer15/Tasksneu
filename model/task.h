#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <ctime>
#include <string>


class Task { // Klassen werden verwendet, um Objekte zu erstellen
private: // öffentlich
    int id;
    std::string desc;
    std::tm due; // HÜ richtiges Datum hinschreiben
    std::string state;
    std::string assignee;
    int priority;
public:
    // Konstruktor
    Task(int id, const std::string& desc, const std::string& state, const std::string& assignee);

    void print();

    int getId();

    void setDesc(std::string desc); // ich verwende getter und setter wenn ich möchte das die Description gelsesn und geändert werden kann


    std::string getDesc();

    std::tm getDue();

    void setDue(std::tm due);

    void setState(std::string state);

    std::string getState();

    void setAssignee(std::string assignee);

    std::string getAssignee();

    void setPriority(int priority);

    int getPriority();

};

#endif // TASK_H
