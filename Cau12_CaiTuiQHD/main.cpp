#include<iostream>
#include<fstream>
#include<iomanip>
#define MAX 50
using namespace std;
using std::setw;

int w[MAX], c[MAX];
int MaxV[MAX][MAX];

ifstream input("input.txt");
ofstream output("output.txt");

void Input(int &n,int &b)
{
	input >> n; 
	input >> b; 

	for(int i=1;i<=n;i++)
	{
		input >> w[i];
		input >> c[i];
	}
	
	output<<"* Input: \n\n";
	output<<setw(7)<<"n="<<n<<setw(7)<<"b="<<b<<"\n\n";
	output<<"i"<<setw(10)<<"w[i]"<<setw(10)<<"c[i]\n";
	for(int i=1;i<=n;i++)
	output<<i<<setw(9)<<w[i]<<setw(9)<<c[i]<<"\n";
	output<<"\n";
}

void Bag_best(int n,int b)
{
	int i,L;
	int Select[MAX],sumW=0;
	for(L=0;L<=b;L++) MaxV[0][L]=0;
	for(i=0;i<=n;i++) MaxV[i][0]=0;
	
	for(i=1;i<=n;i++)
	{
		Select[i]=0;
		for(L=1;L<=b;L++)
		{
			if( (L>=w[i]) && (MaxV[i-1][L-w[i]]+c[i]>MaxV[i-1][L]) )
			{
				MaxV[i][L]=MaxV[i-1][L-w[i]]+c[i];
			}
			else MaxV[i][L]=MaxV[i-1][L];
		}
	}
	
	output<<"---------------------------\n* Output: \n\n- Bang ket qua: \n\n";
	//In bang ket qua 
	for(i=0;i<=n;i++)
	{
		for(L=0;L<=b;L++)
		{
			output<<setw(4)<<MaxV[i][L];
		}
		output<<"\n";
	}
	
	output<<"\n- Tong gia tri lon nhat mang duoc: "<<MaxV[n][b] ;
	
	//Truy vet
	output<<"\n- Nhung vat duoc chon: ";
	while(b>0)
	{
		for(i = n;i >= 1; i--)
		{
			if(MaxV[i][b] != MaxV[i-1][b]) 
			{
				sumW+=w[i];
				Select[i]=1;
				output << i <<"\t";	
				b-=w[i];
					
			}
		}				
	}	
	output<<"\n- Tong trong luong vat: "<<sumW;
    output.close();
}
int main()
{
	int n,b;
	Input(n,b);
	Bag_best(n,b);
	return 0;
}
