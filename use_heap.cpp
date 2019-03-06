#include<algorithm>
#include<vector>
#include<ctime>
#include<iostream>

using namespace std;

bool Mycompare(const int &a,const int &b)//should a be after b?
{
    return a>b;
}
int main()
{
    vector<int> nums;
    srand(time(NULL));
    const int len = 50;
    const int MAX = 1000;
    for(int i=0;i<len;i++)
    {
        int num=rand()%MAX;
        nums.push_back(num);
        cout<<num<<" ";
    }
    cout<<endl;
    make_heap(nums.begin(),nums.end(),Mycompare);
    for(int i=0;i<len;i++)
    {
        cout<<nums.front()<<" ";
        pop_heap(nums.begin(),nums.end(),Mycompare);
        nums.pop_back();
    }

    return 0;
}
