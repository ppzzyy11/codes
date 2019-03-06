#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;

int MaximumLengthPrefixOfOneStringAsSubsequencesInAnother(const string &s,const string& t)
{
	int i=0;
	int j=0;
	while(j<t.size())
	{
		if(i==s.size()) break;
		if(s[i]==t[j])
		{
			i++;
			j++;
		}else
		{
			j++;
		}
	}
	return i;
}

int main()
{//test pass
	//const string s="digger";
	//const string t="biggerdiagram";
	const string s="geeksforgeeks";
	const string t="agbcedfeitk";
	cout<<MaximumLengthPrefixOfOneStringAsSubsequencesInAnother(s,t)<<endl;
	return 0;
}
