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

char KthNonRepeatingCharacter(const string& str, const int k)
{
	vector<int> cnt;
	vector<char> rec;
	unordered_map<char,int> hash;
	for(int i=0;i<str.size();i++)
	{
		char ch=str[i];
		if(hash.count(ch)==0)
		{
			hash[ch]=cnt.size();
			rec.push_back(ch);
			cnt.push_back(1);
		}else
		{
			int idx=hash[ch];
			cnt[idx]++;
		}
	}
	int No=0;
	for(int i=0;i<cnt.size();i++)
	{
		if(cnt[i]==1)
		{
			No++;
			if(No==k)
			{
				return rec[i];
			}
		}
	}
	cout<<"No such character"<<endl;
	return 0;
}

int main()
{
	string str="geeksforgeeks";
	int k=4;//2 3 4
	cout<<KthNonRepeatingCharacter(str,k)<<endl;
	return 0;
}
