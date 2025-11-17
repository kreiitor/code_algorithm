/*
输入一个百分制的成绩t，将其转换成对应的等级，具体转换规则如下：
90~100为A;  90~100 为 A；
80~89为B;  80~89 为 B；
70~79为C;  70~79 为 C；
60~69为D;  60~69 为 D;
0~59为E;  0~59 为 E;
Input  输入
输入数据有多组，每组占一行，由一个整数组成。
Output  输出
对于每组输入数据，输出一行。如果输入数据不在0~100范围内，请输出一行：“Score is error!”。
Sample Input  样例输入
56
67
100
123
Sample Output  示例输出
E
D
A
Score is error!
*/
#include<iostream>
#include<string>

using namespace std;

int main()
{
    int score;
    string grade;
    while(cin >> score){
        if(score<0 || score>100) grade = "Score is error!";
        else if(score>=90 && score <=100) grade = "A";
        else if(score>=80 && score <=89) grade = "B";
        else if(score>=70 && score <=79) grade = "C";
        else if(score>=60 && score <=69) grade = "D";
        else if(score>=0 && score <=59) grade = "E";        
        cout << grade << endl;
    }
    return 0;
}