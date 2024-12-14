#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 100; 
int bookID[MAX_BOOKS];
bool isIssued[MAX_BOOKS];
string bookName[MAX_BOOKS];
string authorName[MAX_BOOKS];
int bookCount = 0;

void searchBookByID();
void issueBook();

int main() {
    int choice;
    do {
        cout << "\n========== SEARCH AND ISSUE MODULE ==========\n";
        cout << "[1] Search Book by ID\n";
        cout << "[2] Issue a Book\n";
        cout << "[3] Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: searchBookByID(); break;
            case 2: issueBook(); break;
            case 3: cout << "Exiting Module!\n"; break;
            default: cout << "Invalid choice! Please try again.\n"; break;
        }
    } while (choice != 3);

    return 0;
}

void searchBookByID() {
    int searchID;
    cout << "Enter Book ID: ";
    cin >> searchID;
    for (int i = 0; i < bookCount; i++) {
        if (bookID[i] == searchID) {
            cout << "Book Found:\n";
            cout << "Name: " << bookName[i] << ", Author: " << authorName[i] << "\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void issueBook() {
    int searchID;
    cout << "Enter Book ID to issue: ";
    cin >> searchID;
    for (int i = 0; i < bookCount; i++) {
        if (bookID[i] == searchID) {
            if (!isIssued[i]) {
                isIssued[i] = true;
                cout << "Book issued successfully.\n";
                return;
            } else {
                cout << "Book is already issued.\n";
                return;
            }
        }
    }
    cout << "Book not found.\n";
}
