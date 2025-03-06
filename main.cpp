#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    std::string description;
    bool completed;

    Task(std::string desc) : description(desc), completed(false) {}
    void markCompleted() { completed = true; }
};

class TodoList {
public:
    std::vector<Task> tasks;

    void addTask(const std::string& desc) { tasks.push_back(Task(desc)); }
    void markTaskCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].markCompleted();
        }
    }
    void displayTasks() const {
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].description << " [" << (tasks[i].completed ? "✔" : "✘") << "]\n";
        }
    }
    void viewAllTasks() const {
        std::cout << "Alle opgaver:\n";
        displayTasks();
    }
};

int main() {
    TodoList todo;
    todo.addTask("Køb ind");
    todo.addTask("Lær C++");
    
    todo.viewAllTasks();
    
    int taskNumber;
    std::cout << "Markér en opgave som fuldført (indtast nummer): ";
    std::cin >> taskNumber;
    todo.markTaskCompleted(taskNumber - 1);
    
    todo.viewAllTasks();
    return 0;
}

