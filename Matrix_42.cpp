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

ostream& operator<<(ostream& os,const pair<int,int>& p)
{
	cout<<'('<<p.first<<','<<p.second<<')'<<endl;
	return os;
}

string Position2String(int N,int i,int j)
{
	string str="";
	while(N>1)
	{
		if(i<N/2&&j<N/2)
		{
			str+='a';
		}else if(i<N/2&&j>=N/2)
		{
			str+='b';
			j-=N/2;
		}else if(i>=N/2&&j<N/2)
		{
			str+='c';
			i-=N/2;
		}else
		{
			str+='d';
			i-=N/2;
			j-=N/2;
		}
		N=N/2;
	}
	return str;
}

pair<int,int> String2Position(const string& str)
{
	int x=0;
	int y=0;
	for(int i=0;i<str.size();i++)
	{
		x=x*2;
		y=y*2;
		switch(str[i])
		{
			case 'a':
				;
				break;

			case 'b':
				y++;
				break;

			case 'c':
				x++;
				break;

			case 'd':
				x++;
				y++;
				break;
		};
	}
	return make_pair(x,y);
}

string ReturnPreviousElementsInAnExpandingMatrix(const string& str)
{
	int N=1;
	for(int i=0;i<str.size();i++)
	{
		N*=2;
	}
	auto p=String2Position(str);
	int x=p.first;
	int y=p.second;
	if(y==0)
	{
		y=N-1;
	}else
	{
		y--;
	}
	return Position2String(N,x,y);
}

int main()
{
	//string str="dda";
	//string str="cca";
	string str="aacbddc";
	cout<<ReturnPreviousElementsInAnExpandingMatrix(str)<<endl;
	return 0;
}
