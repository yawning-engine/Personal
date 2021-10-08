#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;


int main() {
    string tags[20], query[20],searchorder[20],line,value,tag,tagstack[20];
    int n,q,i,j,k,ts,tpos,dotcount;
    cin>>n>>q;
    for(i=0;i<n;i++)
    {
    	getline(cin,tags[i],'>');
    }
    for(i=0;i<q;i++)
    {
    	cin>>query[i];
    }
/*        for(i=0;i<tagnum;i++)
    {
    	cout<<tagnames[i]<<endl;
    } */
    for(i=0;i<q;i++)
    {
    	line=query[i];
    	value = line.substr(line.find('~')+1); //value of the attribute to be found
    	tpos = 0;
    	dotcount=0;
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
    	for(j=n-1,k=0;j>=0;j++)
    	{
		if(tags[j].find(tag) != -1)
		{
			for(ts=0;ts<k;ts++)
			{
				if(tagstack[ts] == searchorder[ts])
					{
						if (tagstack[ts] == searchorder[dotcount])
						{
							if(tags[j].find(value) != -1)
							{
								cout<<tags[j].substr(tags[j].find(value),tags[j].find("/")-tags[j].find(value))<<endl;
								break;
							}
							else
							{
								cout<<"Not Found!"<<endl;
								break;
								
							}						
						}
					}
				else
				{
					cout<<"Not Found!"<<endl;
					break;
				}
			}
		}
		if(tags[j].find("/") != -1)
		{
			tagstack[k]=tags[j].substr(tags[j].find("/"),tags[j].find(" ")-tags[j].find("/"));
			k++;
		}
		else
		{
			k--;  
		}
		 	
    	}
	
    }
    
    
    return 0;
}

