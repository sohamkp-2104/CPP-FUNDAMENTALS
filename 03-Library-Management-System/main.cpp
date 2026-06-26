#include <iostream>
#include "Library.h"

using namespace std;

int main() {
    Library lib;

    // Add Books
    lib.addBook(Book(1, "C++ Basics", "Bjarne Stroustrup"));
    lib.addBook(Book(2, "Data Structures", "Mark Allen"));
    lib.addBook(Book(3, "DBMS", "Navathe"));

    // Add Members
    lib.addMember(Member(101, "Alice"));
    lib.addMember(Member(102, "Bob"));

    // Issue Books
    lib.issueBook(1, 101);
    lib.issueBook(2, 102);

    cout << "\n All Books:\n";
    lib.displayBooks();

    cout << "\n Search by Title (C++)\n";
    lib.searchByTitle("C++");

    cout << "\n Search by Author (Mark)\n";
    lib.searchByAuthor("Mark");

    // Return Book
    lib.returnBook(1, 101);

    cout << "\n After Return:\n";
    lib.displayBooks();

    return 0;
}