#include <iostream>
#include <unordered_map>
#include <ctime>
#include "bank.h"
#include "classes.h"

unordered_map<int, Account> accounts;
minHeap minH;
maxHeap maxH;

//User functions
void error();

// void updateKey(int accountID, int newBalance) {
//     int i = idToIndex[accountID];
//     items[i].first = newBalance;
//
// }

void accountCreate() {
    string name;
    int id, routingNum, checkingsNum, savingsNum;

    cout << "Name: ";
    cin >> name;

    cout << "\nID: ";
    cin >> id;

    cout << "\nRouting Number: ";
    cin >> routingNum;

    cout << "\nCheckings Account Number: ";
    cin >> checkingsNum;

    cout << "\nSavings Account Number: ";
    cin >> savingsNum;

    double balance = 0; //Automatically set to 0

    Account newAcct(id, routingNum, checkingsNum, savingsNum, name, balance);

    accounts.emplace(id, newAcct);
    minH.insert(balance, id);
    maxH.insert(balance, id);

    time_t now = time(nullptr);

    cout << "\nCreated Account:" << endl;
    cout << ctime(&now) << endl;
}

void accountDelete(int accountID) {
    if(accounts.find(accountID) == accounts.end()) {
        cout << "Account was not found." << endl;
        return;
    }

    minH.removeByID(accountID);
    maxH.removeByID(accountID);
    accounts.erase(accountID);

    cout << "Account " << accountID << " successfully deleted." << endl;;
}

void deposit(int accountID, double depositAmount) {

    auto it = accounts.find(accountID);
    if(it == accounts.end()) {
        cout << "Account was not found." << endl;
        return;
    }

    if(depositAmount <= 0) {
        cout << "Invalid amount." << endl;
        return;
    }

    Account& acct = it->second; //we want iterator to point to balance amount
    double oldBalance = acct.getBalance();
    double newBalance = oldBalance + depositAmount;
    acct.setBalance(newBalance);

    //updateKey updates the balances so that minHeap and maxHeap are accurate
    maxH.updateKey(accountID, newBalance);
    minH.updateKey(accountID, newBalance);

    time_t now = time(nullptr);

    cout << "A deposit was made to your account." << ctime(&now) << endl;
    cout << "Your current balance is: $" << newBalance << endl;
}

void withdrawal(int accountID, int withdrawAmount) {
    auto it = accounts.find(accountID);

    if(it == accounts.end()) {
        cout << "Account not found" << endl;
        return;
    }

    Account& acct = it->second; //Want balance so point to second
    double oldBalance = acct.getBalance();

    if(withdrawAmount <= 0 || withdrawAmount > oldBalance) {
        cout << "Withdraw amount must be a valid amount." << endl;
        return;
    }

    double newBalance = oldBalance - withdrawAmount;
    acct.setBalance(newBalance);

    //Update heaps accordingly
    maxH.updateKey(accountID, newBalance);
    minH.updateKey(accountID, newBalance);

    time_t now = time(nullptr);

    cout << "A withdraw was made to your account." << ctime(&now) << endl;
    cout << "Your current balance is: $" << newBalance << endl;
}

/*
int moneyTransfer(int accountNum, double amount) { //double amount

    //Takes in value, checks to see if account exists or not
    //Should just be a hashmap
    if(accounts.find(accountNum)) { //if(hashmap[accountNum])
        originalAccount -= amount;
        newAccount += amount;
    } else {
        cout << "This account does not exist." << endl;
    }
}
*/

void accountReport();



//Admin tools
void accountLookup() {
    int accountID;
    cout << "Account ID: ";
    cin >> accountID;

    double bal = 0; //accounts.find()

    if(accounts.find(accountID) != accounts.end()) {
        const Account& acct = accounts.find(accountID)->second;

        cout << "\nAccount Information: " << endl;
        cout << "ID: " << acct.getID() << endl;
        cout << "Name: " << acct.getName() << endl;
        cout << "Routing: #" << acct.getRoutingNum() << endl;
        cout << "Checkings: #" << acct.getCheckingsNum() << endl;
        cout << "Savings: #" << acct.getSavingsNum() << endl;
        cout << "Balance: $" << acct.getBalance() << endl;
    } else {
        cout << "Account not found." << endl;
    }
}

void menu() {
    cout << "1. Create Account" << endl;
    cout << "2. Delete Account" << endl;
    cout << "3. Deposit" << endl;
    cout << "4. Withdraw" << endl;
    cout << "5. Account Lookup" << endl;
    cout << "6. Account with Least Money using minHeap" << endl;
    cout << "7. Account with Most Money using maxHeap" << endl;
    //cout << "8. Top Accounts with Most Money" << endl;
    //Top Accounts with Least Money wouldn't be useful to the bank so don't include
    cout << "8. Exit System" << endl;
}

void handleChoice(int c) { //, unordered_map<double, Account>& accounts, minHeap& minH, maxHeap& maxH
    switch (c) {
        case 1: {
            accountCreate();
            break;
        }
        case 2: {
            int accountID;
            cout << "Enter ID:" << endl;
            cin >> accountID;

            accountDelete(accountID);
            break;
        }
        case 3: { //deposit
            int accountID;
            int depositAmount;

            cout << "Enter ID: ";
            cin >> accountID;

            cout << "\nEnter deposit amount: ";
            cin >> depositAmount;

            deposit(accountID, depositAmount);
            break;
        }
        case 4: {
            int accountID;
            int withdrawAmount;

            cout << "Enter ID: ";
            cin >> accountID;

            const Account& acct = accounts.find(accountID)->second;
            cout << "Current balance: $" << acct.getBalance() << endl;

            cout << "\nEnter withdraw amount: ";
            cin >> withdrawAmount;

            withdrawal(accountID, withdrawAmount);
            break;
        }
        case 5: {
            accountLookup();
            break;
        }
        case 6: {
            auto [minBal, minID] = minH.viewMin();
            Account acct = accounts[minID];

            cout << "Account with least money:" << endl;
            cout << "Account ID: " << acct.getID() << endl;
            cout << "Balance: $" << minBal << endl << endl;
            break;
        }
        case 7: {
            auto [maxBal, maxID] = maxH.viewMax();
            Account acct = accounts[maxID];

            cout << "Account with most money:" << endl;
            cout << "Account ID: " << acct.getID() << endl;
            cout << "Balance: $" << maxBal << endl << endl;
            break;
        }
        case 8: {
            return;
        }

        default: {
            cout << "\nERROR: Choose one of the options.\n\n" << endl;
        }

    }
}