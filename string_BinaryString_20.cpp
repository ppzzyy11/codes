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

int WaysToRemoveOneElementFromABinaryStringSoXORBecomesZero(const string& str)
{
	vector<int> rec(2,0);
	for(int i=0;i<str.size();i++)
	{
		switch (str[i])
		{
			case '0':
				rec[0]++;
				break;

			case '1':
				rec[1]++;
				break;
		}
	}
	if(rec[1]%2==1) return rec[1];
	else return rec[0];
}

int main()
{
	string str="10111";
	cout<<WaysToRemoveOneElementFromABinaryStringSoXORBecomesZero(str)<<endl;
	return 0;
}
