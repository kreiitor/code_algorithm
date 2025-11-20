/*
假设一个班有n(n<=50)个学生，每人考m(m<=5)门课，求每个学生的平均成绩和每门课的平均成绩，并输出各科成绩均大于等于平均成绩的学生数量。
 

Input  输入
输入数据有多个测试实例，每个测试实例的第一行包括两个整数n和m，分别表示学生数和课程数。然后是n行数据，每行包括m个整数（即：考试分数）。
Output  输出
对于每个测试实例，输出3行数据，第一行包含n个数据，表示n个学生的平均成绩，结果保留两位小数；第二行包含m个数据，表示m门课的平均成绩，结果保留两位小数；
第三行是一个整数，表示该班级中各科成绩均大于等于平均成绩的学生数量。
每个测试实例后面跟一个空行。
Sample Input  样例输入
2 2
5 10
10 20
Sample Output  示例输出
7.50 15.00
7.50 15.00
1
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;


double means(vector<int> & arr){
    int total=0;
    for(int t:arr){
        total += t;
    }
    return (double)total/arr.size();
}

bool is_greater(vector<int> &score,vector<double> &lesson_means){
    if(score.size()!=lesson_means.size()) return false;
    for(int i=0;i<score.size();i++){
        if(score[i]<lesson_means[i]) return false;
    }
    return true;
}

struct stu{
    vector<int> scores;
};




int main()
{
    int m,n;
    while(cin >> n >> m){
        vector<stu> stus;
        int score;
        for(int i=1;i<=n;i++){
            stu stu_;
            for(int j=1;j<=m && cin>>score;j++){
                stu_.scores.push_back(score);
            }
            stus.push_back(stu_);
        }
        //输出n个学生的平均成绩
        for(int i=0;i<n;i++){
            cout << fixed << setprecision(2) << means(stus[i].scores);
            if(i!=n-1) cout << ' ';
        }
        cout << endl;
        //输出m门课程的平均成绩
        vector<double> lesson_means;
        for(int j=0;j<m;j++){
            int total=0;
            for(int i=0;i<n;i++){
                total += stus[i].scores[j];
            }
            lesson_means.push_back((double)total/n);
        }
        for(int i=0;i<m;i++){
            cout << fixed << setprecision(2) << lesson_means[i];
            if(i!=n-1) cout << ' ';
        }
        cout << endl;
        //输出各科分数都比平均分高的学生个数
        int count=0;
        for(int i=0;i<n;i++){
            if(is_greater(stus[i].scores,lesson_means)) count++;
        }
        cout << count << endl;
    }
    return 0;
}