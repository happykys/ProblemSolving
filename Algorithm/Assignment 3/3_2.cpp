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
    int L = first + 1;
    int R = last;
    int pivot = a[first];
    while(L < R) // L >= R이면 종료
    {
        while(a[L] < pivot) L++; // pivot보다 큰거나같은값 나올때까지
        while(a[R] > pivot) R--; // pivot보다 작거나같은값 나올때까지
        if(L <= R)
        {
            if(L < R) swap(a[L], a[R]); // stable
            L++;
            R--;
        }
    }
    swap(a[first], a[R]);
    if(first < R) quickSort(a, first, R - 1);
    if(last > L) quickSort(a, R + 1, last);
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
    int num;
    for(int i = 1 ; i < n ; i++)
    {
        if(arr[i] == arr[i-1])
        {
            cnt++;
            if(cnt >= maxCnt)
            {
                maxCnt = cnt;
                num = arr[i];
            }
        }
        else
        {
            cnt = 1;
        }
    }

    cout << num << " " << maxCnt << endl;

    delete[] arr;
    return 0;
}
