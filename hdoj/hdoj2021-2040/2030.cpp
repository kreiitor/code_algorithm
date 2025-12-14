/*
统计给定文本文件中汉字的个数。
1.这个题是一个关键点，如何在cpp中判断一个字符是否是汉字
2.利用中文字符在 GBK/GB2312/GB18030 内码中高位为1（signed char 时表现为负）的特性

Input  输入
输入文件首先包含一个整数n，表示测试实例的个数，然后是n段文本。
Output  输出
对于每一段文本，输出其中的汉字的个数，每个测试实例的输出占一行。
[Hint:]从汉字机内码的特点考虑~
Sample Input  样例输入
2
WaHaHa! WaHaHa! 今年过节不说话要说只说普通话WaHaHa! WaHaHa!
马上就要期末考试了Are you ready?
Sample Output  示例输出
14
9
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string dummy;
    getline(cin, dummy);  // 消耗 cin >> n 后剩余的换行符

    for(int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        int cnt = 0;
        for(size_t j = 0; j < s.length(); ) {
            // 利用中文字符在 GBK/GB2312/GB18030 内码中高位为1（signed char 时表现为负）的特性
            if(static_cast<unsigned char>(s[j]) > 127) {  // 或者直接写 if(s[j] < 0) 效果相同（char 为 signed 时）
                cnt++;
                j += 2;
            } else {
                j++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}