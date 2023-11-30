#include <iostream>
#include <vector>

using namespace std;

struct Task
{
    string description;
    bool completed;
};

vector<Task> tasks;

void addTask()
{
    string description;
    cout << "Enter task description: ";
    getline(cin, description);

    Task task;
    task.description = description;
    task.completed = false;
    tasks.push_back(task);

    cout << "Task added successfully!" << endl;
}

void viewTasks()
{
    if (tasks.empty())
    {
        cout << "No tasks to display." << endl;
        return;
    }

    cout << "Tasks:" << endl;
    for (const Task &task : tasks)
    {
        cout << "- " << task.description << " ("
             << (task.completed ? "Completed" : "Pending") << ")" << endl;
    }
}

void markTaskCompleted()
{
    int index;
    cout << "Enter task index (starting from 0): ";
    cin >> index;

    if (index < 0 || index >= tasks.size())
    {
        cout << "Invalid task index." << endl;
        return;
    }

    tasks[index].completed = true;
    cout << "Task marked as completed." << endl;
}

void removeTask()
{
    int index;
    cout << "Enter task index (starting from 0): ";
    cin >> index;

    if (index < 0 || index >= tasks.size())
    {
        cout << "Invalid task index." << endl;
        return;
    }

    tasks.erase(tasks.begin() + index);
    cout << "Task removed successfully." << endl;
}

int main()
{
    int option;

    do
    {
        cout << endl
             << "TO-DO LIST MANAGER" << endl;
        cout << "--------------------" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your option (1-5): ";
        cin >> option;

        switch (option)
        {
        case 1:
            addTask();
            break;
        case 2:
            viewTasks();
            break;
        case 3:
            markTaskCompleted();
            break;
        case 4:
            removeTask();
            break;
        case 5:
            cout << "Exiting to-do list manager..." << endl;
            break;
        default:
            cout << "Invalid option." << endl;
        }
    } while (option != 5);

    return 0;
}