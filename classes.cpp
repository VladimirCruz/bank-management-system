#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
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

//Maximum Heap functions
void maxHeap::heapifyUp(int i) {

    while(i > 0) {
        int parent = (i-1)/2;
        if(items[i].first > items[parent].first) {
            swapAndUpdate(i, parent);
            i = parent;
        } else break;
    }
}

void maxHeap::heapifyDown(int i) {
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
        swapAndUpdate(i, largest);
        i = largest;
    }
}

void maxHeap::insert(double bal, int id) {
    items.push_back({bal, id});
    int i = items.size() -1;
    idToIndex[id] = i;
    heapifyUp(i);
}

void maxHeap::extractMax() {
    int i = items.size()-1;

    swap(items[0], items[i]);
    items.pop_back();
    heapifyDown(0);

}

void maxHeap::swapAndUpdate(int a, int b) {
    swap(items[a], items[b]);
    idToIndex[items[a].second] = a;
    idToIndex[items[b].second] = b;
}

void maxHeap::updateKey(int id, double newBalance) {
    int i = idToIndex[id]; //idToIndex literally means "id leads to index"
    items[i].first = newBalance; //key of items[i] is now equal to the new balance
    heapifyUp(i);
    heapifyDown(i);
}

int maxHeap::getIndex(int id) {
    return idToIndex[id];
}

void maxHeap::removeByID(int id) {
    if(idToIndex.find(id) == idToIndex.end()) return;

    int i = idToIndex[id];
    int lastItem = items.size() - 1;

    if(i != lastItem) {
        swap(items[i], items[lastItem]);
        idToIndex[items[i].second] = i;
    }

    items.pop_back();
    idToIndex.erase(id);

    if(i < items.size()) {
        heapifyUp(i);
        heapifyDown(i);
    }
}

pair<double, int> maxHeap::viewMax() const {
    return items[0];
}

//Minimum Heap functions
void minHeap::heapifyUp(int i) {

    while(i > 0) {
        int parent = (i - 1) / 2;
        if(items[i] < items[parent]) {
            swapAndUpdate(i, parent);
            //Advance up
            i = parent;
        } else break;
    }
}

void minHeap::heapifyDown(int i) {
    while(i < items.size()) {

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
            swapAndUpdate(i, smallest);
            i = smallest;
        } else break;
    }
}

void minHeap::insert(double bal, int id) {
    items.push_back({bal, id});
    int i = items.size() - 1;
    idToIndex[id] = i;
    heapifyUp(i);
}

void minHeap::extractMin() {
    int i = items.size()-1;

    swap(items[0], items[i]);
    items.pop_back();
    heapifyDown(0);
}

void minHeap::swapAndUpdate(int a, int b) {
    swap(items[a], items[b]);
    idToIndex[items[a].second] = a;
    idToIndex[items[b].second] = b;
}

void minHeap::updateKey(int id, double newBalance) {
    int i = idToIndex[id];
    items[i].first = newBalance;
    heapifyUp(i);
    heapifyDown(i);
}

int minHeap::getIndex(int id) {
    return idToIndex[id];
}

void minHeap::removeByID(int id) {
    if(idToIndex.find(id)== idToIndex.end()) return;
    int i = idToIndex[id];
    int lastItem = items.size() - 1;

    if(i != lastItem) {
        swap(items[i], items[lastItem]);
        idToIndex[items[i].second] = i;
    }

    items.pop_back();
    idToIndex.erase(id);

    if(i < items.size()) {
        heapifyUp(i);
        heapifyDown(i);
    }
}

pair<double, int> minHeap::viewMin() const {
    return items[0];
}