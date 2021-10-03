#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,q[3],i,j,m;
	cin>>n>>q[0];
	int *obuff = new int[n];
	int **nums = new int*[n];
	for(i=0;i<n;i++)
	{
		cin>>m;	
		nums[i] = new int[m];
		for (j=0;j<m;j++)
		{
			cin>>nums[i][j];
		}
	}
	for(i=0;i<q[0];i++)
	{
		cin>>q[1]>>q[2];
		
		obuff[i] = nums[q[1]][q[2]]; 	
	}
	for(i=0;i<q[0];i++)
	{
		cout<<obuff[i]<<endl;
	}
	delete[] obuff;
	delete[] *nums;
	
	return 0;
}
