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

int CountStringWithoutConsecutive1s(const int n)
{
	vector<vector<int>> dp(n+1,vector<int>(2,0));
	dp[1][0]=dp[1][1]=1;
	for(int i=2;i<dp.size();i++)
	{
		dp[i][0]=dp[i-1][0]+dp[i-1][1];
		dp[i][1]=dp[i-1][0];
	}
	return dp[n][0]+dp[n][1];
}

int CountStringsWithConsecutive1s(const int n)
{
	int n2=1;
	for(int i=0;i<n;i++)
	{
		n2=n2*2;
	}
	return n2-CountStringWithoutConsecutive1s(n);
}

int main()
{
	int n=5;//2 3 5
	cout<<CountStringsWithConsecutive1s(n)<<endl;
	return 0;
}
