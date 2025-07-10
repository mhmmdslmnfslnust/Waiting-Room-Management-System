#pragma once

#include <iostream>
#include <string>
#include "Patient.h"

using namespace std;

class HospitalWaitingRoom {
private:
    int front;
    int rear;
    int capacity;
    Patient* patients;

public:
    HospitalWaitingRoom(int size) {
        front = 0;
        rear = 0;
        capacity = size;
        patients = new Patient[capacity];
    }

    // Destructor to free allocated memory
    ~HospitalWaitingRoom() {
        delete[] patients;
    }

    // RegisterPatient(): Assigns an ID to a patient and registers them
    void RegisterPatient(const string& patientName) {
        // If rear reaches capacity, try to shift the queue
        if (rear == capacity) {
            if (front == 0) {
                // No space available even after potential shifting
                cout << "Hospital is full! Cannot register more patients." << endl;
                cout << "Current capacity: " << capacity << ", All positions occupied." << endl;
                return;
            }
            
            // Shift all patients to the beginning of the array
            cout << "Queue is full at the end, shifting patients to make space..." << endl;
            int numPatients = getWaitingCount();
            for (int i = 0; i < numPatients; i++) {
                patients[i] = patients[front + i];
            }
            front = 0;
            rear = numPatients;
            cout << "Queue shifted successfully. " << numPatients << " patients moved to beginning." << endl;
        }

        // Actual registration of the new patient
        Patient newPatient(patientName);
        patients[rear] = newPatient;
        rear++;
        cout << "Patient registered successfully! ID: " << newPatient.getId() 
             << ", Name: " << newPatient.getName() << endl;
        cout << "Queue status: " << getWaitingCount() << "/" << capacity << " patients waiting." << endl;
    }

    // ServePatient(): Calls the next patient for service
    void ServePatient() {
        if (isEmpty()) {
            cout << "No patients waiting!" << endl;
            return;
        }
        
        Patient servedPatient = patients[front];
        front++;
        cout << "Now serving patient - ID: " << servedPatient.getId() 
             << ", Name: " << servedPatient.getName() << endl;
        cout << "Queue status: " << getWaitingCount() << "/" << capacity << " patients waiting." << endl;
    }

    // CancelAll(): Cancels all appointments so doctor can go to lunch
    void CancelAll() {
        if (isEmpty()) {
            cout << "No appointments to cancel." << endl;
            return;
        }
        
        cout << "Cancelling all appointments..." << endl;
        int cancelledCount = getWaitingCount();
        front = rear = 0; // Restting the queue, [will overrite previous patients]]
        cout << "Cancelled " << cancelledCount  << endl;
    }

    // CanDoctorGoHome(): Returns true if no one is waiting
    bool CanDoctorGoHome() {
        bool canGoHome = (isEmpty());
        if (canGoHome) {
            cout << "Doctor can go home! No patients waiting." << endl; // reminder comment: I might add this in main
        } else {
            cout << "Doctor cannot go home yet. " << getWaitingCount() << " patient(s) still waiting." << endl;
        }
        return canGoHome;
    }

    // ShowAllPatient(): Shows all waiting patients in queue order (first come, first served)
    void ShowAllPatient() {
        if (isEmpty()) {
            cout << "No patients waiting!" << endl;
            return;
        }

        cout << "\n=== Waiting Patients (Queue Order) ===" << endl;
        cout << "Queue status: " << getWaitingCount() << "/" << capacity << " patients waiting." << endl;
        for (int i = front; i < rear; i++) {
            cout << "Position " << (i - front + 1) << ": ";
            patients[i].displayPatient();
        }
        cout << "======================================" << endl;
    }

    // Utility methods
    bool isEmpty() const {
        return front == rear;
    }

    bool isFull() const {
        return rear == capacity;
    }

    int getWaitingCount() const {
        return rear - front;
    }
};
