/*
在2×n的一个长方形方格中,用一个1× 2的骨牌铺满方格,输入n ,输出铺放方案的总数.
例如n=3时,为2× 3方格，骨牌的铺放方案有三种,如下图：
1.类似斐波那契数列。多一个列就相当于，竖放这个列就是dp[n-1]，另外就是横放，就是另外占据一列，剩下n-2列dp[n-2]

Input
输入数据由多行组成，每行包含一个整数n,表示该测试实例的长方形方格的规格是2×n (0<n<=50)。
Output
对于每个测试实例，请输出铺放方案的总数，每个实例的输出占一行。
Sample Input
1
3
2
Sample Output
1
3
2
*/

#include <iostream>
#include<vector>
using namespace std;

void init(vector<long long> & dp){
    dp[0]=0;dp[1]=1;dp[2]=2;
    for(int i=3;i<=50;++i){
        dp[i] = dp[i-1]+dp[i-2];
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