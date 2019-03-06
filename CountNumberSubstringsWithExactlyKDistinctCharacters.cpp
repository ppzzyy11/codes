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

bool BiggerOrEqualThan(const vector<int>& nums1,const vector<int>& nums2)//所有nums2中不为0的值，nums1中对应的位置都应该更大
{
	if(nums1.size()!=nums2.size()) return 0;
	for(int i=0;i<nums1.size();i++)
	{
		if(nums2[i]!=0)
			if(nums1[i]<nums2[i])
			{
				return 0;
			}
	}
	return 1;
}

int CountSubstringsWithExactlyKDistinctCharacters(const string& str,const int k)
{
	int res=0;
	vector<vector<int>> dp(str.size(),vector<int>(str.size(),0));
	for(int i=0;i<str.size();i++)
	{
		int cnt=0;
		unordered_set<char> hash;
		for(int j=i;j<str.size();j++)
		{
			char ch=str[j];
			if(hash.count(ch)==0)
			{
				hash.insert(ch);
				cnt++;
			}
			dp[i][j]=cnt;
			if(cnt==k)
			{
				cout<<str.substr(i,j-i+1)<<endl;
				res++;
			}
		}
	}
	return res;
}

int main()
{
	string str="abcbaa";
	int k=3;
	cout<<CountSubstringsWithExactlyKDistinctCharacters(str,k)<<endl;
	return 0;
}
