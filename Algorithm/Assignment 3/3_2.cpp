#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void quickSort(int a[], int first, int last)
{
    if(first < last)
    {
        int L = first + 1;
        int R = last;
        int pivot = a[first];
        while(L <= R)
        {
            while(L <= last && a[L] < pivot) L++;
            while(R >= first + 1 && a[R] >= pivot) R--;
            if(L <= R)
            {
                swap(a[L], a[R]);
                L++;
                R--;
            }
        }
        swap(a[first], a[R]);
        quickSort(a, first, R - 1);
        quickSort(a, R + 1, last);
    }
}

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];

    for(int i = 0 ; i < n ; i++) cin >> arr[i];

    quickSort(arr, 0, n-1);
    
    int cnt = 1;
    int maxCnt = 1;
    int num = arr[0];
    for(int i = 1 ; i < n ; i++)
    {
        if(arr[i] == arr[i-1])
        {
            cnt++;
        }
        else
        {
            cnt = 1;
        }

        if(cnt >= maxCnt)
        {
            maxCnt = cnt;
            if(num < arr[i]) num = arr[i];
        }
    }

    cout << num << " " << maxCnt << endl;

    delete[] arr;
    return 0;
}
