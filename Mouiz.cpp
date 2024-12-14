#include <iostream>
#include <string>
using namespace std;

extern const int MAX_BOOKS;
extern int bookID[];
extern string bookName[];
extern string authorName[];
extern int shelfNumber[];
extern int bookCount;

void searchBookByID();
void searchBooksByShelf();

int main() {
    int choice;
    do {
        cout << "\n==== SEARCH BOOKS ====\n";
        cout << "1. Search Book by ID\n2. Search Books by Shelf\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: searchBookByID(); break;
            case 2: searchBooksByShelf(); break;
            case 3: cout << "Exiting Search Module...\n"; break;
            default: cout << "Invalid choice! Try again.\n"; break;
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
