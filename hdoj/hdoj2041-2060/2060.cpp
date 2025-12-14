/*
台面上共有 21 颗目标球，包括 15 颗红球和 6 颗彩球：黄球、绿球、棕球、蓝球、粉球、黑球。
玩家需使用白色主球将目标球击入袋中，其击入袋中的球所对应的固定分值总和即为该玩家的得分。
玩家首先需将一颗红球击入袋中，随后获得红球分值（1 分），接着获得击打彩球的机会，之后交替进行。
在所有红球入袋前，被击入袋中的彩球需取出放回置球点。换言之，若台面上仅剩彩球，
玩家应按以下顺序击打目标球：黄球（2 分）、绿球（3 分）、棕球（4 分）、蓝球（5 分）、粉球（6 分）、黑球（7 分）。
彩球入袋后不再取出，当台面无球剩余时游戏结束，得分较高者获胜。
注：红球入袋后不再取出。
例如，如果棋盘上有 12 个红球（如果棋盘上仍有红球剩余，可以确定所有颜色
球必须在球台上）。因此，假设菲尔普能够连续将球击入洞中，他能得到的最高分数是
12 * 1（一杆打进 12 个红球）+ 7 * 12（击入红球后，目标应为价值最高的黑球）+ 2 + 3 + 4 + 5 + 6 + 7（当无红球剩余时，将所有彩球击入袋中）。
现在，你的任务是判断菲利普在告知你台面情况（还剩多少颗目标球未入袋，以及对手的得分）时，是否应该做出放弃的决定。
如果菲利普仍有获胜的机会，只需打印"Yes"，否则打印"No"。（注：如果他在台面上可能获得的最大得分加上他当前的得分等于对手当前的得分，仍然输出"Yes"）
Input  输入
第一行包含一个数字 N，表示总共有多少种情况。随后是 N 行，每行由三个整数组成：
Ball_Left P_Score O_Score 分别代表台面上剩余的目标球数量、菲利普当前的得分，以及对手当前的得分。
所有输入值均在 32 位整数范围内。
Output  输出
你需要计算菲尔普斯能获得的最大剩余分数，并判断他是否有获胜的可能。
Sample Input  样例输入
2
12 1 1
1 30 39
Sample Output  示例输出
Yes
No
*/

#include <iostream>
#include<vector>
#include<numeric>
using namespace std;

const vector<int> coloredballs = {2,3,4,5,6,7};

int main()
{
    int n;cin>>n;
    int ball_left,p_score,o_score;
    for(int i=0;i<n;++i){
        cin >> ball_left >> p_score >> o_score;
        if(ball_left>6){
            p_score += (ball_left-6)*8+27;
        }else{
            p_score += accumulate(coloredballs.begin()+6-ball_left,coloredballs.end(),0);
        }
        if(p_score>=o_score){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }   
    }
    
    return 0;
}