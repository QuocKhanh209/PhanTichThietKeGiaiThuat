#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>


using namespace std;

void Quicksort(vector<int> &a, int l, int r) {
    int i = l, j = r;
    int x = a[(l+r) / 2];
    while (i <= j) {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++; j--;
        }
    }
    if (i < r) Quicksort(a, i, r);
    if (j > l) Quicksort(a, l, j);
}

int Datainput(vector<int> &a) {
    int n ;
    std::ifstream input("input.txt");
    if (!input.is_open()){
            cout << "Khong mo duoc file!!"<< endl;
    }
	input >> n;
	for (int i = 0; i < n; i++){
        int temp;
		input >> temp;
        a.push_back(temp);
	}
    return n;
}

void Dataoutput(vector<int> &a, int n, float Time) {
    std::ofstream output("output.txt");
    output << "Mang sau khi sap xep : " << endl;
    for (int i = 0; i < n; i++){
        output << a[i] << " ";
    }
    output << "\nThoi gian chay cua thuat toan QuickSort la : " << Time << " seconds" << endl;
    output.close();
}

int main(){
    vector<int> array;
    int n;
    clock_t end, start;
    start = clock();
    n = Datainput(array);
    array.resize(n);
    Quicksort(array, 0 , n - 1);
    end = clock();
    Dataoutput(array, n , (end - start) / CLOCKS_PER_SEC);
}