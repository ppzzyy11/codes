#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;

int CountDistinctSubsequences(const string&str)
{
	unordered_map<char,int> rec;
	vector<int> dp(str.size()+1,0);//这里把str的初始下标当做1来看待 ，dp【0】=1是指，空字符
	dp[0]=1;
	for(int i=0;i<str.size();i++)
	{
		if(rec.count(str[i])==0)
		{
			dp[i+1]=2*dp[i];
			rec[str[i]]=i;//注意，这里是0坐标开始
		}else
		{
			dp[i+1]=2*dp[i]-dp[rec[str[i]]];
			rec[str[i]]=i;
		}
	}
	return dp.back();
}

int main()
{
	const string str="fff";//fgf,fff通过测试，稳得一笔
	cout<<CountDistinctSubsequences(str)<<endl;
	return 0;
}
