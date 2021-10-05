#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

void parseInts(string str) 
{
	stringstream ss(str);
	vector<string> nums;
	int i,num;
	string temp;
	while(getline(ss,temp,','))
	{
		//num = int(temp);
		//nums.push_back(temp);
		cout<<temp;
	}
	/*for(i=0;i<nums.size();i++)
		cout<<nums[i];*/
	
}

int main() 
{
	string str;
	cin >> str;
	parseInts(str);
	/*for(int i = 0; i < integers.size(); i++) 
	{
		cout << integers[i] << "\n";
	}*/
    
	return 0;
}
