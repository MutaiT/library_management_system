#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "globals.h"
using namespace std;

std::vector<Book*> books;
std::vector<Member> members;

// Function Definitions
void addBook() {
    string title, author, ISBN, type, extra;
    cout << "Enter Book Title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter Author: ";
    getline(cin, author);
    cout << "Enter ISBN: ";
    cin >> ISBN;
    cout << "Enter Book Type (Fiction/NonFiction): ";
    cin >> type;

    if (type == "Fiction") {
        cout << "Enter Genre: ";
        cin.ignore();
        getline(cin, extra);
        books.push_back(new Fiction(title, author, ISBN, extra));
    } else if (type == "NonFiction") {
        cout << "Enter Subject: ";
        cin.ignore();
        getline(cin, extra);
        books.push_back(new NonFiction(title, author, ISBN, extra));
    } else {
        cout << "Invalid type!" << endl;
    }
}

void listBooks() {
    for (const auto& book : books) {
        book->displayDetails();
        cout << "-------------------" << endl;
    }
}

void addMember() {
    string id, name;
    cout << "Enter Member ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);

    members.push_back(Member(id, name));
}

void listMembers() {
    for (const auto& member : members) {
        member.displayDetails();
        cout << "-------------------" << endl;
    }
}

void borrowBook() {
    string memberID, ISBN;
    cout << "Enter Member ID: ";
    cin >> memberID;
    cout << "Enter Book ISBN: ";
    cin >> ISBN;

    Member* member = nullptr;
    Book* book = nullptr;

    for (auto& m : members) {
        if (m.getMemberID() == memberID) {
            member = &m;
            break;
        }
    }

    for (auto& b : books) {
        if (b->getISBN() == ISBN) {
            book = b;
            break;
        }
    }

    if (member && book && book->getAvailability()) {
        member->borrowBook(ISBN);
        book->setAvailability(false);
        cout << "Book borrowed successfully!" << endl;
    } else {
        cout << "Invalid Member ID, ISBN, or book not available!" << endl;
    }
}

void returnBook() {
    string memberID, ISBN;
    cout << "Enter Member ID: ";
    cin >> memberID;
    cout << "Enter Book ISBN: ";
    cin >> ISBN;

    Member* member = nullptr;
    Book* book = nullptr;

    for (auto& m : members) {
        if (m.getMemberID() == memberID) {
            member = &m;
            break;
        }
    }

    for (auto& b : books) {
        if (b->getISBN() == ISBN) {
            book = b;
            break;
        }
    }

    if (member && book) {
        member->returnBook(ISBN);
        book->setAvailability(true);
        cout << "Book returned successfully!" << endl;
    } else {
        cout << "Invalid Member ID or ISBN!" << endl;
    }
}

void saveBooks() {
    ofstream outFile("books.txt");
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }
    for (const auto& book : books) {
        Fiction* fictionBook = dynamic_cast<Fiction*>(book);
        NonFiction* nonFictionBook = dynamic_cast<NonFiction*>(book);

        if (fictionBook) {
            outFile << "Fiction," << fictionBook->getTitle() << "," 
                    << fictionBook->getAuthor() << "," 
                    << fictionBook->getISBN() << "," 
                    << fictionBook->getAvailability() << endl;
        } else if (nonFictionBook) {
            outFile << "NonFiction," << nonFictionBook->getTitle() << "," 
                    << nonFictionBook->getAuthor() << "," 
                    << nonFictionBook->getISBN() << "," 
                    << nonFictionBook->getAvailability() << endl;
        }
    }
    outFile.close();
}

void saveMembers() {
    ofstream outFile("members.txt");
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }
    for (const auto& member : members) {
        outFile << member.getMemberID() << "," 
                << member.getName() << ",";
        for (const string& bookISBN : member.getBorrowedBooks()) {
            outFile << bookISBN << ";";
        }
        outFile << endl;
    }
    outFile.close();
}

void loadBooks() {
    ifstream inFile("books.txt");
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }
    string type, title, author, ISBN, availability;
    while (getline(inFile, type, ',')) {
        getline(inFile, title, ',');
        getline(inFile, author, ',');
        getline(inFile, ISBN, ',');
        getline(inFile, availability);

        if (type == "Fiction") {
            books.push_back(new Fiction(title, author, ISBN, ""));
        } else if (type == "NonFiction") {
            books.push_back(new NonFiction(title, author, ISBN, ""));
        }
        books.back()->setAvailability(availability == "1");
    }
    inFile.close();
}

void loadMembers() {
    ifstream inFile("members.txt");
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) { // Read each line from the file
        stringstream ss(line);

        string id, name, borrowedBooks;
        // Extract ID and name with a comma delimiter
        getline(ss, id, ',');
        getline(ss, name, ',');

        // Extract the rest (borrowedBooks) as a single string
        getline(ss, borrowedBooks);

        Member member(id, name);

        // Split borrowedBooks by ';'
        stringstream booksStream(borrowedBooks);
        string bookISBN;
        while (getline(booksStream, bookISBN, ';')) {
            if (!bookISBN.empty()) {
                member.borrowBook(bookISBN);
            }
        }

        members.push_back(member);
    }

    inFile.close();
    cout << "Members loaded successfully!" << endl;
}

void showMenu() {
    cout << "Library Management System\n";
    cout << "1. Add Book\n";
    cout << "2. List Books\n";
    cout << "3. Add Member\n";
    cout << "4. List Members\n";
    cout << "5. Borrow Book\n";
    cout << "6. Return Book\n";
    cout << "7. Exit\n";
}

int main() {
    loadBooks();
    loadMembers();

    int choice;
    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1: addBook(); break;
                case 2: listBooks(); break;
                case 3: addMember(); break;
                case 4: listMembers(); break;
                case 5: borrowBook(); break;
                case 6: returnBook(); break;
                case 7:
                    saveBooks();
                    saveMembers();
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout << "Invalid choice! Try again." << endl;
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    } while (choice != 7);

    for (auto& book : books) {
        delete book;
    }

    return 0;
}
