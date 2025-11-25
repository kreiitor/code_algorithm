/*
有一只经过训练的蜜蜂只能爬向右侧相邻的蜂房，不能反向爬行。请编程计算蜜蜂从蜂房a爬到蜂房b的可能路线数。
其中，蜂房的结构如下所示(i只能到i+1,i+2)。

1.可以知道，这个是动态规划，计dp[i]为从1到i的走法
 

Input
输入数据的第一行是一个整数N,表示测试实例的个数，然后是N 行数据，每行包含两个整数a和b(0<a<b<50)。
Output
对于每个测试实例，请输出蜜蜂从蜂房a爬到蜂房b的可能路线数，每个实例的输出占一行。
Sample Input
2
1 2
3 6
Sample Output
1
3
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