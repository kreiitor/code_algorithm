/*
Give you a number on base ten,you should output it on base two.(0 < n < 1000)
1.进制转换，连除即可
Input
For each case there is a postive number n on base ten, end of file.
Output
For each case output a number on base two.
Sample Input
1
2
3
Sample Output
1
10
11
*/


#include <iostream>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;



int main()
{
    int n,ans;
    while(cin >> n){
        ans=0;
        for(int i=0;n;++i){
            ans += n%2*((i>0?pow(10,i):1));
            n/=2;
       }
        cout << ans << endl;
    }
    return 0;
}