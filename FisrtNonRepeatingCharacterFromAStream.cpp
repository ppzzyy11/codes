#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;
void FisrtNonRepeatingCharacterFromAStream(string &str)//wp asummed that there is only 26 characters from 'a' to 'z'
{
	list<int> dll;
	list<int> Nil(1);
	vector<bool> repeated(26,0);
	vector<list<int>::iterator> add(26,Nil.begin());

	for(auto ch:str)
	{
		int index=ch-'a';
		if(repeated[index]==1)
		{
			;
		}else if(add[index]==Nil.begin())
		{
			dll.push_back(ch);
			add[index]=Nil.end();
		}else
		{
			repeated[index]=1;
			dll.remove(ch);
			cout<<"remove "<<ch<<endl;
		}
		if(dll.size()!=0)
		{
			cout<<(char)dll.front()<<endl;
		}else
		{
			cout<<"dll empty"<<endl;
		}
		cout<<"dll:";
		for(auto it=dll.begin();it!=dll.end();it++)
		{
			cout<<(char)*it<<" ";
		}
		cout<<endl;
		cout<<"repeated:";
		for(auto r:repeated)
		{
			cout<<r<<" ";
		}
		cout<<endl;
		cout<<"add:";
		for(auto it=add.begin();it!=add.end();it++)
		{
			cout<<(*it==Nil.end())<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	string str="abcdefadcb";
	FisrtNonRepeatingCharacterFromAStream(str);
	return 0;
}
