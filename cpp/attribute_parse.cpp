#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;


int main() 
{

    string tags[20], query[20],searchorder[20],line,value,tag,tagstack[20],findval,validarg,spaceval;
    int n,q,i,j,k,ts,tpos,vpos,dotcount,found;
    
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
    	found=0;
    	for(j=0;line[j] != '~';j++) //pos of supertag in case of nested tags
    	{
		if(line[j] == '.')
		{
			searchorder[dotcount] = line.substr(tpos,j-tpos);
			tpos = j+1;
			dotcount++;
		}
    	
    	}
    	searchorder[dotcount]=line.substr(tpos,line.find('~')-tpos);
    	tag = "<" + searchorder[dotcount];
    	for(j=n-1,k=0;j>=0;j--)
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
								spaceval = tags[j].substr(tags[j].find(" "));
								vpos = spaceval.find(value);
								findval = spaceval.substr(vpos + value.length() + 4);
								validarg = spaceval.substr(vpos-1,value.length()+2);
								if(validarg == " " + value + " ")
								{
									cout<<findval.substr(0,findval.find("\""))<<endl;
									found=1;
									break;
								}
								else
								{
									cout<<"Not Found!"<<endl;
									found=1;
									break;
								
								}
							}
							
							else
							{
								cout<<"Not Found!"<<endl;
								found=1;
								break;
								
							}						
						}
					}
				else
				{
					cout<<"Not Found!"<<endl;
					found=1;
					break;
				}
			}
			break;
		}
		if(tags[j].find("/") != -1)
		{
			tagstack[k]=tags[j].substr(tags[j].find("/")+1,tags[j].find(" ")-tags[j].find("/")+1);
			k++;
		}
		else
		{
			k--;  
		}
		 	
    	}
    	if(found == 0)
    		cout<<"Not Found!"<<endl;
	
    }
    
    
    return 0;
}

