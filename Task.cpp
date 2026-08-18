#include "Task.h"
#include <iostream>
using namespace std;

// Default constructor
Task::Task() {
    taskId = 0;
    title = "";
    description = "";
    priority = 1;
    completed = false;
}

// Parameterized constructor
Task::Task(int id, string title, string description, int priority, bool completed) {
    taskId = id;
    this->title = title;
    this->description = description;
    this->priority = priority;
    this->completed = completed;
}

// Getters
int Task::getTaskId() const {
    return taskId;
}

string Task::getTitle() const {
    return title;
}

string Task::getDescription() const {
    return description;
}

int Task::getPriority() const {
    return priority;
}

bool Task::isCompleted() const {
    return completed;
}

// Setters
void Task::setTitle(string title) {
    this->title = title;
}

void Task::setDescription(string description) {
    this->description = description;
}

void Task::setPriority(int priority) {
    this->priority = priority;
}

void Task::setCompleted(bool completed) {
    this->completed = completed;
}

// Display task information
void Task::displayTask() const {
    cout << "\n-----------------------------" << endl;
    cout << "Task ID     : " << taskId << endl;
    cout << "Title       : " << title << endl;
    cout << "Description : " << description << endl;
    cout << "Priority    : " << priority << endl;
    cout << "Status      : "
         << (completed ? "Completed" : "Pending") << endl;
}
