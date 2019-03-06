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

string AddTwoBitStrings(const string& str1,const string& str2)
{
	string res="";
	int i=str1.size()-1,j=str2.size()-1;
	int add=0;
	while(i>=0||j>=0||add>0)
	{
		int num=0;
		if(i>=0) {num+=str1[i]-'0';i--;}
		if(j>=0) {num+=str2[j]-'0';j--;}
		if(add) num++;
		char ch='0'+num%2;
		add=num/2;
		res+=ch;
	}
	reverse(res.begin(),res.end());
	return res;
}

int main()
{
	string str1="111111";
	string str2="1111";
	cout<<AddTwoBitStrings(str1,str2)<<endl;
	return 0;
}
