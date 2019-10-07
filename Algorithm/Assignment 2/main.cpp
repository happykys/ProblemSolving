#include <iostream>
using namespace std;

int main()
{
    long long a;
    int n, m;
    cin >> a >> n >> m;

    for(int i = 0 ; i < n; i++)
    {
        a *= n;
        a %= m;
    }

    cout << a;
    return 0;
}
