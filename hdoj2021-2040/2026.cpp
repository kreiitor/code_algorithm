/*
输入一个英文句子，将每个单词的第一个字母改成大写字母。
1.字符操作库cctype

Input  输入
输入数据包含多个测试实例，每个测试实例是一个长度不超过100的英文句子，占一行。
Output  输出
请输出按照要求改写后的英文句子。
Sample Input  样例输入
i like acm
i want to get an accepted
Sample Output  示例输出
I Like Acm
I Want To Get An Accepted
*/
#include<iostream>
#include<string>
#include<cctype>

using namespace std;
int main()
{
    string line;
    while(getline(cin,line)){
        if(line.empty()) continue;
        int len = line.length();
        for(int i=0;i<len;i++){
            if(i==0) line[0] = toupper(line[0]);
            else{
                if(line[i-1] == ' '){
                    line[i] = toupper(line[i]);
                }
            }
        }
        for(int i=0;i<len;i++){
            cout << line[i];
        }
        cout << endl;
        
    }
}