#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<cctype>
#include<set>
#include<map>
#include<climits>
using namespace std;


ostream& operator<<(ostream& os, const vector<vector<int>>& mat)
{
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			cout<<mat[i][j]<<'\t';
		}
		cout<<endl;
	}
	return os;
}
ostream& operator<<(ostream& os, const vector<string>& strs)
{
	for(auto str:strs)
	{
		cout<<str<<endl;
	}
	return os;
}
ostream& operator<<(ostream& os, const vector<int>& nums)
{
	for(auto num:nums)
	{
		cout<<num<<' ';
	}
	cout<<endl;
	return os;
}
ostream& operator<<(ostream& os, const vector<vector<string>>& strs)
{
	for(int i=0;i<strs.size();i++)
	{
		for(int j=0;j<strs[i].size();j++)
		{
			cout<<strs[i][j]<<' ';
			//cout<<i<<":"<<j<<endl;
		}
		cout<<endl;
	}
	return os;
}
ostream& operator<<(ostream& os,const vector<vector<char>>& mat)
{
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			cout<<mat[i][j]<<' ';
		}
		cout<<endl;
	}
	return os;
}

struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int v):val(v),left(NULL),right(NULL){}
};

TreeNode* NewNode(const int val)
{
	return ( new TreeNode(val) );
}

TreeNode* DeleteTree(TreeNode* node)
{
	if(node==NULL) return NULL;
	DeleteTree(node->left);
	DeleteTree(node->right);
	delete node;
	return NULL;
}

void PreOrder(TreeNode* node)
{
	if(node==NULL) return ;
	cout<<node->val<<' ';
	PreOrder(node->left);
	PreOrder(node->right);
}
void InOrder(TreeNode* node)
{
	if(node==NULL) return ;
	InOrder(node->left);
	cout<<node->val<<' ';
	InOrder(node->right);
}
void BuildAncestorMatrix(TreeNode* node,vector<int>& anc,vector<vector<int>>& mat)
{
	if(node==NULL) return ;
	if(node->left)
	{
		mat[node->val][node->left->val]=1;
		for(int i=0;i<anc.size();i++)
		{
			mat[anc[i]][node->left->val]=1;
		}
	}
	if(node->right)
	{
		mat[node->val][node->right->val]=1;
		for(int i=0;i<anc.size();i++)
		{
			mat[anc[i]][node->right->val]=1;
		}
	}
	anc.push_back(node->val);
	BuildAncestorMatrix(node->left,anc,mat);
	BuildAncestorMatrix(node->right,anc,mat);
	anc.pop_back();
	return ;
}

TreeNode* BuildTreeFromMatrix(vector<vector<int>>& mat)
{
	vector<TreeNode*> nodes;
	for(int i=0;i<mat.size();i++)//O(N)
	{
		nodes.push_back(NewNode(i));
	}
	vector<int> cnts(mat.size(),0);
	vector<vector<int>> lvl(mat.size(),vector<int>(0,0));
	for(int j=0;j<mat[0].size();j++)//O(N^2)
	{
		int cnt=0;
		for(int i=0;i<mat.size();i++)
		{
			if(mat[i][j]==1)
			{
				cnt++;
			}
		}
		lvl[cnt].push_back(j);
	}

	//下面这个循环为O(N^2)
	for(int i=0;i<lvl.size();i++)//O(N)
	{
		for(int j=0;j<lvl[i].size();j++)//这个i与j总共为O(N)啦
		{
			 int node=lvl[i][j];//对node进行祖先匹配
			 for(int k=0;k<mat.size();k++)//O(N)
			 {
				 if(mat[k][node]==1&&cnts[k]!=2)
				 {
					 cnts[k]++;
					 if(nodes[k]->left==NULL)
					 {
						 nodes[k]->left=nodes[node];
						 cout<<k<<"s left  is "<<node<<endl;
					 }
					 else if(nodes[k]->right==NULL)
					 {
						 nodes[k]->right=nodes[node];
						 cout<<k<<"s right is "<<node<<endl;
					 }
				 }
			 }
		}
	}
	cout<<endl;
	return nodes[lvl[0][0]];
}

int main()
{
	TreeNode* root=NewNode(5);
	root->left=NewNode(1);
	root->right=NewNode(2);
	root->left->left=NewNode(0);
	root->left->right=NewNode(4);
	root->right->left=NewNode(3);
	PreOrder(root);
	cout<<endl;
	InOrder(root);
	cout<<endl<<endl;;

	vector<vector<int>> mat(6,vector<int>(6,0));
	vector<int> anc;
	BuildAncestorMatrix(root,anc,mat);
	cout<<mat<<endl;
	root=DeleteTree(root);
	PreOrder(root);

	TreeNode* node=BuildTreeFromMatrix(mat);
	PreOrder(node);
	cout<<endl;
	InOrder(node);
	node=DeleteTree(node);

	return 0;
}
