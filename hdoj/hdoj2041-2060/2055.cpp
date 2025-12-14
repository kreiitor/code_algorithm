/*
we define f(A) = 1, f(a) = -1, f(B) = 2, f(b) = -2, ... f(Z) = 26, f(z) = -26;
Give you a letter x and a number y , you should output the result of y+f(x).
 

Input
On the first line, contains a number T.then T lines follow, each line is a case.each case contains a letter and a number.
Output
for each case, you should the result of y+f(x) on a line.
Sample Input
6
R 1
P 2
G 3
r 1
p 2
g 3
Sample Output
19
18
10
-17
-14
-4
*/
#include <iostream>
#include<cctype>

using namespace std;

int main()
{
    int T;cin>>T;char c;int n,charNum;
    for(int i=0;i<T&&cin>>c>>n;++i){
        if(isupper(c)){
            charNum = c-'A'+1;
            cout << charNum+n << endl;
        }else{
            charNum = c-'a'+1;
            cout << n-charNum << endl;
        }
    }
    return 0;
}