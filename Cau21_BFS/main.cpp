#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#define MAX 50

using namespace std;
int n;
int s=2,t=5;
int temp=s;
int A[MAX][MAX], Daxet[MAX], Truoc[MAX], queue[MAX];
ifstream input("input.txt");
ofstream output("output.txt");

void Input()
{
	int i, j;
    input >> n;
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
            input >> A[i][j];
		}
	}
    
}

void Init(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		Daxet[i]=0;
		Truoc[i]=0;
	}
}

void XuatDuongDi(int s, int t)
{
	int j;
    output << t << "<- ";
	j=t;
	while(Truoc[j]!=s)
	{
        output << Truoc[j] << "<- ";
		j=Truoc[j];
	}
	output << s << endl;
}

void BFS(int s, int t)
{
	int i,u,j,dauQ=1,cuoiQ=1;
	queue[cuoiQ]=s;
	Daxet[s]=1;
	while(dauQ<=cuoiQ)
	{
		u=queue[dauQ];
		dauQ++;
		for(j=0;j<n;j++)
		{
			if((A[u][j]==1)&&(Daxet[j]==0))
			{
				cuoiQ++;
				queue[cuoiQ]=j;
				Daxet[j]=1;
				Truoc[j]=u;
			}
		}
	}
	XuatDuongDi(temp,t);
}
    
int main()
{
	Input(); 
	Init(n);
	output << "\n- Duong di ngan nhat la: ";
	BFS(s,t);
    output.close();
	return 0;
}
