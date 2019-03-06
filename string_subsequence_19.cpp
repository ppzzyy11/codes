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
ostream& operator<<(ostream& os, const vector<string>& strs)
{
	for(auto str:strs)
	{
		cout<<str<<endl;
	}
	return os;
}

void Helper(const string& str1,int i,const string& str2,int j,const vector<vector<int>>& mat,string &tmp,vector<string>& res)
{
	if(i==0||j==0)
	{
		reverse(tmp.begin(),tmp.end());
		res.push_back(tmp);
		reverse(tmp.begin(),tmp.end());
		return ;
	}

	if(i!=j&&str1[i-1]==str2[j-1])
	{
		tmp+=str1[i-1];
		Helper(str1,i-1,str2,j-1,mat,tmp,res);
		tmp.pop_back();
	}else if(mat[i-1][j]>=mat[i][j-1])
	{
		Helper(str1,i-1,str2,j,mat,tmp,res);
	}else
	{
		Helper(str1,i,str2,j-1,mat,tmp,res);
	}
}
void LongestRepeatingSubsequence(const string& str1,const string& str2)
{
	vector<vector<int>> mat(str1.size()+1,vector<int>(str2.size()+1.,0));
	for(int i=0;i<str1.size();i++)
	{
		for(int j=0;j<str2.size();j++)
		{
			if(str1[i]==str2[j]&&i!=j)
			{
				mat[i+1][j+1]=mat[i][j]+1;
			}else
			{
				mat[i+1][j+1]=max(mat[i][j+1],mat[i+1][j]);
			}
		}
	}

	string tmp="";
	vector<string> res;
	Helper(str1,str1.size(),str2,str2.size(),mat,tmp,res);
	cout<<res<<endl;
}
void LRS(const string& str)
{
	LongestRepeatingSubsequence(str,str);
}

int main()
{
	//string str="AABEBCDD";
	string str="AAAA";
	LRS(str);
	return 0;
}
