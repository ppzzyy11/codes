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

int NumOfSubstringWhichRecursivelyAddUpTo9(const string& str)
{
	vector<int> dp(10,0);
	int cnt=0;
	dp[0]=1;
	for(auto s:str)
	{
		int num=s-'0';
		vector<int> tmp(dp.size(),0);
		for(int i=0;i<dp.size();i++)
		{
			int idx=((num+i)>10)+(num+i)%10;
			tmp[idx]+=dp[i];
		}
		//tmp[0]=1;
		//dp=tmp;
		//cnt+=dp.back();
		for(int i=0;i<dp.size();i++)
		{
			dp[i]+=tmp[i];
		}
	}
	return dp.back();
	//return cnt;
}

int main()
{
	string str="999";
	//string str="4189";
	cout<<NumOfSubstringWhichRecursivelyAddUpTo9(str)<<endl;
	return 0;
}
