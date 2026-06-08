#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student
{
public:
    int rollNo;
    string name;
    int age;
    string course;

    void addStudent()
    {
        ofstream file("students.txt", ios::app);

        cout << "\nEnter Roll No: ";
        cin >> rollNo;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();

        cout << "Enter Course: ";
        getline(cin, course);

        file << rollNo << "|"
             << name << "|"
             << age << "|"
             << course << endl;

        file.close();

        cout << "\nStudent Record Added Successfully!\n";
    }

    void displayStudents()
    {
        ifstream file("students.txt");

        string line;

        cout << "\n----- Student Records -----\n";

        while (getline(file, line))
        {
            cout << line << endl;
        }

        file.close();
    }

    void searchStudent()
    {
        int searchRoll;
        cout << "\nEnter Roll No to Search: ";
        cin >> searchRoll;

        ifstream file("students.txt");

        string line;
        bool found = false;

        while (getline(file, line))
        {
            int pos = line.find('|');
            int roll = stoi(line.substr(0, pos));

            if (roll == searchRoll)
            {
                cout << "\nRecord Found:\n";
                cout << line << endl;
                found = true;
                break;
            }
        }

        if (!found)
            cout << "\nRecord Not Found!\n";

        file.close();
    }

    void updateStudent()
    {
        int searchRoll;
        cout << "\nEnter Roll No to Update: ";
        cin >> searchRoll;
        cin.ignore();

        ifstream file("students.txt");
        ofstream temp("temp.txt");

        string line;
        bool found = false;

        while (getline(file, line))
        {
            int pos = line.find('|');
            int roll = stoi(line.substr(0, pos));

            if (roll == searchRoll)
            {
                found = true;

                cout << "\nEnter New Name: ";
                getline(cin, name);

                cout << "Enter New Age: ";
                cin >> age;
                cin.ignore();

                cout << "Enter New Course: ";
                getline(cin, course);

                temp << searchRoll << "|"
                     << name << "|"
                     << age << "|"
                     << course << endl;
            }
            else
            {
                temp << line << endl;
            }
        }

        file.close();
        temp.close();

        remove("students.txt");
        rename("temp.txt", "students.txt");

        if (found)
            cout << "\nRecord Updated Successfully!\n";
        else
            cout << "\nRecord Not Found!\n";
    }

    void deleteStudent()
    {
        int searchRoll;
        cout << "\nEnter Roll No to Delete: ";
        cin >> searchRoll;

        ifstream file("students.txt");
        ofstream temp("temp.txt");

        string line;
        bool found = false;

        while (getline(file, line))
        {
            int pos = line.find('|');
            int roll = stoi(line.substr(0, pos));

            if (roll == searchRoll)
            {
                found = true;
            }
            else
            {
                temp << line << endl;
            }
        }

        file.close();
        temp.close();

        remove("students.txt");
        rename("temp.txt", "students.txt");

        if (found)
            cout << "\nRecord Deleted Successfully!\n";
        else
            cout << "\nRecord Not Found!\n";
    }
};

int main()
{
    Student s;
    int choice;

    do
    {
        cout << "\n\n===== STUDENT MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Search Student";
        cout << "\n4. Update Student";
        cout << "\n5. Delete Student";
        cout << "\n6. Exit";
        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            s.addStudent();
            break;

        case 2:
            s.displayStudents();
            break;

        case 3:
            s.searchStudent();
            break;

        case 4:
            s.updateStudent();
            break;

        case 5:
            s.deleteStudent();
            break;

        case 6:
            cout << "\nThank You!";
            break;

        default:
            cout << "\nInvalid Choice!";
        }

    } while (choice != 6);

    return 0;
}