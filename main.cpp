#include <iostream>
#include <vector>
#include <limits>
#include "Task.h"
#include <algorithm>

using namespace std;

void showMenu();
void addTask(vector<Task>& tasks, int& nextId);
void viewTasks(const vector<Task>& tasks);
void searchTask(const vector<Task>& tasks);
void updateTask(vector<Task>& tasks);
void deleteTask(vector<Task>& tasks);
void markTaskCompleted(vector<Task>& tasks);
void sortTasksByPriority(vector<Task>& tasks);


int main() {
    vector<Task> tasks;
    int nextId = 1;
    int choice;

    do {
        showMenu();

        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            addTask(tasks, nextId);
            break;

        case 2:
            viewTasks(tasks);
            break;

        case 3:
            searchTask(tasks);
            break;

        case 4:
            updateTask(tasks);
            break;

        case 5:
            deleteTask(tasks);
            break;

        case 6:
            markTaskCompleted(tasks);
            break;

        case 7:
            sortTasksByPriority(tasks);
            break;

        case 8:
            cout << "Exiting Task Management System..." << endl;
            break;

        default:
            cout << "Invalid choice. Please choose 1-8." << endl;
        }

    } while (choice != 8);

    return 0;
}

void showMenu() {
    cout << "\n=================================" << endl;
    cout << "      TASK MANAGEMENT SYSTEM     " << endl;
    cout << "=================================" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Search Task" << endl;
    cout << "4. Update Task" << endl;
    cout << "5. Delete Task" << endl;
    cout << "6. Mark Task Completed" << endl;
    cout << "7. Sort by Priority" << endl;
    cout << "8. Exit" << endl;
    cout << "=================================" << endl;
}

void addTask(vector<Task>& tasks, int& nextId) {
    string title;
    string description;
    int priority;

    cout << "\n--- Add New Task ---" << endl;

    cout << "Enter task title: ";
    getline(cin, title);

    cout << "Enter task description: ";
    getline(cin, description);

    do {
        cout << "Enter priority (1 = Low, 2 = Medium, 3 = High): ";
        cin >> priority;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Please enter 1, 2, or 3." << endl;
            priority = 0;
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (priority < 1 || priority > 3) {
                cout << "Priority must be between 1 and 3." << endl;
            }
        }

    } while (priority < 1 || priority > 3);

    Task newTask(nextId, title, description, priority, false);

    tasks.push_back(newTask);

    cout << "Task added successfully. Task ID: "
         << nextId << endl;

    nextId++;
}

void viewTasks(const vector<Task>& tasks) {
    cout << "\n--- All Tasks ---" << endl;

    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }

    for (const Task& task : tasks) {
        task.displayTask();
    }
}

void searchTask(const vector<Task>& tasks) {
    int searchId;

    cout << "\n--- Search Task ---" << endl;

    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }

    cout << "Enter Task ID to search: ";
    cin >> searchId;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid input. Please enter a number." << endl;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (const Task& task : tasks) {
        if (task.getTaskId() == searchId) {
            cout << "Task found:" << endl;
            task.displayTask();
            return;
        }
    }

    cout << "Task with ID " << searchId << " not found." << endl;
}

void updateTask(vector<Task>& tasks) {
    int updateId;

    cout << "\n--- Update Task ---" << endl;

    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }

    cout << "Enter Task ID to update: ";
    cin >> updateId;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid input. Please enter a number." << endl;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (Task& task : tasks) {
        if (task.getTaskId() == updateId) {

            string newTitle;
            string newDescription;
            int newPriority;

            cout << "Task found:" << endl;
            task.displayTask();

            cout << "\nEnter new title: ";
            getline(cin, newTitle);

            cout << "Enter new description: ";
            getline(cin, newDescription);

            do {
                cout << "Enter new priority (1 = Low, 2 = Medium, 3 = High): ";
                cin >> newPriority;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Invalid input. Please enter 1, 2, or 3." << endl;
                    newPriority = 0;
                }
                else {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    if (newPriority < 1 || newPriority > 3) {
                        cout << "Priority must be between 1 and 3." << endl;
                    }
                }

            } while (newPriority < 1 || newPriority > 3);

            task.setTitle(newTitle);
            task.setDescription(newDescription);
            task.setPriority(newPriority);

            cout << "Task updated successfully." << endl;

            return;
        }
    }

    cout << "Task with ID " << updateId << " not found." << endl;
}

void deleteTask(vector<Task>& tasks) {
    int deleteId;

    cout << "\n--- Delete Task ---" << endl;

    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }

    cout << "Enter Task ID to delete: ";
    cin >> deleteId;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid input. Please enter a number." << endl;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->getTaskId() == deleteId) {

            cout << "Task found:" << endl;
            it->displayTask();

            tasks.erase(it);

            cout << "Task deleted successfully." << endl;
            return;
        }
    }

    cout << "Task with ID " << deleteId << " not found." << endl;
}

void markTaskCompleted(vector<Task>& tasks) {
    int taskId;

    cout << "\n--- Mark Task Completed ---" << endl;

    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }

    cout << "Enter Task ID to mark as completed: ";
    cin >> taskId;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid input. Please enter a number." << endl;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (Task& task : tasks) {
        if (task.getTaskId() == taskId) {

            if (task.isCompleted()) {
                cout << "This task is already completed." << endl;
                return;
            }

            task.setCompleted(true);

            cout << "Task marked as completed successfully." << endl;
            return;
        }
    }

    cout << "Task with ID " << taskId << " not found." << endl;
}

void sortTasksByPriority(vector<Task>& tasks) {
    cout << "\n--- Sort Tasks by Priority ---" << endl;

    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }

    sort(tasks.begin(), tasks.end(),
        [](const Task& a, const Task& b) {
            return a.getPriority() > b.getPriority();
        }
    );

    cout << "Tasks sorted by priority successfully." << endl;
    cout << "(High -> Medium -> Low)" << endl;
}
