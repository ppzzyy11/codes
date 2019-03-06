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

bool IfBinaryNumberDivisibleBy5(const string& str)
{
	const vector<int> rmds={1,2,4,3};

	int idx=0;
	int rmd=0;
	for(int i=str.size()-1;i>=0;i--)
	{
		if(str[i]=='1')
		{
			rmd+=rmds[idx];
			rmd%=5;
		}
		idx++;
		idx%=rmds.size();
	}
	return rmd==0;
}


int main()
{
	string str="0000101001";
	//string str="10000101001";
	cout<<IfBinaryNumberDivisibleBy5(str)<<endl;
	return 0;
}
