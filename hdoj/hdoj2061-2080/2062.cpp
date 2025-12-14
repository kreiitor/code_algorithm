/*
考虑集合 An = { 1, 2, …, n }。例如，A1 = {1}，A3 = {1, 2, 3}。
子集序列被定义为一个非空子集的数组。将所有 An 的子集序列按字典序排序。你的任务是找到第 m 个序列。
1.An的子集（非空），考虑元素顺序，因为是数组
2.为了不生成无用的排列，准确找到m所在区块。先用第一个数字分簇，再用元素个数分组
3.之后就是确定了首个元素的k-th permutation问题
4.k-th permutation问题很基础，要从k-th变成0-indexed然后进行添加和删除

Input  输入
输入包含多个测试用例。每个测试用例由两个数字 n 和 m 组成（0 < n <= 20，0 < m <= An 的子集序列总数）。
Output  输出
对于每个测试用例，你应该在一行中输出 An 的第 m 个子集序列。
Sample Input  样例输入
1 1
2 1
2 2
2 3
2 4
3 10
Sample Output  示例输出
1
1
1 2   
2
2 1
2 3 1
*/

#include <iostream>
#include<vector>
using namespace std;

const int maxN = 20;

void createP(vector<long long> & p){
    p[0]=1;p[1]=1;
    for(int i=2;i<=maxN;++i){
        p[i]=i*p[i-1];
    }
    return;
}

int main()
{
    vector<long long> p(maxN+1,0);
    createP(p);
    int n;
    long long m;
    while(cin >> n >> m){
        // 分簇：计算以每个数字开头的序列数量
        long long cluster_size = 0;
        for(int i=0;i<=n-1;++i){
            cluster_size += p[n-1]/p[n-1-i];
        }
        
        // 确定第一个数字（修正：使用0-indexed计算）
        int first_num = (m-1) / cluster_size + 1;
        m -= (first_num-1) * cluster_size;

        // 分组：确定序列长度
        int group_num;
        for(int i=0;i<=n-1;++i){
            long long count = p[n-1]/p[n-1-i];
            if(m <= count){
                group_num = i+1;
                break;
            }
            m -= count;
        }

        // 构建序列
        vector<int> nums;
        for(int i=1;i<=n;++i){
            nums.push_back(i);
        }
        
        vector<int> ans;
        ans.push_back(first_num);
        nums.erase(nums.begin()+first_num-1); // 移除已使用的元素
        
        // 生成剩余部分的排列（k-th permutation算法）
        long long current_m = m - 1; // 转为0-indexed
        int remaining_count = n - 1;  // 剩余可用元素数量
        
        for(int i=remaining_count-1; i>=remaining_count-group_num+1; --i){
            if(i < 0 || nums.empty()) break;
            
            long long block_size = p[i];
            int index = current_m / block_size;
            current_m %= block_size;
            
            if((size_t)index < nums.size()){
                ans.push_back(nums[index]);
                nums.erase(nums.begin() + index);
            }
        }
        
        // 输出结果（只取前group_num个元素）
        for(int i=0;i<group_num;++i){
            if(i>0) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}