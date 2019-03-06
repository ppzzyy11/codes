#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;

string& ReplaceABWithC(string& str)
{
	int i=0,j=0;
	while(j<str.size())
	{
		if(j+1<str.size()&&str[j]=='A'&&str[j+1]=='B')
		{
			str[i]='C';
			i++;j++;j++;
		}else
		{
			str[i]=str[j];
			i++;j++;
		}
	}
	str.resize(i);
	return str;
}

int main()
{
	string str="helloABworld";
	cout<<ReplaceABWithC(str)<<endl;
	str="fghABsdfABysu";
	cout<<ReplaceABWithC(str)<<endl;
	return 0;
}
