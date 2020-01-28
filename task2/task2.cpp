#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <stdio.h>

using namespace std;
int main(int argc, char* argv[])
{
	if(argc>1)
	{
		list<double>four;
		ifstream file1(argv[1]);
		string buff;
		while(!file1.eof())
		{
			file1>>buff;
			four.push_back(stod(buff));
		}
		file1.close();
		int four_size = four.size();
		
		if(argc>2)
		{
			list<double>point;
			ifstream file2(argv[2]);
			while(!file2.eof())
			{
				file2>>buff;
				point.push_back(stod(buff));
			}
			file2.close();
			int point_size = point.size();
			
			double **quad;
			int quad_size = four_size/2;
			quad = new double*[quad_size];
			for(int i=0;i<quad_size;i++)
			{
				quad[i]=new double[2];
			}
			
			int iter0 = 0, iter1 = 0;
			for(double n : four)
			{
				quad[iter0][iter1] = n;
				iter1++;
				if(iter1>1){iter1=0; iter0++;}
			}
			
			double **points;
			int points_size = point_size/2;
			points = new double*[points_size];
			for(int i=0;i<points_size;i++)
			{
				points[i]=new double[2];
			}
			
			iter0 = 0; iter1 = 0;
			for(double n : point)
			{
				points[iter0][iter1] = n;
				iter1++;
				if(iter1>1){iter1=0; iter0++;}
			}
			
			//function
			double Ymax=quad[0][0],Ymin=quad[0][0],Xmax=quad[0][1],Xmin=quad[0][1];
			for(int i=0;i<quad_size;i++)
			{
				if(quad[i][0]>Ymax){Ymax=quad[i][0];}
				if(quad[i][0]<Ymin){Ymin=quad[i][0];}
				if(quad[i][1]>Xmax){Xmax=quad[i][1];}
				if(quad[i][1]<Xmin){Xmin=quad[i][1];}
			}
			
			double g[4];
			
			for(int i=0;i<4;i++)
			{
				int j=i+1;
				if (j=4){j=0;}
				if((quad[i][0] - quad[j][0])==0){g[i]=0;}
				else if((quad[i][1] - quad[j][1])==0){g[i]=0;}
				else {g[i]= (quad[i][0] - quad[j][0])/(quad[i][1] - quad[j][1]);}
			}
			
			int *point_status = new int[points_size];
			for(int i=0;i<points_size;i++)
			{
				point_status[i]=9;
				for(int j=0;j<quad_size;j++)
				{
					if(points[i][0]==quad[j][0] && points[i][1]==quad[j][1]){point_status[i]=0;}
				}
				if(points[i][0]>Ymax || points[i][0]<Ymin || points[i][1]>Xmax || points[i][1]<Xmin){point_status[i]=3;}
				if(points[i][0]<=Ymax && points[i][0]>=Ymin && points[i][1]<=Xmax && points[i][1]>=Xmin && point_status[i]==9)
				{
					for(int k=0;k<4;k++)
					{
						if(g[k]==0)
						{
							if(points[i][0]==quad[k][0] || points[i][1]==quad[k][1]){point_status[i]=1;}	
						}
					}
					for(int k=0;k<4;k++)
					{
						if(g[k]==0 && point_status[i]==9)
						{
							if(points[i][0]!=quad[k][0] || points[i][1]!=quad[k][1]){point_status[i]=2;}	
						}
					}
					for(int k=0;k<4;k++)
					{
						if(g[k]!=0)
						{
							int K=k+1;
							if(K=4){K=0;}
							if((quad[k][0]-points[i][0])==0)
							{
								if(quad[k][1]>quad[K][1]){point_status[i]=2;}
								else{point_status[i]=3;}
							}
							if((quad[k][1]-points[i][1])==0 && point_status[i]==9)
							{
								if(quad[k][0]>quad[K][0]){point_status[i]=2;}
								else{point_status[i]=3;}
							}
							else if(point_status[i]==9)
							{
								double quadG = (quad[k][0]-points[i][0])/(quad[k][1]-points[i][1]);
								if(quadG==g[k]){point_status[i]=1;}
								else if(quadG>g[k]){point_status[i]=2;}
								else {point_status[i]=3;}
							}
						}
					}
				}
			}
			for(int i=0;i<points_size;i++)
			{
				switch(point_status[i])
				{
					case 0:
					cout<<i<<" - a point on one of the vertices"<<endl;
					break;
					
					case 1:
					cout<<i<<" - a point on one side"<<endl;
					break;
					
					case 2:
					cout<<i<<" - point inside"<<endl;
					break;
					
					case 3:
					cout<<i<<" - point outside"<<endl;
					break;
					
					default:
					cout<<i<<" - I don't know where the point is"<<endl;
					break;
				}
			}
		}
	}
	system("Pause");
	return 0;
}