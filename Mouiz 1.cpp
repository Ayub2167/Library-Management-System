#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 100; 
int bookID[MAX_BOOKS];
string bookName[MAX_BOOKS];
string authorName[MAX_BOOKS];
int shelfNumber[MAX_BOOKS];
float price[MAX_BOOKS];
bool isIssued[MAX_BOOKS];
int bookCount = 0;

void displayBooks();

int main() {
    int choice;
    do {
        cout << "\n========== DISPLAY MODULE ==========\n";
        cout << "[1] Display All Books\n";
        cout << "[2] Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: displayBooks(); break;
            case 2: cout << "Exiting Display Module!\n"; break;
            default: cout << "Invalid choice! Please try again.\n"; break;
        }
    } while (choice != 2);

    return 0;
}

void displayBooks() {
    if (bookCount == 0) {
        cout << "No books available.\n";
        return;
    }
    cout << "\n======= ALL BOOKS =======\n";
    for (int i = 0; i < bookCount; i++) {
        cout << "Book ID: " << bookID[i] << "\n";
        cout << "Name: " << bookName[i] << "\n";
        cout << "Author: " << authorName[i] << "\n";
        cout << "Shelf: " << shelfNumber[i] << "\n";
        cout << "Price: " << price[i] << "\n";
        cout << "Issued: " << (isIssued[i] ? "Yes" : "No") << "\n";
        cout << "--------------------------\n";
    }
}
