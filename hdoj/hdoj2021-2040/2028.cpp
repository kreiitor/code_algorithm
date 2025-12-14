/*
求n个数的最小公倍数。
1.最小公倍数lcm和最大公因数gcd有关系：a*b=lcm*gcd
2.在已知一个求另一个的时候，最好先除后乘，防止范围溢出
3.所以这两类问题实际上是一类问题，如何求最大公因数，这里使用辗转相除法
4.在使用accumulate时应该注意，要确定初始的单位值，比如lcm算法的单位值为1（因为1和谁的最小公倍数都是那个数本身）
5.accumulate函数，适用于第一第二个生成一个值再和第三个生成一个值，以此递推

Input  输入
输入包含多个测试实例，每个测试实例的开始是一个正整数n，然后是n个正整数。
Output  输出
为每组测试数据输出它们的最小公倍数，每个测试实例的输出占一行。你可以假设最后的输出是一个32位的整数。
Sample Input  样例输入
2 4 6
3 2 5 7
Sample Output  示例输出
12
70
*/
#include<iostream>
#include<numeric>
#include<vector>
#include<algorithm>

int get_gcd(int m, int n){
    while(n!=0){
        int r = m%n;
        m = n;
        n = r;
    }
    return m;
}

using namespace std;
int main()
{
    int n,num;
    vector<int> nums;
    while(cin>>n){
        if(n==0) continue;
        if(n==1){
            cin >> num;
            continue;
        }
        nums.clear();
        for(int i=0;i<n && cin >> num;i++){
            nums.push_back(num);
        }

        int lcm = accumulate(nums.begin(),nums.end(),1,[](int a,int b){return a/get_gcd(a,b)*b;});
        cout << lcm << endl;
    }
}