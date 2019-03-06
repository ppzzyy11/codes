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

bool winC(char ch,const vector<vector<char>>& mat)
{
	for(int i=0;i<mat.size();i++)
	{
		if(mat[i][0]==ch&&mat[i][1]==ch&&mat[i][2]==ch) return 1;
	}
	for(int j=0;j<mat[0].size();j++)
	{
		if(mat[0][j]==ch&&mat[1][j]==ch&&mat[2][j]==ch) return 1;
	}
	if(mat[0][0]==ch&&mat[1][1]==ch&&mat[2][2]==ch) return 1;
	if(mat[0][2]==ch&&mat[1][1]==ch&&mat[2][0]==ch) return 1;
	return 0;
}

bool ValidityOfAGivenTicTacToeBoardConfiguration(const vector<vector<char>>& mat)
{
	if(mat.size()!=3)
	{
		return 0;
	}
	for(int i=0;i<mat.size();i++)
	{
		if(mat[i].size()!=3)
			return 0;
	}
	int cntX=0,cntO=0;
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			if(mat[i][j]=='X')
			{
				cntX++;
			}else if(mat[i][j]=='O')
			{
				cntO++;
			}
		}
	}
	if(cntO!=cntX&&cntX!=cntO+1)
		return 0;

	bool winX=0,winO=0;
	winX=winC('X',mat);
	winO=winC('O',mat);
	if(winX&&winO) return 0;
	return 1;
}


int main()
{
	vector<vector<char>> mat=
	{
		//{ 'X', 'X', 'O' },
		//{ 'O', 'O', 'X' },
		//{ 'X', 'O', 'X' }

		//{ 'O', 'X', 'X' },
		//{ 'O', 'X', 'X' },
		//{ 'O', 'O', 'X' }

		{ 'O', 'X', ' ' },
		{ ' ', ' ', ' ' },
		{ ' ', ' ', ' ' }
	};

	cout<<ValidityOfAGivenTicTacToeBoardConfiguration(mat)<<endl;
	return 0;
}
