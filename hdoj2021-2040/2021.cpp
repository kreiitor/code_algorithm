/*
如果每个老师的工资额都知道，最少需要准备多少张人民币，才能在给每位老师发工资的时候都不用老师找零呢？
这里假设老师的工资都是正整数，单位元，人民币一共有100元、50元、10元、5元、2元和1元六种。
1.经典的贪心算法

Input  输入
输入数据包含多个测试实例，每个测试实例的第一行是一个整数n（n<100），表示老师的人数，然后是n个老师的工资。
n=0表示输入的结束，不做处理。
Output  输出
对于每个测试实例输出一个整数x,表示至少需要准备的人民币张数。每个输出占一行。
Sample Input  样例输入
3
1 2 3
0
Sample Output  示例输出
4
*/
#include<iostream>

using namespace std;
int main()
{
    int money[] = {100,50,10,5,2,1};
    int n;
    while(cin>>n){
        if(n==0) break;
        int salary,count=0;
        for(int i=0;i<n && cin>>salary;i++){
            for(int j=0;j<6;j++){
                count += salary/money[j];
                salary -= salary/money[j]*money[j];
            }
        }
        cout << count << endl;
        
    }
    return 0;
}