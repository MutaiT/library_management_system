#include "globals.h"
#include <iostream>
#include <algorithm>
using namespace std;

Member::Member(string id, string n) : memberID(id), name(n) {}

string Member::getMemberID() const { return memberID; }
string Member::getName() const { return name; }
vector<string> Member::getBorrowedBooks() const { return borrowedBooks; }

void Member::borrowBook(const string& bookISBN) {
    borrowedBooks.push_back(bookISBN);
}

void Member::returnBook(const string& bookISBN) {
    borrowedBooks.erase(remove(borrowedBooks.begin(), borrowedBooks.end(), bookISBN), borrowedBooks.end());
}

void Member::displayDetails() const {
    cout << "Member ID: " << memberID << "\nName: " << name << "\nBorrowed Books: ";
    for (const string& book : borrowedBooks) {
        cout << book << " ";
    }
    cout << endl;
}
