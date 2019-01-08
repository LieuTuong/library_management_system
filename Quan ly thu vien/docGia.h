#ifndef __DOCGIA_H__
#define __DOCGIA_H__

#include <iostream>
#include<string>
#include<vector>
#include"DATE.h"
using namespace std;

class DocGia
{
private:
	string maDocGia;
	string hoTen;
	string CMND;
	DATE ngaySinh;
	DATE ngayLapThe;

public:
	//DocGia(string _maDocGia, string _hoTen, string _CMND, DATE _ngaySinh,string _ngayLapThe) :maDocGia(_maDocGia), hoTen(_hoTen), CMND(_CMND), ngaySinh(_ngaySinh),ngayLapThe(_ngayLapThe){}
	DocGia();
	void set_maDocGia();
	void set_hoTen();
	void set_CMND();
	void set_ngaySinh();
	void set_ngayLapThe();

	string get_maDocGia();
	string get_hoTen();
	string get_CMND();
	void get_ngaySinh();
	void get_ngayLapThe();

	
	void nhap();
	void xuat();
	friend ostream& operator<<(ostream& outDev, DocGia* x);
};
#endif