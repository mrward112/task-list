#include <iostream>
#include <string>
#include <vector>

class ToDoList {
private:
    std::vector<std::string> tasks;

public:
    void addTask(const std::string& task) {
        tasks.push_back(task);
        std::cout << "Task added: " << task << std::endl;
    }


    void removeTask(int index) {
        if (index < 0 || index >= tasks.size()) {
            std::cout << "Invalid task index!" << std::endl;
            return;
        }
        std::cout << "Task removed: " << tasks[index] << std::endl;
        tasks.erase(tasks.begin() + index);
    }

    void displayTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks to display!" << std::endl;
            return;
        }

        std::cout << "Tasks:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i << ": " << tasks[i] << std::endl;
        }
    }

    void accessTask(int index) const {
        if (index < 0 || index >= tasks.size()) {
            std::cout << "Invalid task index!" << std::endl;
            return;
        }
        std::cout << "Task at index " << index << ": " << tasks[index] << std::endl;
    }
};

int main() {
    ToDoList toDoList;
    int choice;
    std::string task;
    int index;

    while (true) {
        std::cout << "\nTo-Do List Menu:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Remove Task\n";
        std::cout << "3. Display Tasks\n";
        std::cout << "4. Access Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter the task: ";
            std::cin.ignore(); // Ignore the newline character left by std::cin
            std::getline(std::cin, task);
            toDoList.addTask(task);
            break;
        case 2:
            std::cout << "Enter the task index to remove: ";
            std::cin >> index;
            toDoList.removeTask(index);
            break;
        case 3:
            toDoList.displayTasks();
            break;
        case 4:
            std::cout << "Enter the task index to access: ";
            std::cin >> index;
            toDoList.accessTask(index);
            break;
        case 5:
            std::cout << "Exiting..." << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice! Please try again." << std::endl;
        }
    }
}
