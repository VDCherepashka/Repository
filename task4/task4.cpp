#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <stdio.h>
#include <cmath>

using namespace std;
int main(int argc, char* argv[])
{
	if(argc>1)
	{
		string buff;
		list<string>timelist;
		ifstream file1(argv[1]);
		
		while(!file1.eof())
		{
			file1>>buff;
			timelist.push_back(buff);
		}
		file1.close();
		
		string *TimeList = new string[timelist.size()];
		
		int iter = 0;
		for(string n : timelist)
		{
			TimeList[iter]=n;
			iter++;
		}
		
		int *TL = new int[timelist.size()];
		
		for(int i=0;i<timelist.size();i++)
		{
			int y=0;
			int v=-10;
			string Ch0="";
			string Ch1="";
			for(char c : TimeList[i])
			{
				if(c == ':'){v=y;}
				if(y==v+1 || y==v+2){Ch1+=c;}
				if(y>v+2){Ch0+=c;}
				y++;
			}
			TL[i]=(stoi(Ch0)*60)+stoi(Ch1);
		}
		int Mans = 0;
		int MaxMans = 0;
		for(int i=480;i<1200;i++)
		{
			for(int j=0;j<timelist.size();j++)
			{
				if(i == TL[j] && j%2==0)
				{
					Mans++;
					if(Mans>MaxMans){MaxMans=Mans;}
				}
				if(i == TL[j] && j%2!=0)
				{
					Mans--;
				}
			}
		}
		int ChekMax = MaxMans;
		list<int>Ent;
		list<int>Esc;
		int checkEnt = 0;
		int checkEsc = 0;
		Mans = 0;
		for(int i=480;i<1200;i++)
		{
			for(int j=0;j<timelist.size();j++)
			{
				if(i == TL[j] && j%2==0)
				{
					Mans++;
					if(Mans==ChekMax && checkEsc!=TL[j]){Ent.push_back(TL[j]);}
					if(Mans==ChekMax && checkEsc==TL[j]){checkEnt=TL[j];Esc.pop_back();}
					
				}
				if(i == TL[j] && j%2!=0)
				{
					if(Mans==ChekMax){Esc.push_back(TL[j]); checkEsc=TL[j];}
					
					Mans--;
				}
			}
		}
		int *EntINT= new int[Ent.size()];
		int *EscINT= new int[Esc.size()];
		
		iter = 0;
		for(int n : Ent)
		{
			EntINT[iter]=n;
			iter++;
		}

		iter = 0;
		for(int n : Esc)
		{
			EscINT[iter]=n;
			iter++;
		}

		for(int w=0;w<Esc.size();w++)
		{
			if(EntINT[w]%60<10){cout<<EntINT[w]/60<<":"<<"0"<<EntINT[w]%60<<" ";}
			else{cout<<EntINT[w]/60<<":"<<EntINT[w]%60<<" ";}
			if(EscINT[w]%60<10){cout<<EscINT[w]/60<<":"<<"0"<<EscINT[w]%60<<endl;}
			else{cout<<EscINT[w]/60<<":"<<EscINT[w]%60<<endl;}
		}
	}
	system("Pause");
	return 0;
}