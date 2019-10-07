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
    int length;
    int i, j, k;
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
    maxSum = value[0];
    length = 1;
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            float sum = 0;
            for (k = i; k <=  j; k++)
            sum = sum + value[k];
            if (sum > maxSum)
            {
                maxSum = sum;
                length = j - i + 1;
            }
            else if (sum == maxSum)
            {
                if (length > j - i + 1) length = j - i + 1;
            }
        }
    }
    ///////////////////////////////////////////////////////

    // 시간 측정 종료
    end = clock();

    // 결과 출력
    cout << length << " " << maxSum << endl;

    result = (double)(end - start);
    cout << "result : " << ((result) / CLOCKS_PER_SEC) << " seconds" << endl;
    /* microseconds
    cout << "result : " << result << " microseconds" << endl;
    */

    return 0;
}
