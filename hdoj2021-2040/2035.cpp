/*
求A^B的最后三位数表示的整数。
说明：A^B的含义是“A的B次方”
 
Input  输入
输入数据包含多个测试实例，每个实例占一行，由两个正整数A和B组成（1<=A,B<=10000），如果A=0, B=0，则表示输入数据的结束，不做处理。
Output  输出
对于每个测试实例，请输出A^B的最后三位表示的整数，每个输出占一行。
Sample Input  样本输入
2 3
12 6
6789 10000
0 0
Sample Output  样本输出
8
984
1

*/
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int ah, am, as, bh, bm, bs;
        cin >> ah >> am >> as >> bh >> bm >> bs;
        
        int tot_s = as + bs;
        int tot_m = am + bm + tot_s / 60;
        int tot_h = ah + bh + tot_m / 60;
        
        cout << tot_h << " "
             << (tot_m % 60) << " "
             << (tot_s % 60) << endl;
    }
    return 0;
}