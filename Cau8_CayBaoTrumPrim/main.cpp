/*
- Bai toan: tim cay bao trum di qua tat ca cac dinh cua do thi co trong so nho nhat
- Mo ta thuat toan:
	dau vao: do thi co trong so lien thong 
	bat dau xet tu mot dinh tuy y dua vao mang chua dinh MST
	lap cho toi khi so dinh cua MST = so dinh cua G: 
		chon canh co trong so nho nhat tu cac dinh trong mang den cac dinh chua xet
		them dinh vua tim vao tap cac dinh MST
	dau ra: danh sach dinh va canh cua MST
- Danh gia thuat toan: O(n2)
*/
#include<iostream>
#include<conio.h>
#include <fstream>
using namespace std;
#define TRUE 1 
#define FALSE  0 
#define MAX 10000 
int a[100][100];//ma tran trong so cua do thi
int n;//so dinh
int m;//so canh
int weight;//do dai cay bao trum nho nhat
int chuaxet[100];//mang danh dau cac dinh chua xet
int cost;
ifstream input("input.txt");
ofstream output("output.txt");
void Input(){
	input >> n;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			input >> a[i][j];
			if (a[i][j] == 0) a[i][j] = MAX;
		}
	}
    input.close();
}

void Prim(){
	int Lowcost[MAX];
	int Closest [MAX];
	int i,j,k,min=0;
	int U [MAX];// mang luu cac dinh da xet
	int top=1;
	U[top] = 1;
	output  << "Cay bao trum nho nhat:" << endl;
	for (i=2; i<=n;i++){
		Lowcost[i] = a[1][i];
		Closest[i] = 1;
		chuaxet[i] = TRUE;
	}
	chuaxet[1] = FALSE;
	for (i=2;i<=n;i++){
		min = Lowcost[2];
		k = 2;
		for (j=2;j<=n;j++){
			if (Lowcost[j]<min){
				min = Lowcost [j];
				k = j;
			}
		}
		chuaxet[k]=FALSE;
		weight = weight + min;
		output  << "\nCanh: (" << Closest[k] << "," << k << ") \nco trong so: "<<Lowcost[k]<<endl;
		Lowcost [k]= MAX;
		for(j=2;j<=n;j++)
			if((chuaxet[j]==TRUE)&&a[k][j]<Lowcost[j]){
				Lowcost[j] = a[k][j];
				Closest[j]=k;
			}
		top++;
		U[top] = k;
		output <<"Cac dinh da xet: ";
		for (int tmp =1; tmp<=top; tmp++) output <<U[tmp]<<" ";
		output <<endl;
	
	}
	output <<"\nTong trong so cay bao trum nho nhat: "<< weight <<endl;
    output.close();
}

int main(){
 Input(); 
 Prim();
}
