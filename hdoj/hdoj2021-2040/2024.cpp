/*
输入一个字符串，判断其是否是C的合法标识符。
1.第一个字符不能是数字
2.字符只能是字母，数字下划线
3.对于字符串，整行读入，推荐使用getline来得到字符串
4.在进行不同类型读入时，换行符应该用占位变量吃掉
string dummy; //消耗掉第一行末尾的换行符，防止接下来读取的时候算到下一行
    getline(cin,dummy);

Input  输入
输入数据包含多个测试实例，数据的第一行是一个整数n,表示测试实例的个数，然后是n行输入数据，每行是一个长度不超过50的字符串。
Output  输出
对于每组输入数据，输出一行。如果输入数据是C的合法标识符，则输出"yes"，否则，输出“no”。
Sample Input  样例输入
3
12ajf
fi8x_a
ff  ai_2
Sample Output  示例输出
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
    string dummy; //消耗掉第一行末尾的换行符，防止接下来读取的时候算到下一行
    getline(cin,dummy);
    while(n--){
        string s;
        bool flag = true;
        getline(cin,s);
        if(s.empty()||(s[0]>='0' && s[0]<='9')){
            flag = false;
        }else{
            for(int i=0;i<s.length();i++){
                if(!((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')||(s[i]>='0' && s[i]<='9')||(s[i]=='_'))){
                    flag = false;
                    break;
                }
            }
        }
        cout << (flag?"yes":"no") << endl;
    }
    return 0;
}