#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,q;
	int i,j,m;
	cin>>n>>q;
	int **nums = new int*[n];
	for(i=0;i<n;i++)
	{
		cin>>m;	
		nums[i] = new int[m];
		nums[i][0] = m;
		for (j=1;j<=m;j++)
		{
			cin>>nums[i][j];
		}
	}
	for(i=0;i<n;i++)
	{
		for (j=1;j<=nums[i][0];j++)
		{
			cout<<nums[i][j]<<" ";
		}
		cout<<"\n";
	}
	

}
