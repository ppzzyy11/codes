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
		string t=tmp;
		while(i!=0)
		{
			i--;
			tmp+=str1[i];
		}
		while(j!=0)
		{
			j--;
			tmp+=str2[j];
		}
		reverse(tmp.begin(),tmp.end());
		res.push_back(tmp);
		reverse(tmp.begin(),tmp.end());
		tmp=t;
		return ;
	}

	if(str1[i-1]==str2[j-1])
	{
		tmp+=str1[i-1];
		Helper(str1,i-1,str2,j-1,mat,tmp,res);
		tmp.pop_back();
	}else {
		if(mat[i][j-1]>=mat[i-1][j])
		{
			tmp+=str2[j-1];
			Helper(str1,i,str2,j-1,mat,tmp,res);
			tmp.pop_back();
		}
		if(mat[i][j-1]<=mat[i-1][j])
		{
			tmp+=str1[i-1];
			Helper(str1,i-1,str2,j,mat,tmp,res);
			tmp.pop_back();
		}
	}
}
void PrintAllLCS(const string& str1,const string& str2)
{
	vector<vector<int>> mat(str1.size()+1,vector<int>(str2.size()+1.,0));
	for(int i=0;i<str1.size();i++)
	{
		for(int j=0;j<str2.size();j++)
		{
			if(str1[i]==str2[j])
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

int main()
{
	string str1="AGGTAB";
	string str2="GXTXAYB";
	PrintAllLCS(str1,str2);
	return 0;
}
