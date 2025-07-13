#include <iostream>
#include <string>
#include <limits> // For numeric_limits
#include "waitingRoomImplementationInFIFO.h"

using namespace std;

void displayMenu() {
    cout << "\n=== Hospital Waiting Room Management System ===" << endl;
    cout << "1. Register Patient" << endl;
    cout << "2. Serve Patient" << endl;
    cout << "3. Show All Patients" << endl;
    cout << "4. Cancel All Appointments" << endl;
    cout << "5. Can Doctor Go Home?" << endl;
    cout << "6. Exit" << endl;
    cout << "================================================" << endl;
    cout << "Enter your choice: ";
}

int main() {
    // Create a waiting room with capacity for 10 patients
    HospitalWaitingRoom waitingRoom(5);
    
    int choice;
    string patientName;
    
    while (true) {
        displayMenu(); // reminder comment: Decide if we want it as a case
        cin >> choice;
        
        // I encoutered erro of infinite loop when entering a non-integer value, so this is to ensure that that does not happen
        if (cin.fail()) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input! Please enter a number.\n";
            continue; // or loop again
        }

        switch (choice) {
            case 1:
                cout << "Enter patient name: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, patientName);
                waitingRoom.RegisterPatient(patientName);
                break;
                
            case 2:
                waitingRoom.ServePatient();
                break;
                
            case 3:
                waitingRoom.ShowAllPatient();
                break;
                
            case 4:
                waitingRoom.CancelAll();
                break;
                
            case 5:
                waitingRoom.CanDoctorGoHome();
                break;
                
            case 6:
                cout << "Thank you for using the Hospital Waiting Room Management System!" << endl;
                return 0;
                
            default:
                cout << "Invalid choice! Please enter a number between 1 and 6." << endl;
                break;
        }
    }
    
    return 0;
}
