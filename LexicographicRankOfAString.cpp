#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;

///Lexicographic rank of a string
//就是说所有的permutations中，目前这个string，它排第几？
//我们假设没有 duplicates，如果有问题会变得稍微没意义: aa 是排第一还是第二？？？？？ 都说得通
int LexicographicRankOfAString(const string& str)
{
	vector<int> scm(str.size(),0);//smaller characters number after this character
	for(int i=0;i<scm.size();i++)
	{
		for(int j=i+1;j<scm.size();j++)
		{
			if(str[i]>str[j])
				scm[i]++;
		}
	}
	for(int i=0;i<scm.size();i++)
	{
		cout<<scm[i]<<" ";
	}
	cout<<endl;
	int res=1;
	for(int i=0;i<scm.size();i++)
	{
		int num=scm[i];
		int tmp=1;
		for(int j=1;j<str.size()-i;j++)
		{
			tmp*=j;
		}
		res+=tmp*num;
	}
	return res;

}
int main()
{
	cout<<LexicographicRankOfAString("abc")<<endl;//1
	cout<<LexicographicRankOfAString("cba")<<endl;//6
	cout<<LexicographicRankOfAString("string")<<endl;//598
	//cout<<LexicographicRankOfAString("geeks")<<endl;// 不知道结果
	return 0;
}
