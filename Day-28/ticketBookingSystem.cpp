#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

struct train {
    int trainNumber;
    string trainName;
    string source;
    string destination;
    string departureTime;
    string arrivalTime;
    int availableSeats;
};

struct booking {
    int PNR;
    int trainNumber;
    string passengerName;
    int age;
};

//function prototypes
void addTrain(vector<train>& trains, const train& newTrain);
void viewTrainDetails(const vector<train>& trains, int trainNumber);
void bookTicket(vector<train>& trains, vector<booking>& bookings, int trainNumber, const string& passengerName, int age);
void cancelTicket(vector<train>& trains, vector<booking>& bookings, int PNR);
void loadTrainsFromFile(vector<train>& trains, const string& filename);
void loadBookingsFromFile(vector<booking>& bookings, const string& filename);
void saveTrainsToFile(const vector<train>& trains, const string& filename);
void saveBookingsToFile(const vector<booking>& bookings, const string& filename);


int main() {
    vector<train> trains;
    vector<booking> bookings;
    int choice;
    loadBookingsFromFile(bookings, "bookings.csv");
    loadTrainsFromFile(trains, "trains.csv");

    do {
        cout << "Train Ticket Booking System" << endl;
        cout << "1. Add Train" << endl;
        cout << "2. View Train Details" << endl;
        cout << "3. Book Ticket" << endl;
        cout << "4. Cancel Ticket" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                train newTrain;
                cout << "Enter Train Number: ";
                cin >> newTrain.trainNumber;
                cin.ignore(); // Clear newline character from input buffer
                cout << "Enter Train Name: ";
                getline(cin, newTrain.trainName);
                cout << "Enter Source: ";
                getline(cin, newTrain.source);
                cout << "Enter Destination: ";
                getline(cin, newTrain.destination);
                cout << "Enter Departure Time: ";
                getline(cin, newTrain.departureTime);
                cout << "Enter Arrival Time: ";
                getline(cin, newTrain.arrivalTime);
                cout << "Enter Available Seats: ";
                cin >> newTrain.availableSeats;

                addTrain(trains, newTrain);
                break;
            }
            case 2: {
                int trainNumber;
                cout << "Enter Train Number to view details: ";
                cin >> trainNumber;
                viewTrainDetails(trains, trainNumber);
                break;
            }
            case 3: {
                int trainNumber, age;
                string passengerName;
                cout << "Enter Train Number to book ticket: ";
                cin >> trainNumber;
                cin.ignore(); // Clear newline character from input buffer
                cout << "Enter Passenger Name: ";
                getline(cin, passengerName);
                cout << "Enter Age: ";
                cin >> age;

                bookTicket(trains, bookings, trainNumber, passengerName, age);
                break;
            }
            case 4: {
                int PNR;
                cout << "Enter PNR to cancel ticket: ";
                cin >> PNR;

                cancelTicket(trains, bookings, PNR);
                break;
            }
            case 5:
                cout << "Exiting the system." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    saveTrainsToFile(trains, "trains.csv");
    saveBookingsToFile(bookings, "bookings.csv");

}

void addTrain(vector<train>& trains, const train& newTrain) {
    trains.push_back(newTrain);
    cout << "Train added successfully." << endl;
}
void viewTrainDetails(const vector<train>& trains, int trainNumber) {
    for (const auto& t : trains) {
        if (t.trainNumber == trainNumber) {
            cout << "Train Number: " << t.trainNumber << endl;
            cout << "Train Name: " << t.trainName << endl;
            cout << "Source: " << t.source << endl;
            cout << "Destination: " << t.destination << endl;
            cout << "Departure Time: " << t.departureTime << endl;
            cout << "Arrival Time: " << t.arrivalTime << endl;
            cout << "Available Seats: " << t.availableSeats << endl;
            return;
        }
    }
    cout << "Train not found." << endl;
}

void bookTicket(vector<train>& trains, vector<booking>& bookings, int trainNumber, const string& passengerName, int age) {
    for (auto& t : trains) {
        if (t.trainNumber == trainNumber) {
            if (t.availableSeats > 0) {
                t.availableSeats--;
                booking newBooking;
                newBooking.PNR = bookings.size() + 1; // Simple PNR generation
                newBooking.trainNumber = trainNumber;
                newBooking.passengerName = passengerName;
                newBooking.age = age;
                bookings.push_back(newBooking);
                cout << "Ticket booked successfully. PNR: " << newBooking.PNR << endl;
            } else {
                cout << "No available seats on this train." << endl;
            }
            return;
        }
    }
    cout << "Train not found." << endl;
}

void cancelTicket(vector<train>& trains, vector<booking>& bookings, int PNR) {
    auto it = find_if(bookings.begin(), bookings.end(), [PNR](const booking& b) {
        return b.PNR == PNR;
    });

    if (it != bookings.end()) {
        for (auto& t : trains) {
            if (t.trainNumber == it->trainNumber) {
                t.availableSeats++;
                break;
            }
        }
        bookings.erase(it);
        cout << "Ticket canceled successfully." << endl;
    } else {
        cout << "Booking not found." << endl;
    }
}

void loadTrainsFromFile(vector<train>& trains, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        train t;
        getline(ss, line, ',');
        t.trainNumber = stoi(line);
        getline(ss, t.trainName, ',');
        getline(ss, t.source, ',');
        getline(ss, t.destination, ',');
        getline(ss, t.departureTime, ',');
        getline(ss, t.arrivalTime, ',');
        getline(ss, line);
        t.availableSeats = stoi(line);
        trains.push_back(t);
    }
    file.close();
}
void loadBookingsFromFile(vector<booking>& bookings, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        booking b;
        getline(ss, line, ',');
        b.PNR = stoi(line);
        getline(ss, line, ',');
        b.trainNumber = stoi(line);
        getline(ss, b.passengerName, ',');
        getline(ss, line);
        b.age = stoi(line);
        bookings.push_back(b);
    }
    file.close();
}
void saveTrainsToFile(const vector<train>& trains, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }

    for (const auto& t : trains) {
        file << t.trainNumber << ","
             << t.trainName << ","
             << t.source << ","
             << t.destination << ","
             << t.departureTime << ","
             << t.arrivalTime << ","
             << t.availableSeats
             << "\n";
    }
    file.close();
}
void saveBookingsToFile(const vector<booking>& bookings, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }
    for (const auto& b : bookings) {
        file << b.PNR << ","
             << b.trainNumber << ","
             << b.passengerName << ","
             << b.age
             << "\n";
    }
    file.close();
}
