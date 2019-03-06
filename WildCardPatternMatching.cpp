#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;

bool Helper(const string& txt,int i,const string& pat,int j,vector<vector<int>>&mem)
{
	if(i<0||i>=txt.size()) return 0;
	if(j<0||j>=pat.size()) return 0;
	if(mem[i][j]!=-1)
	{
		//cout<<"mem read\n";
		//下面这些测试实例并没有用到
		//难道是因为是单pat的缘故么？
		return mem[i][j];
	}

	bool res=0;
	if(txt[i]==pat[j]||pat[j]=='?')
	{
		if(i==txt.size()-1&&j==pat.size()-1)
		{
			return 1;
		}
		res=Helper(txt,i+1,pat,j+1,mem);
	}else if(pat[j]=='*')
	{
		if(i==txt.size()-1&&j==pat.size()-1)
		{
			return 1;
		}
		res=Helper(txt,i,pat,j+1,mem)||Helper(txt,i+1,pat,j,mem);
	}else
	{
		res=0;
	}
	mem[i][j]=res;
	return res;
}
//* match with 0 or more instances of any character or set of characters
//? matches with any one character
bool StringMatching(const string& pat,const string& txt)
{
	vector<vector<int>> mem(txt.size(),vector<int>(pat.size(),-1));
	return Helper(txt,0,pat,0,mem);
}
int main()
{

	cout<<endl<<StringMatching("g*ks", "geeks"); // Yes
	cout<<endl<<StringMatching("ge?ks*", "geeksforgeeks"); // Yes
	cout<<endl<<StringMatching("g*k", "gee");  // No because 'k' is not in second
	cout<<endl<<StringMatching("*pqrs", "pqrst"); // No because 't' is not in first
	cout<<endl<<StringMatching("abc*bcd", "abcdhghgbcd"); // Yes
	cout<<endl<<StringMatching("abc*c?d", "abcd"); // No because second must have 2
	cout<<endl<<StringMatching("****************ba***********ab", "baaabab"); // yes
	return 0;
}
