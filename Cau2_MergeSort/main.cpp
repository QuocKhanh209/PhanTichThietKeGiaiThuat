#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void Datainput(vector<int> &a , int &n) {
    ifstream input("input.txt");
    if (!input.is_open()){
            cout << "Khong mo duoc file!!"<< endl;
    }
	input >> n;
	for (int i = 0; i < n; i++){
        int temp;
		input >> temp;
        a.push_back(temp);
	}
}

void Dataoutput(vector<int> &a, int n) {
    ofstream output("output.txt");
    if (!output.is_open()){
        cout << "Khong mo duoc file!!"<< endl;
    } 
    else {
        output << "Mang sau khi sap xep : " << endl;
        for (int i = 0; i < n; i++){
            output << a[i] << " ";
        }
        output.close();
    }
    // for (int i = 0; i < n; i++){
    //     // output << a[i] << " ";
    //     cout << a[i] << " ";
    // }
}

void Merge(vector<int> &a, int l, int m , int r){
    int i = l;
    int j = m + 1;
    int p = l;
    int c[10000];
    while (i <= m && j <= r)
    {
        if (a[i] < a[j]){
            c[p] = a[i];
            i++;
        }
        else {
            c[p] = a[j];
            j++;
        }
        p++;
    }

    while (i <= m){
        c[p] = a[i];
        i++; p++;
    }

    while (j <= r)
    {
        c[p] = a[j];
        j++;p++;
    }
    
    for (int i = l; i <= r; i++){
        a[i] = c[i];
    }
    
}

void Merge_Sort(vector<int> &a, int l, int r){
    if (l < r){
        int m = (l + r) / 2;
        Merge_Sort(a,l,m);
        Merge_Sort(a, m + 1, r);
        Merge(a,l,m,r);
    }
}

int main(){
    vector<int> array;
    int n;
    Datainput(array, n);
    Merge_Sort(array, 0, n - 1);
    Dataoutput(array, n);
}