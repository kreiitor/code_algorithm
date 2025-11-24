/*
给定三条边，请你判断一下能不能组成一个三角形。
1.三个正数判断只用判断两边之和大于第三遍。
2.正数double正整数int

Input  输入
输入数据第一行包含一个数M，接下有M行，每行一个实例，包含三个正数A,B,C。其中A,B,C <1000;
Output  输出
对于每个测试实例，如果三条边长A,B,C能组成三角形的话，输出YES，否则NO。
Sample Input  样本输入
2
1 2 3
2 2 2
Sample Output  样本输出
NO
YES
*/
#include <iostream>
#include<cmath>
using namespace std;

int main() 
{
    int m;
    cin >> m;
    double a,b,c;
    for(int i=0;i<m &&cin>>a>>b>>c;++i){
        bool is_triangle=(a+b>c)&&(a+c>b)&&(b+c>a);
        cout << (is_triangle?"YES":"NO") << endl;
    }

    return 0;
}