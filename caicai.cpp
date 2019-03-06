#include <iostream>
#include <iomanip>
#include <vector>
//#include <

using std::endl;
using std::cout;
using std::cin;



int main()
{
	int i=1;
	double ithreward=8.0;
	double ithstake=10.0;
	double sumstake=10.0;
	double rate=100*ithreward/sumstake;
	double shouyi=ithreward+ithstake-sumstake;
	double except=-1;
	double p=0.5;

	for(i=1;i<20;i++)
	{
		//cout<<"No."<<i<<"\t奖金:\t"<<ithreward<<
		cout<<std::fixed<<std::setprecision(10)<<i<<"\t"<<ithreward<<"\t"<<ithstake<<"\t"<<sumstake<<"\t"\
			<<shouyi<<"\t"<<rate<<"\t"<<except<<"\t"<<-except/sumstake<<"\t"<<p<<endl;
		except+=sumstake*p;
		p=p/2;
		ithreward*=3;
		ithstake*=3;
		sumstake+=ithstake;
		shouyi=ithreward+ithstake-sumstake;
		except+=shouyi*p-sumstake*p;
		rate=100*(shouyi)/sumstake;
	}

	return 0;
}
