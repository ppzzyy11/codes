//open addressing --line probing 的实现
//并未经过严格的暴力测试
#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class HashSet{
    private:
        vector<int> nums;
        int hash(int n)
        {
            return n%7;
        }
    public:
        HashSet()
        {
            nums.resize(7,INT_MIN);
        }
        int insert(int val);
        int remove(int val);
        int count(int val);
};

int HashSet::insert(int val)
{
    int id=hash(val);
    for(int i=0;i<nums.size();i++)
    {
        int idx=hash(id+i);
        if(nums[idx]==INT_MIN)
        {
            nums[idx]=val;
            return val;
        }
    }
    return INT_MIN;
}

int HashSet::remove(int val)
{
    int id=hash(val);
    for(int i=0;i<nums.size();i++)
    {
        int idx=hash(id+i);
        if(nums[idx]==INT_MIN)
        {
            return INT_MIN;
        }
        if(nums[idx]==val)
        {
            int tmp=nums[idx];
            nums[idx]=INT_MIN;
            return tmp;
        }
    }
    return INT_MIN;
}

int HashSet::count(int val)
{
    int id=hash(val);
    for(int i=0;i<nums.size();i++)
    {
        int idx=hash(id+i);
        if(nums[idx]==INT_MIN)
        {
            return 0;
        }
        if(nums[idx]==val)
            return 1;
    }
    return 0;
}

int main()
{
    HashSet hs;
    hs.insert(10);
    cout<<hs.count(10)<<endl;
    cout<<hs.count(9)<<endl;
    cout<<hs.count(3)<<endl;
    hs.remove(3);
    cout<<hs.count(10)<<endl;
    cout<<hs.count(9)<<endl;
    cout<<hs.count(3)<<endl;
    hs.insert(3);
    cout<<hs.count(10)<<endl;
    cout<<hs.count(9)<<endl;
    cout<<hs.count(3)<<endl;
    hs.insert(17);
    cout<<hs.count(10)<<endl;
    cout<<hs.count(17)<<endl;
    cout<<hs.count(3)<<endl;
    return 0;
}
