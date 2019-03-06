#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<cctype>
#include<set>
#include<map>
#include<climits>
using namespace std;


ostream& operator<<(ostream& os, const vector<vector<int>>& mat)
{
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			cout<<mat[i][j]<<'\t';
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
ostream& operator<<(ostream& os, const vector<int>& nums)
{
	for(auto num:nums)
	{
		cout<<num<<' ';
	}
	cout<<endl;
	return os;
}
ostream& operator<<(ostream& os, const vector<vector<string>>& strs)
{
	for(int i=0;i<strs.size();i++)
	{
		for(int j=0;j<strs[i].size();j++)
		{
			cout<<strs[i][j]<<' ';
			//cout<<i<<":"<<j<<endl;
		}
		cout<<endl;
	}
	return os;
}
ostream& operator<<(ostream& os,const vector<vector<char>>& mat)
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

int MaximumSizeRectangleBinarySubMatirxWithAll1S(const vector<vector<bool>>& mat)
{
	if(mat.size()==0) return 0;
	if(mat[0].size()==0) return 0;
	int res=0;
	vector<int> h(mat[0].size()+1,0);
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			if(mat[i][j]==1)
				h[j]++;
			else
				h[j]=0;
		}
		//cout<<h<<endl;
		stack<int> st;
		st.push(-1);
		for(int j=0;j<h.size();j++)
		{
			while(st.top()!=-1&&h[st.top()]>=h[j])
			{
				int top=st.top();
				st.pop();
				//cout<<top<<":"<<h[top]<<"\t"<<(j-st.top()-1)<<endl;;
				res=max(res,h[top]*(j-st.top()-1));
			} st.push(j);
		}
	}
	return res;
}

int main()
{
	vector<vector<bool>> mat=
	{
		{0, 1, 1, 0},
		{1, 1, 1, 1},
		{1, 1, 1, 1},
		{1, 1, 0, 0},
	};
	cout<<MaximumSizeRectangleBinarySubMatirxWithAll1S(mat)<<endl;
	return 0;
}
