/*
有n(n<=100)个整数，已经按照从小到大顺序排列好，现在另外给一个整数x，请将该数插入到序列中，并使新的序列仍然有序。
1.关键依旧是空格输出的条件判断

Input  输入
输入数据包含多个测试实例，每组数据由两行组成，第一行是n和m，第二行是已经有序的n个数的数列。n和m同时为0标示输入数据的结束，本行不做处理。
Output  输出
对于每个测试实例，输出插入新的元素后的数列。
Sample Input  样例输入
3 3
1 2 4
0 0
Sample Output  示例输出
1 2 3 4
*/
#include<iostream>

using namespace std;
int main()
{
    int m,n;
    while(cin >> n >> m){
        if(m==0 && n==0) break;
        int num,count=0;
        for(int i=0;i<n && cin >> num;i++){
            if(m<=num && count==0){
                cout << m << ' ';
                count ++;
            }
            cout << num ;
            if(i!=n-1) cout << ' ' ;
            if(count==0 && i == n-1) cout << ' ' << m;
            cout << endl;

        }
    }
    return 0;
}