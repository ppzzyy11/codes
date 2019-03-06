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


void Helper(const string& str,int i,string& tmp,vector<string>& res)
{
	if(i==str.size())
	{
		res.push_back(tmp);
		return ;
	}

	if(str[i]=='?')
	{
		tmp+='1';
		Helper(str,i+1,tmp,res);
		tmp.pop_back();

		tmp+='0';
		Helper(str,i+1,tmp,res);
		tmp.pop_back();
	}else
	{
		tmp+=str[i];
		Helper(str,i+1,tmp,res);
		tmp.pop_back();
	}
}

void GenerateAllStringsFromPattern(const string& str)
{
	string tmp="";
	vector<string> res;
	Helper(str,0,tmp,res);
	cout<<res;
}

int main()
{
	string str="1??0?101";
	GenerateAllStringsFromPattern(str);
	return 0;
}
