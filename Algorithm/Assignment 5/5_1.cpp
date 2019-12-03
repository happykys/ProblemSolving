#include <iostream>
#include <vector>

using namespace std;

vector<vector <int>> v;
int visit[100000];

void DFS(int p)
{
    if(visit[p] == 1) return;
    visit[p] = 1;
    for(int i = 0 ; i < v[p].size() ; i++)
    {
        DFS(v[p][i]);
    }
}

int main()
{
    int n;
    cin >> n;

    v.resize(n);

    for(int i = 0 ; i < n ; i++)
    {
        int a;
        cin >> a;
        if(a != 0)
        {
            if(i - a >= 0)
            {
                v[i].push_back(i - a);
            }
            if(i + a < n)
            {
                v[i].push_back(i + a);
            }
        }
    }

    int M = 0;
    int index;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++) visit[j] = 0;
        DFS(i);
        int cnt = 0;
        for(int j = 0 ; j < n ; j++)
        {
            if(visit[j] == 1) cnt++;
        }
        if(cnt >= M)
        {
            M = cnt;
            index = i;
        }
    }

    cout << index << " " << M;

    return 0;
}
