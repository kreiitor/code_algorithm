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
#include<algorithm>
#include<string>
#include<vector>
#include<sstream>
#include<cmath>

using namespace std;
int main()
{
    string line;
    while(getline(cin,line)){
        //跳过空行
        if(line.empty()) continue;
        stringstream ss(line);
        int n,m;
        ss >> n;
        vector<double> scores(n);
        while(ss>>m){
            scores.push_back(m);
        }
        double m = 0.0;
        for(double t : scores){
            m += t;
        }
        m = (m-max(scores)-min(scores))/n
        cout << m << endl;
    }
    return 0;
}