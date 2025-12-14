/*
有一个长度为n(n<=100)的数列，该数列定义为从2开始的递增有序偶数，现在要求你按照顺序每m个数求出一个平均值，如果最后不足m个，则以实际数量求平均值。编程输出该平均值序列。
1.特别烦人的边界问题，空格是否输出需要尽可能的讨论
2.

Input  输入
输入数据有多组，每组占一行，包含两个正整数n和m，n和m的含义如上所述。
Output  输出
对于每组输入数据，输出一个平均值序列，每组输出占一行。
Sample Input  样例输入
3 2
4 2
Sample Output  示例输出
3 6
3 7
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{   
    int n,m;
    while(cin >> n >> m){
        vector<int> evens;
        int count=1,q = n/m;
        int total=0;
        if(q*m == n){
            for(int i=1;i<=n;i++){
                total += 2*i;
                if(i%m==0){
                    cout << total/m;
                    total = 0;
                    if(i<n) cout << ' ';
                }
            }


        }
        else{
            int w = q*m;
            for(int i=1;i<=w;i++){
                total += 2*i;
                if(i%m==0){
                    cout << total/m;
                    total = 0;
                    cout << ' ';
                }
            }
            for(int i=w+1;i<=n;i++){
                total += 2*i;
            }
            cout << total/(n-w) << endl;
        }
        
    }
    
    return 0;
}