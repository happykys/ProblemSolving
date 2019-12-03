#include <iostream>

using namespace std;

int C[100][100];

int nCr(int n, int r)
{
    if(n < r) return 0;
    if(n == 0 || r == 0 || n == r) return 1;

    if(C[n][r] != 0) return C[n][r];
    else return C[n][r] = (nCr(n-1, r-1) + nCr(n-1, r));
}

int main()
{
    int n, r;
    cin >> n >> r;
    cout << nCr(n, r);
    return 0;
}
