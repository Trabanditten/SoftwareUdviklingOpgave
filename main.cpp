#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
    void markCompleted() { completed = true; }
    void editDescription(const std::string& newDesc) { description = newDesc; }
};

class TodoList {
public:
    std::vector<Task> tasks;

    void addTask(const std::string& desc) { tasks.emplace_back(desc); }

    void markTaskCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].markCompleted();
        }
    }

    void editTask(int index, const std::string& newDesc) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].editDescription(newDesc);
        }
    }

    void deleteTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
        }
    }

    void viewAllTasks() const {
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].description << " [" << (tasks[i].completed ? "✔" : "✘") << "]\n";
        }
    }
};

int main() {
    TodoList todo;
    todo.addTask("Køb ind");
    todo.addTask("Lær C++");

    int choice, taskNumber;
    std::string newDesc;
    do {
        std::cout << "\n1. Markér opgave som fuldført\n";
        std::cout << "2. Slet opgave\n";
        std::cout << "3. Rediger opgave\n";
        std::cout << "4. Vis alle opgaver\n";
        std::cout << "5. Afslut\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Indtast nummer på opgaven at markere som fuldført: ";
            std::cin >> taskNumber;
            todo.markTaskCompleted(taskNumber - 1);
            break;
        case 2:
            std::cout << "Indtast nummer på opgaven at slette: ";
            std::cin >> taskNumber;
            todo.deleteTask(taskNumber - 1);
            break;
        case 3:
            std::cout << "Indtast nummer på opgaven at redigere: ";
            std::cin >> taskNumber;
            std::cin.ignore(); 
            std::cout << "Indtast ny beskrivelse: ";
            std::getline(std::cin, newDesc);
            todo.editTask(taskNumber - 1, newDesc);
            break;
        case 4:
            todo.viewAllTasks();
            break;
        }
    } while (choice != 5);

    return 0;
}

