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
		nums[i][0] = m;
		for (j=1;j<=m;j++)
		{
			cin>>nums[i][j];
		}
	}
/*	for(i=0;i<n;i++)
	{
		for (j=1;j<=nums[i][0];j++)
		{
			cout<<nums[i][j]<<" ";
		}
		cout<<"\n";
	} 
*/
	for(i=0;i<q[0];i++)
	{
		cin>>q[1]>>q[2];
		
		obuff[i] = nums[q[1]][q[2]+1]; 	
	}
	for(i=0;i<q[0];i++)
	{
		cout<<obuff[i]<<"\n";
	}
	
	return 0;
}
