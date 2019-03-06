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

int SubstringWithHighestFrequencyLengthProduct(const string& str)
{
	unordered_map<string,int> fre;
	for(int i=0;i<str.size();i++)
	{
		string tmp="";
		for(int j=i;j<str.size();j++)
		{
			tmp+=str[j];
			fre[tmp]++;
		}
	}
	int pdct=INT_MIN;
	string  substr="";
	for(auto it=fre.begin();it!=fre.end();it++)
	{
		if((int)it->first.size()*it->second>pdct)
		{
			substr=it->first;
			pdct=it->first.size()*(it->second);
		}
	}
	cout<<substr<<endl;
	return pdct;
}

int main()
{
	string str="zzzzzz";
	//string str="abddab";
	cout<<SubstringWithHighestFrequencyLengthProduct(str)<<endl;
	return 0;
}
