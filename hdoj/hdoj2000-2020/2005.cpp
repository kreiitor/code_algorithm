/*
给定一个日期，输出这个日期是该年的第几天。
1.输入输出练习，有分隔符版本

Input  输入
输入数据有多组，每组占一行，数据格式为YYYY/MM/DD组成，具体参见sample input ,另外，可以向你确保所有的输入数据是合法的。
Output  输出
对于每组输入数据，输出一行，表示该日期是该年的第几天。
Sample Input  样例输入
1985/1/20
2006/3/12
Sample Output  示例输出
20
71
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    int year,month,day;
    char sep;
    while(cin >> year >> sep >> month >> sep >> day){
        bool flag = false;
        if(year%400==0 || (year%4==0 && year%100!=0)) flag = true;
        vector<int> days{31,28,31,30,31,30,31,31,30,31,30,31};
        int total = 0;
        for(int i=0;i<month-1;i++){
            total = total + days[i];
            if(flag && i == 1) total++;
        }
        total = total + day;
        cout << total << endl;
    }
    return 0;
}