/*
 * Opposite Question of BinaryIndexedTree 6
 *
 *
 * Left Right
 *
 * Or you can just reverse the nums so you can get the correct answer
 *
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<cctype>
#include<set>
#include<map>
#include<climits>
using namespace std;


ostream& operator<<(ostream& os, const vector<vector<int>>& mat)
{
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			cout<<mat[i][j]<<'\t';
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
ostream& operator<<(ostream& os,const vector<vector<char>>& mat)
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

template<typename Value>
class BinaryIndexedTree{
	public:
		BinaryIndexedTree(vector<Value>& nums)
		{
			Convert(nums);
			BIT.resize(nums.size()+1,0);
		}
		~BinaryIndexedTree()
		{
		}
		Value GetSum(const int idx)const ;
		bool Update(const int idx,const Value val);
	protected:
	private:
		vector<Value> BIT;
		void Convert(vector<Value>&);

};

template<typename Value>
Value BinaryIndexedTree<Value>::GetSum(const int idx) const
{
	Value sum=0;
	int i=idx+1;
	while(i>0)
	{
		sum+=BIT[i];
		i=i-(i&(-i));
	}
	return sum;
}

template<typename Value>
bool BinaryIndexedTree<Value>::Update(const int idx,const Value val)
{
	int i=idx+1;
	while(i<BIT.size())
	{
		BIT[i]+=val;
		i=i+(i&(-i));
	}
	return true;
}

template<typename Value>
void BinaryIndexedTree<Value>::Convert(vector<Value>&  nums)//O(N) using map
{
	vector<Value> tmp=nums;
	unordered_map<Value,vector<int>> hash;//may overload hash
	for(int i=0;i<nums.size();i++)
	{
		hash[nums[i]].push_back(i);
	}
	sort(tmp.begin(),tmp.end());
	for(int i=0;i<tmp.size();i++)
	{
		for(auto idx:hash[tmp[i]])//indexes that have value of tmp[i] in nums
		{
			nums[idx]=i;
		}
	}
}

template<typename Value>
class Smaller:public BinaryIndexedTree<Value>
{
	public:
		Smaller(vector<Value>& nums):BinaryIndexedTree<Value> (nums)//use BinaryIndexedTree as a hash
	{
		smaller.resize(nums.size(),0);
		Cnt=0;
		for(int i=0;i<nums.size();i++)
		{
			smaller[i]=this->GetSum(nums[i]);//
			this->Update(nums[i],1);
		}
		for(auto s:smaller)
		{
			Cnt+=s;
		}
	}
		int GetNthVale(const int idx)const
		{
			if(idx<0||idx>=smaller.size()) return INT_MIN;
			return smaller[idx];
		}
		int GetCnt()const {return Cnt;}
	private:
	protected:
		vector<int> smaller;//store the result smaller than nums[i] that is on the left of nums[i]
		int Cnt;
};

template<typename Value>
class Bigger:public BinaryIndexedTree<Value>
{
	public:
		Bigger(vector<Value>& nums):BinaryIndexedTree<Value> (nums)
	{
		bigger.resize(nums.size(),0);
		Cnt=0;
		for(int i=nums.size()-1;i>=0;i--)
		{
			bigger[i]=this->GetSum(nums.size()-nums[i]-1);
			this->Update(nums.size()-nums[i]-1,1);
		}
		for(auto b:bigger)
		{
			Cnt+=b;
		}
	}
		int GetNthVale(const int idx) const
		{
			if(idx<0||idx>=bigger.size()) return INT_MIN;
			return bigger[idx];
		}
		int GetCnt()const {return Cnt;}
	private:
	protected:
		int Cnt;
		vector<int> bigger;//store the number of elements bigger than than is on the right of nums[i]

};

int main()
{
	//vector<int> nums{2,4,6,8,INT_MAX/4,INT_MIN/4};
	vector<int> nums{9,6,4,5,8};
	//vector<int> nums{8,4,2,1};
	//vector<int> nums{8,4,2,1};
	Smaller<int> sl(nums);
	Bigger<int> bg(nums);
	for(int i=0;i<nums.size();i++)
	{
		cout<<sl.GetNthVale(i)<<' ';
	}
	cout<<'\n';
	for(int i=0;i<nums.size();i++)
	{
		cout<<bg.GetNthVale(i)<<' ';
	}
	cout<<'\n';
	int res=0;
	for(int i=0;i<nums.size();i++)
	{
		res+=sl.GetNthVale(i)*bg.GetNthVale(i);
	}
	cout<<res<<endl;
	return 0;
}
