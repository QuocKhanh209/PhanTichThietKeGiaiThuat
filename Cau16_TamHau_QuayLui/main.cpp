#include<stdio.h>
#include<iostream>
#include<fstream>

using namespace std;
int x[8], a[8], b[15], c[15], dem=0;

ifstream input("input.txt");
ofstream output("output.txt");

void print()
{
	int i;
    output << "\n-------------------------------\n";
    output << "Buoc\thang\tcot";
	for (i=0; i<8; i++)
        output << "\n" << i + 1 << "\t" << i + 1 << "\t" << x[i] + 1;
}

void Try(int i)
{
	int j;
	if (i<=7)
	{
		for (j=0; j<8; j++)
		{
			if (a[j] == 1 && b[i+j] ==1 && c[i-j+7] == 1)//chua co quan hau nao o cot j
			{
				x[i] = j; 
				a[j] = 0; 
                b[i+j] = 0; 
                c[i-j+7] = 0;
				Try(i+1);
				a[j] = 1; 
                b[i+j] = 1; 
                c[i-j+7] = 1;
            }
        }
    }
	else
	{ 
		print();
        dem++;
	}
}

void TamHau()
{
	int i;
	for (i=0; i<8; i++)
	{
		a[i] = 1;
		x[i] = -1;
	}
	for (i=0; i<15; i++)
	{
		b[i] = 1;
		c[i] = 1;
	}
	Try(0);
    output << "\n Tong so cach dat quan Hau: " << dem;
}

int main()
{ 
    TamHau();
    return 0;
}
