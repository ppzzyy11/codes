#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main()
{
    const vector<int> nums{-10, 0, 2, -2, -20, 10};
    int sum=0;
    int des=20;
    unordered_map<int,int> rec;//sum index
    rec[0]=-1;

    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
        if(rec.count(sum-des)>0)
        {
            for(int j=rec[sum-des]+1;j<=i;j++)
            {
                cout<<nums[j]<<" ";
            }
            cout<<endl;
            return 0;
        }
        rec[sum]=i;
    }

}
