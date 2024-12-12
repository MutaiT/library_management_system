#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
protected:
    string title;
    string author;
    string ISBN;
    bool isAvailable;

public:
    Book(string t, string a, string isbn);
    virtual ~Book();

    string getTitle() const;
    string getAuthor() const;
    string getISBN() const;
    bool getAvailability() const;

    void setAvailability(bool status);
    virtual void displayDetails() const = 0; // Pure virtual function
};

class Fiction : public Book
{
private:
    string genre;

public:
    Fiction(string t, string a, string isbn, string g);
    void displayDetails() const override;
};

class NonFiction : public Book
{
private:
    string subject;

public:
    NonFiction(string t, string a, string isbn, string s);
    void displayDetails() const override;
};

#endif
