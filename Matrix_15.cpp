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

void FloodFill(vector<vector<char>>& mat,int x, int y, char preC, char newC)
//void FloodFill(vector<vector<int>>& mat,int x, int y, int preC, int newC)
{
	if(x<0||y<0) return ;
	if(x>=mat.size()) return ;
	if(y>=mat[x].size()) return ;
	if(mat[x][y]!=preC) return ;
	mat[x][y]=newC;//go before the following 4 Recur
	FloodFill(mat,x-1,y,preC,newC);
	FloodFill(mat,x+1,y,preC,newC);
	FloodFill(mat,x,y+1,preC,newC);
	FloodFill(mat,x,y-1,preC,newC);
}

void ReplaceAllOWithXIfSurroundedByX(vector<vector<char>>& mat)
{
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat.size();j++)
		{
			if(mat[i][j]=='O')
			{
				mat[i][j]='-';
			}
		}
	}
	for(int i=0;i<mat.size();i++)
	{
		if(mat[i][0]=='-') FloodFill(mat,i,0,'-','O');
		if(mat[i][mat[i].size()-1]=='-') FloodFill(mat,i,mat[i].size()-1,'-','O');
	}
	for(int j=0;j<mat[0].size();j++)
	{
		if(mat[0][j]=='-') FloodFill(mat,0,j,'-','O');
		if(mat[mat.size()-1][j]=='-') FloodFill(mat,mat.size()-1,j,'-','O');
	}
	for(int i=1;i<mat.size();i++)
	{
		for(int j=1;j<mat[i].size();j++)
		{
			if(mat[i][j]=='-')
				mat[i][j]='X';
		}
	}
}

int main()
{
	vector<vector<char>> mat=
	{
		//{'X', 'O', 'X', 'X', 'X', 'X'},
		//{'X', 'O', 'X', 'X', 'O', 'X'},
		//{'X', 'X', 'X', 'O', 'O', 'X'},
		//{'O', 'X', 'X', 'X', 'X', 'X'},
		//{'X', 'X', 'X', 'O', 'X', 'O'},
		//{'O', 'O', 'X', 'O', 'O', 'O'},
		{'X', 'X', 'X', 'X'},
		{'X', 'O', 'X', 'X'},
		{'X', 'O', 'O', 'X'},
		{'X', 'O', 'X', 'X'},
		{'X', 'X', 'O', 'O'},
	};
	cout<<mat<<endl;
	ReplaceAllOWithXIfSurroundedByX(mat);
	cout<<mat<<endl;
	return 0;
}
