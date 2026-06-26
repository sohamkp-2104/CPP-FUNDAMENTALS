#include <iostream>
#include <fstream>
using namespace std;

class Student {
    int id;
    char name[50];
    int age;
    char course[50];

public:
    void getData() {
        cout << "\nEnter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Course: ";
        cin.ignore();
        cin.getline(course, 50);
    }

    void showData() {
        cout << "\nID: " << id;
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nCourse: " << course << endl;
    }

    int getId() {
        return id;
    }
};

// ADD STUDENT
void addStudent() {
    Student s;
    ofstream file("students.dat", ios::binary | ios::app);

    s.getData();
    file.write((char*)&s, sizeof(s));

    file.close();
    cout << "\nStudent added successfully!\n";
}

// DISPLAY ALL
void displayStudents() {
    Student s;
    ifstream file("students.dat", ios::binary);

    while (file.read((char*)&s, sizeof(s))) {
        s.showData();
        cout << "-------------------";
    }

    file.close();
}

// SEARCH & UPDATE
void updateStudent() {
    int id, found = 0;
    Student s;
    fstream file("students.dat", ios::binary | ios::in | ios::out);

    cout << "\nEnter ID to update: ";
    cin >> id;

    while (file.read((char*)&s, sizeof(s))) {
        if (s.getId() == id) {
            cout << "\nCurrent Record:";
            s.showData();

            cout << "\nEnter new details:\n";
            s.getData();

            int pos = (-1) * sizeof(s);
            file.seekp(pos, ios::cur);
            file.write((char*)&s, sizeof(s));

            cout << "\nRecord updated!";
            found = 1;
            break;
        }
    }

    if (!found)
        cout << "\nRecord not found!";

    file.close();
}

// DELETE STUDENT
void deleteStudent() {
    int id;
    Student s;
    ifstream file("students.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    cout << "\nEnter ID to delete: ";
    cin >> id;

    while (file.read((char*)&s, sizeof(s))) {
        if (s.getId() != id) {
            temp.write((char*)&s, sizeof(s));
        }
    }

    file.close();
    temp.close();

    remove("students.dat");
    rename("temp.dat", "students.dat");

    cout << "\nRecord deleted successfully!\n";
}

// MAIN MENU
int main() {
    int choice;

    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: updateStudent(); break;
            case 4: deleteStudent(); break;
            case 5: cout << "\nExiting...\n"; break;
            default: cout << "\nInvalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}