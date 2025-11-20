/*
对于给定的一个字符串，统计其中数字字符出现的次数。
1.这题的关键是如何判断是否是数字，这里可以使用以下两种方法：
2.首先是标准库#include<cctype>，其中的isdigit,isalpha等函数
3.其次是用ascii码的范围line[j]>='0' && line[j]<='9'

Input  输入
输入数据有多行，第一行是一个整数n，表示测试实例的个数，后面跟着n行，每行包括一个由字母和数字组成的字符串。
 

Output  输出
对于每个测试实例，输出该串中数值的个数，每个输出占一行。
 

Sample Input  样例输入
2
asdfasdf123123asdfasdf
asdf111111111asdfasdfasdf
 

Sample Output  示例输出
6
9
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cctype>

using namespace std;
int main()
{
    int n;
    string line;
    cin >> n;
    for(int i=0;i<n && cin>>line;i++){
        int digital_count=0;
        for(int j=0;j<line.length();j++){
            if(line[j]>='0' && line[j]<='9') digital_count++;
        }
        cout << digital_count << endl;
    }
    
    return 0;
}