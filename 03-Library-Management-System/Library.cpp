#include "Library.h"

// Add Book
void Library::addBook(Book b) {
    books.push_back(b);
}

// Add Member
void Library::addMember(Member m) {
    members.push_back(m);
}

// Issue Book
void Library::issueBook(int bookId, int memberId) {
    for (auto &b : books) {
        if (b.bookId == bookId) {
            if (!b.isIssued) {
                for (auto &m : members) {
                    if (m.memberId == memberId) {
                        b.isIssued = true;
                        m.borrowedBooks.push_back(bookId);
                        cout << "Book issued successfully!\n";
                        return;
                    }
                }
            } else {
                cout << "Book already issued.\n";
                return;
            }
        }
    }
    cout << "Invalid Book or Member ID.\n";
}

// Return Book
void Library::returnBook(int bookId, int memberId) {
    for (auto &b : books) {
        if (b.bookId == bookId) {
            for (auto &m : members) {
                if (m.memberId == memberId) {
                    b.isIssued = false;

                    for (auto it = m.borrowedBooks.begin(); it != m.borrowedBooks.end(); it++) {
                        if (*it == bookId) {
                            m.borrowedBooks.erase(it);
                            break;
                        }
                    }

                    cout << "Book returned successfully!\n";
                    return;
                }
            }
        }
    }
    cout << "Invalid return request.\n";
}

// Search by Title
void Library::searchByTitle(string title) {
    for (auto &b : books) {
        if (b.title.find(title) != string::npos) {
            b.display();
        }
    }
}

// Search by Author
void Library::searchByAuthor(string author) {
    for (auto &b : books) {
        if (b.author.find(author) != string::npos) {
            b.display();
        }
    }
}

// Display Books
void Library::displayBooks() {
    for (auto &b : books) {
        b.display();
    }
}