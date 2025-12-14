/*
比赛是设在一条笔直的道路上，长度为L米，规则很简单，谁先到达终点谁就算获胜。
车在有电的情况下能够以VT1 m/s的速度“飞驰”，可惜电池容量有限，
每次充满电最多只能行驶C米的距离，以后就只能用脚来蹬了，乌龟用脚蹬时的速度为VT2 m/s。
更过分的是，乌龟竟然在跑道上修建了很多很多（N个)的供电站，供自己给电动车充电。
其中，每次充电需要花费T秒钟的时间。当然，乌龟经过一个充电站的时候可以选择去或不去充电。
比赛马上开始了，兔子和带着充满电的电动车的乌龟并列站在起跑线上。你的任务就是写个程序，
判断乌龟用最佳的方案进军时，能不能赢了一直以恒定速度奔跑的兔子。
1.在进行分析的时候，要判断每个充电站是否充电。这时候，充电和没充电就是一个判断指标
2.充了电之后，要走几个充电站也是要判断的指标，也就是说，到了第i个充电口的时候，之前充电的j充电站。两个指标
3.二维dp

Input
本题目包含多组测试，请处理到文件结束。每个测试包括四行：
第一行是一个整数L代表跑道的总长度
第二行包含三个整数N，C，T，分别表示充电站的个数，电动车冲满电以后能行驶的距离以及每次充电所需要的时间
第三行也是三个整数VR，VT1，VT2，分别表示兔子跑步的速度，乌龟开电动车的速度，乌龟脚蹬电动车的速度
第四行包含了N(N<=100)个整数p1,p2...pn,分别表示各个充电站离跑道起点的距离，其中0<p1<p2<...<pn<L
其中每个数都在32位整型范围之内。
Output
当乌龟有可能赢的时候输出一行 “What a pity rabbit!"。否则输出一行"Good job,rabbit!";
题目数据保证不会出现乌龟和兔子同时到达的情况。
Sample Input
100
3 20 5
5 8 2
10 40 60
100
3 60 5
5 8 2
10 40 60
Sample Output
Good job,rabbit!
What a pity rabbit!
*/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxN=102;
const double Inf = 1e20;


int main()
{
    int l,n,c,t,vr,vt1,vt2,p;
    while(cin >> l){
        cin >> n >> c >> t;cin >> vr >> vt1 >> vt2;
        vector<int> charges(n+2,0);
        charges[0]=0;charges[n+1]=l;
        for(int i=1;i<=n && cin>>p;++i){
            charges[i] = p;
        }
        vector<vector<double>> dp(maxN,vector<double>(maxN,Inf));dp[0][0]=0.0;

        for(int i=0;i<=n+1;++i){
            for(int j=0;j<=i;++j){
                if(dp[i][j]>=Inf) continue;//说明此时的状态没有被提前探查，下面的min无效果；
                if(i>=1 && i<=n){//判断当前充电站是否需要充电
                    dp[i][i] = (dp[i][i]>=dp[i][j]+t)?dp[i][j]+t:dp[i][i];
                }
                double time;int e;//剩余电量
                for(int k=i+1;k<=n+1;++k){//进行状态转移，保持充电站不变，从i转移到k>i
                    int dist = charges[k]-charges[i];
                    int e = (c-(charges[i]-charges[j])>=0)?(c-(charges[i]-charges[j])):0;
                    if(dist<=e){
                        time = (double)dist/vt1;
                    }else{
                        time = (double)e/vt1+(double)(dist-e)/vt2;
                    }
                    dp[k][j] = (dp[k][j]>=dp[i][j]+time)?dp[i][j]+time:dp[k][j];
                }
            }
        }
        double tr=(double)l/vr,tt;
        tt = *min_element(dp[n+1].begin(),dp[n+1].begin()+n+2);
        if(tt<tr){
            cout << "What a pity rabbit!" << endl;
        }else{
            cout << "Good job,rabbit!" << endl;
        }
        
    }
    return 0;
}