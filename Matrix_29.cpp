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

bool PreProcess(vector<vector<int>>& mat,vector<vector<int>>& sum)
{
	if(mat.size()==0) return 1;
	if(mat[0].size()==0) return 1;
	sum.resize(mat.size(),vector<int>(mat[0].size(),0));
	for(int i=mat.size()-1;i>=0;i--)
	{
		for(int j=mat[i].size()-1;j>=0;j--)
		{
			int tmp=0;
			if(i==mat.size()-1&&j==mat[i].size()-1)
			{
				tmp=mat[i][j];
			}else if(i==mat.size()-1)
			{
				tmp=mat[i][j]+sum[i][j+1];
			}else if(j==mat[i].size()-1)
			{
				tmp=mat[i][j]+sum[i+1][j];
			}else
			{
				tmp=mat[i][j]+sum[i+1][j]+sum[i][j+1]-sum[i+1][j+1];
			}
			sum[i][j]=tmp;
		}
	}
	return 0;
}

int SumQuery(const int lx,const int ly,const int rx,const int ry,const vector<vector<int>>& sum)
{
	if(rx==sum.size()-1&&ry==sum[rx].size()-1)
	{
		return sum[lx][ly];
	}else if(rx==sum.size()-1)
	{
		return sum[lx][ly]-sum[lx][ry+1];
	}else if(ry==sum[rx].size()-1)
	{
		return sum[lx][ly]-sum[rx+1][ly];
	}else
	{
		return sum[lx][ly]-sum[rx+1][ly]-sum[lx][ry+1]+sum[rx+1][ry+1];
	}
}

int main()
{
	vector<vector<int>> mat=
	{
		{1, 2, 3, 4, 6},
		{5, 3, 8, 1, 2},
		{4, 6, 7, 5, 5},
		{2, 4, 8, 9, 4},
	};
	vector<vector<int>> sum;
	PreProcess(mat,sum);
	cout<<mat<<endl;
	cout<<sum<<endl;
	vector<vector<int>> queries=
	{
		{2,2,3,4},
		{0,0,1,1},
		{1,2,3,3}
	};
	for(int i=0;i<queries.size();i++)
	{
		int lx=queries[i][0];
		int ly=queries[i][1];
		int rx=queries[i][2];
		int ry=queries[i][3];
		cout<<SumQuery(lx,ly,rx,ry,sum)<<endl;
	}
	return 0;
}
