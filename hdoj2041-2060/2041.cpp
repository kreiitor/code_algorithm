/*
有一楼梯共M级，刚开始时你在第一级，若每次只能跨上一级或二级，要走上第M级，共有多少种走法？
1.经典的动态规划问题，从大到小解题

Input  输入
输入数据首先包含一个整数N，表示测试实例的个数，然后是N行数据，每行包含一个整数M（1<=M<=40）,表示楼梯的级数。
Output  输出
对于每个测试实例，请输出不同走法的数量
Sample Input  样本输入
2
2
3
Sample Output  样本输出
1
2
*/

#include <iostream>
#include<vector>
using namespace std;


int main()
{
    int n;cin>>n;
    int m;
    for(int i=0;i<n && cin >> m;++i){
        vector<int> dp(m+1,0);
        dp[1]=1;
        for(int j=2;j<=m;++j){
            dp[j] = dp[j-1]+dp[j-2];
        }
        cout << dp[m] << endl;
    }
    return 0;
}