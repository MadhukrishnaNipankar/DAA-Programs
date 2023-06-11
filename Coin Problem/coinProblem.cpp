/*
Take the Amount from user as input
Give the minimum possible combination of currency[i]
*/

#include <iostream>
#include <map>
using namespace std;

int main()
{

    map<int, int> hash;

    int currencyList[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

    // Accepting Amount (input) from user
    int amount = 0;
    cout << "Enter the Required Amount : ";
    cin >> amount;

    int i = 0;
    while (i < 10 && amount > 0)
    {
        if (amount >= currencyList[i])
        {
            amount = amount - currencyList[i];
            // cout<<currencyList[i]<<" ";
            hash[currencyList[i]]++;
        }

        if (amount < currencyList[i])
        {
            i++;
        }
    }

    cout << "Minimum possible combination of Currency is :" << endl;
    for (auto it : hash)
    {
        cout << it.first << " : \t" << it.second << endl;
    }

    /*
    case 1:
    amount > 2000

    eg. amount = 4500
    4500 - 2000 = 2500 .
    print -> 2000 : 1
    2500 - 2000 = 500 .
    print -> 2000 : 1.


    case 2:

    eg.
    amount < currencyList[i]
    500 - 500 = 0
    print -> 500 : 1



    */
}