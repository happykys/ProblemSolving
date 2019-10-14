#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void bubble_sort(int arr[], int n)
{
    for(int i = n-1 ; i > 0 ; i--)
    {
        bool sorted = true;
        for(int j = 0 ; j < i ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                sorted = false;
            }
        }
        if(sorted) break;
    }
}

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0 ; i < n ; i++) cin >> arr[i];

    bubble_sort(arr, n);

    for(int i = 0 ; i < n ; i++) cout << arr[i] << " ";

    delete[] arr;
    return 0;
}
