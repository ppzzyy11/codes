#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Ele
{
    char ch;
    int fre;
    Ele(char ch='\0',int fre=0):ch(ch),fre(fre){}
};
inline bool operator <(const Ele& ele1,const Ele& ele2)
{
	return ele1.fre<ele2.fre;
}
ostream& operator <<(ostream& os,const vector<Ele>& eles)
{
    for(auto ele:eles)
    {
        cout<<ele.ch<<":"<<ele.fre<<"\t";
    }
    return os;
}
ostream& operator <<(ostream& os,const vector<int>& vec)
{
    for(auto v:vec)
    {
        cout<<v<<" ";
    }
    return os;
}
void RearrangeString(string &str,int dstn)
{
    vector<Ele> MH(26);//Max heap
    for(int i=0;i<MH.size();i++)
    {
        MH[i].ch='a'+i;
        MH[i].fre=0;
    }
	for(auto s:str)
	{
		MH[s-'a'].fre++;
	}
	make_heap(MH.begin(),MH.end());
	cout<<MH<<endl;
	string res=str;
	for(int i=0;i<res.size();i++)
	{
		res[i]='\0';
	}
	while(MH.size()&&MH[0].fre!=0)
	{
		Ele& ele=MH[0];
		int pos=0;
		char ch=ele.ch;
		int fre=ele.fre;
		while(pos<res.size()&&res[pos]!='\0')
		{
			pos++;
		}
		while(fre&&pos<res.size())
		{
			fre--;
			res[pos]=ch;
			pos+=dstn;
		}

		pop_heap(MH.begin(),MH.end());
		MH.pop_back();
	}
	cout<<res;

}

int main()
{
    string str="sadfasxzfasdfas";
    string str1="abcd";
    string str2="cdab";

    string txt="aabaacaabaa";
    //string pat="aa";
    string pat="aa";
    RearrangeString(str,3);

    return 0;
}
