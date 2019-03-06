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

void AnagramSeraching(const string& txt,const string& pat)
{
	if(pat.size()>txt.size()) return ;
	vector<int> rec_t(256,0);
	vector<int> rec_p(256,0);
	for(int i=0;i<pat.size();i++)
	{
		rec_t[txt[i]]++;
		rec_p[pat[i]]++;
	}
	if(rec_t==rec_p)
	{
		cout<<"Found at index 0:\t"<<txt.substr(0,pat.size())<<endl;
	}

	int len=pat.size();
	for(int i=pat.size();i<txt.size();i++)
	{
		rec_t[txt[i-len]]--;
		rec_t[txt[i]]++;
		if(rec_p==rec_t)
		{
			cout<<"Found at index "<<i-len+1<<":\t"<<txt.substr(i-len+1,len)<<endl;
		}
	}
	return ;
}

int main()
{
	string txt="BACDGABCDA";
	string pat="ABCD";
	AnagramSeraching(txt,pat);
	return 0;
}
