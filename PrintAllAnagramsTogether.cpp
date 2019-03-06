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

vector<vector<string>> PrintAllAnagramsTogether(const vector<string>& strs)
{
	vector<vector<string>> mat;
	vector<vector<int>> recs;//mat rec same index the string and its anagram
	for(auto str:strs)
	{
		vector<int> rec(256,0);
		for(auto s:str)
		{
			rec[s]++;
		}
		int i;
		for( i=0;i<recs.size();i++)
		{
			if(rec==recs[i])
			{
				mat[i].push_back(str);
				break;
			}
		}
		if(i==recs.size())
		{
			recs.push_back(rec);
			vector<string> tmp;
			tmp.push_back(str);
			mat.push_back(tmp);
		}
	}
	cout<<mat<<endl;
	return mat;
}

int main()
{
	const vector<string> strs={"cat", "dog", "tac", "god", "act"};
	PrintAllAnagramsTogether(strs);
	return 0;
}
