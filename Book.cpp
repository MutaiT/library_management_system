#include "globals.h"
#include <iostream>
using namespace std;

// Base class constructor and methods
Book::Book(string t, string a, string isbn) : title(t), author(a), ISBN(isbn), isAvailable(true) {}

Book::~Book() {}

string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getISBN() const { return ISBN; }
bool Book::getAvailability() const { return isAvailable; }
void Book::setAvailability(bool status) { isAvailable = status; }

// Derived class constructors and methods
Fiction::Fiction(string t, string a, string isbn, string g) : Book(t, a, isbn), genre(g) {}
void Fiction::displayDetails() const {
    cout << "Title: " << title << "\nAuthor: " << author << "\nISBN: " << ISBN 
         << "\nAvailable: " << (isAvailable ? "Yes" : "No") << "\nGenre: " << genre << endl;
}

NonFiction::NonFiction(string t, string a, string isbn, string s) : Book(t, a, isbn), subject(s) {}
void NonFiction::displayDetails() const {
    cout << "Title: " << title << "\nAuthor: " << author << "\nISBN: " << ISBN 
         << "\nAvailable: " << (isAvailable ? "Yes" : "No") << "\nSubject: " << subject << endl;
}
