#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;

bool Helper(const string&txt, int i,const string&pat, int j,vector<vector<int>>&mem)
{
	if(i<0||i>=txt.size()) return 0;
	if(j<0||j>=pat.size()) return 0;
	if(mem[i][j]!=-1) return mem[i][j];

	bool res;
	if(txt[i]==pat[j]||pat[j]=='?')
	{
		if(i==txt.size()-1&&j==pat.size()-1)
			return mem[i][j]=1;
		res=Helper(txt,i+1,pat,j+1,mem);
	}else if(pat[j]=='*')
	{
		if(i==txt.size()-1&&j==pat.size()-1)
			return mem[i][j]=1;
		res=Helper(txt,i+1,pat,j,mem)||Helper(txt,i,pat,j+1,mem);
	}else
	{
		res=0;
	}
	return mem[i][j]=res;
}
bool WildcardMatching(const string& txt,const string& pat)
{
	vector<vector<int>> mem(txt.size(),vector<int>(pat.size(),-1));
	return 	Helper(txt,0,pat,0,mem);
}

int main()
{
	const string txt="baaabab";
	const vector<string> pat={
		"*****ba*****ab"  ,
		"ba*****ab"    ,
		"ba*ab"        ,
		"a*ab"         ,
		"a*****ab"     ,

		"*a*****ab"    ,
		"ba*ab****"    ,
		"****"        ,
		"*"            ,
		"aa?ab"        ,

		"b*b"          ,
		"a*a"          ,
		"baaabab"      ,
		"?baaabab"     ,
		"*baaaba*"     ,
	};
	for(int i=0;i<pat.size();i++)
	{
		cout<<WildcardMatching(txt,pat[i])<<endl;
	}
	return 0;
}
