#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;

const vector<vector<int>> moves=
{
	{-1,-1},
	{+0,-1},
	{+1,-1},
	{+1,+0},
	{+1,+1},
	{+0,+1},
	{-1,+1},
	{-1,+0}
};
void Helper(const vector<string>&mat,int x,int y,const string& str,int i,vector<pair<int,int>>&rec)
{
	if(x<0||x>=mat.size()) return ;
	if(y<0||y>=mat[0].size()) return ;
	if(str[i]==mat[x][y])
	{
		rec.push_back(make_pair(x,y));
		if(i==str.size()-1)
		{
			for(int i=0;i<rec.size();i++)
			{
				cout<<str[i]<<"("<<rec[i].first<<","<<rec[i].second<<")"<<"\t";

			}
			cout<<endl;
		}else
		for(int j=0;j<moves.size();j++)
		{
			Helper(mat,x+moves[j][0],y+moves[j][1],str,i+1,rec);
		}
		rec.pop_back();
	}
	return ;
}
void FindAllOccurrencesOfWordInAMatrix(const vector<string>&mat,const string&str)
{
	{
		if(mat.size()<=0)
		{
			cerr<<"Mat size is 0!"<<endl;
			return ;
		}
		int len=mat[0].size();
		for(int i=1;i<mat.size();i++)
		{
			if(len!=mat[i].size())
			{
				cerr<<"mat's elements' sizes are not equal!"<<endl;
				return ;
			}
		}
	}

	vector<pair<int,int>> rec;
	//Helper(mat,1,2,str,0,rec);
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			Helper(mat,i,j,str,0,rec);
		}
	}
	return ;
}

int main()
{
	const vector<string> mat=
	{
		"BNEYS",
		"HEDES",
		"SGNDE"
	};
	const string str="DES";
	FindAllOccurrencesOfWordInAMatrix(mat,str);
	return 0;
}
