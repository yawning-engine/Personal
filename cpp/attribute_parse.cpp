#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;


int main() {
    string tags[20], query[20],searchorder[20],line,value,findval,endtag,tag;
    int n,q,i,j,k,tpos,vpos,dotcount,found,size;
    cin>>n>>q;
    for(i=0;i<n;i++)
    {
    	getline(cin,tags[i],'>');
    }
    for(i=0;i<q;i++)
    {
    	cin>>query[i];
    }
    for(i=0;i<q;i++)
    {
    	line=query[i];
    	value = line.substr(line.find('~')+1); //value of the attribute to be found
    	tpos = 0;
    	dotcount=0;
    	size=0;
    	for(j=0;line[j] != '~';j++) //pos of supertag in case of nested tags
    	{
		if(line[j] == '.')
		{
			searchorder[dotcount] = line.substr(tpos,j);
			tpos = j+1;
			dotcount++;
		}
		
    	
    	}
    	searchorder[dotcount]=line.substr(tpos,line.find('~')-tpos);
    	tag = "<" + searchorder[dotcount];
    	for(j=0;j<=dotcount;j++)
    	{
    		endtag = "</" + searchorder[j];
    		found=0;
    		for(k=n-1;k>=0;k--)
    		{
    			if(tags[k].find(endtag) != -1) 
    			{
    				found = 1;
    				size++;
    			}
    			if ((size <= dotcount) && (found == 1))
    				break;
    			if ((size > dotcount) && (found == 0))
    			{
    				cout<<"Not Found!"<<endl;
    				break;
    			}
    			if ((size > dotcount) && (found == 1))
    			{
    				if(tags[k].find(tag) != -1)
    				{
    					vpos = tags[k].find(value);
    					if((vpos >= 0) && (vpos < tags[k].length()))
    					{
    						findval =tags[k].substr(vpos + value.length() + 4);
    						cout<<findval.substr(0,findval.find("\""))<<endl;
    						break;
    					}
    					else
    					{
    						cout<<"Not Found!"<<endl;
    						break;
    					}
    				}
    			}	
    		}
    	}
	
    }
    
    
    return 0;
}

