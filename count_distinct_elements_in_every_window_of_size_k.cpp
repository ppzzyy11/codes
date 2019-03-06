#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main()
{
    vector<int> nums{1, 2, 1, 3, 4, 2, 3};
    int k=4;
    int len=0;
    int Max_len=0;
    unordered_map<int,int> rec;//num cnt
    for(int i=0;i<nums.size();i++)
    {
        if(i<k)
        {
            if(rec[nums[i]]==0)
            {
                len++;
            }
            rec[nums[i]]++;
        }else
        {
            cout<<len<<endl;
            rec[nums[i-k]]--;
            if(rec[nums[i-k]]==0)
            {
                len--;
            }
            if(rec[nums[i]]==0)
                len++;
            rec[nums[i]]++;
        }
    }
    cout<<len<<endl;
    return 0;
}
