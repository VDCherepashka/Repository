#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <stdio.h>

using namespace std;
int main(int argc, char* argv[])
{
	string buff;
		
	list<double>Cash1;
	ifstream file1("Cash1.txt");
	while(!file1.eof())
	{
		file1>>buff;
		Cash1.push_back(stod(buff));
	}
	file1.close();
	
	list<double>Cash2;
	ifstream file2("Cash2.txt");
	while(!file2.eof())
	{
		file2>>buff;
		Cash2.push_back(stod(buff));
	}
	file2.close();
	
	list<double>Cash3;
	ifstream file3("Cash3.txt");
	while(!file3.eof())
	{
		file3>>buff;
		Cash3.push_back(stod(buff));
	}
	file3.close();
	
	list<double>Cash4;
	ifstream file4("Cash4.txt");
	while(!file4.eof())
	{
		file4>>buff;
		Cash4.push_back(stod(buff));
	}
	file4.close();
	
	list<double>Cash5;
	ifstream file5("Cash5.txt");
	while(!file5.eof())
	{
		file5>>buff;
		Cash5.push_back(stod(buff));
	}
	file5.close();
	
	double Cash[5][16];
	int iter = 0;
	for(int n : Cash1)
	{
		Cash[0][iter]=n;
		iter++;
	}
	iter = 0;
	for(int n : Cash2)
	{
		Cash[1][iter]=n;
		iter++;
	}
	iter = 0;
	for(int n : Cash3)
	{
		Cash[2][iter]=n;
		iter++;
	}
	iter = 0;
	for(int n : Cash4)
	{
		Cash[3][iter]=n;
		iter++;
	}
	iter = 0;
	for(int n : Cash5)
	{
		Cash[4][iter]=n;
		iter++;
	}
	
	//function
	
	double AllCash[16];
	int index=0;
	double max=0;
	for(int i=0;i<16;i++)
	{
		AllCash[i]=Cash[0][i]+Cash[1][i]+Cash[2][i]+Cash[3][i]+Cash[4][i];
		if(AllCash[i]>max){index = i+1; max = AllCash[i];}
	}
	cout<<index<<endl;
	system("Pause");
	return 0;
}