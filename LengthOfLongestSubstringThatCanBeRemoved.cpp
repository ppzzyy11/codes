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

int LengthOfLongestSubstringThatCanBeRemoved(const string& str)
{
	vector<int> nums;
	int i=0;
	while(i<str.size())
	{
		int cnt=0;
		while(i<str.size()&&str[i]=='1')
		{
			cnt++;
			i++;
		}
		nums.push_back(cnt);
		cnt=0;
		while(i<str.size()&&str[i]=='0')
		{
			cnt++;
			i++;
		}
		nums.push_back(cnt);
	}

	int res=0;
	for(int i=0;i<nums.size();i=i+2)
	{
		res=max(res,min(nums[i]*2,nums[i+1])/2*3);
	}
	return res;
}

int main()
{
	string str="100100100111000000";
	//string str="111011";
	//string str="1011100000100";
	cout<<LengthOfLongestSubstringThatCanBeRemoved(str)<<endl;
	return 0;
}
