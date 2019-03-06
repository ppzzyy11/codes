#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;

int NumberOfTimesOccursAsASubsequences(const string& str0, const string& str1)
{
	vector<int> rec(str1.size(),0);
	vector<int> tmp(str1.size(),0);

	for(int i=0;i<str0.size();i++)
	{
		for(int j=0;j<str1.size();j++)
		{
			tmp[j]=0;
		}
		for(int j=0;j<str1.size();j++)
		{
			if(str1[j]==str0[i])
			{
				if(j==0)
				{
					tmp[0]++;
				}else
				{
					tmp[j]+=rec[j-1];
				}
			}
		}
		for(int j=0;j<str1.size();j++)
		{
			rec[j]+=tmp[j];
		}
	}
	return rec.back();
}

int main()
{
	string str0="GeeksforGeeks";
	string str1="Gees";//Gks Gee通过测试
	cout<<NumberOfTimesOccursAsASubsequences(str0,str1)<<endl;
	return 0;
}
