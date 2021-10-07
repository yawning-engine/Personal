#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string tags[20], query[20],line,value,findval;
    int n,q,i,j,tpos,vpos,quote,tagnum;
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
	tagnum = stoi(line.substr(tpos+3,vpos));
	
	line = tags[tagnum-1];
	if(line.find(value))
	{
		findval = line.substr(line.find(value)+value.length()+4);
		quote = findval.find('\"');
		cout<<findval.substr(0,quote)<<endl;
	}
	else
		cout<<"Not Found!"<<endl;
    }
    
    
    return 0;
}

