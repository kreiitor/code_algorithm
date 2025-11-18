/*
对于表达式n^2+n+41，当n在（x,y）范围内取整数值时（包括x,y）(-39<=x<y<=50)，判定该表达式的值是否都为素数。


Input  输入
输入数据有多组，每组占一行，由两个整数x，y组成，当x=0,y=0时，表示输入结束，该行不做处理。
Output  输出
对于每个给定范围内的取值，如果表达式的值都为素数，则输出"OK",否则请输出“Sorry”,每组输出占一行。
Sample Input  样例输入
0 1
0 0
Sample Output  示例输出
OK
*/

#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

bool is_prime(int n){
    n = abs(n);
    for(int i=2;i<int(sqrt(n))+1;i++){
        if(n%i==0) return false;
    }
    return true;
}

int main()
{
    int x,y;
    while(cin >> x >> y){
        if(x==0 && y==0) continue;
        bool flag = true;
        for(int i=x;i<=y;i++){
            if(!is_prime(i*i+i+41)){
                flag = false;
                break;
            }
        }
        if(flag) cout << "OK" << endl;
        else cout << "Sorry" << endl;
    }
    return 0;
}