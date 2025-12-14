/*
Problem Description  问题描述
对于输入的每个字符串，查找其中的最大字母，在该字母后面插入字符串“(max)”。
1.对于字符串的操作，有标准库cctype,其中有转大小写函数toupper,tolower
2.再进行大小写转换的时候， 必须转换为unsigned char避免未定义行为
char c = '\xFF'; // 负值字符
std::toupper(static_cast<unsigned char>(c)); // 安全
std::toupper(c); // 可能崩溃！
3.Google C++ Style Guide 明确规定
"对于输入参数，优先使用 const T& 而不是值传递，除非参数是小型内置类型（如int）或需要拷贝的对象。

Input  输入
输入数据包括多个测试实例，每个实例由一行长度不超过100的字符串组成，字符串仅由大小写字母构成。
Output  输出
对于每个测试实例输出一行字符串，输出的结果是插入字符串“(max)”后的结果，如果存在多个最大的字母，就在每一个最大字母后面都插入"(max)"。
Sample Input  样例输入
abcdefgfedcba
xxxxx
Sample Output  示例输出
abcdefg(max)fedcba
x(max)x(max)x(max)x(max)x(max)
*/
#include<iostream>
#include<string>
#include<algorithm>

bool comp(char a,char b){
    return a>b;
}

using namespace std;
int main()
{
    string line;
    while(getline(cin,line)){
        //跳过空行
        if(line.empty()) continue;
        string temp = line;
        sort(line.begin(),line.end(),comp);
        char max_s=line[0];
        for(char s:temp){
            cout << s ;
            if(s==max_s) cout << "(max)";
        }
        cout << endl;
    }
    return 0;
}