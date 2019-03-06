#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main()
{
    vector<int> nums{10, 12, 12, 12, 10, 11, 10};
    int res=(nums.size()!=0);


    for(int i=0;i<nums.size();i++)
    {
        unordered_map<int,bool> rec;
        int MAX=nums[i],MIN=MAX;
        rec[MAX]=1;
        for(int j=i+1;j<nums.size();j++)
        {
            if(rec[nums[j]]==1)
                break;
            MAX=max(MAX,nums[j]);
            MIN=min(MIN,nums[j]);
            rec[nums[j]]=1;
            if(MAX-MIN==j-i)
                res=max(res,j-i+1);
        }
    }
    cout<<res<<endl;
    return 0;
}
