/*
首先,给每位新娘打扮得几乎一模一样,并盖上大大的红盖头随机坐成一排;
然后,让各位新郎寻找自己的新娘.每人只准找一个,并且不允许多人找一个.
最后,揭开盖头,如果找错了对象就要当众跪搓衣板...
假设一共有N对新婚夫妇,其中有M个新郎找错了新娘,求发生这种情况一共有多少种可能.
1.这个题和上一个题的感觉一样，只不过多乘一个组合数用来表示找对的，然后是m个都错的概率（这里需要把init48的dp[1]弄成1，因为下面是乘以dp1[m]）
2.这里的dp1[1]是1就表示，当m等于1的时候，不可能错，这个表达式失效，改成求哪一个错的组合数（即取1，达到数学等价）

Input
输入数据的第一行是一个整数C,表示测试实例的个数，然后是C行数据，每行包含两个整数N和M(1<M<=N<=20)。
Output
对于每个测试实例，请输出一共有多少种发生这种情况的可能，每个实例的输出占一行。
Sample Input
2
2 2
3 2
Sample Output
1
3
*/

#include <iostream>
#include<vector>
#include<iomanip>
using namespace std;

void init(vector<long long> & dp){
    dp[0]=1;dp[1]=1;dp[2]=2;
    for(int i=3;i<=20;++i){
        dp[i]=i*dp[i-1];
    }
    return;
}

//m个都错的事件
void init48(vector<long long> & dp){
    dp[0]=0;dp[1]=1;dp[2]=1,dp[3]=2;
    for(int i=4;i<=20;++i){
        dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
    }
    return;
}

int main()
{
    vector<long long> dp(21,0);
    init(dp);
    vector<long long> dp1(21,0);
    init48(dp1);
    int C,n,m;
    cin >> C;
    for(int i=0;i<C && cin >> n >> m;++i){
        cout << dp[n]/(dp[m]*dp[n-m])*dp1[m];
        cout << endl;
    }
    return 0;
}