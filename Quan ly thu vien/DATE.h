#ifndef __DATE_H__
#define __DATE_H__
#include<iostream>
using namespace std;
class DATE
{
protected:
	int ngay;
	int thang;
	int nam;
public:
	DATE();
	void set_ngay();
	void set_thang();
	void set_nam();

	int get_ngay();
	int get_thang();
	int get_nam();

	void nhap();
	void xuat();
	
	
	DATE tinhNgayHetHan(int hanNgay);

	friend ostream& operator<<(ostream& outDev, const DATE& x);
};

bool laNamNhuan(int nam);

int tinhSoNgayTrongThang(int thang,int nam);

bool laNgayHopLe(int ngay, int thang,int nam);

int offsetDays(int d, int m, int y);


void revoffsetDays(int offset, int y, int d, int m);

int demNamNhuan(DATE d);

int khoangCachNgay(DATE d1, DATE d2);
#endif