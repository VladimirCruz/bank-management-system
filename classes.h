#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <ctime>

using namespace std;

class Account {
    private:
    int id;                 //Immutable
    int routingNum;         //Immutable
    int checkingsNum;       //Immutable
    int savingsNum;         //Immutable
    string name;            //Mutable

    double balance;         //Mutable

    public:
    Account() = default;
    Account(int id, int routingNum, int checkingsNum, int savingsNum, const string& name, double balance);

    //Getters
    int getID() const;
    int getRoutingNum() const;
    int getCheckingsNum() const;
    int getSavingsNum() const;
    const string& getName() const;

    //Setter - Since other variables are likely not to change
    string& setName(const string& newName);

    double getBalance() const;
    void setBalance(double amount);

};

class Customer {
private:
    string name;
    string address;
    string email;
    string DOB; //date of birth
    int phoneNumber;

    vector<Account> account;

public:

    //Constructor
    Customer(string& name, string& address, string& email, const string& DOB, int phoneNumber);

    //Getters
    string getName();
    string getEmail();
    int getPhoneNumber();

    //Setters
    string setName();
    string setEmail();
    int setPhoneNumber();

};

class maxHeap {

    private:
    vector<pair<double, int>> items; //balance, id
    unordered_map<int, int> idToIndex;

    //TO-DO
    //Transaction class goes here

    void heapifyUp(int i);
    void heapifyDown(int i);
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i) + 1; }
    int right(int i) { return (2 * i) + 2; }

    void swapAndUpdate(int a, int b);

    public:

    //TO-DO
    void insert(double bal, int id);
    void extractMax();
    void updateKey(int id, double newBalance);
    int getIndex(int id);
    void removeByID(int id);
    pair<double, int> viewMax() const;
};

class minHeap {

    private:
    vector<pair<double, int>> items; //balance, id
    unordered_map<int, int> idToIndex;

    //TO-DO
    //Transaction class goes here

    void heapifyUp(int i);
    void heapifyDown(int i);
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i) + 1; }
    int right(int i) { return (2 * i) + 2; }

    void swapAndUpdate(int a, int b);

    public:

    //Any user input goes in public. Private is only for things not controlled by user.
    void insert(double bal, int id); //O(logn)
    void extractMin(); //O(logn)
    void updateKey(int id, double newBalance);
    int getIndex(int id);
    void removeByID(int id);
    pair<double, int> viewMin() const; //O(1)

};

#endif //CLASSES_H
