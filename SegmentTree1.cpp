#include<iostream>
#include<vector>
#include<queue>
//http://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/
//Let us consider the following problem to understand Segment Trees.
//
//We have an array arr[0 . . . n-1]. We should be able to
//1 Find the sum of elements from index l to r where 0 <= l <= r <= n-1
//
//2 Change value of a specified element of the array to a new value x. We need to do arr[i] = x where 0 <= i <= n-1.
using namespace std;

struct TreeNode{
    int val;
    int l;
    int r;
    TreeNode* left,*right;
    TreeNode(int s,int e,int v):l(s),r(e),val(v),left(NULL),right(NULL){}
};
class SegmentTree{
    private:
        TreeNode* root;

        int getSum(TreeNode*,int l,int r);
        int Update(TreeNode*,int index,int val);
        TreeNode* BuildHelper(vector<int>&nums,int s,int e);
    public:
        int getSum(int l,int r)
        {
            return getSum(root,l,r);
        }
        int Update(int index,int val)
        {
            //没有对index进行判断
            return Update(root,index,val);
        }
        SegmentTree(vector<int>nums)
        {
            root=BuildHelper(nums,0,nums.size()-1);
        }
        ~SegmentTree()
        {
            if(root==NULL) return ;
            queue<TreeNode*> que;
            que.push(root);
            while(!que.empty())
            {
                TreeNode* fnt=que.front();
                que.pop();
                if(fnt->left) que.push(fnt->left);
                if(fnt->right) que.push(fnt->right);
                delete fnt;
            }
        }
};

int SegmentTree::getSum(TreeNode* node,int l,int r)
{
    if(node==NULL) return 0;
    if(l>r) return 0;
    if(l>node->r||r<node->l) return 0;
    if(node->r<=r&&node->l>=l) return node->val;
    return getSum(node->left,l,r)+getSum(node->right,l,r);
}

int SegmentTree::Update(TreeNode* node,int index,int val)
{
    if(node==NULL) return 0;
    if(node->l==node->r&&node->l==index)
    {
        int diff=val-node->val;
        node->val+=diff;
        return diff;
    }else
    {
        if(node->left->l<=index&&node->left->r>=index)
        {
            int diff=Update(node->left,index,val);
            node->val+=diff;
            return diff;
        }else if(node->right->l<=index&&node->right->r>=index)
        {
            int diff=Update(node->right,index,val);
            node->val+=diff;
            return diff;
        }
        return 0;
    }
}
TreeNode* SegmentTree::BuildHelper(vector<int>&nums,int s,int e)
{
    if(s>e) return NULL;
    if(s==e)
    {
        TreeNode* node= new TreeNode(s,e,nums[s]);
        return node;
    }else
    {
        TreeNode* node= new TreeNode(s,e,0);
        int m=(s+e)>>1;
        node->left=BuildHelper(nums,s,m);
        node->right=BuildHelper(nums,m+1,e);
        int val_l=(node->left==NULL?0:node->left->val);
        int val_r=(node->right==NULL?0:node->right->val);
        node->val=val_l+val_r;
        return node;
    }
}
//~jiexi
int main()
{
    vector<int> nums{1,3,5,7,9,11};
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    SegmentTree seg(nums);
    for(int i=0;i<nums.size();i++)
    {
        for(int j=i;j<nums.size();j++)
            cout<<seg.getSum(i,j)<<" ";
        cout<<endl;
    }
    seg.Update(3,100);
    nums[3]=100;
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<nums.size();i++)
    {
        for(int j=i;j<nums.size();j++)
            cout<<seg.getSum(i,j)<<" ";
        cout<<endl;
    }
    return 0;
}
