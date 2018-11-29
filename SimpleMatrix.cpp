#include<iostream>
#include<math.h>
using namespace std;
//Generating a specific data type
typedef map<int,double> SRow;
template<int N> struct SMatrix
{
	map<int,SRow> data;
};

const int N=5;
SRow current;
current.insert(pair<int,double> (0,-2.0));
current.insert(pair<int,double>(1,1.0));
SMatrix<N> sparseMat;
sparseMat.data[0] = current;
int currentIndex=0;
for (int row=1;row<N-1;row++)
{	//Insert 3 elements
	current.clear();
	current.insert(pair<int,double>(currentIndex,1.0));
	current.insert(pair<int,double>(currentIndex+1,-2.0));
	current.insert(pair<int,double>(currentIndex+2,1.0));
	sparseMat.data[row] = current
	currentIndex++;
}
current.clear();
current.insert(pair<int,double>(N-2,1.0));
current.insert(pair<int,double>(N-1,-2.0));
sparseMat.data[N-1] = current;
print(sparseMat);

templeat <int N>
	    void print(SMatrix<N>& sm)
{
	SparseRow sr;
	SparseRow::const_iterator it;
	for (int row=0;row<N;row++)
	{
		SparseRow sr = sm.data[row];
		//Iterate over row
		for (it=sm.data[row].begin();i!=sm.data[row].end();it++)
		{
			cout<<(*it).second<<",";}
			cout<<endl;}
}
