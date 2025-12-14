/*
Give you two numbers A and B, if A is equal to B, you should print "YES", or print "NO".
1.string容器的find函数，没找到返回-1否则返回第一个满足字符的下标

Input
each test case contains two numbers A and B.
Output
for each case, if A is equal to B, you should print "YES", or print "NO".
Sample Input
1 2
2 2
3 3
4 3
Sample Output
NO
YES
YES
NO

*/
#include <iostream>
#include <string>
#include <algorithm>
#include <utility> // For pair

using namespace std;

// 移除多余的零
pair<string, string> funct(string str) {
    size_t i = str.find('.');
    string strInt = str;
    string strFloat = "";

    if (i != string::npos) {
        strInt = str.substr(0, i);
        strFloat = str.substr(i + 1);
    }
    
    size_t first_non_zero_int = strInt.find_first_not_of('0');
    if (first_non_zero_int == string::npos) {
        strInt = "0";
    } else {
        strInt = strInt.substr(first_non_zero_int);
    }

    if (!strFloat.empty()) {
        size_t last_non_zero_float = strFloat.find_last_not_of('0');

        if (last_non_zero_float != string::npos) {
            strFloat = strFloat.substr(0, last_non_zero_float + 1);
        } else {
            strFloat = ""; 
        }
    }
    
    return {strInt, strFloat};
}

int main()
{
    string A, B;
    while (cin >> A >> B) {
        pair<string, string> normalizedA = funct(A);
        pair<string, string> normalizedB = funct(B);

        if (normalizedA.first == normalizedB.first && normalizedA.second == normalizedB.second) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}