/*
Give you the width and height of the rectangle,darw it.

Input
Input contains a number of test cases.For each case ,
there are two numbers n and m (0 < n,m < 75)indicate the width and height of the rectangle.Iuput ends of EOF.
Output
For each case,you should draw a rectangle with the width and height giving in the input.
after each case, you should a blank line.
Sample Input
3 2
Sample Output
+---+
|   |
|   |
+---+
*/
#include <iostream>

using namespace std;

int main()
{
    int n,m,count=0;
    while(cin >> n >> m){
        if(count>0) cout << endl;
        for(int i=0;i<=m+1;++i){//高度,因为上下多两行用来做边
            if(i==0||i==m+1){
                cout << '+';
                for(int j=0;j<n;++j) cout << '-';
                cout << "+\n";
            }else{
                cout << '|';
                for(int j=0;j<n;++j) cout << ' ';
                cout << "|\n";
            }
        }
        ++count;
    }
    return 0;
}