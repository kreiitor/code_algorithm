/*
一般来说一个比较安全的密码至少应该满足下面两个条件：
(1).密码长度大于等于8，且不要超过16。
(2).密码中的字符应该来自下面“字符类别”中四组中的至少三组。
这四个字符类别分别为：
1.大写字母：A,B,C...Z;
2.小写字母：a,b,c...z;
3.数字：0,1,2...9;
4.特殊符号：~,!,@,#,$,%,^;

给你一个密码，你的任务就是判断它是不是一个安全的密码。
 

Input  输入
输入数据第一行包含一个数M，接下有M行，每行一个密码（长度最大可能为50），密码仅包括上面的四类字符。
Output  输出
对于每个测试实例，判断这个密码是不是一个安全的密码，是的话输出YES，否则输出NO。
Sample Input  样本输入
3
a1b2c3d4
Linle@ACM
^~^@^@!%
Sample Output  样本输出
NO
YES
NO

*/

#include <iostream>
#include<string>
#include <cctype>

using namespace std;

int count_Character_Categories(const string& str)//动词开头的驼峰命名法
{
    bool hasUpper=false,hasLower=false,hasDigital=false,hasSpecial=false;
    const std::string specialChars = "~!@#$%^";
    for(char c:str){
        if (std::isupper(static_cast<unsigned char>(c))) {
            hasUpper = true;
        } else if (std::islower(static_cast<unsigned char>(c))) {
            hasLower = true;
        } else if (std::isdigit(static_cast<unsigned char>(c))) {
            hasDigital = true;
        } else if (specialChars.find(c) != std::string::npos) {
            hasSpecial = true;
        }
        //提前结束；
        if (hasUpper && hasLower && hasDigital && hasSpecial) {
            break;
        }
    }
    return int(hasUpper + hasLower + hasDigital + hasSpecial);
}

int main()
{
    int m;cin>>m;
    string dummy;getline(cin,dummy);
    string str;
    for(int j=0;j<m&&getline(cin,str);++j){
        bool flag = (str.length()>=8&&str.length()<=16) && count_Character_Categories(str)>=3;
        cout << (flag?"YES":"NO") << endl;
    }
    
    
    return 0;
}