/*
给你n个整数，求他们中所有奇数的乘积。
1.依旧输入输出，这次是一行之中空格分隔符但是不定个数的数据
2.这次引入一个sstream库用来处理输入输出！！
3.还要进行去重操作
4.要处理大整数的int溢出问题

Input  输入
输入数据包含多个测试实例，每个测试实例占一行，每行的第一个数为n，表示本组数据一共有n个，接着是n个整数，你可以假设每组数据必定至少存在一个奇数。
Output  输出
输出每组数中的所有奇数的乘积，对于测试实例，输出一行。
Sample Input  样例输入
3 1 2 3
4 2 3 4 5
Sample Output  示例输出
3
15
*/
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<unordered_set>

using namespace std;
int main()
{
    string line;
    while(getline(cin,line)){
        //跳过空行
        if(line.empty()) continue;
        stringstream ss(line);
        int n;
        ss >> n;

        long long multiple = 1;
        unordered_set<int> seen;
        int num;
        for(int i=0;i<n && ss >> num;i++){
            if(num%2!=0 && seen.find(num) == seen.end()){
                multiple = multiple * num;
                seen.insert(num);
            }
        }
        cout << multiple << endl;
    }
    return 0;
}