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
    float currentSum, currentLength;
    maxSum = currentSum = value[0];
    minLength = n+1; // 큰 값으로 초기화
    currentLength = 1;

    for (i = 1; i < n; i++)
    {
        if (currentSum > 0)
        { // if (sum[i-1] > 0) {
            currentSum += value[i]; //sum[i] = sum[i-1] + value[i];
            currentLength++; // length[i] = length[i-1] + 1;
        }
        else
        {
            currentSum = value[i]; // sum[i] = value[i];
            currentLength = 1; //length[i] = 1;
        }

        if (maxSum < currentSum)
        {
            maxSum = currentSum;
            minLength = currentLength;
        }
        else
        {
            if(maxSum == currentSum)
            {
                if (currentLength < minLength) minLength = currentLength;
            }
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
