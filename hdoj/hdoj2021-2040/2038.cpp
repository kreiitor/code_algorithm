/*
A和B 都是由3个整数组成，分别表示时分秒，比如，假设A为34 45 56，就表示A所表示的时间是34小时 45分钟 56秒。
 
Input  输入
输入数据有多行组成，首先是一个整数N，表示测试实例的个数，然后是N行数据，每行有6个整数AH,AM,AS,BH,BM,BS，分别表示时间A和B所对应的时分秒。题目保证所有的数据合法。
Output  输出
对于每个测试实例，输出A+B，每个输出结果也是由时分秒3部分组成，同时也要满足时间的规则（即：分和秒的取值范围在0~59），每个输出占一行，并且所有的部分都可以用32位整数表示。
Sample Input  样本输入
2
1 2 3 4 5 6
34 45 56 12 23 34
Sample Output  样本输出
5 7 9
47 9 30
*/
// 时间相加（第二题）—— 老铁防寄进阶版
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