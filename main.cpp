#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    std::string _description;
    Task(std::string description) : _description(description) {}
};

class TodoList {
public:
    std::vector<Task> todolist;
    void addTask(std::string desc) { todolist.push_back(Task(desc)); }
};

int main() {
    TodoList todo;
    std::string task;
    
    std::cout << "Tilføj en opgave: ";
    std::getline(std::cin, task);
    todo.addTask(task);

    return 0;
}

