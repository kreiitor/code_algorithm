/*
想了一想，阿牛从家里拿来了一块上等的牛肉干，准备在上面刻下一个长度为n的只由"E" "O" "F"三种字符组成的字符串
（可以只有其中一种或两种字符，但绝对不能有其他字符）,阿牛同时禁止在串中出现O相邻的情况，他认为，"OO"看起来就像发怒的眼睛，效果不好。
你，NEW ACMer,EOF的崇拜者，能帮阿牛算一下一共有多少种满足要求的不同的字符串吗？
1.求出来一列数列，找规律
2.或者ai的做法，记录末尾为O的字符串为a[i],否则为b[i]然后关注这两个的递推关系，结果为a+b
Input
输入数据包含多个测试实例,每个测试实例占一行,由一个整数n组成，(0<n<40)。
Output
对于每个测试实例，请输出全部的满足要求的涂法，每个实例的输出占一行。
Sample Input
1
2
Sample Output
3
8
*/

#include <iostream>
#include<vector>
using namespace std;

void init(vector<long long> & dp){
    dp[0]=0;dp[1]=3;dp[2]=8;
    for(int i=3;i<=50;++i){
        dp[i] = 2*(dp[i-1]+dp[i-2]);
    }
    return;
}


int main()
{
    int n;
    vector<long long> dp(51,0);
    init(dp);
    while(cin >> n){
        cout<<dp[n] << endl;
    }
    return 0;
}