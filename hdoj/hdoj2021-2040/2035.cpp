/*
求A^B的最后三位数表示的整数。
说明：A^B的含义是“A的B次方”
1。pow函数的输出是double类型，容易溢出导致结果错误
2.因为只关心后三位数字，所以可以用后三位数字（模1000）不停的乘以A
 
Input  输入
输入数据包含多个测试实例，每个实例占一行，由两个正整数A和B组成（1<=A,B<=10000），如果A=0, B=0，则表示输入数据的结束，不做处理。
Output  输出
对于每个测试实例，请输出A^B的最后三位表示的整数，每个输出占一行。
Sample Input  样本输入
2 3
12 6
6789 10000
0 0
Sample Output  样本输出
8
984
1

*/
#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
    int m,n;
    while(cin>>m>>n){
        if(m==0 && n==0) break;
        long long num = pow(m,n);
        int result = 1;
        for(int i=0;i<n;++i){
            result = result * m %1000;
        }
        
        cout << result <<endl;

    }
    return 0;
}