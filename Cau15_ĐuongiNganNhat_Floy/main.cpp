#include <iostream>
#include <fstream>
using namespace std;
#define max 1000
int a[max][max];//ma tran trong so do thi
int d[max][max];//mang ghi do dai duong di giua cac dinh
int p[max][max];//mang ghi cac dinh giua 
int s[max];//mang ghi duong di
int n, u, v;
ifstream input("input.txt");
ofstream output("output.txt");

void Input(){

    input >> n >> u >> v;

	 for (int i = 1; i <= n; i++){
		  for (int j = 1; j <= n; j++){
			   input >> a[i][j];
			   if (i != j && a[i][j] == 0)
			    a[i][j] = max;
		  }
	 }
}
void Print(int u, int v){
		//Truy vet
	if (d[u][v] >= max) {
	  		output <<"\nKhong co duong di"<<endl;
	}
	else {
		output <<"\nDuong di ngan nhat tu "<<u<<" den "<<v<< " co do dai la "<<d[u][v]<<endl;
		int t = 1; int i=u; int j=v; int k;
		s[t]=v;
		while (p[i][j]!=0) {
			k = p[i][j];
			t++;
			s[t] = k; 
			j = k;
		}
		output <<"\nDuong di: "<<u;
		int count = t;
		while(count>0) {
			output <<" -> "<<s[count];
			count--;
		}
	}
    output.close();
}
void Floyd(){
	int i, j, k;
	//Khoi dong ma tran d va p
	for (i=1; i<=n; i++){
		for (j=1; j<=n;j++){
			d[i][j] = a[i][j];
			p[i][j]=0;
		}
	}
	//Tinh ma tran d va p 
	for (k=1; k<=n;k++)
	{
		for (i=1; i<=n; i++){
			if (d[i][k]>0 & d[i][k]<max){
				for(j=1;j<=n;j++){
					if(d[k][j]>0 && d[k][j]<max){
						if (d[i][k] + d[k][j] < d[i][j]){
							d[i][j] = d[i][k] + d[k][j];
							p[i][j] = k;
						}
					}
				}
			}
		}
        if (k == n){
            output<<"k = "<<k<<endl;
            output<<"\nMa tran d:"<<endl;
            for (int b = 1; b<=n; b++){
            for (int c = 1; c<= n; c++){
                output<< d[b][c] <<"	";
                }
                output<<endl;
            }
            output<<endl;
            output<<"Ma tran p:"<<endl;
            for (int b = 1; b<=n; b++){
                for (int c = 1; c<= n; c++){
                output<< p[b][c]<<"	";
                }
            output<<endl;
            }
            output<<endl;
        }
	}
}
int main(){
    Input();
    Floyd();
    Print(u, v);
}
