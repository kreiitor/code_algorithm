/*
There must be many A + B problems in our HDOJ , now a new one is coming.
Give you two hexadecimal long longegers , your task is to calculate the sum of them,and prlong long it in hexadecimal too.
Easy ? AC it !
1.如果想借助标准函数的话，可以直接使用stoll(a,nullptr,16)，将十六进制转换为longlong十进制，然后使用cout << '+/-' << hex << sum << endl;
2.然后使用cout << '+/-' << hex << sum << endl;进行输出

Input
The input contains several test cases, please process to the end of the file.
Each case consists of two hexadecimal long longegers A and B in a line seperated by a blank.
The length of A and B is less than 15.
Output
For each test case,prlong long the sum of A and B in hexadecimal in one line.
Sample Input
+A -A
+1A 12
1A -9
-1A -12
1A -AA
Sample Output
0
2C
11
-2C
-90
*/

#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

pair<bool,long long> todecimal(string str){
    string num_bit = "0123456789ABCDEF";
    long long len = str.length(),num=0;
    bool is_positive = true;
    for(long long i=0;i<=len-1;++i){
        if(str[i]==' ') continue;
        if(str[i]=='-'){
            is_positive = false;
        }else if(str[i]=='+'){
            is_positive = true;
        }else{
        num = num*16 + (long long)num_bit.find(str[i]);
        }
    }
    return {is_positive,num};
}

string tohexadecimal(long long n){
    bool is_positive = (n>=0);
    n = abs(n);
    if(n==0) return "0";
    string res,num_bit = "0123456789ABCDEF";
    while(n){
        res.push_back(num_bit[n%16]);n/=16;
    }
    if(!is_positive) res.push_back('-');
    reverse(res.begin(),res.end());
    return res;
}

int main()
{
    string a,b;
    pair<bool,long long> a_,b_;
    long long res;
    while(cin>>a>>b){
        a_=todecimal(a);b_=todecimal(b);
        long long a_int = (a_.first)?a_.second:-a_.second,b_int=(b_.first)?b_.second:-b_.second;
        res = a_int + b_int;
        cout << tohexadecimal(res) << endl;
    }
    return 0;
}