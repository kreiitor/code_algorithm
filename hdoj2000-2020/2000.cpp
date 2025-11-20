/* 
2000题，根据输入的字符串，按照ascii码进行排序，输出排序结果
主要锻炼输入输出能力，中间无如空格等字符情况
1.cpp中的字符可以之间进行比较
2.cin一行就是读取一行数据
*/



#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{   
    string input;

    while(cin >> input){
        vector<char> chars(input.begin(),input.end());
        sort(chars.begin(),chars.end());
        for(int i=0;i<3;i++){
            if(i!=0) cout << "";
            cout << chars[i];
        }
        cout << endl;
    }
    return 0;
}