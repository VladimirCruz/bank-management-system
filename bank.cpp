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

void menu() {
    cout << "1. Create Account" << endl;
    cout << "2. Delete Account" << endl;
    cout << "3. Deposit" << endl;
    cout << "4. Withdraw" << endl;
    cout << "5. Transfer Money" << endl;
    cout << "6. Account Lookup" << endl;
    cout << "7. Account with Least Money using minHeap" << endl;
    cout << "8. Account with Most Money using maxHeap" << endl;
    cout << "9. Top Accounts with Most Money" << endl;
    cout << "10. Exit System" << endl;
}

void handleChoice(int c) { //, unordered_map<double, Account>& accounts, minHeap& minH, maxHeap& maxH
    switch (c) {
        case 1: {
            accountCreate();
            break;
        }
        case 2: {
            cout << "Deleted Account" << endl;
            break;
        }
        case 6: {
            accountLookup();
            break;
        }
        case 7: {
            auto [minBal, minID] = minH.viewMin();
            Account acct = accounts[minID];

            cout << "Account with least money:" << endl;
            cout << "Account ID: " << acct.getID() << endl;
            cout << "Balance: $" << minBal << endl << endl;
            break;
        }
        case 8: {
            auto [maxBal, maxID] = maxH.viewMax();
            Account acct = accounts[maxID];

            cout << "Account with most money:" << endl;
            cout << "Account ID: " << acct.getID() << endl;
            cout << "Balance: $" << maxBal << endl << endl;
            break;
        }
        case 10: {
            return;
        }

        default: {
            cout << "\nERROR: Choose one of the options.\n\n" << endl;
        }

        }
    }

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

/*
void accountDelete() {
    int id;
    cout << "Enter Account ID: " << endl;
    cin >> id;

    if(accounts.find(id) != accounts.end()) {

    }

    swap(minH[0], minH[id]);
    swap(maxH[0], maxH[id]);


}
*/



void deposit(int accountID, int depositAmount) {

    auto it = accounts.find(accountID);
    if(it == accounts.end()) {
        cout << "Account was not found." << endl;
        return;
    }

    if(amount <= 0) {
        cout << "Invalid amount." << endl;
        return;
    }

    Account& acct = it->second; //we want iterator to point to balance amount
    double oldBalance = acct.getBalance();
    double newBalance = oldBalance + depositAmount;
    //Update minHeap and maxHeap


    time_t now = time(nullptr);

    cout << "A deposit was made to your account." << ctime(&now) << endl;
    cout << "Your current balance is: $" << balance << endl;

}

int withdrawal();

/*
int moneyTransfer(int accountNum, float amount) { //float amount

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
    int id;
    cout << "Account ID: ";
    cin >> id;

    double bal = 0; //accounts.find()

    if(accounts.find(id) != accounts.end()) {
        const Account& acct = accounts.find(id)->second;

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


//Functions for menus
int mergeSort();