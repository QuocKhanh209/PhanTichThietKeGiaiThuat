#include<iostream>
#include<fstream>
#include <string>
#define MAX 50

using namespace std;
string kq="";
int m,n,i,j;
int c[MAX][MAX];

ifstream input("input.txt");
ofstream output("output.txt");

void LCS(string S1, string S2)
{
	m=S1.length();
	n=S2.length();
	
	for(i=0;i<=m;i++) 
	{
		c[i][0]=0;
	}
	for(j=0;j<=n;j++) 
	{
		c[0][j]=0;
	}

	for(i=0;i<=m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(S1[i]==S2[j]) 
			{
				c[i+1][j+1]=c[i][j]+1;
				
			}
			else
			if(c[i][j+1]>=c[i+1][j]) 
			{
				c[i+1][j+1]=c[i][j+1];
			}
			else c[i+1][j+1]=c[i+1][j];
		}
	}
	
	//In bang ket qua 
	output<<"\n- Bang ma tran ket qua: \n";
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			output<<c[i][j]<<"  ";
		}
		output<<"\n";
	}
	
	//Truy vet
	//int i=m, j=n;
	while(i>0&&j>0)
    if(S1[i-1]==S2[j-1])
    {
    	kq=S1[i-1]+kq;
		i--;j--;
	}
	else {
		if(c[i][j]==c[i-1][j]) i--;
		else j--;
	}
	output<<"\n- Xau con chung dai nhat la: "<< kq << endl;
	output<<"\n- Do dai xau con chung dai nhat: " << c[m][n];
    output.close();
}
	
void Input(string &S1, string &S2){
    input >> S1 >> S2;
    output << "Mang 1: " << S1 << endl;
    output << "Mang 2: " << S2 << endl;
    output << "<------------------Ket qua------------------->" << endl;
}    

int main()
{
    string S1, S2;
    Input(S1, S2);
	LCS(S1,S2);
	return 0;
}
