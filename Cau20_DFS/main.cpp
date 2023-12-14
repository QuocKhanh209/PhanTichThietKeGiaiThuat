#include<iostream>
#include<fstream>
using namespace std;
int n,s,t;
int a[100][100];
int daxet[100];
int truoc[100];

ifstream input("input.txt");
ofstream output("output.txt");

void Input(){
	int i,j;
    input >> n >> s >> t;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++) 
		input >>a[i][j];
    }
	for(i=1;i<=n;i++){
		daxet[i]=0;
		truoc[i]=0;
	}
}
void print(){
	output<<t<<"<--";
	int j=t;
	while(truoc[j]!=s){
		output<<truoc[j]<<"<--";
		j=truoc[j];
	}
	output<<s<<endl;
}
void DFS(int s){
	int u;
	daxet[s]=1;
	for(u=1;u<=n;u++){
//		cout<<"Ahihi vong for u= "<<u<<endl;
		if(a[s][u]==1&&daxet[u]==0){
			daxet[u]=1;
//			cout<<"Da xet: "<<u<<endl;
			truoc[u]=s;
//			cout<<"Truoc u: "<<s<<endl;
			if(u==t) print();
			else {
//				cout<<endl<<"DFS: "<<u<<endl;
				DFS(u);
			}
			daxet[u]=0;
//			cout<<"Tra lai chua xet:"<<u<<endl;
		}
	}
}
int main(){
	Input();
	DFS(s);
    output.close();
	return 0;
}
