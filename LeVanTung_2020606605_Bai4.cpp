#include <iostream>
using namespace std;
void NhapN(int &n){
	do{
		cout <<"Nhap n = ";cin>>n;
	}while(n < 0);
}
void Nhap(int *a, int n){
	for(int i = 0; i < n; i++){
		cout <<"a["<<i<<"] = ";cin>>*(a+i);
	}
}
void Xuat(int *a, int n){
	cout <<"Mang co "<<n<<" phan tu : ";
	for(int i = 0; i < n; i++){
		cout <<*(a+i)<<"   ";
	}
}
void Chen(int *a, int &n, int x, int vt){
	for(int i = n - 1; i >= vt; i--){
		*(a+i+1) = *(a+i);
	}
	*(a+vt) = x;
	n++;
}
void Xoa(int *a, int &n, int vt){
	for(int i = vt; i < n; i++){
		*(a+i) = *(a+i+1);
	}
	n--;
}
void Coppy(int *a, int &n){
	for(int i = n-1; i >= 0; i--){
		if(*(a+i) % 2 != 0){
			Chen(a,n,*(a+i),n);
			
		}
	}
	cout<<"\nMang sau khi sao chep le ve cuoi : "<<endl;
	Xuat(a,n);
}
void Check(int *a, int n){
	int check = 1;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if(*(a+i) == *(a+j)){
				check = 0;
				break;
			}
		}
	}
	if(check == 1){
		cout<<endl <<"Mang da chuan hoa "<<endl;
	}else{
		cout<<endl <<"Mang chua chuan hoa !"<<endl;
		for(int i = 0; i < n; i++){
		    for(int j = i+1; j < n; j++){
	    		if(*(a+i) == *(a+j)){
    				Xoa(a,n,j);
	    		}
    		}
    	}
	    cout <<"Mang sau khi chuan hoa : "<<endl;
	    Xuat(a,n);
	}
}
void ChuanHoaMang(int *a, int &n){
	
}
int main(){
	int n;
	NhapN(n);
	int *a = new int[n];
	Nhap(a,n);
	Xuat(a,n);
	Coppy(a,n);
	Check(a,n);
	ChuanHoaMang(a,n);
	delete [] a;
}
