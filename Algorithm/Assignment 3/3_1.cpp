#include <iostream>

using namespace std;

int c[1000000]; // 두 배열의 원소들이 정렬되어 저장될 배열

void merge(int a[], int first, int mid, int last)
{
    int i = first; // 왼쪽배열 첫 인덱스
    int j = mid + 1; // 오른쪽 배열 첫 인덱스
    int k = first; // 합쳐질 배열 첫 인덱스

    while(i <= mid && j <= last)
    {
        if(a[i] <= a[j]) // 더 작은 값이 합쳐질 배열에 들어감
        {
            c[k++] = a[i++];
        }
        else
        {
            c[k++] = a[j++];
        }
    }

    // 두 배열중 하나라도 값이 남은 경우 남은 값들을 전부 합칠 배열에 넣어줌
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

    for(int l = first ; l <= last ; l++) // 정렬된 배열을 원래 배열에 대입
    {
        a[l] = c[l];
    }
}
void mergeSort(int a[], int first, int last)
{
    if(first < last) // 병합정렬 탈출조건
    {
        int mid = (first + last) / 2; // 가운데 기점
        mergeSort(a, first, mid); // 중앙을 기준으로 양쪽으로 분할
        mergeSort(a, mid+1, last);
        merge(a, first, mid, last); // 분할된 후 정렬된 양쪽 배열을 다시 하나로 합침
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    int* a = new int[n + m];

    for(int i = 0 ; i < n + m ; i++) cin >> a[i]; // 두 집합을 하나의 배열에 모은다

    mergeSort(a, 0, n + m - 1); // 한번에 정렬

    int cnt = 0; // 교집합 원소의 개수
    for(int i = 1 ; i < n + m ; i++)
    {
        if(a[i] == a[i-1]) cnt++; // 서로 같은 값이 있으면 카운트 1 증가
    }
    cout << cnt;

    delete[] a;

    return 0;
}
