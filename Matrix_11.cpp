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

bool winC(char ch,const vector<vector<char>>& mat)
{
	for(int i=0;i<mat.size();i++)
	{
		if(mat[i][0]==ch&&mat[i][1]==ch&&mat[i][2]==ch) return 1;
	}
	for(int j=0;j<mat[0].size();j++)
	{
		if(mat[0][j]==ch&&mat[1][j]==ch&&mat[2][j]==ch) return 1;
	}
	if(mat[0][0]==ch&&mat[1][1]==ch&&mat[2][2]==ch) return 1;
	if(mat[0][2]==ch&&mat[1][1]==ch&&mat[2][0]==ch) return 1;
	return 0;
}

int TheFirst1(const vector<bool> nums)//OK -1 ,no first 1
{
	int l=0,r=nums.size()-1;
	while(l<=r)
	{
		int m=l+(r-l)/2;
		if(nums[m]==1&&(m==0||nums[m-1]==0))//m==0 的判断也可以放在最开始的位置，判断第一个字母是否为1返回结果就可以了
			return m;
		else if(nums[m]==0)//m should bigger
			l=m+1;
		else
		{
			r=m-1;
		}
	}
	return -1;//no zero
}

int main()
{
	vector<vector<bool>> mat=
	{
		{0, 0, 0, 1},
		{0, 1, 1, 1},
		{1, 1, 1, 1},
		{0, 0, 0, 0}
	};

	for(int i=0;i<mat.size();i++)
	{
		cout<<TheFirst1(mat[i])<<endl;
	}
	return 0;
}
