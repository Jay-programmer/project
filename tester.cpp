#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){
	int numbers=100;
	
	cout<<"You have "<<numbers<<" manuals available."<<endl;
	
	for(int i = 1; i<numbers;i++)
	{
		cout<<i<<",";
	}
	
	cout<<numbers<<endl;
	
	return 0;
	}