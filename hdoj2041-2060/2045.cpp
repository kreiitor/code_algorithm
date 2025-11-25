/*
著名的RPG难题:
有排成一行的ｎ个方格，用红(Red)、粉(Pink)、绿(Green)三色涂每个格子，每格涂一色，要求任何相邻的方格不能同色，
且首尾两格也不同色．求全部的满足要求的涂法.
1.别忘了首尾两格也不能重复
Input
输入数据包含多个测试实例,每个测试实例占一行,由一个整数N组成，(0<n<=50)。
Output
对于每个测试实例，请输出全部的满足要求的涂法，每个实例的输出占一行。
Sample Input
1
2
Sample Output
3
6
*/

#include <iostream>
#include<vector>
using namespace std;

void arr_init( vector<long long> & arr){
    arr[0]=3;arr[1]=3;arr[2]=6;arr[3]=6;
    for(size_t i=4;i<arr.size();++i){
        arr[i] = 2*arr[i-2]+arr[i-1];
    }
    return ;
}

int main()
{
    int n;
    vector<long long> arr(51,0);
    arr_init(arr);
    while(cin>>n){
        cout<<arr[n]<<endl;
    }
    return 0;
}