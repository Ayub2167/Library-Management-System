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

void addBook();

int main() {
    int choice;
    do {
        cout << "\n========== LIBRARY MANAGEMENT SYSTEM ==========\n";
        cout << "[1] Add Book\n";
        cout << "[2] Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: cout << "Exiting system!\n"; break;
            default: cout << "Invalid choice! Please try again.\n"; break;
        }
    } while (choice != 2);

    return 0;
}

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        cout << "Library is full. Cannot add more books.\n";
        return;
    }
    bookID[bookCount] = bookCount + 1;
    cout << "Enter Book Name: ";
    cin.ignore();
    getline(cin, bookName[bookCount]);
    cout << "Enter Author Name: ";
    getline(cin, authorName[bookCount]);
    cout << "Enter Shelf Number: ";
    cin >> shelfNumber[bookCount];
    cout << "Enter Price: ";
    cin >> price[bookCount];
    isIssued[bookCount] = false;
    cout << "Book Added Successfully with ID: " << bookID[bookCount] << "\n";
    bookCount++;
}
