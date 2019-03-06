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

string EfficientMethodFor2sComplementOfABinaryString(const string& str)
{
	string res=str;
	int i=res.size()-1;
	while(i>=0&&res[i]!='1')
		i--;
	if(i<0)
	{
		res='1'+res;
		return res;
	}
	for(int j=i-1;j>=0;j--)
	{
		if(res[j]=='1')
			res[j]='0';
		else
			res[j]='1';
	}
	return res;
}

int main()
{
	//string str="0111";
	//string str="1100";
	//string str="1000100";
	//string str="11111111";
	string str="00000";
	cout<<EfficientMethodFor2sComplementOfABinaryString(str)<<endl;
	return 0;
}
