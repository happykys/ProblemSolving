#include <iostream>

using namespace std;

struct Person // 방문객 구조체
{
    int arrive; // 절대 도착 시간
    int spend; // 심사 받는데 걸리는 시간
    int finish; // 심사 끝나는 절대 시간
};

void rebuildHeap(Person a[], int root, int n) // root를 루트로 하는 트리를 힙으로 O(log n)
{
    int i;
    int x = a[root].finish;
    int current = root;

    while(2 * current + 1 < n)
    {
        int leftChild = 2 * current + 1;
        int rightChild = leftChild + 1;
        int smallChild;
        if(rightChild < n && a[rightChild].finish <  a[leftChild].finish)
        {
            smallChild = rightChild;
        }
        else
        {
            smallChild = leftChild;
        }

        if(x > a[smallChild].finish)
        {
            a[current].finish = a[smallChild].finish;
            current = smallChild;
        }
        else
        {
            break;
        }
    }
    a[current].finish = x;
}
void toHeap(Person a[], int n) // 전체 힙 rebuild
{
    for(int root = n / 2 - 1 ; root >= 0 ; root--)
    {
        rebuildHeap(a, root, n);
    }
}

int main()
{
    int n, k;
    cin >> k;
    cin >> n;
    int arriveSum = 0;
    double waiting = 0;
    Person* Airport = new Person[n]; // 공항에 도착한 사람들 정보
    Person* Gate = new Person[k]; // k개의 심사대

    for(int i = 0 ; i < n ; i++) // 사람들 정보 입력받아옴
    {
        cin >> Airport[i].arrive >> Airport[i].spend;
        Airport[i].arrive += arriveSum;
        arriveSum = Airport[i].arrive;
    }

    for(int i = 0 ; i < k ; i++) // k개의 심사대에 먼저온 k명의 사람을 보냄
    {
        Gate[i] = Airport[i];
        Gate[i].finish = Gate[i].arrive + Gate[i].spend;
    }

    toHeap(Gate, k); // rebuild

    for(int i = k ; i < n ; i++) // k명의 사람 이후에 온 사람들에 대해 작업을 수행
    {
        if(Gate[0].finish > Airport[i].arrive) // 앞사람 심사가 끝나기를 기다리는 경우
        {
            waiting += (Gate[0].finish - Airport[i].arrive);
            Airport[i].finish = Gate[0].finish + Airport[i].spend;
        }
        else // 앞사람 심사가 끝나고 공항에 도착한 경우
        {
            Airport[i].finish = Airport[i].arrive + Airport[i].spend;
        }
        Gate[0] = Airport[i];
        toHeap(Gate, k); // 새로 들어온 사람에 대해 다시 rebuild
    }

    cout << fixed;
    cout.precision(1); // 소수점 한자리까지 출력
    cout << waiting / n; // 평균 대기 시간

    delete[] Airport;
    delete[] Gate;
    return 0;
}
