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

int NumberOfWords(const string& str)//Count of words whose i-th letter is either (i-1)-th, i-th, or (i+1)-th letter of given word
{
	if(str.size()<=1) return str.size();
	int cnt=1;
	for(int i=0;i<str.size();i++)
	{
		if(i==0)
		{
			if(str[0]!=str[1])
				cnt*=2;
		}else if(i==str.size()-1)
		{
			if(str[i]!=str[i-1])
			{
				cnt*=2;
			}
		}else
		{
			if(str[i-1]!=str[i]&&str[i]!=str[i+1]&&str[i-1]!=str[i+1])
			{
				cnt*=3;
			}else if(str[i-1]==str[i]&&str[i]==str[i+1])
			{
				cnt*=1;
			}else
			{
				cnt*=2;
			}
		}
	}
	return cnt;
}

int main()
{
	string str="abc";
	cout<<NumberOfWords(str)<<endl;
	return 0;
}
