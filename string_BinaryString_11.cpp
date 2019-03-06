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

void Helper(const int&n, int cnt1, string& tmp,vector<string>& res)
{
	if(tmp.size()==n)
	{
		res.push_back(tmp);
		return ;
	}
	tmp+='1';
	Helper(n,cnt1+1,tmp,res);
	tmp.pop_back();

	if(cnt1*2>tmp.size())
	{
		tmp+='0';
		Helper(n,cnt1,tmp,res);
		tmp.pop_back();
	}
}

void GenerateAllPermutationsSuchThat1MoreThan0AtEveryPoint(const int n)
{
	string tmp="";
	vector<string> res;
	Helper(n,0,tmp,res);
	cout<<res;
}

int main()
{
	int n=4;
	GenerateAllPermutationsSuchThat1MoreThan0AtEveryPoint(n);
	return 0;
}
