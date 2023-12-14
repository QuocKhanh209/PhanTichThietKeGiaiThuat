#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int a[10000];
int wMax,wm,wr,wl;
void Datainput(int &n) {
    ifstream input("input.txt");
    if (!input.is_open()){
            cout << "Khong mo duoc file!!"<< endl;
    } else {
        input >> n;
        for (int i = 0; i < n; i++){
            int temp;
            input >> temp;
            a[i] = temp;
            // a.push_back(temp);
        }
    }
}

void Dataoutput(int dau, int cuoi) {
    ofstream output("output.txt");
    int subSum = 0;
    output << "Chi so dau va cuoi la: " << dau + 1<< " va " << cuoi + 1<< endl;
    for (int i = dau; i <= cuoi; i++){
        subSum += a[i];
        output << a[i] << " ";
    }
    output << "\nTong cua day con lon nhat la: " << subSum << endl;
    output.close();
}

int MaxLeft(int i, int j, int &dau){
    int Max_Sum = -10000;
    int sum =0;
    for (int k = j; k >= i; k--){
        sum += a[k];
        if (Max_Sum < sum){
            Max_Sum = sum;
            dau = k;
        }
    }
    return Max_Sum;
}

int MaxRight(int i, int j, int &cuoi){
    int Max_Sum = -10000;
    int sum = 0;
    for (int k = i; k <= j; k++){
        sum += a[k];
        if (Max_Sum < sum){
            Max_Sum = sum;
            cuoi = k;
        }
    }
    return Max_Sum;
}

int MaxSub(int i, int j, int &dau, int &cuoi){
    int dau1, dau2, dau3, cuoi1, cuoi2, cuoi3;
    if (i == j) {
        dau = cuoi = i;
        return a[i];
    }
    else {
        int m = (i + j) / 2;
        wl = MaxSub(i , m, dau1, cuoi1);
        wr = MaxSub(m + 1, j, dau2, cuoi2);
        wm = MaxLeft(i, m, dau3) + MaxRight(m + 1, j, cuoi3);
        wMax = max(max(wl, wr), wm);

        if (wMax == wl) {
            dau = dau1;
            cuoi = cuoi1;
        }
        else if (wMax == wr) {
            dau = dau2;
            cuoi = cuoi2;
        }
        else if (wMax == wm) {
            dau = dau3;
            cuoi = cuoi3;
        }
        return wMax;
    }
}

int main(){
    int array[10000];
    int n = 0, max = 0, dau = 0, cuoi = 0;
    Datainput(n);
    if (n != 0){
        max = MaxSub( 0, n - 1, dau, cuoi);
        Dataoutput(dau, cuoi);
    }
}