#include<iostream>
#include<math.h>
using namespace std;
class BinomialLatticeStra
{
protected:
	double u,d,p;
	double s,r,k;
	BinomialType btype;
public:
	//Public functions for normal clients
	double downValue() const{return d;}
	double upValue() const{return u;}
	double probValue() const{return p;}
	BinomialType binomialType() const {return btype;}
};
class CRRStrat: public BinomialLatticeStra
{
public:
	CRRStrat(double vol, double interest, double delta;)
};
CRRStrat::CRRStrat(double vol,double interest, double delta)
	: BinomialLatticeStrat(vol,interest,delta)
{
	double R1 = (r-0.5*s*s)*k;
	double R2 = s*::sqrt(k);

	u=::exp(R1+R2);
	d=::exp(R1-R2);

	double discounting=::exp(-r*k);
	p=0.5;
}

JRStra::JRStra(double vol, double interest, double delta)
	BinomialLatticeStra(double vol, double interest, double delta)
{
	double k2=::sqrt(k);
	u=::exp(s*k2);
	d=1.0/u;
	p=0.5+((r-0.5*s*s)*k2*0.5)/s;
}

EQPStra::EQPStra(double vol, double interest, double delta)
	:BinomialLatticeStra(vol,interest,delta)
{
	btype=Additive;
	double mu = r-0.5*s*s;
	double a = nu*k;
	double b = 0.5*::sqrt((4.0*s*s*k)-(3.0*mu*mu*k*k));

	//EQP Parameters
	u = 0.5*a+b;
	d = 1.5*a-b;
	p=0.5;
}

TRGStra::TRGStra(double vol, double interest, double delta)
	:BinomialLatticeStra(vol,interest,delta)
{	btype=Additive;
	double nu=r-0.5*s*s;
	double nudt=nu*k;
	u=::sqrt(s*s*k+nudt*nudt);
	d=-u;
	p=0.5*(1.0+nudt/u));
}

ModCRRStra::ModCRRStra(double vol, double interest, double delta,double S,double K,int N)
	   :BinomialLatticeStra(vol,interest,delta)
{
	double KN =::log(K/S)/double(N);
	double VN = s*::sqrt(k);

	u=::exp(KN+VN);
	d=::exp(KN-VN);
	p=(::exp(r*k)-d)/(u-d);
}

virtual void updateLattice(Lattice<double,int,2>& source, double rootValue) const;

void BinomialLatticeStra::updateLattice
	(Lattice<double,int,2>& source, double rootValue) const
{	int si=source.MinIndex();
	source[si][source[si].MinIndex()]=rootValue;
	for (int n=source.MinIndex()+1;n<=source.MaxIndex();n++)
		{for (int i=source[n].MinIndex;i<source.MaxIndex();i++)
			{source[n][i]=d*source[n-1][i];
			source[n][i+1]=u*source[n-1][i];}
		}

}	
	
		
	