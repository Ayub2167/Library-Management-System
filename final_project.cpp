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
void displayBooks();
void searchBookByID();
void issueBook();
void returnBook();
void searchBooksByShelf();

int main() {
    int choice;
    do {
        cout << "\n========== LIBRARY MANAGEMENT SYSTEM ==========\n";
        cout<<"Enter the numbers 1-7 for your preffered option."<<endl;
        cout << "[1] Add Book"<<endl;
        cout << "[2] Display All Books"<<endl;
        cout << "[3] Search Book by ID"<<endl;
        cout << "[4] Issue a Book"<<endl;
        cout << "[5] Return a Book"<<endl;
        cout << "[6] Search Books by Shelf"<<endl;
        cout << "[7] Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); 
            break;
            case 2: displayBooks(); 
            break;
            case 3: searchBookByID(); 
            break;
            case 4: issueBook(); 
            break;
            case 5: returnBook(); 
            break;
            case 6: searchBooksByShelf(); 
            break;
            case 7: cout << "Exiting system!"<<endl;
            break;
            default: cout << "Invalid choice! Please try again."<<endl;
            break;
        }
    } while (choice != 7);

    system("pause");
    return 0;
}

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        cout << "Library is full. Cannot add more books."<<endl;
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
    cout << "Book Added Successfully with ID: " << bookID[bookCount] <<endl;
    bookCount++;
}

void displayBooks() {
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

void searchBookByID() {
    int searchID;
    cout << "Enter Book ID: ";
    cin >> searchID;
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (bookID[i] == searchID) {
            cout << "Book Found:\n";
            cout << "Name: " << bookName[i] << ", Author: " << authorName[i] << "\n";
            found = true;
            break;
        }
    }
    if (!found) cout << "Nope, no such book in here.\n";
}

void issueBook() {
    int searchID;
    cout << "Enter Book ID to issue: ";
    cin >> searchID;
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (bookID[i] == searchID) {
            if (!isIssued[i]) {
                isIssued[i] = true;
                cout << "Book issued successfully.\n";
            } else {
                cout << "Book is already issued.\n";
            }
            found = true;
            break;
        }
    }
    if (!found) cout << "Nope, no such book in here.\n";
}

void returnBook() {
    int searchID;
    cout << "Enter Book ID to return: ";
    cin >> searchID;
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (bookID[i] == searchID) {
            if (isIssued[i]) {
                isIssued[i] = false;
                cout << "Book returned successfully.\n";
            } else {
                cout << "Book was not issued.\n";
            }
            found = true;
            break;
        }
    }
    if (!found) cout << "Nope, no such book in here.\n";
}

void searchBooksByShelf() {
    int searchShelf;
    cout << "Enter Shelf Number: ";
    cin >> searchShelf;
    cout << "\nBooks on Shelf " << searchShelf << ":\n";
    for (int i = 0; i < bookCount; i++) {
        if (shelfNumber[i] == searchShelf) {
            cout << bookName[i] << " by " << authorName[i] << "\n";
        }
    }
}
