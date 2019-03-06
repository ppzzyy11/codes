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

bool IfTwoStringsAreAnagram(const string& str1,const string& str2)
{
	vector<int> rec(256,0);
	for(auto s:str1)
	{
		rec[s]++;
	}
	for(auto s:str2)
	{
		rec[s]--;
		if(rec[s]<0)
			return 0;
	}
	for(auto r:rec)
	{
		if(r!=0)
			return 0;
	}
	return 1;
}

int main()
{
	string str1="geeksforgeeks";
	string str2="orgeeksfgeeks";
	cout<<IfTwoStringsAreAnagram(str1,str2)<<endl;
	return 0;
}
