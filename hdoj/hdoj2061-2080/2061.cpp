/*
背景：
现在，我来告诉你规则，你的任务就是编程计算 GPA。
如果有 K(K > 0)门课程，第 i 门课程的学分为 Ci，你的成绩为 Si，那么 GPA 的计算公式为
GPA = (C1 * S1 + C2 * S2 +……+Ci * Si……) / (C1 + C2 + ……+ Ci……) (1 <= i <= K, Ci != 0)
如果存在一门课程的成绩满足 0 <= Si < 60，则 GPA 始终不存在。
1.这个题的关键在于，成绩必须用double存储，猜测是因为有可能是浮点数


Input  输入
第一个数字 N 表示有 N 个测试用例(N <= 50)。每个测试用例中，首先给出一个数字 K（课程总数），
随后跟随 K 行数据，每行遵循以下格式：课程名称（长度 <= 30），学分(<= 10)，成绩(<= 100)。
注意：课程名称中不包含空格。所有输入都是合法的。
Output  输出
按照上述描述输出每个案例的 GPA，如果 GPA 不存在，则输出："Sorry!"，否则直接输出 GPA 值，结果保留两位小数。两个测试案例之间有一个空行。
Sample Input  样例输入
2
3
Algorithm 3 97
DataStruct 3 90
softwareProject 4 85
Database 4 59
English 4 81
Sample Output  示例输出
90.10

Sorry!
*/

#include <iostream>
#include<iomanip>
#include<string>
using namespace std;


int main()
{
    int n,k;cin >> n;
    for(int i=0;i<n&&cin>>k;++i){
        if(i>0) cout << endl;
        string dummy;double credit,score;double total_credit=0.0, total_score_multiple_credit=0.0;
        bool gpa_exists = true;
        for(int j=0;j<k;++j){
            cin >> dummy >> credit >> score;
            if(score<60) gpa_exists = false;
            if(gpa_exists){
                total_credit += credit;
                total_score_multiple_credit += credit*score;
            }
        }
        if(gpa_exists){
            cout << fixed << setprecision(2) << static_cast<double>(total_score_multiple_credit)/total_credit << endl;
        }else{
            cout << "Sorry!" << endl;
        }
    }
    return 0;
}