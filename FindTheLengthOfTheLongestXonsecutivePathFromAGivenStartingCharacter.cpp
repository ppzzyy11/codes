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

int Helper(int i,int j, vector<vector<int>>& dp,const vector<vector<char>>& mat)
{
	if(i<0||j<0) return 0;
	if(i>=mat.size()||j>=mat[0].size()) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	dp[i][j]=1;
	if(i>0&&mat[i-1][j]==mat[i][j]+1) dp[i][j]=max(1+Helper(i-1,j,dp,mat),dp[i][j]);
	if(j>0&&mat[i][j-1]==mat[i][j]+1) dp[i][j]=max(1+Helper(i,j-1,dp,mat),dp[i][j]);
	if(i<mat.size()-1&&mat[i+1][j]==mat[i][j]+1) dp[i][j]=max(1+Helper(i+1,j,dp,mat),dp[i][j]);
	if(j<mat[0].size()-1&&mat[i][j+1]==mat[i][j]+1) dp[i][j]=max(1+Helper(i,j+1,dp,mat),dp[i][j]);

	if(i>0&&j>0&&mat[i-1][j-1]==mat[i][j]+1) dp[i][j]=max(1+Helper(i-1,j-1,dp,mat),dp[i][j]);
	if(i>0&&j<mat[0].size()-1&&mat[i-1][j+1]==mat[i][j]+1) dp[i][j]=max(1+Helper(i-1,j+1,dp,mat),dp[i][j]);
	if(i<mat.size()-1&&j>0&&mat[i+1][j-1]==mat[i][j]+1) dp[i][j]=max(1+Helper(i+1,j-1,dp,mat),dp[i][j]);
	if(i<mat.size()-1&&j<mat[0].size()-1&&mat[i+1][j+1]==mat[i][j]+1) dp[i][j]=max(1+Helper(i+1,j+1,dp,mat),dp[i][j]);


	return dp[i][j];
}

int FindTheLengthOfTheLongestConsecutivePathFromAGivenStartingCharacter(const vector<vector<char>>& mat,const char ch)
{
	int res=0;
	vector<vector<int>> dp(mat.size(),vector<int>(mat[0].size(),-1));
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			if(mat[i][j]==ch)
				res=max(res,Helper(i,j,dp,mat));
		}
	}
	//cout<<mat<<endl;
	return res;
}
int FindTheLengthOfTheLongestConsecutivePath(const vector<vector<char>>& mat)
{
	int res=0;
	vector<vector<int>> dp(mat.size(),vector<int>(mat[0].size(),-1));
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			res=max(res,Helper(i,j,dp,mat));
		}
	}
	//cout<<mat<<endl;
	return res;
}

int main()
{
	vector<vector<char>> mat=
	{
		//{'a', 'c', 'd'},
		//{'h', 'b', 'e'},
		//{'i', 'g', 'f'}

		{'b', 'e', 'f'},
		{'h', 'd', 'a'},
		{'i', 'c', 'a'}
	};
	//char ch='e';
	char ch='b';
	cout<<FindTheLengthOfTheLongestConsecutivePathFromAGivenStartingCharacter(mat,ch)<<endl;
	return 0;
}
