/*
还记得中学时候学过的杨辉三角吗？具体的定义这里不再描述，你可以参考以下的图形：
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
1.把第i行和第i行向右平移一个单位的相加，就是下一行
2.有递推结构，可以考虑使用动态规划
3.动态规划一般而言都需要多一个值，用来处理开始时的边界处理


Input  输入
输入数据包含多个测试实例，每个测试实例的输入只包含一个正整数n（1<=n<=30），表示将要输出的杨辉三角的层数。
Output  输出
对应于每一个输入，请输出相应层数的杨辉三角，每一层的整数之间用一个空格隔开，每一个杨辉三角后面加一个空行。
Sample Input  样例输入
2 3
Sample Output  示例输出
1
1 1

1
1 1
1 2 1
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
    int n,count=0;
    while(cin >> n){
        if(count>0)cout<<endl;
        vector<long long> dp(n+1,0);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            dp[i] = 1;
            for(int j=i-1;j>=1;j--){
                dp[j] = dp[j-1] + dp[j];
            }
            for(int j=1;j<=i;j++){
                cout << dp[j];
                if(j<i) cout << ' ';
            }
            cout << endl;
        }
        count ++;
    }
    return 0;
}