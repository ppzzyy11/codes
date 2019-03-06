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
struct Ele{
	int x;
	int y;
	int val;
	Ele(int x,int y,int val):x(x),y(y),val(val){}
};
ostream& operator<<(ostream& os, const vector<Ele>& eles)
{
	for(auto e:eles)
	{
		cout<<'('<<e.x<<','<<e.y<<')'<<' '<<e.val<<'\t';
	}
	cout<<endl;
	return os;
}

//idea is to count the left-top corner of every separated island(Note that every island can have one and only one left-top corner)//wo can also count the right-bottom corner
int CountNumberOfIslandsWhereEveryIslandRowWiseAmdColumnWiseSeparated(const vector<vector<char>>& mat)// 对角线相连的不叫同一个island
{
	int cnt=0;
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			if(mat[i][j]=='X')
				if((i==0||mat[i-1][j]=='O')&&(j==0||mat[i][j-1]=='O'))
				{
					cnt++;
				}
		}
	}
	return cnt;
}

int main()
{
	vector<vector<char>> mat=
	{
		//{'O', 'O', 'O'},
		//{'X', 'X', 'O'},
		//{'X', 'X', 'O'},
		//{'O', 'O', 'X'},
		//{'O', 'O', 'X'},
		//{'X', 'X', 'O'}
		{'X', 'O', 'O', 'O', 'O', 'O'},
		{'X', 'O', 'X', 'X', 'X', 'X'},
		{'O', 'O', 'O', 'O', 'O', 'O'},
		{'X', 'X', 'X', 'O', 'X', 'X'},
		{'X', 'X', 'X', 'O', 'X', 'X'},
		{'O', 'O', 'O', 'O', 'X', 'X'},
	};
	cout<<CountNumberOfIslandsWhereEveryIslandRowWiseAmdColumnWiseSeparated(mat)<<endl;
	return 0;
}
