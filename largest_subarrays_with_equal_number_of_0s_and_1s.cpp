#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main()
{
    vector<int>nums{1, 0, 1, 1, 1, 0, 0};
    unordered_map<int,int> rec;//sun index
    int sum=0;
    int res=0;

    rec[0]=-1;
    for(int i=0;i<nums.size();i++)
    {
        sum+=(nums[i]==1?1:-1);
        if(rec.count(sum)!=0)
        {
            res=max(res,i-rec[sum]);
        }else
        {
            rec[sum]=i;
        }
    }
    cout<<res<<endl;
    return 0;
}
