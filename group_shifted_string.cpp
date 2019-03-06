#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

int main()
{
    vector<string> strs{"acd", "dfg", "wyz", "yab", "mop",
                     "bdfh", "a", "x", "moqs"};
    unordered_map<string,vector<string>> rec;

    for(int i=0;i<strs.size();i++)
    {
        string str=strs[i];
        if(str.size()!=0)
        {
            char sta=str[0];
            for(int i=0;i<str.size();i++)
            {
                str[i]-=sta+26;
                str[i]=str[i]%26;
            }
            rec[str].push_back(strs[i]);
        }
    }
    for(auto r:rec)
    {
        //cout<<r.first<<endl;
        for(int i=0;i<r.second.size();i++)
        {
            cout<<r.second[i]<<endl;
        }
        cout<<endl;
    }
    return 0;
}
