#include <iostream>
using namespace std;

#define MAX_SIZE 100004

int maximum(int arr[], int first, int last)
{
    int lmax, rmax;
    if(first == last)
    {
        return arr[first];
    }
    else if(first < last)
    {
        int mid = (first + last) / 2;
        lmax = maximum(arr, first, mid);
        rmax = maximum(arr, mid + 1, last);

        if(lmax > rmax) return lmax;
        else return rmax;
    }
}

int main()
{
    int n;
    int price[MAX_SIZE];
    int minimum[MAX_SIZE];
    int profit[MAX_SIZE];

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> price[i];
    }

    minimum[0] = price[0];

    for(int i = 1; i < n; i++)
    {
        if(minimum[i-1] > price[i])
        {
            minimum[i] = price[i];
        }
        else
        {
            minimum[i] = minimum[i-1];
        }

        if(price[i] > minimum[i])
        {
            profit[i] = price[i] - minimum[i];
        }
    }

    int max_profit = maximum(profit, 0, n-1);

    if(max_profit == 0)
    {
        cout << 0;
    }
    else
    {
        int buy = minimum[0];
        int sell;
        for(int i = 1 ; i < n ; i++)
        {
            if(profit[i] == max_profit)
            {
                if(buy >= minimum[i])
                {
                    buy = minimum[i];
                    sell = price[i];
                }
            }
        }
        cout << buy << " " << sell << " "<< max_profit;
    }
    return 0;
}
