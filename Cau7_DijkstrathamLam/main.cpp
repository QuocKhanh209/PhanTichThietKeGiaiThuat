//bai toan tim duong di ngan nhat tren do thi (giai thuat Dijkstra)
#include <iostream>
#include <fstream>
using namespace std;
#define MAX 100
int n; // so dinh do thi
int a[MAX][MAX]; //ma tran trong so do thi
int Daxet[MAX]; //danh dau cac dinh da xet
int L[MAX]; //mang ghi nhan cac dinh
int Truoc[MAX]; //chua dinh ngay truoc
int s, t;

ofstream output("output.txt");
void Input(){
    ifstream input("input.txt");
	input >> n >> s;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			input >>a[i][j];
			if (a[i][j] == 0) a[i][j] = MAX;
		}
	}
}

void Init()
{
    for(int i=1;i<=n;i++)
    {
        L[i]= MAX;
        Daxet[i]=0;
        Truoc[i]=0;
    }
}

void Output(int s, int k, int Truoc[MAX]){
	int i;
	output<<"\nDuong di ngan nhat tu "<<s<<" den "<<k<<" la :";
	output<< k << " <- ";
	i = Truoc[k];
	while (i!=s){
		output<<i<<" <- ";
		i = Truoc[i];
	}
	output<<s;
	output<<"\nTrong so: "<<L[k];
	output<<endl;
}

void Dijkstra(){
	int u, v, minp;
	int h = 1;
    for(int i=1;i<=n;i++)
    {
        L[i]=a[s][i];
        Truoc[i]=s;
        Daxet[i]=0;
    }
    Truoc[s]=0;
    L[s] = 0;
    Daxet[s]=1;
    while(h<n) 
    {
        minp=MAX;
        for(int i=1;i<=n;i++)
        {
            if(Daxet[i]==0 && minp > L[i])
            {
                minp=L[i];
                u=i;
            }
        }
        Daxet[u]=1;
        for(int i=1;i<=n;i++)
        {
            if(Daxet[i]==0 && L[u]+a[u][i] < L[i])
            {
                L[i]=L[u]+a[u][i];
                Truoc[i]=u;
            }
        }
        Output(s,u,Truoc);
        h++;
    }
}

int main(){
	Input();
	Init();	
	Dijkstra();
}
