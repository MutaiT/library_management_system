#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>
using namespace std;

class Member {
private:
    string memberID;
    string name;
    vector<string> borrowedBooks;

public:
    Member(string id, string n);

    string getMemberID() const;
    string getName() const;
    vector<string> getBorrowedBooks() const;

    void borrowBook(const string& bookISBN);
    void returnBook(const string& bookISBN);
    void displayDetails() const;
};

#endif
