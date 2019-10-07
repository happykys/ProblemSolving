    #include <iostream>

    using namespace std;

    struct value // 분할된 범위에서의 값들
    {
        int buy; // 최대 이익을 얻었을 때의 산 가격
        int sell; // 이 때의 판 가격
        int maximum; // 해당 범위의 최대 가격
        int minimum; // 해당 범위의 최소 가격
    };

    value find_max(int arr[], int first, int last)
    {
        if(first == last) // 가격 범위가 한개가 될 때 까지 분할
        {
            int a = arr[first]; // 해당 인덱스의 가격
            value v = {a, a, a, a};
            // 한 개가 남았을 때의 산 가격, 판 가격, 최대값, 최소값 = 자기 자신
            return v;
        }

        value v;
        int mid = (first + last) / 2; // 둘로 분할하기 위한 중간 인덱스
        value l_value = find_max(arr, first, mid); // 중간을 기준으로 양쪽으로 분할
        value r_value = find_max(arr, mid+1, last);

        // 좌우 분할의 반환값의 최솟값 중 작은 값이 전체의 최솟값이 된다
        if(l_value.minimum < r_value.minimum) v.minimum = l_value.minimum;
        else v.minimum = r_value.minimum;
        // 좌우 분할의 반환값의 최댓값 중 큰 값이 전체의 최댓값 된다
        if(l_value.maximum > r_value.maximum) v.maximum = l_value.maximum;
        else v.maximum = r_value.maximum;

        int l_max = l_value.sell - l_value.buy; // 왼쪽 분할의 최대 이익
        int r_max = r_value.sell - r_value.buy; // 오른쪽 분할의 최대 이익
        int all_max = r_value.maximum - l_value.minimum; // 오른쪽 분할의 최댓값 - 왼쪽 분할의 최솟값

        // 이 세 값중 가장 큰 값의 sell과 buy가 전체 리턴값의 sell과 buy가 된다
        // 값이 같을 경우 buy가 작은것을 우선순위로 둔다
        // L : 왼쪽 분할, R : 오른쪽 분할, M : 좌우의 최대-최소 차이
        if(l_max > r_max && l_max > all_max) // L > R, M
        {
            v.buy = l_value.buy;
            v.sell = l_value.sell;
        }
        else if(l_max == r_max && l_max > all_max) // L = R > M
        {
            if(l_value.buy < r_value.buy)
            {
                v.buy = l_value.buy;
                v.sell = l_value.sell;
            }
            else
            {
                v.buy = r_value.buy;
                v.sell = r_value.sell;
            }
        }
        else if(l_max == all_max && l_max > r_max) // L = M > R
        {
            if(l_value.buy < l_value.minimum)
            {
                v.buy = l_value.buy;
                v.sell = l_value.sell;
            }
            else
            {
                v.buy = l_value.minimum;
                v.sell = r_value.maximum;
            }
        }
        else if(r_max > l_max && r_max > all_max) // R > L, M
        {
            v.buy = r_value.buy;
            v.sell = r_value.sell;
        }
        else if(r_max == all_max && r_max > l_max) // R = M > L
        {
            if(r_value.buy < l_value.minimum)
            {
                v.buy = r_value.buy;
                v.sell = r_value.sell;
            }
            else
            {
                v.buy = l_value.minimum;
                v.sell = r_value.maximum;
            }
        }
        else if(all_max > l_max && all_max > r_max) // M > L, R
        {
            v.buy = l_value.minimum;
            v.sell = r_value.maximum;
        }
        else if(l_max == r_max && l_max == all_max) // L = R = M
        {
            if(l_value.buy < r_value.buy)
            {
                if(l_value.buy < l_value.minimum)
                {
                    v.buy = l_value.buy;
                    v.sell = l_value.sell;
                }
                else
                {
                    v.buy = l_value.minimum;
                    v.sell = r_value.maximum;
                }
            }
            else
            {
                if(r_value.buy < l_value.minimum)
                {
                    v.buy = r_value.buy;
                    v.sell = r_value.sell;
                }
                else
                {
                    v.buy = l_value.minimum;
                    v.sell = r_value.maximum;
                }
            }
        }
        return v;
    }

    int main()
    {
        int n; // 입력받을 주식 가격의 수
        cin >> n;

        int* price = new int[n]; // 주식 가격들을 저장할 배열
        for(int i = 0 ; i < n ; i++) cin >> price[i];

        // 분할 정복을 사용해 최대 이익이 될 때의 산 가격, 판 가격을 반환받음
        value v = find_max(price, 0, n-1);

        // 이득을 볼 수 있다면
        if(v.sell - v.buy > 0) cout << v.buy << " " << v.sell << " " << v.sell - v.buy;
        // 이득이 없다면
        else cout << 0;

        delete[] price; // 동적 메모리 반납

        return 0;
    }
