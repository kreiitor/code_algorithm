/*
有一头母牛，它每年年初生一头小母牛。每头小母牛从第四个年头开始，每年年初也生一头小母牛。请编程实现在第n年的时候，共有多少头母牛？
1.有第一个样例输出可以知道，问第n年实际上是第n-1年过完之后有多少头
2.经过书写几轮之后，可以知道，f(n) = f(n-1)+f(n-3)
3.第一年生出的小母牛，第四年可以生育，这一点题目描述不明确；

Input  输入
输入数据由多个测试实例组成，每个测试实例占一行，包括一个整数n(0<n<55)，n的含义如题目中描述。
n=0表示输入数据的结束，不做处理。
Output  输出
对于每个测试实例，输出在第n年的时候母牛的数量。
每个输出占一行。
Sample Input  样例输入
2
4
5
0
Sample Output  示例输出
2
4
6
*/
#include<iostream>
#include<vector>

using namespace std;
int main()
{
    int n;
    while(cin >> n){
        if(n==0) continue;
        vector<int> arr(55),arr_big(55);
        for(int i =0;i<4;i++){//初始化前四年的情况
            arr_big[i] = 1;
            arr[i] = i+1;
        }
        for(int i=4;i<n;i++){
            arr[i] = arr[i-1]+arr[i-3];
        }
        cout << arr[n-1] <<endl;

    }
    return 0;
}