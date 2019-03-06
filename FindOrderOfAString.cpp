#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>
#include<stack>
using namespace std;

void TopologicalSortingUntil(int src,const vector<vector<bool>>& gh,vector<bool>&visited,stack<int>&st)
{
	visited[src]=1;
	const vector<bool>& arr=gh[src];
	for(int i=0;i<arr.size();i++)
	{
		if(visited[i]==0&&gh[src][i]==1)
		{
			TopologicalSortingUntil(i,gh,visited,st);
		}
	}
	st.push(src);
}
void FindOrderOfCharacters(const vector<string>&strings)
{
	unordered_map<char,int> rec;//character and its index in both diminasion
	unordered_map<int,char> anti;//index and character
	int index=0;
	for(auto str:strings)//这里建立两种映射
	{
		for(auto s:str)
		{
			if(rec.count(s)==0)
			{
				rec[s]=index;
				anti[index]=s;
				index++;
			}
		}
	}
	vector<vector<bool>> gh(index,vector<bool>(index,0));

	for(int i=0;i<strings.size();i++)//建立图
	{
		for(int j=i+1;j<strings.size();j++)
		{
			int k=0;
			int len=min(strings[i].size(),strings[j].size());
			while(k<len&&strings[i][k]==strings[j][k])
			{
				k++;
			}
			if(k<len)
				gh[rec[strings[i][k]]][rec[strings[j][k]]]=1;
		}
	}

	stack<int> st;
	vector<bool> visited(index,0);
	for(int i=0;i<index;i++)
	{
		if(visited[i]==0)
		{
			TopologicalSortingUntil(i,gh,visited,st);
		}
	}
	while(!st.empty())
	{
		int idx=st.top();
		cout<<anti[idx]<<" ";
		st.pop();
	}
	cout<<endl;
}

int main()
{
	vector<string> words={"caa", "aaa", "aab"};
	FindOrderOfCharacters(words);//'c', 'a', 'b'
	words={"baa", "abcd", "abca", "cab", "cad"};
	FindOrderOfCharacters(words);//'b', 'd', 'a', 'c'
	return 0;
}
