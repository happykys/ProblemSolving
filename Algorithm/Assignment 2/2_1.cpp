#include <iostream>
using namespace std;

long long f(long long a, long long n, long long m)
{
    if(n == 1) return a % m; // a^0 = 1
    long long s = f(a, n/2, m); // s = a^(n/2) mod m
    s = s * s % m; // s = (a^(n/2) * a^(n/2)) mod m;
    return (n % 2 == 0) ? s : s * a % m;
    // n이 짝수 : a^n = a^(n/2) * a^(n/2)
    // n이 홀수 : a^n = a^(n/2) * a^(n/2) * a
}

int main()
{
    long long a, n, m; // (a^n) mod m 을 구하는 프로그램
    cin >> a >> n >> m;
    cout << f(a, n, m); // 함수 호출
    return 0;
}
