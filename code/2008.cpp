/*
统计给定的n个数中，负数、零和正数的个数。
1.cpp中的类型十分的重要，并不和python一样可以自动选择
2.不要出现需要double但是使用了int的情况
3.

Input  输入
输入数据有多组，每组占一行，每行的第一个数是整数n（n<100），表示需要统计的数值的个数，然后是n个实数；如果n=0，则表示输入结束，该行不做处理。
Output  输出
对于每组输入数据，输出一行a,b和c，分别表示给定的数据中负数、零和正数的个数。
Sample Input  样例输入
6 0 1 2 3 -1 0
5 1 2 3 4 0.5
0 
Sample Output  示例输出
1 2 3
0 0 5
*/
#include<iostream>
#include<string>
#include<sstream>

using namespace std;
int main()
{
    string line;
    while(getline(cin,line)){
        //跳过空行
        if(line.empty()) continue;
        int n;
        double num;
        stringstream ss(line);
        ss >> n;
        if(n==0) continue;
        int a=0,b=0,c=0;
        for(int i=0;i<n && ss >> num;i++){
            if(num<0) a++;
            else if(num==0) b++;
            else c++;
        }
        cout << a << ' ' << b << ' ' << c << endl;
    }
    return 0;
}