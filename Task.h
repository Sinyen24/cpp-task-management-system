#ifndef TASK_H
#define TASK_H

#include <string>
using namespace std;

class Task {
private:
    int taskId;
    string title;
    string description;
    int priority;
    bool completed;

public:
    Task();

    Task(int id, string title, string description, int priority, bool completed);

    int getTaskId() const;
    string getTitle() const;
    string getDescription() const;
    int getPriority() const;
    bool isCompleted() const;

    void setTitle(string title);
    void setDescription(string description);
    void setPriority(int priority);
    void setCompleted(bool completed);

    void displayTask() const;
};

#endif
