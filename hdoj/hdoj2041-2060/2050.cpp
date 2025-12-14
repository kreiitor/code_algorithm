/* template.cpp
我们看到过很多直线分割平面的题目，今天的这个题目稍微有些变化，我们要求的是n条折线分割平面的最大数目。
比如，一条折线可以将平面分成两部分，两条折线最多可以将平面分成7部分，具体如下所示。
1.和直线分割平面如出一辙。各个直线的交点总和加一就是分成的面数
2.折线在于，每次多两条直线，并且这两条直线相交（每条直线都和之前的每条直线分别相交，乘二）
Input
输入数据的第一行是一个整数C,表示测试实例的个数，然后是C 行数据，每行包含一个整数n(0<n<=10000),表示折线的数量
Output
对于每个测试实例，请输出平面的最大分割数，每个实例的输出占一行。
Sample Input
2
1
2
Sample Output
2
7
*/


#include <iostream>
#include<vector>
#include<iomanip>
using namespace std;

void init(vector<long long> & dp){
    dp[0]=1;dp[1]=1;dp[2]=6;
    for(int i=3;i<=10000;++i){
        dp[i]=dp[i-1]+1+4*(i-1);
    }
    return;
}

int main()
{
    vector<long long> dp(10001,0);
    init(dp);
    int C,n;
    cin >> C;
    for(int i=0;i<C && cin >> n;++i){
        cout << dp[n]+1;
        cout << endl;
    }
    return 0;
}