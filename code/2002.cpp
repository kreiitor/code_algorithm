/*
根据输入的半径值，计算球的体积。
Input  输入
输入数据有多组，每组占一行，每行包括一个实数，表示球的半径。
Output  输出
输出对应的球的体积，对于每组输入数据，输出一行，计算结果保留三位小数。
1.cpp中整数除法会导致取整，想要得到小数需要加上1.0进行强制转换
*/
#include<iostream>
#include<iomanip>

#define PI 3.1415927
using namespace std;

int main()
{
    double r;
    while(cin >> r){
       double v = 4.0/3*PI*r*r*r;
       cout << fixed << setprecision(3) << v << endl;
    }
    return 0;
}