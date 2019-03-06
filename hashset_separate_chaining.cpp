//separate chaining  的实现
//并未经过严格的暴力测试
#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class HashSet{
    private:
        struct Int{
            int val;
            struct Int* next;
            Int(int x):val(x),next(NULL){}
        };
        vector<Int*> nums;
        int hash(int n)
        {
            return n%7;
        }
        bool DEBUG=1;
    public:
        HashSet()
        {
            nums.resize(7,NULL);
        }
        ~HashSet()
        {
            for(int i=0;i<nums.size();i++)
            {
                Int* s=nums[i];
                Int *cur=s,*next;
                while(cur)
                {
                    next=cur->next;
                    delete cur;
                    cur=next;
                }
            }
        }
        int insert(int val);
        int remove(int val);
        int count(int val);
};

int HashSet::insert(int val)
{
    int idx=hash(val);
    Int* &s=nums[idx];
    if(s==NULL)
    {
        s= new Int(val);
        return val;
    }
    Int * cur=s;
    while(cur->next)
    {
        if(cur->val==val)
            return INT_MIN;
        cur=cur->next;
    }
    if(cur->val==val)
        return INT_MIN;
    cur->next= new Int(val);
    return val;
}

int HashSet::remove(int val)
{
    int idx=hash(val);
    Int* s =nums[idx];
    if(s==NULL) return INT_MIN;
    if(s->val==val)
    {
        nums[idx]=s->next;
        delete s;
    }
    Int * pre=s;
    Int * cur=s->next;
    while(cur)
    {
        if(cur->val==val)
        {
            pre->next=cur->next;
            delete cur;
            return val;
        }
        pre=cur;
        cur=cur->next;
    }
    return INT_MIN;
}
int HashSet::count(int val)
{
    int idx=hash(val);
    Int * s = nums[idx];
    while(s)
    {
        if(s->val==val)
            return 1;
        s=s->next;
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
    hs.insert(3);
    cout<<hs.count(10)<<endl;
    cout<<hs.count(9)<<endl;
    cout<<hs.count(3)<<endl;
    hs.insert(17);
    cout<<hs.count(10)<<endl;
    cout<<hs.count(17)<<endl;
    cout<<hs.count(3)<<endl;
    hs.remove(3);
    cout<<hs.count(10)<<endl;
    cout<<hs.count(9)<<endl;
    cout<<hs.count(3)<<endl;
    return 0;
}
