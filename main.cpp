#include <bits/stdc++.h>
#include <stdio.h>
#include "find.h"
#include "company.h"
#define MAX 100000
using namespace std;

int main() {
  // mo file html doc
    fstream file;
    string input;
    int amount =20 ;
    file.open("HTML.txt", ios::in);
    if (file.is_open()){
        string line;
        while (getline(file, line)) {
            input = input + line + "\n";
        };
    };
    file.close();

    //mo file ck de ghi
    file.open("ck.txt", ios::out);
    string* info = getInfo(input, amount);
    Company *company = new Company[amount];
    file << amount << endl;
    for (int i  = 0; i < amount; i++){
        company[i] = Company(info[i]);
    }
    for (int i  = 0; i < amount; i++){
      file << company[i].name << endl;
      file << company[i].code << endl;
      file << company[i].price_ceiling << endl;
      file << company[i].price_floor << endl;
      file << company[i].price_close << endl;
      file << company[i].mass << endl;
     }
     file.close();
    //luu file nhi phan
    fstream fout("nhiphan.dat",ios::out | ios::binary);
    fout.write((char *) &amount, sizeof(amount));
    for (int i  = 0; i < amount; i++){
      fout.write((char *) &company[i].name, sizeof(company[i].name));
      fout.write((char *) &company[i].code, sizeof(company[i].code));
      fout.write((char *) &company[i].price_ceiling, sizeof(company[i].price_ceiling));
      fout.write((char *) &company[i].price_floor, sizeof(company[i].price_floor));
      fout.write((char *) &company[i].price_close, sizeof(company[i].price_close));
      fout.write((char *) &company[i].mass, sizeof(company[i].mass));
     }
     fout.close();
		
     int N;
	  fstream fin("ck.txt", ios::in);
	  fin >> N;
	  COMPANY COMPANY[N];
	  string temp;
	  getline(fin, temp);
	  for(int i=0;i<N;i++) {
		 string Ten;
		 getline(fin,Ten);
		 COMPANY[i].setTen(Ten);

		 string Ma;
		 getline(fin,Ma);
		 COMPANY[i].setMa(Ma);
		 
		 double Giasan;
		 fin >> Giasan;
		 COMPANY[i].setGiasan(Giasan);

		 double Giatran;
		 fin >> Giatran;
		 COMPANY[i].setGiatran(Giatran);

		 double Giadongcua;
		 fin >> Giadongcua;
		 COMPANY[i].setGiadongcua(Giadongcua);

		 getline(fin, temp);
		 
		 string Khoiluong;
		 getline(fin,Khoiluong);
		 COMPANY[i].setKhoiluong(Khoiluong);
	 }
	 
 //memu chon
  int chon;
  do {
    cout << "\t\t\t" << "Thông tin chứng khoán ngày 06/07/2020." << "\t\t\t" << endl;
		cout << "1. Liệt kê toàn bộ thông tin chứng khoán theo ngày." << endl;
		cout << "2. Hiển thị chứng khoán có giá đóng cửa cao nhất theo ngày." << endl;
		cout << "3. Hiển thị chứng khoán có khối lượng giao dịch cao nhất theo ngày." << endl;
		cout << "4.Exit! " << endl;
		cout << endl;
		cout << "\t\t\t\t\t" << "Xin mời lựa chọn ?" << endl;
		cin >> chon;
    		/*Xử lý sau khi chọn*/
		if( chon == 1 ) {
		for(int i=0;i<N;i++) {
			cout << "stt: " << i+1 << endl;
			cout <<"Ten : " << COMPANY[i].getTen() << endl;
			cout << "Ma: " << COMPANY[i].getMa() << endl;
			cout << "Gia san: " << COMPANY[i].getGiasan() << endl;
			cout << "Gia tran: " << COMPANY[i].getGiatran() << endl;
			cout << "Gia dong cua: " << COMPANY[i].getGiadongcua() << endl;
			cout << "Khoi luong: " << COMPANY[i].getKhoiluong() << "\n" << endl;
		}
		}
		
		if( chon == 2 ) {
      	double max = COMPANY[0].getGiadongcua();
      	for (int i  = 0; i < 20; i++) {
      		double a = COMPANY[i].getGiadongcua();
      		if ( max < a ) {
      		 max = a ;
      		}
			}
			for (int i  = 0; i < 20; i++) {
				if(max == COMPANY[i].getGiadongcua()){
					cout << "gia dong cua cao nhat la: " << max << endl;
					cout <<"Ten : " << COMPANY[i].getTen() << endl;
					cout << "Ma: " << COMPANY[i].getMa() << endl;
					cout << "Gia san: " << COMPANY[i].getGiasan() << endl;
					cout << "Gia tran: " << COMPANY[i].getGiatran() << endl;
					cout << "Gia dong cua: " << COMPANY[i].getGiadongcua() << endl;
					cout << "Khoi luong: " << COMPANY[i].getKhoiluong() << "\n" << endl;
				}
			}
		}
		
		if( chon == 3 ) {
			string a[10000];
			string check = COMPANY[0].getKhoiluong();

      // bo dau "," o trong string
			int i,n,j,k;
			n = check.length();
			for(i=0;i<n;i++) {
				if(check[i] == ',') {
					for(j=i;j<n;j++)
					{
          			check[j]=check[j+1];
					}
					n--;	//so ki tu cua chuoi giam xuong
					i--;	//sau buoc nay thi i se tang (vong for) nen ta se giam no xuong
				}
			}
    
			for (i=0;i<n;i++)
			{ 
				check[i];
			}

			int max = ::atof(check.c_str());
			
			// cho vong lap tim lon nhat
			for (int i = 0; i < N; i++) {
				string a = COMPANY[i].getKhoiluong();
				n = a.length();
				for(j=0;j<n;j++) {
					if(a[j] == ',') {
						for(k=j;k<n;k++)
						{
							a[k]=a[k+1];
 						}
					n--;	//so ki tu cua chuoi giam xuong
					j--;	//sau buoc nay thi i se tang (vong for) nen ta se giam no xuong
					}
				}
  
			for (j=0;j<n;j++)
			{ 
				a[j];
			}
			double b = ::atof(a.c_str());
				if(max < b) {
					max = b;
				}
				}
				
				for (int i = 0; i < N; i++) {
				string a = COMPANY[i].getKhoiluong();
				n = a.length();
				for(j=0;j<n;j++) {
					if(a[j] == ',') {
						for(k=j;k<n;k++)
						{
							a[k]=a[k+1];
 						}
					n--;	//so ki tu cua chuoi giam xuong
					j--;	//sau buoc nay thi i se tang (vong for) nen ta se giam no xuong
					}
				}
  
			for (j=0;j<n;j++)
			{ 
				a[j];
			}
			double b = ::atof(a.c_str());
				if (max == b ) {
					cout << "khoi luong giao dich cao nhat la: " << max << endl;
					cout <<"Ten : " << COMPANY[i].getTen() << endl;
					cout << "Ma: " << COMPANY[i].getMa() << endl;
					cout << "Gia san: " << COMPANY[i].getGiasan() << endl;
					cout << "Gia tran: " << COMPANY[i].getGiatran() << endl;
					cout << "Gia dong cua: " << COMPANY[i].getGiadongcua() << endl;
					cout << "Khoi luong: " << COMPANY[i].getKhoiluong() << "\n" << endl;
				}
			}
		}
		if( chon == 4 ) {
			break;
		}
		if(chon!=0){//Neu chon #0 va sau khi thuc hien xong thĂ¬ quay ve menu chon
   cout<<endl;
   cout<<"========================="<<endl;
   cout<<"=> Nhan Enter de tro ve !";
   cin.ignore();//Doc va loai bo ki tu con trong bo nho dem
   cin.get();//Giu ky tu Enter trong bo nho dem
   system("clear");//Xoa
  }
}
  while(chon!=0);
		
	fin.close();
     
    return 0;
} 