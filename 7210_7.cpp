// Name = Anupam
// Roll No = 7210
// SE COMP-B

#include<bits/stdc++.h>
using namespace std;

int main(){
  cout<<"enter the number of rows and coloumn ";
	int r,c;cin>>r>>c;
	int a[r][c];
	
	int cnt=0;
    cout<<"enter the elements of first matrix "<<endl;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>a[i][j];
			if(a[i][j]!=0) cnt++;	
		}
	}
    cout<<"enter the number of rows and coloumn of second matrix ";
	int r1,c1;cin>>r1>>c1;
	int a1[r1][c1];
	cout<<"enter the elements of first matrix "<<endl;
	int cnt1=0;
	for(int i=0;i<r1;i++){
		for(int j=0;j<c1;j++){
			cin>>a1[i][j];
			if(a1[i][j]!=0) cnt1++;	
		}
	}
	int a_f[cnt+1][3];
	a_f[0][0]=r;a_f[0][1]=c;a_f[0][2]=cnt;
	
	int k=1;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(a[i][j]!=0){
				a_f[k][0]=i;a_f[k][1]=j;a_f[k][2]=a[i][j];
				k++;
			}
		}
	}
	cout<<endl;
    cout<<"sparse matrix repersentation of the first matrix is "<<endl;
	for(int i=0;i<=cnt;i++){
		for(int j=0;j<3;j++) cout<<a_f[i][j]<<" ";
		cout<<endl;
	}
	
	

	int a1_f[cnt1+1][3];
	a1_f[0][0]=r1;a1_f[0][1]=c1;a1_f[0][2]=cnt1;
	
	int k1=1;
	for(int i=0;i<r1;i++){
		for(int j=0;j<c1;j++){
			if(a1[i][j]!=0){
				a1_f[k1][0]=i;a1_f[k1][1]=j;a1_f[k1][2]=a1[i][j];
				k1++;
			}
		}
	}
	cout<<endl;
    cout<<"sparse matrix repersentation of the second  matrix is "<<endl;
	for(int i=0;i<=cnt1;i++){
		for(int j=0;j<3;j++) cout<<a1_f[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	
	//addition of two spars matrix
	
	if(r==r1 and c==c1){
		int add[cnt+cnt1+1][3];
		add[0][0]=r;add[0][1]=c;add[0][2]=0;
		int i=1,j=1,k2=1;
		while(i<=cnt and j<=cnt1){
			if(a_f[i][0]==a1_f[j][0] and a_f[i][1]==a1_f[j][1] ){
				add[k2][0]=a1_f[j][0];add[k2][1]=a1_f[j][1];
				add[k2][2]=a_f[i][2]+a1_f[j][2];
				i++;k2++;j++;
			}
			else if(a_f[i][0]==a1_f[j][0]){
				if(a_f[i][1]>a1_f[j][1] ){
					
					
					add[k2][0]=a1_f[j][0];add[k2][1]=a1_f[j][1];
					add[k2][2]=a1_f[j][2];
					k2++;j++;
				}
				else{
					add[k2][0]=a_f[i][0];add[k2][1]=a_f[i][1];
					add[k2][2]=a_f[i][2];
					i++;k2++;
				}
			}
			else if(a_f[i][0]>a1_f[j][0] ){
				add[k2][0]=a1_f[j][0];add[k2][1]=a1_f[j][1];
				add[k2][2]=a1_f[j][2];
				k2++;j++;
			}
			else{
				add[k2][0]=a_f[i][0];add[k2][1]=a_f[i][1];
				add[k2][2]=a_f[i][2];
				i++;k2++;
			}
		}
		while(i<cnt ){
			add[k2][0]=a_f[i][0];add[k2][1]=a_f[i][1];
			add[k2][2]=a1[i][2];
			i++;k2++;
		}
		while(j<cnt1){
			add[k2][0]=a1_f[j][0];add[k2][1]=a1_f[j][1];
			add[k2][2]=a1_f[j][2];
			k2++;j++;
		}
		add[0][2]=k2-1;
        cout<<"addition of two sparse matrix is "<<endl;
		for(int i=0;i<k2;i++){
			cout<<add[i][0]<<" "<<add[i][1]<<" "<<add[i][2]<<endl;
		}
	
	}
	else cout<<"addition not possible"<<endl;
	
	
	//transpose of matrix a_f by simle transpose method
	
	
	int a_t[cnt+1][3];
	a_t[0][0]=c;a_t[0][1]=r;a_t[0][2]=cnt;int k3=1;
	for(int i=0;i<c;i++){
		for(int j=1;j<=cnt;j++){
			if(a_f[j][1]==i){
				a_t[k3][0]=a_f[j][1];a_t[k3][1]=a_f[j][0];a_t[k3][2]=a_f[j][2];
				k3++;
			}
		}
	}
	cout<<"transpsose of of mattrix a_f is"<<endl;
	for(int i=0;i<=cnt;i++){
		cout<<a_t[i][0]<<" "<<a_t[i][1]<<" "<<a_t[i][2]<<endl;
	}
	
	
	//transpose of matrix a_f by fast transpose method
	
	
	
	
	int a_tf[cnt+1][3];
	a_tf[0][0]=c;a_tf[0][1]=r;a_tf[0][2]=cnt;int k4=1;
	
	int arr[c]={0};
	
	
	for(int j=1;j<=cnt;j++){
		arr[a_f[j][1]]++;
		
	}
	int len=sizeof(arr)/sizeof(arr[0]);
	int arr1[c];
	arr1[0]=1;
	for(int i=1;i<c;i++){
		arr1[i]=arr1[i-1]+arr[i-1];
	}
	for(int j=1;j<=cnt;j++){
		a_tf[arr1[a_f[j][1]]][0]=a_f[j][1];
		a_tf[arr1[a_f[j][1]]][1]=a_f[j][0];
		a_tf[arr1[a_f[j][1]]][2]=a_f[j][2];
		arr1[a_f[j][1]]++;
	}
	cout<<"transpsose of of mattrix a_f is by fast transpose is"<<endl;
	for(int i=0;i<=cnt;i++){
		cout<<a_tf[i][0]<<" "<<a_tf[i][1]<<" "<<a_tf[i][2]<<endl;
	}
	return 0;
}
