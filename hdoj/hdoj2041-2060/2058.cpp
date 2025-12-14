/*
Given a sequence 1,2,3,......N, your job is to calculate 
all the possible sub-sequences that the sum of the sub-sequence is M.
1.注意输入，一般而言10e8左右就必须是O(n)了，现在是9级别，滑动窗口不太行，需要进行新算法
2.既然使用l,r两个进行迭代不行，考虑使用区间长度进行迭代，这样可以复杂度到√2m

Input
Input contains multiple test cases. each case contains two integers N,
 M( 1 <= N, M <= 1000000000).input ends with N = M = 0.
Output
For each test case, print all the possible sub-sequence that its sum is M.
The format is show in the sample below.print a blank line after each test case.
Sample Input
20 10
50 30
0 0
Sample Output
[1,4]
[10,10]

[4,8]
[6,9]
[9,11]
[30,30]
*/

#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    long long n,m,count=0;
    while(cin >> n >> m){
        if(n==0 && m==0) break;
        if(count>0) cout << endl;
        long long temp = 2*m,l;
        for(long long k=(long long)sqrt(temp);k>=1;--k){
            if((temp/k-k+1)%2!=0|| temp%k!=0) continue;//这个可约的条件必须在循环里，在循环条件中会难出现模0错误
            l = (temp/k-k+1)/2;
            if(!(l+k-1<=n&&l>=1)) continue;
            cout << '[' << l << ',' << l+k-1 << ']';
            cout << endl;
        }
        ++count;
    }
    return 0;
}