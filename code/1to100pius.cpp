#include<iostream>
using namespace std;

int main()
{   
    int sum=0,i;
    for(i=1;i<=100;i++){
        sum += i;
    }
    cout << "累加的值为： " << sum << endl;
    return 0;
}