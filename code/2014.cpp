/*
青年歌手大奖赛中，评委会给参赛选手打分。选手得分规则为去掉一个最高分和一个最低分，然后计算平均得分，请编程输出某选手的得分。

Input  输入
输入数据有多组，每组占一行，每行的第一个数是n(2<n<=100)，表示评委的人数，然后是n个评委的打分。
Output  输出
对于每组输入数据，输出选手的得分，结果保留2位小数，每组输出占一行。
Sample Input  样例输入
3 99 98 97
4 100 99 98 97
Sample Output  示例输出
98.00
98.50
 
*/
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<iomanip>

using namespace std;
int main()
{
    string line;
    while(getline(cin,line)){
        //跳过空行
        if(line.empty()) continue;
        stringstream ss(line);
        int n;
        double m;
        ss >> n;
        double total=0.0;
        double max=-11100.0,min=11100.0;
        while(ss>>m){
            total += m;
            if(m>max) max=m;
            if(m<min) min=m;
        }
        double avg = (total-max-min)/(n-2);
        cout <<fixed << setprecision(2) << avg << endl;
    }
    return 0;
}