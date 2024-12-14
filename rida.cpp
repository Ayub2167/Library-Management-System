#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 100; 
int bookID[MAX_BOOKS];
bool isIssued[MAX_BOOKS];
int shelfNumber[MAX_BOOKS];
string bookName[MAX_BOOKS];
string authorName[MAX_BOOKS];
int bookCount = 0;

void returnBook();
void searchBooksByShelf();

int main() {
    int choice;
    do {
        cout << "\n========== RETURN AND SEARCH BY SHELF MODULE ==========\n";
        cout << "[1] Return a Book\n";
        cout << "[2] Search Books by Shelf\n";
        cout << "[3] Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: returnBook(); break;
            case 2: searchBooksByShelf(); break;
            case 3: cout << "Exiting Module!\n"; break;
            default: cout << "Invalid choice! Please try again.\n"; break;
        }
    } while (choice != 3);

    return 0;
}

void returnBook() {
    int searchID;
    cout << "Enter Book ID to return: ";
    cin >> searchID;
    for (int i = 0; i < bookCount; i++) {
        if (bookID[i] == searchID) {
            if (isIssued[i]) {
                isIssued[i] = false;
                cout << "Book returned successfully.\n";
                return;
            } else {
                cout << "Book was not issued.\n";
                return;
            }
        }
    }
    cout << "Book not found.\n";
}

void searchBooksByShelf() {
    int searchShelf;
    cout << "Enter Shelf Number: ";
    cin >> searchShelf;
    cout << "Books on Shelf " << searchShelf << ":\n";
    for (int i = 0; i < bookCount; i++) {
        if (shelfNumber[i] == searchShelf) {
            cout << bookName[i] << " by " << authorName[i] << "\n";
        }
    }
}
