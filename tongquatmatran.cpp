#include<iostream>
using namespace std;

class matran{
	private:
		int n,m;
		int mt[20][20];
	public:
	
	void nhap(){
		cout<<"\nnhap so hang m: ";
		cin>>m;
		cout<<"\nnhap so cot n: ";
		cin>>n;
		cout<<"\nnhap cac phan tu cho ma tran\n";
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				cout<<"a["<<i+1<<"]"<<"["<<j+1<<"]: ";
				cin>>mt[i][j];
			}
		}
	} 
	void xuat(){
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				cout<<mt[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	matran  operator + (const matran&a){
		matran kq;
		if(m!=a.m||n!=a.n){
			cout<<"khong the cong 2 matran\n";
			kq.m=kq.n=0;
		}else{
			kq.m=m;
			kq.n=n;
			for(int i=0; i<m; i++){
				for (int j=0; j<n;j++){
					kq.mt[i][j]=mt[i][j]+a.mt[i][j];
				}
			}
		}
		return kq;
	}
	matran operator - (const matran&a){
		matran kq;
		if(m!=a.m||n!=a.n){
			cout<<"khong the tru 2 ma tran\n";
			kq.m=kq.n=0;
		}else{
			kq.m=m;
			kq.n=n;
			for(int i=0;i<m;i++){
				for(int j=0;j<n;j++){
					kq.mt[i][j]=mt[i][j]-a.mt[i][j];
				}
			}
		}
		return kq;
	}
	matran operator * (const matran&a){
		matran kq;
		if(n!=a.m){
			cout<<"khong the nhan 2 ma tran\n";
			kq.m=kq.n=0;
		}else{
			kq.m=m;
			kq.n=a.n;
			for(int i=0; i<m;i++){
				for(int j=0; j<a.n;j++){
					kq.mt[i][j]=0;
					for(int k=0; k<n; k++){
						kq.mt[i][j]+=mt[i][k]*a.mt[k][j];
					}
					
				}
			}
		}
		return kq;
	}
	matran chuyenvi(){
		matran kq;
		kq.m=n;
		kq.n=m;
		for(int i=0; i<m;i++){
			for(int j=0; j<n; j++){
				kq.mt[j][i]=mt[i][j];
			}
		}	
		return kq;
	}
	int maxchan(){
		int maxbd=-1;
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				if(mt[i][j]%2==0){
					if(maxbd==-1||mt[i][j]>maxbd){
						maxbd=mt[i][j];
					}
				}
			}
		}
		return maxbd;
	} 
	
		
};
int main(){
	matran m1,m2,tong,hieu,tich;
	cout<<"moi nhap ma tran m1";
	m1.nhap();
	cout<<"\nma tran m1 la: \n";m1.xuat();
	cout<<"\nmoi nhap ma tran m2";
	m2.nhap();
	cout<<"\nma tran m2 la: \n";m2.xuat();
	tong=m1+m2;
	cout<<"tong 2 ma tran la: \n";tong.xuat();
	hieu=m1-m2;
	cout<<"hieu 2 ma tran la: \n";hieu.xuat();
	tich=m1*m2;
	cout<<"tich 2 ma tran la: \n";tich.xuat();
	cout<<"ma tran chuyen vi cua m1 la: \n";m1.chuyenvi().xuat();
	cout<<"ma tran chuyen vi cua m2 la: \n";m2.chuyenvi().xuat();
	int maxm1=m1.maxchan();
	if (maxm1!=-1){
		cout<<"\nmax chan m1= "<<maxm1;
	}else{
		cout<<"\nm1 khong ton tai max chan";
	}
	int maxm2=m2.maxchan();
	if (maxm2!=-1){
		cout<<"\nmax chan m2= "<<maxm2;
	}else{
		cout<<"\nm2 khong ton tai max chan";
	}
}
