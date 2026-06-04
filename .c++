#include <iostream>
#include <string>
using namespace std;

struct Passenger {
    int ticketNo;
    string name;
    int age;
    string source;
    string destination;
    Passenger* next;
};

class TrainBooking {
private:
    Passenger* head;
    int ticketCounter;

public:
    TrainBooking() {
        head = NULL;
        ticketCounter = 1001;
    }

    void bookTicket() {
        Passenger* newPassenger = new Passenger();

        newPassenger->ticketNo = ticketCounter++;

        cout << "\nEnter Name: ";
        cin.ignore();
        getline(cin, newPassenger->name);

        cout << "Enter Age: ";
        cin >> newPassenger->age;

        cout << "Enter Source Station: ";
        cin >> newPassenger->source;

        cout << "Enter Destination Station: ";
        cin >> newPassenger->destination;

        newPassenger->next = NULL;

        if (head == NULL) {
            head = newPassenger;
        } else {
            Passenger* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newPassenger;
        }

        cout << "\nTicket Booked Successfully!";
        cout << "\nTicket Number: " << newPassenger->ticketNo << endl;
    }

    void displayTickets() {
        if (head == NULL) {
            cout << "\nNo Bookings Found!\n";
            return;
        }

        Passenger* temp = head;

        cout << "\n--- Booked Tickets ---\n";
        while (temp != NULL) {
            cout << "\nTicket No: " << temp->ticketNo;
            cout << "\nName: " << temp->name;
            cout << "\nAge: " << temp->age;
            cout << "\nFrom: " << temp->source;
            cout << "\nTo: " << temp->destination;
            cout << "\n----------------------\n";

            temp = temp->next;
        }
    }

    void cancelTicket(int ticketNo) {
        if (head == NULL) {
            cout << "\nNo Tickets Available!\n";
            return;
        }

        Passenger* temp = head;
        Passenger* prev = NULL;

        while (temp != NULL && temp->ticketNo != ticketNo) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "\nTicket Not Found!\n";
            return;
        }

        if (prev == NULL)
            head = temp->next;
        else
            prev->next = temp->next;

        delete temp;

        cout << "\nTicket Cancelled Successfully!\n";
    }
};

int main() {
    TrainBooking tb;
    int choice, ticketNo;

    do {
        cout << "\n===== Train Ticket Booking System =====";
        cout << "\n1. Book Ticket";
        cout << "\n2. View Tickets";
        cout << "\n3. Cancel Ticket";
        cout << "\n4. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            tb.bookTicket();
            break;

        case 2:
            tb.displayTickets();
            break;

        case 3:
            cout << "Enter Ticket Number: ";
            cin >> ticketNo;
            tb.cancelTicket(ticketNo);
            break;

        case 4:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}
