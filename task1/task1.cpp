#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <stdio.h>
using namespace std;

int main(int argc, char* argv[])
{
	list<int>input_data;
	string buff;
	if(argc>1)
	{
		ifstream file(argv[1]);
	
		while(!file.eof())
		{
			getline(file,buff);
			input_data.push_back(stoi(buff));
		}
		file.close();
		cout<<endl;
		
		// percentile
		int *ar = new int(input_data.size());
		int Ii=0;
		for (int n : input_data)
		{
			ar[Ii]= n;
			Ii++;
		}
		for(int i=0;i<Ii;i++)
		{
			for(int j=1;j<Ii;j++)
			{
				if(ar[j-1] < ar[j])
				{
					int buf = ar[j-1];
					ar[j-1] = ar[j];
					ar[j] = buf;
				}
			}
		}
		double per = input_data.size()*0.9;
		per = ar[(int)per];
		printf("%.2f\n",per);
		// mediana
		int *arr = new int(input_data.size());
		int I=0;
		for (int n : input_data)
		{
			arr[I]= n;
			I++;
		}
		for(int i=0;i<I;i++)
		{
			for(int j=1;j<I;j++)
			{
				if(arr[j-1] > arr[j])
				{
					int buf = arr[j-1];
					arr[j-1] = arr[j];
					arr[j] = buf;
				}
			}
		}
		cout<<arr[I/2]<<endl;
		// max
		double max = input_data.front();
		for (int n : input_data)
		{
			if(n>max){max = n;}
		}
		printf("%.2f\n",max);
		// min
		double min = input_data.front();
		for (int n : input_data)
		{
			if(n<min){min = n;}
		}
		printf("%.2f\n",min);
		// srz
		double srz = 0;
		for (int n : input_data)
		{
			srz += n;
		}
		srz /= input_data.size();
		printf("%.2f\n",srz);
	}
	system("Pause");
	return 0;
}