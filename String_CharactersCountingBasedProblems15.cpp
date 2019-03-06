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

int CountTotalAnagramSubstrings(const string& str)
{
	int cnt=0;
	map<vector<int>,int> fre;
	for(int i=0;i<str.size();i++)
	{
		vector<int> rec(256,0);
		for(int j=i;j<str.size();j++)
		{
			rec[str[j]]++;
			fre[rec]++;
		}
	}
	for(auto it=fre.begin();it!=fre.end();it++)
	{
		cnt+=(it->second)*(it->second-1)/2;
	}
	return cnt;
}

int main()
{
	string str="";
	//string str="abba";
	cout<<CountTotalAnagramSubstrings(str)<<endl;
	return 0;
}
