#pragma once

#include <iostream>
#include <string>

using namespace std;

class Patient {
private:
    int id;
    string name;
    static int nextId; // Static variable to auto-generate IDs

public:
    // Constructor
    Patient(const string& patientName) {
        id = nextId++;
        name = patientName;
    }

    // Default constructor
    Patient() {
        id = -1;
        name = "";
    }

    // Getters
    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    // Setters
    void setId(int patientId) {
        id = patientId;
    }

    void setName(const string& patientName) {
        name = patientName;
    }

    // Display patient information
    void displayPatient() const {
        cout << "ID: " << id << ", Name: " << name << endl;
    }

    // Static method to reset ID counter (useful for testing)
    static void resetIdCounter() {
        nextId = 1;
    }

    // Static method to get next ID without incrementing
    static int getNextId() {
        return nextId;
    }
};

// Initialize static variable
int Patient::nextId = 1;
