#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<cctype>
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

char KthCharacterOfDecryptedString(const string& str,int k)
{
	if(str.size()==0)
	{
		cout<<"Empty string\n";
		return 0;
	}
	string res="";
	int i=0;
	while(i<str.size())
	{
		string tmp="";
		while(i<str.size()&&isalpha(str[i]))
		{
			tmp+=str[i];
			i++;
		}
		int num=0;
		while(i<str.size()&&isdigit(str[i]))
		{
			num=num*10+str[i]-'0';
			i++;
		}
		for(int i=0;i<num;i++)
		{
			res+=tmp;
		}
	}
	cout<<res<<endl;
	if(k>=res.size())
	{
		cout<<"str is TOO SHORT\n";
		return 0;
	}
	return res[k-1];
}

int main()
{
	//string str="a2b2c3";
	//int k=5;
	string str="ab4c12ed3";
	int k=21;
	//string str="ab4c2ed3";
	//int k=9;
	cout<<KthCharacterOfDecryptedString(str,k)<<endl;
	return 0;
}
