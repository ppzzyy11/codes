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


int NumberOfPathsWithExactlyKCoins(const vector<vector<int>>& mat,int i,int j,int k,vector<vector<vector<int>>>& dp)//Asuming no value below 0
{
	if(i<0||j<0||k<0) return 0;
	if(i>=mat.size()||j>=mat[i].size()) return 0;
	if(dp[i][j][k]!=-1) return dp[i][j][k];
	if(i==mat.size()-1&&j==mat[i].size()-1)
	{
		//return dp[i][j][k]=(k==mat[i][j]);
		if(k==mat[i][j])
		{
			return dp[i][j][k]=1;
		}else
		{
			return dp[i][j][k]=0;
		}
	}
	return dp[i][j][k]=NumberOfPathsWithExactlyKCoins(mat,i+1,j,k-mat[i][j],dp)+NumberOfPathsWithExactlyKCoins(mat,i,j+1,k-mat[i][j],dp);

}

int main()
{
	vector<vector<int>> mat=
	{
		{1, 2, 3},
		{4, 6, 5},
		{3, 2, 1}
	};
	int k=12;
	vector<vector<vector<int>>> dp(mat.size(),vector<vector<int>>(mat[0].size(),vector<int>(k+1,-1)));
	cout<<NumberOfPathsWithExactlyKCoins(mat,0,0,k,dp)<<endl;
	return 0;
}
