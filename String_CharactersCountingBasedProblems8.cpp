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

int NumberOFWords(const string& str)
{
	int i=0;
	int cnt=0;
	bool words=0;
	while(i<str.size())
	{
		while(i<str.size()&&isalpha(str[i]))
		{
			if(words==0)
				cnt++;
			words=1;
			i++;
		}
		while(i<str.size()&&(str[i]==' '||str[i]=='\n'||str[i]=='\t'))
		{
			words=0;
			i++;
		}
	}
	return cnt;
}

int main()
{
	string str="One two         three\n    four\tfive  ";
	cout<<NumberOFWords(str)<<endl;
	return 0;
}
