/*
输入两点坐标（X1,Y1）,（X2,Y2）,计算并输出两点间的距离，结果保留两位小数。
主要练习输入输出，中间存在空格等字符的情况
1.数字格式保留问题，例如保留两位小数，使用iomanip库进行设置
2.cpp中的数学库为：cmath
*/
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
    double x1,y1,x2,y2;
    while(cin >> x1 >> y1 >> x2 >> y2){
       cout << fixed << setprecision(2) << sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
       cout << endl;
    }
    return 0;
}
