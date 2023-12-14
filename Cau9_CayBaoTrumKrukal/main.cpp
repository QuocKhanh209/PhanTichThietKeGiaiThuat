//Thuat toan than lam, tim cay khung nho nhat theo Kruskal
#include<stdio.h>
#include<conio.h>
#include<fstream>
#define MAX 100
using namespace std;
typedef struct Egde{
	int x,y;
};
int n,a[MAX][MAX];
int i, j;

ifstream input("input.txt");
ofstream output("output.txt");


void Input(){
    input >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            input >> a[i][j];
        }
    }
}

void Kruskal(){
	int*D=new int[n];
	Egde *L= new Egde[n-1];
	int Min,Dem=0,Sum=0,T=0,Temp,ts[MAX];
	// Khoi tao, chua co dinh nao thuoc cay nao
	for(i=0;i<n;i++)
	{
		D[i]=0;
	}
	
	do
	{
		//Tim a[i][j] min, canh co trong so nho nhat
		Min=10000;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[i][j]>0 && a[i][j]<Min && !(D[i]!=0&&D[i]==D[j]) )//Tru canh (i,j) tao thanh chu trinh
				{
					Min=a[i][j];
					L[Dem].x=i;
					L[Dem].y=j;
				}
			}		
		}
		
		//Tao cay moi
		if(D[L[Dem].x]==0&&D[L[Dem].y]==0)//ca i,j deu chua thuoc cay nao
		{
			T++;
			D[L[Dem].x]=D[L[Dem].y]=T;//cho chung cung thuoc cay T
		}
		// Dua dinh tuong ung vao cay (Dua i vao cay cua j)
		if(D[L[Dem].x]==0&&D[L[Dem].y]!=0)
		{
			D[L[Dem].x]=D[L[Dem].y];
		}
		// Dua dinh tuong ung vao cay(Dua j vao cay cua i)
		if(D[L[Dem].x]!=0 && D[L[Dem].y]==0)
		{
			D[L[Dem].y]=D[L[Dem].x];
		}
		// Gep 2 cay thanh 1 cay moi neu chung thuoc 2 cay khac nhau
		if(D[L[Dem].x]!=D[L[Dem].y]&&D[L[Dem].y]!=0)
		{
			Temp=D[L[Dem].x];
			for(int i=0;i<n;i++)
			{
				if(Temp==D[i])
				D[i]=D[L[Dem].y];
			}
		}
		ts[Dem]=Min;
		Sum+=Min;
		Dem++;
	}
	while(Dem<n-1);// Chung nao cay bao trum du (n-1) canh
	
	output << "\n- Trong so cua cay khung con nho nhat la: " << Sum;
	output << "\n- Cac canh cua cay khung con nho nhat la: \n";
	for(int i=0;i<n-1;i++)
	{
		output << "("<<L[i].x+1<<"-"<<L[i].y+1<<"):  "<<ts[i]<<endl;
	}
    output.close();
}
int main(){
 	Input();
	Kruskal();
	return 0;
}
