#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string  Remove_b_ac(string &str)
{
	string res;
	int i=0;
	while(i<str.size())
	{
		if(str[i]=='b')
		{
			i=i+1;
		}else if(i+1<str.size()&&str[i]=='a'&&str[i+1]=='c')
		{
			i=i+2;
		}else
		{
			res+=str[i];
			i++;
		}
	}
	cout<<res;
	str=res;
	return res;

}

int main()
{
    string str="sadfasxzfasdfas";
    string str1="abcd";
    string str2="cdab";

    string txt="ac";
    //string pat="aa";
    string pat="aa";
	cout<<txt<<endl;
	Remove_b_ac(txt);

    return 0;
}
