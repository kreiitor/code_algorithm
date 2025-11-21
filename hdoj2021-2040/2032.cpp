/*
还记得中学时候学过的杨辉三角吗？具体的定义这里不再描述，你可以参考以下的图形：
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1


Input  输入
输入数据包含多个测试实例，每个测试实例的输入只包含一个正整数n（1<=n<=30），表示将要输出的杨辉三角的层数。
Output  输出
对应于每一个输入，请输出相应层数的杨辉三角，每一层的整数之间用一个空格隔开，每一个杨辉三角后面加一个空行。
Sample Input  样例输入
2 3
Sample Output  示例输出
1
1 1

1
1 1
1 2 1
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