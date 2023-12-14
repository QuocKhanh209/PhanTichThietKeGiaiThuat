#include<stdio.h>
#include<algorithm>
#include<fstream>
using namespace std;
const int maxn=100000+10;
int n;
int a[maxn];
int MaxS[maxn],MaxE[maxn];
int s1[maxn],s[maxn],e[maxn];

ifstream input("input.txt");
ofstream output("output.txt");
void Input()
{
    input >> n;
    for (int i = 1; i <= n; i++){
        input >> a[i];
    }
	input.close();
}

void Output(){
    output << "Day con co tong Max la: ";
    for(int i = s[n]; i<= e[n];i++) 
        output << a[i] << " ";
    output << "\n";
    output << "Tong gia tri la: " << MaxS[n];
}
int MaxSubSeq(){
	MaxE[1]=a[1];s1[1]=1;
  	MaxS[1]=a[1];s[1]=1;e[1]=1;
  	for(int i = 2 ;i <= n; i++){	
    	// Tinh MaxE[i]=Max(MaxE[i-1],0)+a[i];
    	if (MaxE[i-1]>0){
      		MaxE[i]=MaxE[i-1]+a[i];
      		s1[i]=s1[i-1];
      		
    	}
    	else{
      		MaxE[i]=a[i];
      		s1[i]=i;
    	}
    	// Tinh MaxS[i]=Max(MaxS[i-1],MaxE[i]);
    	if (MaxS[i-1]>=MaxE[i]){
      		MaxS[i]=MaxS[i-1];
      		s[i]=s[i-1];e[i]=e[i-1];
      		}
    	else{
      		MaxS[i]=MaxE[i];
      		s[i]=s1[i];e[i]=i;
      	}
  	}
}

int main(){
  Input();
  MaxSubSeq();
  Output();
}


