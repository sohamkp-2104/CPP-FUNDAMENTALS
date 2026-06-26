#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Member.h"
#include <vector>

class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:
    void addBook(Book b);
    void addMember(Member m);

    void issueBook(int bookId, int memberId);
    void returnBook(int bookId, int memberId);

    void searchByTitle(string title);
    void searchByAuthor(string author);

    void displayBooks();
};

#endif