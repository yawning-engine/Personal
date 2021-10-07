#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string tags[20], query[20],line,value,tagnum;
    int n,q,i,j,tpos,vpos;
    cin>>n>>q;
    for(i=0;i<n;i++)
    	cin>>tags[i];
    for(i=0;i<q;i++)
    	cin>>query[i];
    for(i=0,line=query[i];i<q;i++)
    {
    	vpos = line.find('~');
    	value = line.substr(vpos);
    	tpos = 0;
    	for(j=0;line[j] != '~';j++)
    	{
		if(line[j] == '.')
			tpos = j+1;
    	
    	}
	//tag = line.substr(tpos,vpos);
	tagnum = line.substr(tpos+3,vpos);
    }
    
    return 0;
}

