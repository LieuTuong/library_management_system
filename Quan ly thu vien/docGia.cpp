#include "docGia.h"

DocGia::DocGia()
{
	maDocGia = hoTen = CMND = "";
}

void DocGia::set_hoTen()
{
	getline(cin, hoTen);
}

void DocGia::set_maDocGia()
{
	getline(cin, maDocGia);
}

void DocGia::set_ngaySinh()
{
	ngaySinh.nhap();
}

void DocGia::set_ngayLapThe()
{
	ngayLapThe.nhap();
}

void DocGia::set_CMND()
{
	getline(cin, CMND);
}

string DocGia::get_CMND()
{
	return CMND;
}

string DocGia::get_hoTen()
{
	return hoTen;
}

string DocGia::get_maDocGia()
{
	return maDocGia;
}

void DocGia::get_ngayLapThe()
{
	ngayLapThe.xuat();
}

void DocGia::get_ngaySinh()
{
	ngaySinh.xuat();
}

void DocGia::nhap()
{
	cout << "\nMa doc gia: "; set_maDocGia();
	cout << "\nHo ten: "; set_hoTen();
	cout << "\nCMND: "; set_CMND();
	cout << "\nNgay sinh: "; set_ngaySinh();
	cout << "\nNgay lap the: "; set_ngayLapThe();
}

void DocGia::xuat()
{
	cout << "\nMa doc gia: "<<get_maDocGia();
	cout << "\nHo ten: "<<get_hoTen();
	cout << "\nCMND: "<<get_CMND();
	cout << "\nNgay sinh: "; get_ngaySinh();
	cout << "\nNgay lap the: "; get_ngayLapThe();
}

ostream& operator<<(ostream& outDev, DocGia* x)
{
	outDev << "\nMa doc gia: " << x->get_maDocGia();
	outDev << "\nHo ten: " << x->get_hoTen();
	outDev << "\nCMND: " << x->get_CMND();
	outDev << "\nNgay sinh: "; x->get_ngaySinh();
	outDev << "\nNgay lap the: "; x->get_ngayLapThe();
	return outDev;
}