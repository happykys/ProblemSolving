#include <iostream>

using namespace std;

struct Person
{
    int arrive;
    int spend;
    int finish;
};

void rebuildHeap(Person a[], int root, int n)
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
void toHeap(Person a[], int n)
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
    Person* Airport = new Person[n];
    Person* Gate = new Person[k];
    for(int i = 0 ; i < n ; i++)
    {
        cin >> Airport[i].arrive >> Airport[i].spend;
        Airport[i].arrive += arriveSum;
        arriveSum = Airport[i].arrive;
    }

    for(int i = 0 ; i < k ; i++)
    {
        Gate[i] = Airport[i];
        Gate[i].finish = Gate[i].arrive + Gate[i].spend;
    }

    toHeap(Gate, k);

    for(int i = k ; i < n ; i++)
    {
        if(Gate[0].finish > Airport[i].arrive)
        {
            waiting += (Gate[0].finish - Airport[i].arrive);
            Airport[i].finish = Gate[0].finish + Airport[i].spend;
        }
        else
        {
            Airport[i].finish = Airport[i].arrive + Airport[i].spend;
        }
        Gate[0] = Airport[i];
        toHeap(Gate, k);
    }

    cout << fixed;
    cout.precision(1);
    cout << waiting / n;

    delete[] Airport;
    delete[] Gate;
    return 0;
}
