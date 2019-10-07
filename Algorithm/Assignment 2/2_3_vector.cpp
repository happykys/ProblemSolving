#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; // 입력 데이터 수
    cin >> n;
    int* arr = new int[n];
    for(int i=0;i<n;i++) cin >> arr[i]; // n개의 데이터 입력(R 숫자열)

    vector<int> v;
    for(int i = 1 ; i <= n; i++) v.push_back(i); // 1~n의 값이 저장된 vector

    vector<int> ans; // 정답(S 숫자열)이 저장될 vector
    bool flag = false; // S 숫자열을 결정할 수 있다면 false
                       // 결정할 수 없다면 true

    for(int i = n-1 ; i >= 0 ; i--) // R 숫자열을 뒤에서부터(n-1) 확인
    {
        if(arr[i] >= v.size()) // 만약 R 숫자열의 값이 남은 숫자의 개수보다 크거나 같다면 S결정지을 수 없음.
        {
            flag = true;
            break; // S 숫자열을 결정지을 수 없기 때문에 반복문 돌 필요 없음
        }
        int num = v[arr[i]]; // 찾고자하는 위치의 S 숫자열 값
        ans.push_back(num); // 정답 vector 뒤에 push
        v.erase(v.begin() + arr[i]); // 해당 수 v에서 삭제
    }

    if(flag) cout << -1; // S결정지을 수 없으면 -1 출력
    else // 결정지을 수 있으면
    {
        for(int i = ans.size() - 1 ; i >= 0 ; i--)
        {
            cout << ans[i] << " "; // S의 n-1부터 push_back 해주었으므로 0번째부터 출력하기 위해서는 다시 뒤에서부터 출력
        }
    }
    return 0;
}
