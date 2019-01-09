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
	
	DocGia();
	void set_maDocGia();
	void set_hoTen();
	void set_CMND();
	void set_ngaySinh();
	void set_ngayLapThe();

	string get_maDocGia();
	string get_hoTen();
	string get_CMND();
	
	void nhap();
	
	friend ostream& operator<<(ostream& outDev, DocGia* x);

	string get_ngaySinh();
	
	string get_ngayLapThe();
	
};
#endif