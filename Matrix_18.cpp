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

int FingTheLargestRectangleOf1SWithSwappingOfColumnsAllowed(const vector<vector<bool>>& mat)
{
	if(mat.size()==0) return 0;
	if(mat[0].size()==0) return 0;
	vector<int>  h(mat[0].size(),0);;
	int Max=0;
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			if(mat[i][j]==1)
			{
				h[j]++;
			}else
			{
				h[j]=0;
			}

			vector<int> tmp=h;
			sort(tmp.begin(),tmp.end());// O(nlogn)
			tmp.push_back(0);

			stack<int> st;
			st.push(-1);

			for(int j=0;j<tmp.size();j++)
			{
				while(st.top()!=-1&&tmp[st.top()]>=tmp[j])
				{
					int top=st.top();
					st.pop();


					Max=max(Max,tmp[top]*(j-st.top()-1));
				}

				st.push(j);
			}
		}
	}
	return Max;

}

int main()
{
	vector<vector<bool>> mat=
	{
		//{0, 1, 0, 1, 0},
		//{0, 1, 0, 1, 1},
		//{1, 1, 0, 1, 0}

		{0, 1, 0, 1, 0},
		{0, 1, 1, 1, 1},
		{1, 1, 1, 0, 1},
		{1, 1, 1, 1, 1}
	};
	cout<<FingTheLargestRectangleOf1SWithSwappingOfColumnsAllowed(mat)<<endl;
	return 0;
}
