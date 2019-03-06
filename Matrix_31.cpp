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
			cout<<mat[i][j]<<'\t';
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
ostream& operator<<(ostream& os,const vector<vector<char>>& mat)
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

int CountNegativeNumbersInAColumnWiseAndRowWiseSortedMatrix(const vector<vector<int>>& mat)
{
	int res=0;
	int i=0,j=mat[i].size()-1;
	while(i<mat.size()&&j<mat[i].size())
	{
		if(mat[i][0]>=0) return res;
		while(j>=1&&mat[i][j-1]>=0)
		{
			j--;
		}
		res+=j;
		i++;
	}
	return res;
}

int main()
{
	vector<vector<int>> mat=
	{
		{-3, -2, -1, 1},
		{-2, 2, 3, 4},
		{4, 5, 7, 8}
	};
	cout<<CountNegativeNumbersInAColumnWiseAndRowWiseSortedMatrix(mat)<<endl;
	return 0;
}
