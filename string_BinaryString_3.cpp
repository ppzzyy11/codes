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

int NumberOfFlipsToMakeBinaryStringAlternate(const string& str)
{
	int cnt=0;
	bool num=0;
	for(auto s:str)
	{
		if(s-'0'!=num)
		{
			cnt++;
		}
		num=!num;
	}
	return min(cnt,(int)str.size()-cnt);
}

int main()
{
	//string str="001";
	string str="0001010111";
		cout<<NumberOfFlipsToMakeBinaryStringAlternate(str)<<endl;
	return 0;
}
