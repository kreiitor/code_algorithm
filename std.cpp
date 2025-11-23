// template.cpp
// 常用竞赛模板（C++17）
// 作者：your-name
// 说明：将 solve() 中代码替换为每道题目的实现。


#include <bits/stdc++.h>
using namespace std;


// 常用别名
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using pii = pair<int,int>;


// 常用常数
const int INF = 0x3f3f3f3f;
const ll LINF = (ll)4e18;


// 快速读入（当需要超大输入时可用）
static inline void fast_io(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
}


// 模板入口：把每道题的逻辑放在 solve() 内
void solve(){
// 示例：读入 n，然后 n 行区间，贪心按结束时间排序
int n;
while (cin >> n) {
if (n == 0) return; // 根据题意结束
vector<pair<int,int>> a;
for (int i = 0; i < n; ++i) {
int s,e; cin >> s >> e;
a.emplace_back(e, s);
}
sort(a.begin(), a.end());
int cnt = 0;
int last_end = INT_MIN;
for (auto &p : a) {
int end = p.first, start = p.second;
if (start >= last_end) {
++cnt;
last_end = end;
}
}
cout << cnt << '\n';
}
}


int main(){
fast_io();
solve();
return 0;
}