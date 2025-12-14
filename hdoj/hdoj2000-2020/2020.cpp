/*
输入n(n<=100)个整数，按照绝对值从大到小排序后输出。题目保证对于每一个测试实例，所有的数的绝对值都不相等。
 

Input  输入
输入数据有多组，每组占一行，每行的第一个数字为n,接着是n个整数，n=0表示输入数据的结束，不做处理。
Output  输出
对于每个测试实例，输出排序后的结果，两个数之间用一个空格隔开。每个测试实例占一行。
Sample Input  样例输入
3 3 -4 2
4 0 1 2 -3
0
Sample Output  示例输出
-4 3 2
-3 2 1 0
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
    int n,num;
    while(cin >> n){
        if(n==0) break;
        vector<int> arr(n);
        for(int i=0;i<n && cin>>num;i++){
            arr[i] = num;
        }
        sort(arr.begin(),arr.end(),[](int a,int b){return abs(a)>abs(b);});

        for(int i=0;i<n;i++){
            cout << arr[i];
            if(i!=n-1) cout << ' ';
        }
        cout << endl;

    }

    return 0;
}