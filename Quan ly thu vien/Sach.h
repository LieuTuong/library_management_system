#ifndef __SACH_H__
#define __SACH_H__
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#define LOAISACH 2
#define TINHTRANG 3
using namespace std;

enum loaiSach{
	sach_tieng_viet = 1,
	sach_ngoai_van
};

class SACH
{
protected:
	string maSach;
	string tenSach;
	string tacGia;
	string nhaXuatBan;
	string giaSach;
public:
	SACH();
	void set_maSach();
	void set_tenSach();
	void set_tacGia();
	void set_nhaXuatBan();
	void set_giaSach();

	string get_maSach();
	string get_tenSach();
	string get_tacGia();
	string get_nhaXuatBan();
	string get_giaSach();

	
	virtual ~SACH(){};
	virtual void nhap();


	friend ostream& operator<<(ostream& outDev, SACH* sach);
};


class sachTiengViet :public SACH
{
public:
	sachTiengViet();
	
	~sachTiengViet(){}
	
};


class sachNgoaiVan :public SACH
{
private:
	string ISBN;
public:
	sachNgoaiVan();
	
	~sachNgoaiVan(){};
	void set_ISBN();
	string get_ISBN();

	void nhap();
	
	friend ostream& operator<<(ostream& outDev, sachNgoaiVan* sach);
};


#endif