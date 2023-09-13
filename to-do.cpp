#include <iostream>
#include <vector>
#include <string>

// Structure to represent a task
struct Task {
    std::string description;
    bool completed;
};

// Function to add a task to the list
void addTask(std::vector<Task>& taskList, const std::string& description) {
    Task task;
    task.description = description;
    task.completed = false;
    taskList.push_back(task);
    std::cout << "Task added: " << description << std::endl;
}

// Function to view all tasks
void viewTasks(const std::vector<Task>& taskList) {
    std::cout << "Task List:" << std::endl;
    for (size_t i = 0; i < taskList.size(); ++i) {
        std::cout << i + 1 << ". ";
        if (taskList[i].completed) {
            std::cout << "[X] ";
        } else {
            std::cout << "[ ] ";
        }
        std::cout << taskList[i].description << std::endl;
    }
}

// Function to mark a task as completed
void markTaskCompleted(std::vector<Task>& taskList, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= static_cast<int>(taskList.size())) {
        taskList[taskIndex - 1].completed = true;
        std::cout << "Task marked as completed: " << taskList[taskIndex - 1].description << std::endl;
    } else {
        std::cout << "Invalid task number. Please try again." << std::endl;
    }
}

// Function to remove a task
void removeTask(std::vector<Task>& taskList, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= static_cast<int>(taskList.size())) {
        std::cout << "Task removed: " << taskList[taskIndex - 1].description << std::endl;
        taskList.erase(taskList.begin() + taskIndex - 1);
    } else {
        std::cout << "Invalid task number. Please try again." << std::endl;
    }
}

int main() {
    std::vector<Task> taskList;

    while (true) {
        std::cout << "To-Do List Manager" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Quit" << std::endl;

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::cin.ignore(); // Clear the newline character from the buffer
            std::cout << "Enter task description: ";
            std::string description;
            std::getline(std::cin, description);
            addTask(taskList, description);
        } else if (choice == 2) {
            viewTasks(taskList);
        } else if (choice == 3) {
            viewTasks(taskList);
            std::cout << "Enter the task number to mark as completed: ";
            int taskIndex;
            std::cin >> taskIndex;
            markTaskCompleted(taskList, taskIndex);
        } else if (choice == 4) {
            viewTasks(taskList);
            std::cout << "Enter the task number to remove: ";
            int taskIndex;
            std::cin >> taskIndex;
            removeTask(taskList, taskIndex);
        } else if (choice == 5) {
            break; // Quit the program
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
