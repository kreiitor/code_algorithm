/*

*/

#include <iostream>
#include<vector>
using namespace std;


int main()
{
    int n;cin>>n;
    int m;
    for(int i=0;i<n && cin >> m;++i){
        vector<int> dp(m+1,0);
        dp[1]=1;
        for(int j=2;j<=m;++j){
            dp[j] = dp[j-1]+dp[j-2];
        }
        cout << dp[m] << endl;
    }
    return 0;
}