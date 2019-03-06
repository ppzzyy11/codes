#include<iostream>
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



struct MyCompare{
    inline bool operator() (const int& a, const int& b)//a is before b?
    {
        return a>b;
    }
};

void output(const vector<int> & arr)
{
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    vector<int> arr{1,3,45,6,1,213,1};
    output(arr);
    sort(arr.begin(),arr.end());
    output(arr);
    sort(arr.begin(),arr.end(),MyCompare());
    output(arr);
    return 0;
}
