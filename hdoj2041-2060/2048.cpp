/*
首先，所有参加晚会的人员都将一张写有自己名字的字条放入抽奖箱中；
然后，待所有字条加入完毕，每人从箱中取一个字条；
最后，如果取得的字条上写的就是自己的名字，那么“恭喜你，中奖了！”
这次抽奖活动最后竟然没有一个人中奖！
你能计算一下发生这种情况的概率吗？
不会算？难道你也想以悲剧结尾？！
1.可以分析得到，多加一个人，如果原来全错只用把概率乘以(n-1)/n，对一个也可以，乘1/n
Input
输入数据的第一行是一个整数C,表示测试实例的个数，然后是C 行数据，每行包含一个整数n(1<n<=20),表示参加抽奖的人数。
Output
对于每个测试实例，请输出发生这种情况的百分比，每个实例的输出占一行, 结果保留两位小数(四舍五入)，具体格式请参照sample output。
Sample Input
1
2 
Sample Output
50.00%
*/

#include <iostream>
#include<vector>
#include<iomanip>
using namespace std;

void init(vector<double> & dp){
    dp[0]=0.0;dp[1]=0.0;dp[2]=1.0/2,dp[3]=1.0/3;
    for(int i=4;i<=20;++i){
        dp[i]=(double)(i-1)/i*dp[i-1]+1.0/i*dp[i-2];
    }
    return;
}


int main()
{
    vector<double> dp(21,0);
    init(dp);
    int C,n;
    cin >> C;
    for(int i=0;i<C && cin >> n;++i){
        cout << fixed << setprecision(2);
        cout << dp[n]*100;
        cout << '%' << endl;
    }
    return 0;
}