/*
统计每个元音字母在字符串中出现的次数。
1.在用dummy进行换行符占位的时候，要使用getline获取占位符，cin会直接忽略【Enter】

Input  输入
输入数据首先包括一个整数n，表示测试实例的个数，然后是n行长度不超过100的字符串。
Output  输出
对于每个测试实例输出5行，格式如下：
a:num1  a:数字 1
e:num2  e:数字 2
i:num3  i:数字 3
o:num4
u:num5
多个测试实例之间由一个空行隔开。
请特别注意：最后一块输出后面没有空行：）
Sample Input  样例输入
2
aeiou
my name is ignatius
Sample Output  示例输出
a:1
e:1
i:1
o:1
u:1

a:2
e:1
i:3
o:0
u:1
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;
int main()
{
    int n;
    cin >> n;
    string line,dummy;
    getline(cin,dummy);
    for(int i=0;i<n && getline(cin,line);i++){
        if(i>=1) cout << endl;
        vector<int> count(5);
        if(line.empty()) continue;
        for(char t:line){
            if(t=='a') count[0]++;
            else if(t=='e') count[1]++;
            else if(t=='i') count[2]++;
            else if(t=='o') count[3]++;
            else if(t=='u') count[4]++;
            else continue;
        }
        for(int i=0;i<5;i++){
            if(i==0) cout << "a:" << count[0] << endl;
            else if(i==1) cout << "e:" << count[1] << endl;
            else if(i==2) cout << "i:" << count[2] << endl;
            else if(i==3) cout << "o:" << count[3] << endl;
            else if(i==4) cout << "u:" << count[4];
        }
    }
    return 0;
}