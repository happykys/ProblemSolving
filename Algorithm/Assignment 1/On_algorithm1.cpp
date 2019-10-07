#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

#define size 100000

int main()
{
    float value[size];
    float sum[size];
    int length[size];
    int n;
    float maxSum;
    int minLength;
    int i;
    string file_path;
    ifstream fin;

    // 1 ~ 14 입력해서 testcase 파일 불러오기
    cin >> file_path;
    file_path = "testcase" + file_path + ".txt";
    fin.open(file_path);

    // 입력받을 데이터 수
    fin >> n;

    // 데이터 입력
    for (i = 0; i <n; i++) fin >> value[i];

    clock_t start, end;
    double result;
    start = clock(); // 수행 시간 측정 시작

    ///////////////////////알고리즘////////////////////////
    sum[0] = value[0];
    length[0] = 1;

    for (i = 1; i < n; i++)
    {
        if (sum[i-1] > 0)
        {
            sum[i] = sum[i-1] + value[i];
            length[i] = length[i-1] + 1;
        }
        else
        {
            sum[i] = value[i];
            length[i] = 1;
        }
    }

    maxSum = sum[0];
    minLength = length[0];

    for (int i = 1; i < n; i++)
    {
        if (maxSum < sum[i])
        {
            maxSum = sum[i];
            minLength = length[i];
        }
        else if (maxSum == sum[i])
        {
            if(length[i] < minLength) minLength = length[i];
        }
    }
    ///////////////////////////////////////////////////////

    // 시간 측정 종료
    end = clock();

    // 결과 출력
    cout << minLength << " " << maxSum << endl;

    result = (double)(end - start);
    cout << "result : " << ((result) / CLOCKS_PER_SEC) << " seconds" << endl;
    /* microseconds
    cout << "result : " << result << " microseconds" << endl;
    */

    return 0;
}
