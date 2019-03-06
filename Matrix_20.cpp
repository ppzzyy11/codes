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

int MinimumInitialPoints(const vector<vector<int>>& mat)
{
	vector<vector<int>> dp(mat.size(),vector<int>(mat[0].size(),0));
	dp.back().back()=(mat.back().back()>0?1:(1-mat.back().back()));
	for(int i=mat.size()-1,j=mat[0].size()-2;j>=0;j--)
	{
		dp[i][j]=max(dp[i][j+1]-mat[i][j],1);
	}
	for(int i=mat.size()-2,j=mat[0].size()-1;i>=0;i--)
	{
		dp[i][j]=max(dp[i+1][j]-mat[i][j],1);
	}
	for(int i=mat.size()-2;i>=0;i--)
	{
		for(int j=mat[i].size()-2;j>=0;j--)
		{
			dp[i][j]=max(1,min(dp[i+1][j],dp[i][j+1])-mat[i][j]);
		}
	}
	return dp[0][0];
}

int main()
{
	vector<vector<int>> mat=
	{
		{-2, -3,   3},
		{-5, -10,  1},
		{10,  30, -5}
	};
	cout<<MinimumInitialPoints(mat)<<endl;
	return 0;
}
