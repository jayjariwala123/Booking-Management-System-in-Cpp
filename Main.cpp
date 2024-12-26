#include <iostream>
#include <fstream>
#include <string>
#include "Train.h"
#include "Bus.h"
#include "Flight.h"

using namespace std;

void login();
void signup();
void viewBookings();
void saveBooking(const string &username, const string &transportType);

string current_user; // To keep track of logged-in user

int main() {
    int choice;

    cout << "Welcome to the Transport Booking System" << endl;
    cout << "1. Login" << endl;
    cout << "2. Signup" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        login();
    } else if (choice == 2) {
        signup();
    } else {
        cout << "Invalid choice" << endl;
        return 0;
    }

    if (current_user.empty()) {
        cout << "Authentication failed." << endl;
        return 0;
    }

    // After successful login, allow the user to view bookings or proceed to transport selection
    int action_choice;
    cout << "\n1. View Bookings" << endl;
    cout << "2. Book Transport" << endl;
    cout << "Enter your choice: ";
    cin >> action_choice;

    if (action_choice == 1) {
        viewBookings();
        return 0;
    }

    // Allow the user to choose the transport type for booking
    int transport_choice;
    cout << "\nChoose a mode of transport:" << endl;
    cout << "1. Train" << endl;
    cout << "2. Bus" << endl;
    cout << "3. Flight" << endl;
    cout << "Enter your choice: ";
    cin >> transport_choice;

    switch (transport_choice) {
        case 1:
            Train::bookTrainTicket();
            saveBooking(current_user, "Train");
            break;
        case 2:
            Bus::bookBusTicket();
            saveBooking(current_user, "Bus");
            break;
        case 3:
            Flight::bookFlightTicket();
            saveBooking(current_user, "Flight");
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }

    return 0;
}

void login() {
    string username, password, file_username, file_password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream usersFile("users.txt");

    bool found = false;
    while (usersFile >> file_username >> file_password) {
        if (file_username == username && file_password == password) {
            found = true;
            break;
        }
    }

    usersFile.close();

    if (found) {
        current_user = username;
        cout << "Login successful!" << endl;
    } else {
        cout << "Invalid username or password." << endl;
    }
}

void signup() {
    string username, password;
    cout << "Create username: ";
    cin >> username;
    cout << "Create password: ";
    cin >> password;

    ofstream usersFile("users.txt", ios::app);  // Append new users to the file
    usersFile << username << " " << password << endl;
    usersFile.close();

    cout << "Signup successful!" << endl;
    current_user = username;
}

void saveBooking(const string &username, const string &transportType) {
    ofstream bookingsFile("bookings.txt", ios::app);
    bookingsFile << username << " booked " << transportType << endl;
    bookingsFile.close();
}

void viewBookings() {
    string line;
    ifstream bookingsFile("bookings.txt");

    cout << "\nYour bookings:\n";
    bool found = false;
    while (getline(bookingsFile, line)) {
        if (line.find(current_user) != string::npos) {
            cout << line << endl;
            found = true;
        }
    }

    bookingsFile.close();

    if (!found) {
        cout << "No bookings found." << endl;
    }
}
