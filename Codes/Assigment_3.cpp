#include <iostream>
#include <string>

const int MAX_STUDENTS = 100;

// Struct to store student information
struct Student {
    std::string nim;
    std::string name;
    int age;
};

// Function to add a new student to the array
void addStudent(Student students[], int& numStudents) {
    if (numStudents < MAX_STUDENTS) {
        Student newStudent;
        std::cout << "Enter NIM: ";
        std::cin >> newStudent.nim;
        std::cout << "Enter Name: ";
        std::cin >> newStudent.name;
        std::cout << "Enter Age: ";
        std::cin >> newStudent.age;
        
        students[numStudents] = newStudent;
        numStudents++;
        std::cout << "Student added successfully." << std::endl;
    } else {
        std::cout << "Maximum number of students reached." << std::endl;
    }
}

// Function to search for a student by NIM using linear search
void searchStudentByNIM(const Student students[], int numStudents, const std::string& targetNIM) {
    bool found = false;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].nim == targetNIM) {
            std::cout << "Student Found:" << std::endl;
            std::cout << "NIM: " << students[i].nim << std::endl;
            std::cout << "Name: " << students[i].name << std::endl;
            std::cout << "Age: " << students[i].age << std::endl;
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Student with NIM " << targetNIM << " not found." << std::endl;
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int numStudents = 0;
    
    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add Student" << std::endl;
        std::cout << "2. Search Student by NIM" << std::endl;
        std::cout << "3. Exit" << std::endl;
        int choice;
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                addStudent(students, numStudents);
                break;
            case 2:
                std::cout << "Enter NIM to search: ";
                std::string searchNIM;
                std::cin >> searchNIM;
                searchStudentByNIM(students, numStudents, searchNIM);
                break;
            case 3:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
    
    return 0;
}
