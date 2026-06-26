#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <vector>
using namespace std;

class Member {
public:
    int memberId;
    string name;
    vector<int> borrowedBooks;

    Member() {}

    Member(int id, string n) {
        memberId = id;
        name = n;
    }

    void display() {
        cout << "[" << memberId << "] " << name << endl;
    }
};

#endif