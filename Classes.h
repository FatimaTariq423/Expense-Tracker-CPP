#pragma once
#include <string>
#include <iostream>
using namespace std;

// Base Class
class Transaction {
protected:
    int id;
    string date;
    string description;

public:
    // Constructor
    Transaction(int i, string d, string desc) {
        id = i;
        date = d;
        description = desc;
    }

    virtual ~Transaction() {}

    string getDescription() { return description; }
    string getDate() { return date; }
};

// Derived Class
class Expense : public Transaction {
private:
    double amount;
    string category;

public:
    // Constructor
    Expense(int id, double a, string d, string desc, string cat) 
        : Transaction(id, d, desc) {
        amount = a;
        category = cat;
    }

    double getAmount() { return amount; }
    string getCategory() { return category; }
};