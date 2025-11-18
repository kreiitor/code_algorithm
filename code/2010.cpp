/*
春天是鲜花的季节，水仙花就是其中最迷人的代表，数学上有个水仙花数，他是这样定义的：
“水仙花数”是指一个三位数，它的各位数字的立方和等于其本身，比如：153=1^3+5^3+3^3。
现在要求输出所有在m和n范围内的水仙花数。
1.
2.

Input  输入
输入数据有多组，每组占一行，包括两个整数m和n（100<=m<=n<=999）。
Output  输出
对于每个测试实例，要求输出所有在给定范围内的水仙花数，就是说，输出的水仙花数必须大于等于m,并且小于等于n，如果有多个，则要求从小到大排列在一行内输出，之间用一个空格隔开;
如果给定的范围内不存在水仙花数，则输出no;
每个测试实例的输出占一行。
Sample Input  样例输入
100 120
300 380
Sample Output  示例输出
no
370 371
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool is_iris(int n){
    vector<int> digits(3);
    int i = 0, num = n;
    while(num && i<3){
        digits[i] = num%10;
        num /= 10;
        i++;
    }
    num = 0;
    for(int t : digits){
        num += t*t*t;
    }
    return num == n;
}

int main()
{
    int m,n;
    while(cin >> m >> n){
        vector<int> iris;
        for(int i=m;i<=n;i++){
            if(is_iris(i))
                iris.push_back(i);
        }
        if(iris.empty()) cout << "no" ;
        else{
            int size = iris.size();
            for(int i=0;i<size;i++){
                if(i < size-1) cout << iris[i] << ' ';
            }
            cout << iris[size-1] << endl;
        }
        cout << endl;
    }
    return 0;
}