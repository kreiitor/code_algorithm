/*
“回文串”是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。请写一个程序判断读入的字符串是否是“回文”。
 

Input  输入
输入包含多个测试实例，输入数据的第一行是一个正整数n,表示测试实例的个数，后面紧跟着是n个字符串。
Output  输出
如果一个字符串是回文串，则输出"yes",否则输出"no".
Sample Input  样例输入
4
level
abcde
noon
haha
Sample Output  示例输出
yes
no
yes
no
*/
#include<iostream>
#include<string>

using namespace std;
int main()
{
    int n;
    cin >> n;
    string dummy;
    getline(cin,dummy);//占位换行符

    string line;
    for(int i=0;i<n && getline(cin,line);i++){
        int len = line.length();
        int l=0,r=len-1;
        bool flag = true;
        while(l<r){
            if(line[l]!=line[r]){
                flag = false;
                break;
            }
            l++;r--;
        }
        cout << (flag?"yes":"no") << endl;
    }

    return 0;
}