#include <iostream>
using namespace std;

int main()
{
    int n;
    bool flag = false;
    cin >> n;
    int* ans = new int[n];

    int* arr = new int[n];
    for(int i = 0 ; i < n ; i++) arr[i] = i + 1;

    int* r = new int[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin >>r[i];
        if(r[i] > i) flag = true;
    }

    if(flag)
    {
        cout << -1;
    }
    else
    {
        int j = 0;
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            ans[j] = arr[r[i]];
            for(int k = r[i] ; k < n - 1 ; k++)
            {
                arr[k] = arr[k+1];
            }
            j++;
        }

        for(int i = n - 1 ; i >= 0 ; i--)
        {
            cout << ans[i] << " ";
        }
    }
    return 0;
}
