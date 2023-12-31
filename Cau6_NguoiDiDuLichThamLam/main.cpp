//Bai toan nguoi du lich (phuong phap tham lam)
#include <iostream>
#include <fstream>
using namespace std;
#define max 100
	int n;
	int a[max][max]; //ma tran trong so cua do thi
	int TOUR[max];// mang ghi chu trinh
	int Ddau; //diem dau cua chu trinh
	int v; //Dinh dang xet;
	int k; //duyet qua k dinh de chon
	int w; //dinh duoc chon trong moi buoc
	int mini; //chon min cac canh trong moi buoc
	int COST; //trong so nho nhat cua chu trinh
	int daxet [max]; //danh dau cac dinh da xet

ofstream output("output.txt");
void DataInput (){
	ifstream input("input.txt");
	input >> n >> Ddau;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			input >> a[i][j];
			if(a[i][j] == 0) a[i][j] = max;
		}
	}
}

void DataOutput(int i){
	output <<"\nDuong di: ";
	for (int j = 1; j < i; j++) 
        output << TOUR[j]<<" -> ";
    output << TOUR[i];
	output <<"\nChi phi = "<<COST<<endl;
}

int GTS (){
	//khoi tao
	for (k=1; k<=n; k++){
		daxet[k] = 0; //chua dinh nao duoc xet
	}
	COST = 0;
	int i;
	v = Ddau; //chon dinh dau
	i = 1;
	TOUR[i] = v; //dua v vao chu trinh
	daxet[v] = 1;
	//tim dinh gan nhat voi dinh dang xet
	while (i<n){
		mini = max;
		for (k=1; k<=n; k++){
			if (!daxet[k]){
				if (mini > a[v][k]){
					mini = a[v][k];
					w = k;
				}
			}
		}
		v = w;
		i++;
		TOUR[i] = v;
		daxet[v] = 1;
		COST += mini;
		// DataOutput(i);
	}
	//tro ve dinh dau
	i++;
	TOUR[i] = Ddau;
	COST += a[v][Ddau];
	DataOutput(i);
	return COST;
}

int main(){
	DataInput();
	GTS();
}
