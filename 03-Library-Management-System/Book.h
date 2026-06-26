#ifndef BOOK_H
#define BOOK_H

#include <iostream>
using namespace std;

class Book {
public:
    int bookId;
    string title;
    string author;
    bool isIssued;

    Book() {
        isIssued = false;
    }

    Book(int id, string t, string a) {
        bookId = id;
        title = t;
        author = a;
        isIssued = false;
    }

    void display() {
        cout << "[" << bookId << "] " << title << " by " << author;
        cout << " - " << (isIssued ? "Issued" : "Available") << endl;
    }
};

#endif