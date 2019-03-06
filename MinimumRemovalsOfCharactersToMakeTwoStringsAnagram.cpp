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

int MinimumRemovalsOfCharacters(const string& str1,const string& str2)
{
	vector<int> rec(256,0);
	for(auto s:str1)
	{
		rec[s]++;
	}
	for(auto s:str2)
	{
		rec[s]--;
	}
	int res=0;
	for(auto r:rec)
	{
		res+=abs(r);
	}
	return res;

}

int main()
{
	//string str1="bcadeh";
	//string str2="hea";
	//string str1="cddgk";
	//string str2="gcd";
	string str1="cdg";
	string str2="gcd";
	cout<<MinimumRemovalsOfCharacters(str1,str2)<<endl;
	return 0;
}
