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

bool BiggerOrEqualThan(const vector<int>& nums1,const vector<int>& nums2)//所有nums2中不为0的值，nums1中对应的位置都应该更大
{
	if(nums1.size()!=nums2.size()) return 0;
	for(int i=0;i<nums1.size();i++)
	{
		if(nums2[i]!=0)
			if(nums1[i]<nums2[i])
			{
				return 0;
			}
	}
	return 1;
}

void FindTheSmallestWindowInAStringContainingAllCharacterOfAnotherString(const string& str, const string& pat)
{
	if(str.size()<pat.size())
	{
		cout<<"str is too short!"<<endl;
		return ;
	}
	if(pat.size()==0)
	{
		cout<<"pat empty string"<<endl;
		return ;
	}

	vector<int> rec_pat(256,0);
	vector<int> rec_str(256,0);

	for(auto p:pat)
	{
		rec_pat[p]++;
	}

	int l=0,r=0;
	int L=-1,R=-1;
	int count=0;
	while(r<str.size())
	{
		char ch=str[r];
		if(rec_pat[ch]>0)//need count ch
		{
			if(rec_str[ch]<rec_pat[ch])
			{
				count++;
			}
			rec_str[ch]++;

			if(count==pat.size())// OK, begin to mini Window [l...r]
			{
				while(l<r)//attention: Window start at index l, end at r
				{
					char ch=str[l];
					if(rec_pat[ch]!=0)
					{
						rec_str[ch]--;
						if(rec_str[ch]<rec_pat[ch])
						{
							count--;
							if(count<pat.size())
							{
								if(L==-1)
								{
									L=l;
									R=r;
								}else
								{
									if(r-l<R-L)
									{
										R=r;
										L=l;
									}
								}
								l++;
								break;
							}
						}
					}
					l++;
				}
			}
		}
		r++;
		//cout<<l<<":"<<r<<endl;
		//cout<<L<<":"<<R<<endl<<endl;
		//cout<<rec_str<<endl;
	}
	cout<<L<<"->"<<R<<":"<<str.substr(L,R-L+1)<<endl;
	return ;
}

int main()
{
	//string str="this is a test string";
	//string pat="tist";
	string str="geeksforgeeks";
	string pat="ork";
	FindTheSmallestWindowInAStringContainingAllCharacterOfAnotherString(str,pat);
	return 0;
}
