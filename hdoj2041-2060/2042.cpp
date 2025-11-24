/*
由于徐老汉没钱，收费员就将他的羊拿走一半，看到老汉泪水涟涟，犹豫了一下，又还给老汉一只。
巧合的是，后面每过一个收费站，都是拿走当时羊的一半，然后退还一只，等到老汉到达市场，就只剩下3只羊了。
你,当代有良知的青年，能帮忙算一下老汉最初有多少只羊吗？
 

Input  输入
输入数据第一行是一个整数N，下面由N行组成，每行包含一个整数a(0<a<=30),表示收费站的数量。
Output  输出
对于每个测试实例，请输出最初的羊的数量,每个测试实例的输出占一行。
Sample Input  样本输入
2
1
2
Sample Output  样本输出
4
6
*/

#include <iostream>
#include<vector>
using namespace std;


int main()
{
    int n;cin>>n;
    int a;
    for(int j=0;j<n&&cin >> a;++j){
        int m=3;
        for(int i=0;i<a;++i){
        m = 2*(m-1);
        }
        cout << m << endl;
    }
    
    
    return 0;
}