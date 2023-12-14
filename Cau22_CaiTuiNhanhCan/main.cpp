//thuat toan nhanh can, tim phuong an toi uu
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <fstream>
const int max = 100;

int w[max], v[max], n; 
float wv[max];// Don gia
int soluong;//so luong 
int khoiluong;//khoi luong Balo
int khoiluongdovat;//khoi luong do vat chiem trong t�i sau khi xep toi uu
int TL=0;//trong luong tong c�c vat da xep(hien tai)
int dem = 0;
int gt[100];		//cac buoc cua thuat toan
int sl[100],slmax[100];		//nhanh can
int s=0;//tong gi� tri tai thoi diem hien tai
int fmax=0;//gi� tri lon nhat sau moi lan duyet het
float g;//dieu kien bo nhanh

std::ifstream input("input.txt");
std::ofstream output("output.txt");

void Init()
{
	int i;
    input >> n >> khoiluong;
	for (i = 0; i < n; i++)
	{
        input >> w[i] >> v[i]; 
		wv[i] = (float)v[i] / w[i];
	}
    input.close();
}

void Swap(float &a, float &b) 
{
	float temp = a;
	a = b;
	b = temp;
}

//sap xep theo thu tu giam dan cua gia tri: v[i]/w[i] tuc la wv[i]
void Sort() 
{
	for (int i = 0; i<n; i++) 
	{
		for (int j = i + 1; j<n; j++) 
		{
			if (wv[j]>wv[i]) // Doi vat i,j cho nhau(Doi ca gia tri va khoi luong)
			{
				Swap((float&)w[j], (float&)w[i]);
				Swap((float&)v[j], (float&)v[i]);
				Swap(wv[j], wv[i]);
			}
			else if (wv[j] == wv[i]) // Neu gia tri bang nhau
			{
				if (w[j]<w[i])//sx tang dan cua khoi luong
				{
					Swap((float&)w[j], (float&)w[i]);
					Swap((float&)v[j], (float&)v[i]);
					Swap(wv[j], wv[i]);
				}
			}
		}
	}
}

//hien thi 
void Display() 
{
    output << "\nDo vat   khoiluong    Giatri     DonGia\n";
	for (int i = 0; i<n; i++) 
	{
		// printf("%d  \t  %3d  \t       %3d  \t%5.2f", i+1, w[i], v[i], wv[i]);
        output << "\t"<<i+1<<"\t"<<w[i]<<"\t"<<v[i]<<"\t"<<wv[i]; 
		output << std::endl;
	}
}

//thuat toan nhanh can
void Try(int i) 
{
	int j;
	soluong = (khoiluong - TL) / w[i];
	if(soluong<=0) soluong = 0;
	else soluong = 1;
	for (j = soluong; j >= 0; j--)
	{
		sl[i] = j;
		TL += w[i] * sl[i];
		s += v[i] * sl[i];
		if (i == n-1)
		{
			if (s > fmax)
			{
				for (int k = 0; k < n; k++)
				{
					slmax[k] = sl[k];
				}
				khoiluongdovat = TL;
				fmax = s;
			}
		}
		else
		{
			g = s + (float)v[i + 1] * (khoiluong - TL) / w[i + 1];
			//g = s+ v[i+1];
			if (g > fmax)
				Try(i + 1);
		}
		TL = TL - w[i] * sl[i]; //Tra lai trang thai
		s = s - v[i] * sl[i]; //Tra lai trang thai
	}
}

int main()
{
	Init();
    output << "\n- Danh sach cac do vat sau khi sap xep giam dan theo don gia:\n";
	Sort();
	Display();
    output << "\n- Thuat toan nhanh can: \n";
	Try(0);
    output << "\nDo vat   soluong   khoiluong    giatri\n";
	for (int i = 0; i<n; i++) 
	{
        output << i+1 << "    " << slmax[i] << "    " << w[i] << "    " << v[i] << std::endl;
	}
    output << "\n- Khoi luong tui da dung duoc: " << khoiluongdovat;
    output << "\n- Tong gia tri lon nhat: " << fmax;
    output.close();
	return 1;

}
