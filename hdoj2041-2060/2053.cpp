/*
There are many lamps in a line. All of them are off at first.
 A series of operations are carried out on these lamps. 
 On the i-th operation, the lamps whose numbers are the multiple of i change the condition
( on to off and off to on ).
1.只有为i倍数的时候才会变化，那也就是说，只有n因数的时候会变化，而且只会0/1变化
2.只用求出来因数个数即可

Input
Each test case contains only a number n ( 0< n<= 10^5) in a line.
Output
Output the condition of the n-th lamp after infinity operations ( 0 - off, 1 - on ).
Sample Input
1
5
Sample Output
1
0

Consider the second test case:

The initial condition	   : 0 0 0 0 0 …
After the first operation  : 1 1 1 1 1 …
After the second operation : 1 0 1 0 1 …
After the third operation  : 1 0 0 0 1 …
After the fourth operation : 1 0 0 1 1 …
After the fifth operation  : 1 0 0 1 0 …

The later operations cannot change the condition of the fifth lamp any more. So the answer is 0.
*/
#include <iostream>
#include<vector>
#include<algorithm>

int countFactorNumber(int n){
    if(n==1) return 1;
    int num=0;
    bool flag=false;//用来标识是否n为完全平方数
    for(int i=2;i*i<=n;++i){
        if(n%i==0){
            ++num;
            if(i*i==n) flag=true;
        }
    }
    return (flag)?(2*num+1):(2*num+2);
}

using namespace std;

int main()
{
    int n;
    while(cin >> n){
        cout << ((countFactorNumber(n)%2==0)?0:1) << endl;
    }
    return 0;
}