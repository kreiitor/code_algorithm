/*
输入一个十进制数N，将它转换成R进制数输出。
1.关键在于vector.size()是无符号整数，如果n=0,size-1会变成很大的数，导致崩溃
2.涉及字符串输出的时候，不用vector,而是string,涉及字符串操作更得心应手。

Input  输入
输入数据包含多个测试实例，每个测试实例包含两个整数N(32位整数)和R（2<=R<=16, R<>10）。
Output  输出
为每个测试实例输出转换后的数，每个输出占一行。如果R大于10，则对应的数字规则参考16进制（比如，10用A表示，等等）。
Sample Input  样例输入
7 2
23 12
-4 3
Sample Output  示例输出
111
1B
-11
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n, r;
    char num_bit[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    
    while (cin >> n >> r) {
        string s;
        bool negative = (n < 0);
        if (n < 0) n = -n;
        
        if (n == 0) {
            s = "0";
        } else {
            while (n) {
                s.push_back(num_bit[n % r]);
                n /= r;
            }
            reverse(s.begin(), s.end());
        }
        
        if (negative) cout << "-";
        cout << s << endl;
    }
    return 0;
}