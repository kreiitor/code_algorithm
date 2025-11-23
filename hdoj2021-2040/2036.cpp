/*
输入数据包含多个测试实例，每个测试实例占一行，每行的开始是一个整数n(3<=n<=100)，它表示多边形的边数（当然也是顶点数），
然后是按照逆时针顺序给出的n个顶点的坐标（x1, y1, x2, y2... xn, yn）,为了简化问题，这里的所有坐标都用整数表示。
输入数据中所有的整数都在32位整数范围内，n=0表示数据的结束，不做处理。

1.多边形面积的鞋带公式
2.在处理需要xi和xi+1操作，最后要xn和x1操作时，可以注意用模运算 (i + 1) % n 来处理首尾相连
3.首尾相连就用模，这是一个很常用的思想

Output  输出
对于每个测试实例，请输出对应的多边形面积，结果精确到小数点后一位小数。
每个实例的输出占一行。
Sample Input  样本输入
3 0 0 1 0 0 1
4 1 0 0 1 -1 0 0 -1
0
Sample Output  样本输出
0.5
2.0
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

// 使用结构体来封装数据，提高可读性
struct Point {
    double x, y;
};

// 纯函数：计算由 N 个点定义的多边形的面积
// 核心思想：FP 中的 Reduce/Fold，将 N 个点归约（累加）成一个面积值
double calculate_polygon_area(const vector<Point>& coors) {
    int n = coors.size();
    
    // 边界检查：少于三个点无法构成多边形
    if (n < 3) {
        return 0.0;
    }
    
    double area_sum = 0.0;
    
    // 实施鞋带公式：Area = 0.5 * |(x1y2 + x2y3 + ... + xny1) - (y1x2 + y2x3 + ... + ynx1)|
    for (int i = 0; i < n; ++i) {
        // 当前点 P_i
        const Point& p_i = coors[i];
        
        // 下一个点 P_{i+1}，注意用模运算 (i + 1) % n 来处理首尾相连
        const Point& p_next = coors[(i + 1) % n];
        
        // 累加项：(x_i * y_{i+1} - y_i * x_{i+1})
        area_sum += (p_i.x * p_next.y - p_i.y * p_next.x);
    }
    
    // 返回面积：0.5 * 绝对值
    return 0.5 * abs(area_sum);
}

int main() {
    // 设置 I/O 精度，确保能精确输出 0.5
    // 注意：我们将精度提高到 10 位，以保证 0.5 能被准确输出，避免四舍五入到 0.0
    cout << fixed << setprecision(1); 
    
    int n_int;
    while (cin >> n_int) {
        if (n_int == 0) break;
        
        // 读取输入
        vector<Point> coors;
        coors.reserve(n_int); 
        for (int i = 0; i < n_int; ++i) {
            double x, y;
            if (!(cin >> x >> y)) return 0; 
            coors.push_back({x, y});
        }

        // --- 核心逻辑：数据转换 ---
        // 1. 计算多边形面积 (Transformation)
        double S = calculate_polygon_area(coors);
        
        cout << S << endl;
    }
    return 0;
}