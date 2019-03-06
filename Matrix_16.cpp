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

int FindLongestFromACell(int i, int j, const vector<vector<int>>& mat, vector<vector<int>>& dp)//all numbers in mat are distinct
{
	if(i<0||j<0) return 0;
	if(i>=mat.size()) return 0;
	if(j>=mat[i].size()) return 0;

	if(dp[i][j]!=-1) return dp[i][j];
	if(j<mat[i].size()-1&&mat[i][j+1]==mat[i][j]+1)
		return dp[i][j]=1+FindLongestFromACell(i,j+1,mat,dp);

	if(j>0&&mat[i][j]+1==mat[i][j-1])
		return dp[i][j]=1+FindLongestFromACell(i,j-1,mat,dp);

	if(i>0&&mat[i][j]+1==mat[i-1][j])
		return dp[i][j]=1+FindLongestFromACell(i-1,j,mat,dp);

	if(i<mat.size()-1&&mat[i][j]+1==mat[i+1][j])
		return dp[i][j]=1+FindLongestFromACell(i+1,j,mat,dp);

	return dp[i][j]=1;
}

int FindLongestFromACell(const vector<vector<int>>& mat)
{
	if(mat.size()==0) return -1;
	if(mat[0].size()==0) return -1;
	vector<vector<int>> dp(mat.size(),vector<int>(mat[0].size(),-1));
	int res=0;
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			res=max(res,FindLongestFromACell(i,j,mat,dp));
		}
	}
	//cout<<dp<<endl;;
	return res;
}
int main()
{
	vector<vector<int>> mat=
	{
		{1, 2, 9},
		{5, 3, 8},
		{4, 6, 7}
	};
	cout<<FindLongestFromACell(mat)<<endl;
	return 0;
}
