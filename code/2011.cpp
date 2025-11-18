/*
多项式的描述如下：
1 - 1/2 + 1/3 - 1/4 + 1/5 - 1/6 + ...
现在请你求出该多项式的前n项的和。
Input  输入
输入数据由2行组成，首先是一个正整数m（m<100），表示测试实例的个数，第二行包含m个正整数，对于每一个整数(不妨设为n,n<1000），求该多项式的前n项的和。
Output  输出
对于每个测试实例n，要求输出多项式前n项的和。每个测试实例的输出占一行，结果保留2位小数。
Sample Input  样例输入
2
1 2
Sample Output  示例输出
1.00
0.50
*/
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<iomanip>

using namespace std;

double poly(int num){
    double total = 0.0;
    for(int i=1;i<=num;i++){
        if(i%2==0) total -= 1.0/i;
        else total += 1.0/i;
    }
    return total;
}

int main()
{
    int m;
    cin >> m;
    string line;
    while(getline(cin,line)){
        if(line.empty()) continue;
        stringstream ss(line);
        int num;
        while(ss>>num){
            cout << fixed << setprecision(2) << poly(num) << endl;
        }
    }
    return 0;
}