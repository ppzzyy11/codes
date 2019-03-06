#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;

//直接使用的是dp的思想

int CountDistinctOccurrencesAsSubsequences(const string& s,int m,const string& t,int n,vector<vector<int>> & mem)
{
	if(n==0) return 1;
	if(m==0) return 0;

	if(mem[m][n]!=-1)
	{
		return mem[m][n];
	}
	if(s[m-1]==t[n-1])
	{
		mem[m][n]=CountDistinctOccurrencesAsSubsequences(s,m-1,t,n-1,mem)+CountDistinctOccurrencesAsSubsequences(s,m-1,t,n,mem);
	}else
	{
		mem[m][n]=CountDistinctOccurrencesAsSubsequences(s,m-1,t,n,mem);
	}
	return mem[m][n];
}
int CDAS(const string& s,const string& t)
{
	vector<vector<int>> mem(s.size()+1,vector<int>(t.size()+1,-1));
	int res= CountDistinctOccurrencesAsSubsequences(s,s.size(),t,t.size(),mem);
	//for(int i=0;i<mem.size();i++)
	//{
		//for(int j=0;j<mem[i].size();j++)
		//{
			//cout<<mem[i][j]<<'\t';
		//}
		//cout<<endl;
	//}
	return res;
}

int main()
{
	//const string s="geeek";
	const string s="geeksforgeeks";
	const string t="ge";
	cout<<CDAS(s,t)<<endl;
	return 0;
}
