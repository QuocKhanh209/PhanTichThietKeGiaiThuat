#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
#define MAX 1000;

struct Info
{
    int id;
    int Weight, Value;
    float RealValue;
    int SoLuong;
};

int n = 0; 
int w = 0;
int total = 0, totalValue = 0, totalWeight = 0;
Info ob[1000];

void Datainput() {
    ifstream input("input.txt");
    if (!input.is_open()){
            cout << "Khong mo duoc file!!"<< endl;
    } else {
        input >> n >> w;
        for (int i = 1; i <= n; i++){
            input >> ob[i].Weight >> ob[i].Value;
            // a[i] = temp;
            // a.push_back(temp);
        }
        input.close();
    }
}

void CalculateRealValue(){
    for (int i = 0; i <= n; i++){
        ob[i].id = i; 
        ob[i].RealValue = (float)ob[i].Value / (float)ob[i].Weight;
    }
}

void SortObj(int left, int right){
    float pivot = ob[(left + right) / 2].RealValue;
    int i = left;
    int j = right;

    while (i <= j)
    {
        while (ob[i].RealValue > pivot)
            i++;
        while (ob[j].RealValue < pivot)
            j--;

        if (i <= j)
        {
            Info tmp = ob[i];
            ob[i] = ob[j];
            ob[j] = tmp;
            i++;
            j--;
        }
    }
    if (left < j)
        SortObj(left, j);
    if (i < right)
        SortObj(i, right);
}

void GreedyPick(int W)
{
    for (int i = 1; i <= n; i++)
    {
        if (W >= ob[i].Weight)
        {
            ob[i].SoLuong = 1;
            W -= ob[i].Weight;

            total += ob[i].SoLuong;
            totalValue += ob[i].Value * ob[i].SoLuong;
            totalWeight += ob[i].SoLuong * ob[i].Weight;
        }
    }
}

void Dataoutput() {
    ofstream output("output.txt");
    output << "\nTong so vat da lay: " << total;
    output << "\nGia tri lon nhat co the lay: " << totalValue;
    output << "\nKhoi luong da su dung: " << totalWeight;
    output << "\nCac vat da lay [stt (so luong)] : ";
    for (int i = 1; i <= n; i++)
    {
        if (ob[i].SoLuong > 0)
        {
            output << ob[i].id << " (" << ob[i].SoLuong << ")  "; // chon vat i - so luong ob[i].SoLuong
        }
    }
    output.close();
}

int main(){
    Datainput();
    CalculateRealValue();
    SortObj(1, n);
    GreedyPick(w);
    Dataoutput();
}