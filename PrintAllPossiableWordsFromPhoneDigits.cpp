#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>
#include<stack>
using namespace std;

const vector<string> hashtable=
{
	"",//0
	"",//1
	"abc",//2
	"def",//3
	"ghi",//4
	"jkl",//5
	"mno",//6
	"pqrs",//7
	"tuv",//8
	"wxyz"//9
};
void Helper(string &tmp,vector<string>&res,int j,const vector<int>&nums)
{
	if(j==nums.size())
	{
		res.push_back(tmp);
		return ;
	}
	const string & str=hashtable[nums[j]];
	for(int i=0;i<str.size();i++)
	{
		tmp.push_back(str[i]);
		Helper(tmp,res,j+1,nums);
		tmp.pop_back();
	}

}
void PrintAllPossibleWordsFromPhoneDigits(const vector<int> & nums)
{
	string tmp="";
	vector<string> res;
	Helper(tmp,res,0,nums);
	for(int i=0;i<res.size();i++)
	{
		if(i%10==0)
			cout<<endl;
		cout<<res[i]<<" ";

	}

}

int main()
{
	vector<int> nums={2, 3, 4};
	PrintAllPossibleWordsFromPhoneDigits(nums);
	//adg adh adi aeg aeh aei afg afh afi bdg
	//bdh bdi beg beh bei bfg bfh bfi cdg cdh
	//cdi ceg ceh cei cfg cfh cfi
	return 0;
}
