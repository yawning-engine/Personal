#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) 
{
	stringstream ss;
	vector<int> nums;
	int i,num;
	string temp;
	ss << str;
	while(getline(ss,temp,','))
	{
		//num = int(temp);
		//nums.push_back(num);
		cout<<temp;
	}
	for(i=0;i<nums.size();i++)
		cout<<nums[i];
	
}

int main() 
{
	string str;
	cin >> str;
	vector<int> integers = parseInts(str);
	for(int i = 0; i < integers.size(); i++) 
	{
		cout << integers[i] << "\n";
	}
    
	return 0;
}
