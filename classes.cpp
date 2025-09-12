#include <iostream>
#include <vector>
#include <utility>
#include "classes.h"
using namespace std;

//Account Getters
int Account::getID() const {
    return id;
}
int Account::getRoutingNum() const {
    return routingNum;
}
int Account::getCheckingsNum() const{
    return checkingsNum;
}
int Account::getSavingsNum() const {
    return savingsNum;
}
const string& Account::getName() const {
    return name;
}

//Setter - Since other variables are likely not to change
string& Account::setName(const string& newName) {
    name = newName;
    return name;
}

double Account::getBalance() const {
    return balance;
}
void Account::setBalance(double amount) {
    balance = amount;
}

Account::Account(int id,
                int routingNum,
                int checkingsNum,
                int savingsNum,
                const string &name,
                double balance):
                id(id),
                routingNum(routingNum),
                checkingsNum(checkingsNum),
                savingsNum(savingsNum),
                name(name),
                balance(balance)
{}




//Customer goes here



//Transaction goes here



//Maximum Heap functions
void maxHeap::heapifyUp() {
    int i = items.size()-1;

    while(i > 0) {
        int parent = (i-1)/2;
        if(items[i].first > items[parent].first) {
            swap(items[i], items[parent]);
            i = parent;
        } else break;
    }
}

void maxHeap::heapifyDown() {
    if(items.size() < 2) return;
    int i = 0;

    while(true) {
        int largest = i;
        int l = left(i);
        int r = right(i);

        if(l < items.size() && items[l].first > items[largest].first) {
            largest = l;
        }
        if(r < items.size() && items[r].first > items[largest].first) {
            largest = r;
        }

        if(largest == i) break;
        swap(items[i], items[largest]);
        i = largest;
    }
}

void maxHeap::insert(double bal, int id) {
    items.push_back({bal, id});
    heapifyUp();
}

void maxHeap::extractMax() {
    int i = items.size()-1;

    swap(items[0], items[i]);
    items.pop_back();
    heapifyDown();

}

pair<double, int> maxHeap::viewMax() const {
    return items[0];
}



//Minimum Heap functions
void minHeap::heapifyUp() {
    int i = items.size() - 1;

    while(i > 0) {
        int parent = (i - 1) / 2;
        if(items[i] < items[parent]) {
            swap(items[i], items[parent]);
            //Advance up
            i = parent;
        } else break;
    }
}

void minHeap::heapifyDown() {
    if (items.size() < 2) return; //Structure is not large enough to do any meaningful processes
    int i = 0;

    while(i < items.size()-1) {

        int smallest = i; //smallest will be used to dictate which is the smallest of the 2 child nodes
        int l = left(i);
        int r = right(i);

        if(l < items.size() && items[l] < items[smallest]) {
            smallest = l;
        }
        if(r < items.size() && items[r] < items[smallest]) {
            smallest = r;
        }

        //If smallest is not i, then keep doing loop. Otherwise if it is, then the heap structure is satisfied
        if(smallest != i) {
            swap(items[i], items[smallest]);
            i = smallest;
        } else break;
    }
}

void minHeap::insert(double bal, int id) {
    items.push_back({bal, id});
    heapifyUp();
}

void minHeap::extractMin() {
    int i = items.size()-1;

    swap(items[0], items[i]);
    items.pop_back();
    heapifyDown();
}

pair<double, int> minHeap::viewMin() const {
    return items[0];
}