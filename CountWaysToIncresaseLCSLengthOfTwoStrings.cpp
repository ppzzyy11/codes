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

int CountWaysToIncreaseLCSLengthOfTwoStringsByOne(const string& str1, const string& str2)
{
	vector<vector<int>> lcsl(str1.size()+2,vector<int>(str2.size()+2,0));
	vector<vector<int>> lcsr(str1.size()+2,vector<int>(str2.size()+2,0));
	vector<vector<int>> pstns(26,vector<int>(0,0));
	for(int i=0;i<str2.size();i++)
	{
		pstns[str2[i]-'a'].push_back(i);//a-z 在str2中出现的坐标
	}
	for(int i=0;i<str1.size();i++)
	{
		for(int j=0;j<str2.size();j++)
		{
			if(str1[i]==str2[j])
			{
				lcsl[i+1][j+1]=lcsl[i][j]+1;
			}else
			{
				lcsl[i+1][j+1]=max(lcsl[i+1][j],lcsl[i][j+1]);
			}
		}
	}
	//cout<<lcsl<<endl;
	int LCS=lcsl[str1.size()][str2.size()];

	for(int i=str1.size()-1;i>=0;i--)
	{
		for(int j=str2.size()-1;j>=0;j--)
		{
			if(str1[i]==str2[j])
			{
				lcsr[i+1][j+1]=lcsr[i+2][j+2]+1;
			}else
			{
				lcsr[i+1][j+1]=max(lcsr[i+2][j+1],lcsr[i+1][j+2]);
			}
		}
	}
	//cout<<lcsr<<endl;

	int res=0;
	for(int i=1;i<=str1.size()+1;i++)
	{
		for(char ch='a';ch<='z';ch++)
		{
			for(auto j:pstns[ch-'a'])
			{
				j++;
				//cout<<i<<":"<<j<<":"<<ch<<endl;
				int lcs=lcsl[i-1][j-1]+1+lcsr[i][j+1];
				if(lcs==LCS+1)
				{
					res++;
				}
			}
		}
	}

	return res;
}

int main()
{
	string str1="abcabc";
	string str2="abcd";
	cout<<CountWaysToIncreaseLCSLengthOfTwoStringsByOne(str1,str2)<<endl;
	return 0;
}
