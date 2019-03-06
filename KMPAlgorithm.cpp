#include<iostream>
#include<vector>
using namespace std;

ostream& operator <<(ostream& os,const vector<int>& vec)
{
    for(auto v:vec)
    {
        cout<<v<<" ";
    }
    return os;
}
void KMPAlgorithm(const string& txt,const string& pat)
{
    vector<int> lps(pat.size(),0);
    int i=1,j=0;
    while(i<pat.size())
    {
        if(pat[i]==pat[j])
        {
            j++;
            lps[i]=j;
            i++;
        }else if(j==0)
        {
            i++;
        }else
        {
            j=lps[j-1];
        }
    }

    cout<<lps<<endl;

    i=j=0;
    while(i<txt.size())
    {
        if(pat[j]==txt[i])
        {
            i++;
            j++;
        }

        if(j==pat.size())
        {
            cout<<"Found at index :"<<i-j<<endl;
            j=lps[j-1];
        }else if(i<txt.size()&&pat[j]!=txt[i])
        {
            if(j==0)
            {
                i++;
            }else
            {
                j=lps[j-1];
            }
        }
    }
}

int main()
{
    string str="abcf";
    string str1="abcd";
    string str2="cdab";

    string txt="aabaacaabaa";
    //string pat="aa";
    string pat="aa";

    KMPAlgorithm(txt,pat);
    return 0;
}
