/*
输入数据包含多个测试实例，每个测试实例的第一行只有一个整数n(n<=100)，表示你喜欢看的节目的总数，然后是n行数据，
每行包括两个数据Ti_s,Ti_e (1<=i<=n)，分别表示第i个节目的开始和结束时间，目标是能看尽量多的完整节目
为了简化问题，每个时间都用一个正整数表示。n=0表示输入结束，不做处理。


Output  输出
对于每个测试实例，输出能完整看到的电视节目的个数，每个测试实例的输出占一行。
Sample Input  样本输入
12
1 3
3 4
0 7
3 8
15 19
15 20
10 15
8 18
6 12
5 10
4 14
2 9
0
Sample Output  样本输出
5
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
 * 经典区间调度问题（Interval Scheduling）。
 * 目标：选择尽量多的互不重叠区间。
 * 策略：按结束时间从小到大排序，每次优先选择结束最早的节目。
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n;
        if (!(cin >> n)) return 0;    // 输入结束
        if (n == 0) break;            // n=0 表示终止

        vector<pair<int,int>> a;      // 存 (end, start)

        for (int i = 0; i < n; ++i) {
            int s, e;
            cin >> s >> e;
            a.emplace_back(e, s);     // 为了按结束时间排序，存成 (e, s)
        }

        sort(a.begin(), a.end());     // 按结束时间升序

        int cnt = 0;
        int last_end = INT_MIN;       // 上一个已选节目结束时间

        for (auto &p : a) {
            int end = p.first;
            int start = p.second;
            if (start >= last_end) {  // 不重叠（可以接触，即 start == last_end）
                ++cnt;
                last_end = end;
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}
