#include "iostream"
#include "stdio.h"
#include <fstream>
using namespace std;
int DX[100], Tong=0;

ifstream input("input.txt");
ofstream output("output.txt");

void SXKhongTangGiaTri(int a[100][2], int n)
{
	int i, j, t;
	for(i=0; i<n; i++)
	{
		for(j=i; j<n; j++)
		{
			if(a[i][0]<a[j][0])
			{
				t = a[j][0];
				a[j][0] = a[i][0];
				a[i][0] = t;
				
				t = a[j][1];
				a[j][1] = a[i][1];
				a[i][1] = t;
			}
		}
	}
	output << "\nGia tri cac do vat sau khi sap xep lai:\n";
	for(i=0; i<n; i++)
	{
		output << a[i][0]<<" ";
	}
}

void print(int a[100][2], int Daxet[100], int n)
{
	int i, t=0;
	output <<"\nCac do vat duoc chon: ";
	for(i=0; i<n; i++)
	{
		if(Daxet[i]==1)
		{
			output <<i+1<<" ";
			t+= a[i][0];
		}
	}
	output <<"\nGia tri nhan duoc la: "<<t;
    output.close();
}

void kt(int a[100][2], int Daxet[100], int n)
{
	int i, t;
	t=0;
	for(i=0; i<n; i++)
	{
		if(Daxet[i]==1)
		{
			t+= a[i][0];
		}
	}
	if(t>Tong)
	{
		Tong = t;
		for(i=0; i<n; i++)
		{
			DX[i] = Daxet[i];
			//cout<<Daxet[i]<<" ";
		}
		cout<<endl;
	}
}

void quaylui(int a[100][2], int n, int b, int Daxet[100], int t, int j)
{
	if(t>b)
	{
		Daxet[j] = 0;
		kt(a, Daxet, n);
		return ;
	}
	for(int i=0; i<n; i++)
	{
		if(Daxet[i]==0)
		{		
				Daxet[i] = 1;
				t += a[i][1];
				quaylui(a, n, b, Daxet, t, i);
				Daxet[i] = 0;
				t-=a[i][1];
		}
	}
}

void Input(int a[][2], int DaXet[], int &n, int &b){
    input >> n >> b;
    for (int i=0; i < n; i++){
        input >> a[i][0] >> a[i][1];
        DaXet[i] = 0;
    }
}

int main()
{
	int i, n, b, a[100][2], Daxet[100], t = 0;
    // Value (a[][0])trước Weight (a[][1])
	Input(a, Daxet, n, b);
	// SXKhongTangGiaTri(a, n);
	quaylui(a, n, b, Daxet, t, 0);
	print(a, DX, n);
	return 0;
}
