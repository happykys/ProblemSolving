#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void selection_sort(int arr[], int n)
{
    for(int i = 0 ; i < n-1 ; i++)
    {
        int minIndex = i;
        for(int j = i+1 ; j < n ; j++)
        {
            if(arr[j] < arr[minIndex]) minIndex = j;
        }
        if(minIndex != i) swap(arr[minIndex], arr[i]);
    }
}

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0 ; i < n ; i++) cin >> arr[i];

    selection_sort(arr, n);

    for(int i = 0 ; i < n ; i++) cout << arr[i] << " ";

    delete[] arr;
    return 0;
}
