#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool processPayment(int sender, int receiver, int amount, vector<pair<int, int>>& accounts) {
    if (accounts[sender - 1].second >= amount) {
        accounts[receiver - 1].second += amount;
        accounts[sender - 1].second -= amount;
        return true;
    }
    return false;
}

bool balanceComparator(pair<int, int> account1, pair<int, int> account2) {
    return account1.second < account2.second;
}

int main() {
    int numOfAcc;
    cin >> numOfAcc;
    vector<pair<int, int>> accList;

    for (int i = 0; i < numOfAcc; i++) {
        int accountId, balance;
        cin >> accountId >> balance;
        accList.emplace_back(accountId, balance);
    }

    int numOfTransactions;
    cin >> numOfTransactions;

    while (numOfTransactions--) {
        int fromAccount, toAccount, transferAmount;
        cin >> fromAccount >> toAccount >> transferAmount;
        
        bool transactionResult = processPayment(fromAccount, toAccount, transferAmount, accList);
        
        if (transactionResult)
            cout << "Success\n";
        else
            cout << "Failure\n";
    }

    cout << "\n";
    sort(accList.begin(), accList.end(), balanceComparator);

    for (const auto& [id, balance] : accList)
        cout << id << " " << balance << "\n";

    return 0;
}
