#include"Sach.h"

SACH::SACH()
{
	maSach = tenSach = tacGia = nhaXuatBan = giaSach = "";
}

void SACH::set_maSach()
{
	getline(cin, maSach);
}

void SACH::set_tenSach()
{
	getline(cin, tenSach);
}

void SACH::set_tacGia()
{
	getline(cin, tacGia);
}

void SACH::set_nhaXuatBan()
{
	getline(cin, nhaXuatBan);
}

void SACH::set_giaSach()
{
	getline(cin, giaSach);
}

string SACH::get_maSach()
{
	return maSach;
}

string SACH::get_tenSach()
{
	return tenSach;
}

string SACH::get_tacGia()
{
	return tacGia;
}

string SACH::get_nhaXuatBan()
{
	return nhaXuatBan;
}

string SACH::get_giaSach()
{
	return giaSach;
}

void SACH::nhap()
{
	cout << "\nMa sach: "; set_maSach();
	cout << "\nTen sach: "; set_tenSach();
	cout << "\nTac gia: "; set_tacGia();
	cout << "\nNha xuat ban: "; set_nhaXuatBan();
	cout << "\nGia sach: "; set_giaSach();
}

void SACH::xuat()
{
	cout << "\nMa sach: "<< get_maSach();
	cout << "\nTen sach: "<< get_tenSach();
	cout << "\nTac gia: "<< get_tacGia();
	cout << "\nNha xuat ban: "<<get_nhaXuatBan();
	cout << "\nGia sach: "<< get_giaSach();
}

sachTiengViet::sachTiengViet()
{
	SACH();
}


void sachNgoaiVan::set_ISBN()
{
	getline(cin, ISBN);
}

string sachNgoaiVan::get_ISBN()
{
	return ISBN;
}

void sachNgoaiVan::nhap()
{
	SACH::nhap();
	cout << "\nISBN: "; set_ISBN();
}

void sachNgoaiVan::xuat()
{
	SACH::xuat();
	cout << "\nISBN: " << get_ISBN();
}



sachNgoaiVan::sachNgoaiVan()
{
	SACH();
	ISBN = "";
}

ostream& operator<<(ostream& outDev, SACH* x)
{
	outDev << "\nMa sach: " << x->get_maSach();
	outDev << "\nTen sach: " << x->get_tenSach();
	outDev << "\nTac gia: " << x->get_tacGia();
	outDev << "\nNha xuat ban: " << x->get_nhaXuatBan();
	outDev << "\nGia sach: " << x->get_giaSach();
	return outDev;
}

//ostream& operator<<(ostream& outDev,  sachTiengViet* x)
//{
//	outDev << "\nMa sach: " << x->get_maSach();
//	outDev << "\nTen sach: " << x->get_tenSach();
//	outDev << "\nTac gia: " << x->get_tacGia();
//	outDev << "\nNha xuat ban: " << x->get_nhaXuatBan();
//	outDev << "\nGia sach: " << x->get_giaSach();
//	return outDev;
//}

ostream& operator<<(ostream& outDev,  sachNgoaiVan* x)
{
	outDev << "\nMa sach: " << x->get_maSach();
	outDev << "\nTen sach: " << x->get_tenSach();
	outDev << "\nTac gia: " << x->get_tacGia();
	outDev << "\nNha xuat ban: " << x->get_nhaXuatBan();
	outDev << "\nGia sach: " << x->get_giaSach();
	outDev << "\nISBN: " << x->get_ISBN();
	return outDev;
}