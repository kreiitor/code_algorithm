/*
求实数的绝对值。
Input  输入
输入数据有多组，每组占一行，每行包含一个实数。
Output  输出
对于每组输入数据，输出它的绝对值，要求每组数据输出一行，结果保留两位小数。
Sample Input  样例输入
123
-234.00
Sample Output  示例输出
123.00
234.00
*/
#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
    double r,r_abs;
    while(cin >> r){
        r_abs = r;
        if(r<=0) r_abs = -r;
        
        cout << fixed << setprecision(2) << r_abs << endl;
    }
    return 0;
}