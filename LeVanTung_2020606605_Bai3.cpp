#include <iostream>
#include <string>
using namespace std;
struct DATE {
	int ngay;
	int thang;
	int nam;
};
struct THISINH {
	string SBD;
	string HoTen;
	float DiemToan;
	float DiemLy;
	float DiemHoa;
	float TongDiem; 
};
void Nhap(THISINH &SV){
	fflush(stdin);
	cout <<"Nhap SBD : ";getline(cin,SV.SBD);
	cout <<"Nhap ho ten : ",getline(cin,SV.HoTen);
	do{
		cout <<"Nhap diem toan : ",cin>>SV.DiemToan;
	}while(SV.DiemToan < 0 || SV.DiemToan > 10);
	do{
		cout <<"Nhap diem ly : ",cin>>SV.DiemLy;
	}while(SV.DiemLy < 0 || SV.DiemLy > 10);
	do{
		cout <<"Nhap diem hoa : ",cin>>SV.DiemHoa;
	}while(SV.DiemHoa < 0 || SV.DiemHoa > 10);
	SV.TongDiem = SV.DiemToan + SV.DiemLy + SV.DiemHoa;	
}
void Xuat(THISINH sv){
	
	cout <<"SBD : "<<sv.SBD <<" - Ho va ten : "<<sv.HoTen
	     <<" - Diem Toan : "<<sv.DiemToan
	     <<" - Diem Ly : "<<sv.DiemLy
	     <<" - Diem Hoa : "<<sv.DiemHoa
		 <<" - Tong Diem : "<<sv.TongDiem<<endl;
}

int main(){
	int n = 3;
	THISINH *sv;
	sv = new THISINH[n];
	for(int i = 0; i < n; i++){
		cout <<"Nhap thong tin sinh vien : "<<i+1<<endl;
		Nhap(sv[i]);
		cout<<endl;
	}
	//cout <<"-------------show--------------"<<endl;
	int chon;
	cout <<"---------------MENU------------------"<<endl;
	cout <<"1.Hien thi danh sach thi sinh"<<endl;
	cout <<"2.Hien thi danh sach thi sinh co tong diem tren 14"<<endl;
	cout <<"3.Hien thi danh sach thi sinh theo thu tu tong diem tang dan"<<endl;
	cout <<"Moi ban chon : ";cin>>chon;
	switch(chon){
		case 1: {
			for(int i = 0; i < n; i++){
		        Xuat(sv[i]);
	        }
			break;
		}
		case 2: {
			for(int i = 0; i < n; i++){
		        if(sv[i].TongDiem > 14){
			        Xuat(sv[i]);
		        }
         	}
			break;
		}
		case 3:{
			for(int i = 0; i < n; i++){
		        for(int j = i + 1; j < n; j++){
	        		if(sv[i].TongDiem > sv[j].TongDiem){
	        			THISINH temp = sv[i];
			    	       sv[i] = sv[j];
			    	       sv[j] = temp;
		            }
	            }
		    }
	        cout <<"\nSap Xep :"<<endl;
	        for(int i = 0; i < n; i++){
	        	Xuat(sv[i]);
	        }
			break;
		}
		default : {
			cout <<"Moi ban nhap lai !"<<endl;
			break;
		}
	}
	
	
	
	delete [] sv;
	return 0;
}
