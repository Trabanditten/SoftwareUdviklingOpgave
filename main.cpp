#include <iostream> 
#include <vector>
#include <string>

class Task {
public:
    std::string description;
    std::string dueDate; // Ny variabel til forfaldsdato
    bool completed;

    Task(const std::string& desc, const std::string& date) 
        : description(desc), dueDate(date), completed(false) {}

    void markCompleted() { completed = true; }
    void editDescription(const std::string& newDesc) { description = newDesc; }
    void editDueDate(const std::string& newDate) { dueDate = newDate; } // Ny funktion til at redigere forfaldsdato
};

class TodoList {
public:
    std::vector<Task> tasks;

    void addTask(const std::string& desc, const std::string& date) { 
        tasks.emplace_back(desc, date); 
    }

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

    void editTaskDueDate(int index, const std::string& newDate) { // Ny funktion til at redigere dato
        if (index >= 0 && index < tasks.size()) {
            tasks[index].editDueDate(newDate);
        }
    }

    void deleteTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
        }
    }

    void viewAllTasks() const {
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].description 
                      << " (Forfaldsdato: " << tasks[i].dueDate << ") [" 
                      << (tasks[i].completed ? "✔" : "✘") << "]\n";
        }
    }
};

int main() {
    TodoList todo;
    todo.addTask("Køb ind", "10-03-2025");
    todo.addTask("Lær C++", "15-03-2025");

    int choice, taskNumber;
    std::string newDesc, newDate;
    do {
        std::cout << "\n1. Markér opgave som fuldført\n";
        std::cout << "2. Slet opgave\n";
        std::cout << "3. Rediger opgave\n";
        std::cout << "4. Rediger forfaldsdato\n"; // Ny menuindstilling
        std::cout << "5. Vis alle opgaver\n";
        std::cout << "6. Afslut\n";
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
            std::cout << "Indtast nummer på opgaven at redigere forfaldsdato: ";
            std::cin >> taskNumber;
            std::cin.ignore();
            std::cout << "Indtast ny forfaldsdato (dd-mm-yyyy): ";
            std::getline(std::cin, newDate);
            todo.editTaskDueDate(taskNumber - 1, newDate);
            break;
        case 5:
            todo.viewAllTasks();
            break;
        }
    } while (choice != 6);

    return 0;
}

