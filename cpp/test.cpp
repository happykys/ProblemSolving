#include <iostream>

using namespace std;

int c[1000000];

void merge(int a[], int first, int mid, int last)
{
    // int* c = new int[last - first + 1];
    int i = first;
    int j = mid + 1;
    int k = first;

    while(i <= mid && j <= last)
    {
        if(a[i] <= a[j])
        {
            c[k++] = a[i++];
        }
        else
        {
            c[k++] = a[j++];
        }
    }

    if(i > mid)
    {
        for( ; j <= last ; j++)
        {
            c[k++] = a[j];
        }
    }
    else
    {
        for( ; i <= mid ; i++)
        {
            c[k++] = a[i];
        }
    }

    for(int l = first ; l <= last ; l++)
    {
        a[l] = c[l];
    }
}
void mergeSort(int a[], int first, int last)
{
    if(first < last)
    {
        int mid = (first + last) / 2;
        mergeSort(a, first, mid);
        mergeSort(a, mid+1, last);
        merge(a, first, mid, last);
    }
}

int main()
{
    int n;
    cin >> n;
    int* a = new int[n];

    for(int i = 0 ; i < n ; i++) cin >> a[i];

    mergeSort(a, 0, n - 1);

    for(int i = 0 ; i < n ; i++) cout << a[i] << " ";

    delete[] a;

    return 0;
}

1 2 3 4 5
3 4 5 6 7

1 2 3 3 4 4 5 5 6 7
