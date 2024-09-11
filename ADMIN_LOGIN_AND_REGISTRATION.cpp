//      TASK - 2
//      ADMIN LOGIN AND REGISTRATION SYSTEM

#include <iostream>
#include <fstream>    // For file handling
#include <string>
using namespace std;

// Function to register a new user
void registerUser() {
    string username, password;

    cout << "\n*** User Registration ***\n";
    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    // Appending user credentials to "users.txt"
    ofstream file("users.txt", ios::app);  // Open in append mode
    if (file.is_open()) {
        file << username << endl;
        file << password << endl;
        file.close();
        cout << "\nRegistration successful! You can now log in.\n";
    } else {
        cout << "\nError: Unable to open user file.\n";
    }
}

// Function to log in an existing user
bool loginUser() {
    string username, password, storedUsername, storedPassword;
    bool userFound = false;

    cout << "\n*** User Login ***\n";
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    // Reading credentials from "users.txt"
    ifstream file("users.txt");
    if (!file.is_open()) {
        cout << "\nError: Unable to open user file.\n";
        return false;
    }

    while (getline(file, storedUsername) && getline(file, storedPassword)) {
        if (storedUsername == username && storedPassword == password) {
            userFound = true;
            break;
        }
    }
    file.close();

    if (userFound) {
        cout << "\nLogin successful! Welcome, " << username << ".\n";
        return true;
    } else {
        cout << "\nError: Incorrect username or password.\n";
        return false;
    }
}

int main() {
    int choice;
    bool loggedIn = false;

    // Displaying a welcome message
    cout << "===============================================\n";
    cout << "       Welcome to the Admin Login System        \n";
    cout << "===============================================\n\n";

    // Main menu for user actions
    while (!loggedIn) {
        cout << "\nPlease choose an option:\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loggedIn = loginUser();
                break;
            case 3:
                cout << "\nExiting the program. Goodbye!\n";
                return 0;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    }

    // Message after successful login
    cout << "\n===============================================\n";
    cout << "       Thank you for using the Admin System!    \n";
    cout << "===============================================\n";

    return 0;
}
