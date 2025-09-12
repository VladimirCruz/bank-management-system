#ifndef BANK_H
#define BANK_H

#include <unordered_map>
#include <vector>

#include "classes.h"

using namespace std;

extern unordered_map<int, Account> accounts;
extern minHeap minH;
extern maxHeap maxH;

//Checks for errors (invalid inputs)
void error();

//Menu for bank manager
void menu();

//Handles menu choice
void handleChoice(int c); //, unordered_map<double, Account>& accounts, minHeap& minH, maxHeap& maxH

//Admin can create account
void accountCreate();

//Admin can delete account
void accountDelete();

//Users can deposit money
void deposit();

//Users can withdraw money
int withdrawal();

//Transfer of money from one account, to another
int moneyTransfer();

//Displays recent transactions,
void accountReport();

//Admin tools

//Binary search for looking up accounts
void accountLookup();



//Helper functions
int mergeSort();

#endif //BANK_H