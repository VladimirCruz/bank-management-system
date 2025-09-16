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

    //Random amounts of money inserted into data structures
    for(int i = 0; i < 1000000; i++) {
        double moneyAmount = (static_cast<double>(rand()) / RAND_MAX) * 9999999;

        Account acct(i, i, i, i, "John", moneyAmount);
        accounts.emplace(i, acct);

        minH.insert(moneyAmount, i);
        maxH.insert(moneyAmount, i);
    }

    int choice = 0;

    while(true) {
        menu();
        cin >> choice;
        if(choice == 8) break;
        handleChoice(choice);
    }
}