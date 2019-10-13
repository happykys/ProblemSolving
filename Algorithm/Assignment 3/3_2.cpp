#include <iostream>

using namespace std;

void swap(int &a, int &b) // 두 정수 값을 바꾸는 함수
{
    int tmp = a;
    a = b;
    b = tmp;
}
void quickSort(int a[], int first, int last)
{
    if(first < last) // else일 경우 정렬할 필요 없음
    {
        int pivot = a[first]; // 피벗 값을 가장 앞 원소로 잡음
        int L = first + 1; // 피벗 다음으로 오는 가장 앞에있는 인덱스
        int R = last; // 가장 마지막 인덱스
        while(L <= R)
        {
            while(L <= last && a[L] < pivot) L++; // 피벗보다 크거나 같은 값이 나올때 까지 이동
            while(R >= first + 1 && a[R] >= pivot) R--; // 피벗보다 작은 값이 나올 때 까지 이동
            if(L <= R)
            {
                swap(a[L], a[R]); // 피벗보다 큰 값이 피벗보다 작은값보다 왼쪽에 있을 경우 서로 자리를 바꿈
                L++; // 두 값 사이의 값들도 확인
                R--;
            }
        }
        swap(a[first], a[R]); // 피벗이 있어야 할 자리로 옮겨줌
        quickSort(a, first, R - 1); // 피벗 기준 양쪽으로 분할해서 재귀 정렬
        quickSort(a, R + 1, last);
    }
}

int main()
{
    int n; // 데이터 개수
    cin >> n;
    int* arr = new int[n]; // 데이터 입력받을 배열

    for(int i = 0 ; i < n ; i++) cin >> arr[i];

    quickSort(arr, 0, n-1); // 입력받은 데이터를 오름차순 정렬

    int num = arr[0]; // 가장 많이 나온 값 : 초기 = 배열의 첫번째(가장작은)값
    int cnt = 1; // 현재 원소의 개수
    int maxCnt = 1; // 현재까지 가장 많이 나온 원소의 개수
    for(int i = 1 ; i < n ; i++)
    {
        if(arr[i] == arr[i-1]) // 이전 값과 같다면 카운트 1 증가
        {
            cnt++;
        }
        else // 새로운 값이 나왔다면 카운트 초기화
        {
            cnt = 1;
        }

        if(cnt >= maxCnt) // 지금까지 가장 빈도수 높은 값보다 많거나 같게 나온 경우
        {
            maxCnt = cnt; // 최대 빈도 갱신
            if(num < arr[i]) num = arr[i]; // 최대빈도 같다면 값이 더 큰 숫자가 우선순위
        }
    }

    cout << num << " " << maxCnt << endl;

    delete[] arr;
    return 0;
}
