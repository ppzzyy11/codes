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

char MaximumConsecutiveRepeatingCharacterInString(const string& str)
{
	if(str.size()==0)
	{
		return 0;
	}
	int i=0;
	char ch=str[0];
	int Max=1;
	vector<int> rec(256,0);
	while(i+1<str.size())
	{
		int cnt=1;
		while(i+1<str.size()&&str[i]==str[i+1])
		{
			cnt++;
			i++;
		}
		if(cnt>rec[str[i]])
		{
			rec[str[i]]=cnt;
		}
		if(rec[str[i]]>Max)
		{
			Max=rec[str[i]];
			ch=str[i];
		}
		i++;
	}

	return ch;
}

int main()
{
	string str="geeekk";
	//string str="aaaabbcbbb";
	cout<<MaximumConsecutiveRepeatingCharacterInString(str)<<endl;
	return 0;
}
