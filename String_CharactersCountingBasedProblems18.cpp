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

string PrintAllDistinctCharactersOfAStringInOrder(const string& str)
{
	vector<int> rec(256,0);
	vector<int> idx(256,str.size());//idx 中存储着 所有字符第一次出现的坐标
	for(int i=0;i<str.size();i++)
	{
		rec[str[i]]++;
		if(rec[str[i]]==1)
		{
			idx[str[i]]=i;
		}else
		{
			idx[str[i]]=str.size();//
		}
	}
	string res="";
	cout<<idx<<endl;
	sort(idx.begin(),idx.end());
	cout<<idx<<endl;
	for(int i=0;i<idx.size();i++)
	{
		cout<<str[idx[i]]<<' ';
	}
	cout<<endl;
	for(int i=0;i<idx.size();i++)
	{
		res+=str[idx[i]];
	}
	return res;
}

int main()
{
	string str="Geeks for Geeks";
	cout<<PrintAllDistinctCharactersOfAStringInOrder(str)<<endl;
	return 0;
}
