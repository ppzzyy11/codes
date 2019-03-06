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
		BinaryIndexedTree(const vector<Value>& nums,const Value val=0)
		{
			BIT.resize(nums.size()+1,val);
			for(int i=0;i<nums.size();i++)
			{
				Update(i,nums[i]);
			}
		}
		~BinaryIndexedTree()
		{
			;
		}
		Value GetSum(const int idx)const ;
		bool Update(const int idx,const Value val);
	protected:
	private:
		vector<Value> BIT;

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
class CountInversions:public BinaryIndexedTree<Value>
{
	public:
		CountInversions(vector<Value> & nums):BinaryIndexedTree<Value>(nums)
		{
			Convert(nums);//Without this step input such as INT_MIN,INT_MAX will cost so much time
			//cause bad alloc


			Value Max,Min;
			for(int i=0;i<nums.size();i++)
			{
				if(i==0)
				{
					Min=Max=nums[0];
				}else if(nums[i]<Min)
				{
					Min=nums[i];
				}else if(nums[i]>Max)
				{
					Max=nums[i];
				}
			}
			BIT.resize(Max-Min+2,0);
			for(int i=nums.size()-1;i>=0;i--)
			{
				cnt+=GetSum(nums[i]-Min);
				Update(nums[i]-Min);
			}
		}
		int GetInversions()
		{
			return cnt;
		}
	protected:
		int cnt=0;
		vector<Value> BIT;
	private:
		bool Update(const int idx)//add one to the arr, do a lot in the BIT
		{
			int i=idx+1;
			while(i<BIT.size())
			{
				BIT[i]++;
				i=i+(i&(-i));
			}
			return true;
		}
		int GetSum(const int idx)
		{
			int i=idx+1;
			int res=0;
			while(i>0)
			{
				res+=BIT[i];
				i=i-(i&(-i));
			}
			return res;
		}
		void Convert(vector<Value>& nums);

};

template<typename Value>
void CountInversions<Value>::Convert(vector<Value>&  nums)//O(N) using map
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

int main()
{
	vector<double> nums{2,4,6,8,INT_MAX/4,INT_MIN/4};
	CountInversions<double> CntI(nums);
	cout<<CntI.GetInversions()<<endl;

	return 0;
}
