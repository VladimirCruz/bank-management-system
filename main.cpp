#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <conio.h>
#include <unordered_map>

#include "classes.h"
#include "bank.h"

using namespace std;

int main() {
    //random declaration
    srand(static_cast<unsigned>(time(nullptr)));

    //STOPPED HERE. FIX THIS NOW. - 4/20/25 7:33PM

    //Random amounts of money inserted into data structures
    for(int i = 0; i < 10000; i++) {
        double moneyAmount = (static_cast<double>(rand()) / RAND_MAX) * 999999;

        Account acct(i, i, i, i, "John", moneyAmount);
        accounts.emplace(moneyAmount, acct);

        minH.insert(moneyAmount, i);
        maxH.insert(moneyAmount, i);
    }

    /*

    //Extract balances
    double minBal = minH.viewMin();
    double maxBal = maxH.viewMax();

    //Look up Accounts
    auto itMin = accounts.find(minBal);
    auto itMax = accounts.find(maxBal);

    cout << "\nThe account with the least money is: " << itMin->second.getID() << endl;
    cout << "Balance: $" << fixed << setprecision(2) << minH.viewMin() << endl;

    cout << "\nThe account with the most money is: " << itMax->second.getID() << endl;
    cout << "Balance: $" << fixed << setprecision(2) << maxH.viewMax() << endl;

    cout << endl;

    */

    int choice = 0;

    while(true) {
        menu();
        cin >> choice;
        if(choice == 10) break;
        handleChoice(choice);
    }
}