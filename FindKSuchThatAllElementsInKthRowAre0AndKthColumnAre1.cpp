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

int FindKSuchThatAllElementsInKthRowAre0AndKthColumnAre1(const vector<vector<bool>>& mat)
{
	if(mat.size()==0) return 0;
	if(mat[0].size()==0) return 0;
	int i=0,j=mat[0].size()-1;
	int res=-1;
	while(i<mat.size()&&j>=0)
	{
		if(mat[i][j]==0)
		{
			while(j>=0&&(mat[i][j]==0||i==j))
			{
				j--;
			}
			if(j==-1)
			{
				res=i;
				break;
			}else
			{
				i++;
			}
		}else
		{
			while(i<mat.size()&&(mat[i][j]==1||i==j))
			{
				i++;
			}
			if(i==mat.size())
			{
				res=j;
				break;
			}else
			{
				j--;
			}
		}
	}
	if(res==-1) return res;
	for(int i=0;i<mat.size();i++)
	{
		if(i!=res&&mat[i][res]!=1) return -1;
	}
	for(int j=0;j<mat[0].size();j++)
	{
		if(j!=res&&mat[res][j]!=0) return -1;
	}
	return res;
}

int main()
{
	vector<vector<bool>> mat=
	{
		{0, 0, 1, 1, 0},
		{0, 0, 0, 1, 0},
		{1, 1, 1, 1, 0},
		{0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1}
	};
	cout<<FindKSuchThatAllElementsInKthRowAre0AndKthColumnAre1(mat)<<endl;
	return 0;
}
