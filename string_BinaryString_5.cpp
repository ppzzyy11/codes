#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;

ostream& operator<<(ostream& os, const vector<vector<int>>& mat)
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

int CountBinaryStringsWithKTimesAppearingAdjacentTwoSetBits(const int n,const int k)
{
	vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,(vector<int>(2,0))));
	dp[1][0][0]=dp[1][0][1]=1;
	for(int i=2;i<dp.size();i++)
	{
		for(int j=0;j<dp[i].size()&&j<i;j++)
		{
			dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j][1];
			dp[i][j][1]=dp[i-1][j][0]+(j==0?0:dp[i-1][j-1][1]);
		}
	}
	return dp[n][k][0]+dp[n][k][1];
}

int main()
{
	//int n=5;
	//int k=2;
	int n=4;
	int k=1;
	cout<<CountBinaryStringsWithKTimesAppearingAdjacentTwoSetBits(n,k)<<endl;
	return 0;
}
