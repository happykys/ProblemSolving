#include <iostream>
using namespace std;

int main()
{
    int n;
    int buy, sell;
    int max_profit;
    int min_price;
    cin >> n;
    int* price = new int[n];
    for(int i = 0 ; i < n ; i++) cin >> price[i];

    max_profit = 0;
    min_price = price[0];

    for(int i = 1 ; i < n ; i++)
    {
        if(price[i] - min_price >= max_profit)
        {
            max_profit = price[i] - min_price;
            buy = min_price;
            sell = price[i];
        }
        if(min_price >= price[i])
        {
            min_price = price[i];
        }
    }

    if(max_profit > 0)
    {
        cout << buy << " " << sell << " " << max_profit << endl;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
