#include<iostream>
#include<deque>
#include<queue>
#include<bitset>
#include<map>
#include<stack>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<climits>
#include<cstring>
#include<unordered_set>
#include<unordered_map>
#include"utility"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};




class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        set<int> s;
        vector<int> res(nums.size(),0);
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(s.size()==0)
            {
                s.insert(nums[i]);
                res[i]=0;
            }else
            {
                s.insert(nums[i]);
                auto end=s.lower_bound(nums[i]);
                int cnt=0;
                for(auto it=s.begin();it!=end;it++)
                    cnt++;
                res[i]=cnt;
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}
