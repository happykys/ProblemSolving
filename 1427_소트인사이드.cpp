#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int arr[10] = {0};
    cin>>n;
    while(n>0)
    {
        arr[n%10]++;
        n /= 10;
    }
    for(int i = 9 ; i >= 0 ; i--)
    {
        for(int j = 0 ; j < arr[i] ; j++)
        {
            cout<<i;
        }
    }
    return 0;
}
