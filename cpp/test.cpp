#include <iostream>

using namespace std;

int main(){

   int n;
   cin >> n;
   int arr[10];

   arr[0] = arr[1] = arr[2] = 1;
   arr[3] = 2;
   for(int i=4; i<=n; i++){
      arr[i] = arr[i-4] + arr[i-3] + arr[i-1];
   }

   cout << arr[n] << endl;;

   return 0;
}
