#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void insertion_sort(int arr[], int n)
{
    int j;
    for(int i = 1 ; i < n ; i++)
    {
        int tmp = arr[i];
        for(j = i-1 ; j >= 0 ; j--)
        {
            if(arr[j] > tmp) arr[j+1] = arr[j];
            else break;
        }
        arr[j+1] = tmp;
    }
}

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0 ; i < n ; i++) cin >> arr[i];

    insertion_sort(arr, n);

    for(int i = 0 ; i < n ; i++) cout << arr[i] << " ";

    delete[] arr;
    return 0;
}
