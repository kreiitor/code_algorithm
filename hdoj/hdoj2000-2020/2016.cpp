/*
输入n(n<100)个数，找出其中最小的数，将它与最前面的数交换后输出这些数。
1.在使用不会要函数内返回值的时候，传参尽量使用引用，可以节省内存开支 const vector<int> & arr

Input  输入
输入数据有多组，每组占一行，每行的开始是一个整数n，表示这个测试实例的数值的个数，跟着就是n个整数。n=0表示输入的结束，不做处理。
Output  输出
对于每组输入数据，输出交换后的数列，每组输出占一行
Sample Input  样例输入
4 2 1 3 4
5 5 4 3 2 1
0
Sample Output  示例输出
1 2 3 4
1 4 3 2 5
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // 找最小值的下标
        int minIndex = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[minIndex]) {
                minIndex = i;
            }
        }

        // 交换最前面的数与最小值
        swap(a[0], a[minIndex]);

        // 输出
        for (int i = 0; i < n; i++) {
            if (i > 0) cout << " ";
            cout << a[i];
        }
        cout << endl;
    }
    return 0;
}
