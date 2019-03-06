#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;

ostream& operator<<(ostream& os, const vector<vector<int>>& mat)
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

void PrintLCS(const string& str1,const string& str2)
{
	vector<vector<int>> mat(str1.size()+1,vector<int>(str2.size()+1,0));
	for(int i=0;i<str1.size();i++)
	{
		for(int j=0;j<str2.size();j++)
		{
			if(str1[i]==str2[j])
			{
				mat[i+1][j+1]=mat[i][j]+1;
			}else
			{
				mat[i+1][j+1]=max(mat[i+1][j],mat[i][j+1]);
			}
		}
	}
	int i=str1.size(),j=str2.size();

	string res="";
	while(i!=0&&j!=0)
	{
		if(str1[i-1]==str2[j-1])
		{
			res+=str1[i-1];
			i--;
			j--;
		}else if(mat[i][j-1]>=mat[i-1][j])
		{
			j--;
		}else
		{
			i--;
		}
	}

	reverse(res.begin(),res.end());
	cout<<res<<endl;
	return;
}

int main()
{
	string str1="1234567890";
	string str2="3579";
	PrintLCS(str1,str2);
	return 0;
}
