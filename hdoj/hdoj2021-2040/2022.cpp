/*
分数送上来了，是我做决定的时候了，我的一个选拔原则是，要选一个面试分数绝对值（必须还是32位整数）最大的MM。
特别说明：如果不幸选中一个负分的MM,也没关系，因为我觉得，如果不能吸引你，那要想法恶心你。
 

Input  输入
输入数据有多组，每组的第一行是两个整数m和n，表示应聘MM的总共的行列数，然后是m行整数，每行有n个，m和n的定义见题目的描述。
Output  输出
对于每组输入数据，输出三个整数x,y和s，分别表示选中的MM的行号、列号和分数。
note:行号和列号从一开始，如果有多个MM的分数绝对值一样，那么输出排在最前面的一个（即行号最小的那个，如果行号相同则取列号最小的那个）。
Sample Input  样例输入
2 3
1 4 -3
-7 3 0
Sample Output  示例输出
2 1 -7

*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
    int m,n;
    while(cin >> m >> n){
        int score;
        int row_index,col_index,max_abs_score;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n && cin>>score;j++){
                if(i==1&&j==1){
                    row_index=1;col_index=1;max_abs_score=score;
                    continue;
                }
                if(abs(score)>abs(max_abs_score)){
                    row_index = i;col_index=j;max_abs_score=score;
                }
            }
        }
        cout << row_index << ' ' << col_index << ' ' << max_abs_score << endl;
    }
    return 0;
}