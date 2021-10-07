#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;


int main() {
    string tags[20], query[20],line,value,findval;
    int n,q,i,j,tpos,vpos,quote,tagnum;
    cin>>n>>q;
    for(i=0;i<n;i++)
    {
    	getline(cin,tags[i],'>');
    }
    for(i=0;i<q;i++)
    {
    	cin>>query[i];
    }
    for(i=0,line=query[i];i<q;i++)
    {
    	vpos = line.find('~');
    	value = line.substr(vpos+1); //value of the attribute to be found
    	tpos = 0;
    	for(j=0;line[j] != '~';j++) //pos of supertag in case of nested tags
    	{
		if(line[j] == '.')
			tpos = j+1;
    	
    	}
	//tag = line.substr(tpos,vpos);
	tagnum = stoi(line.substr(tpos+3,vpos)); //tag number
	
	line = tags[tagnum-1]; 
	if(line.find(value))
	{
		findval = line.substr(line.find(value)+value.length()+4);
		quote = findval.find('\"'); // position of closing quote of the attribute
		cout<<findval.substr(0,quote)<<endl;
	}
	else
		cout<<"Not Found!"<<endl;
    }
    
    
    return 0;
}

