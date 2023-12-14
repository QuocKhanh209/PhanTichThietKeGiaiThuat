#include <iostream>
#include <fstream>
using namespace std;
#define MAX 100
int n;
struct Activity 
{
	char id[MAX];
	int start;
	int finish;
};

Activity a[MAX];

ifstream input("input.txt");
ofstream output("output.txt");
void Init()
{
	input >> n;
	for (int i = 0; i < n; i++)
	{
		input >> a[i].id;
		input >> a[i].start;
		input >> a[i].finish;
	}
	input.close();
}

void activitySelection(Activity a[], int n)
{
	int i, j;
	Activity temp;
	//step 1
	//sx theo thu tu tang dan thoi gian ket thuc cong viec
	for (i = 1; i < n; i++) 
	{
		for (j = 0; j < n - 1; j++) 
		{
			if (a[j].finish > a[j + 1].finish) 
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	//In ra ds cong viec da sx
	output << "- Sap xep theo thu tu tang dan thoi gian ket thuc: \n";
	output << "\tID" << "\t\tBat dau" << "\t\tKet thuc" << endl;
	for (i = 0; i < n; i++) 
	{
		output << "\t" << a[i].id << "\t\t" << a[i].start << "\t\t" << a[i].finish << endl;
	}

	//step 2
	//Cho cong viec dau tien vao mang
	output << "* Output: Chon nhung cong viec sau: \n";
	output << "\tID" << "\t\tBat dau" << "\t\tKet thuc" << endl;
	output <<  "\t" << a[0].id << "\t\t" << a[0].start << "\t\t" << a[0].finish << endl;

	//step 3
	//Chon cong viec tiep theo ma khong xung dot voi cong viec truoc do(Khong giao nhau)
	for (j = 1; j < n; j++) 
	{
		if (a[j].start >= a[i].finish) 
		{
			output << "\t" << a[j].id << "\t\t" << a[j].start << "\t\t" << a[j].finish << endl;
			i = j;
		}
	}

    output.close();
}

int main()
{
	Init();
	activitySelection(a, n);
	return 0;
}

