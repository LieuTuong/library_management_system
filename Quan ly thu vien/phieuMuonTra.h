#ifndef __PHIEUMUONTRA_H__
#define __PHIEUMUONTRA_H__
#include"docGia.h"
#include"Sach.h"
#include"DATE.h"
enum loaiPhieu
{
	phieu_sach_tieng_viet = 1,
	phieu_sach_ngoai_van
};
void menuTinhTrang();

class phieuMuonTra
{
protected:
	string maPhieu;
	string maDocGia;
	string maSach;
	DATE ngayMuon;

	
public:
	phieuMuonTra();
	void set_maPhieu();
	void set_maDocGia();
	void set_ngayMuon();
	void set_sachMuon();	
	

	
	string get_maPhieu();
	string get_maDocGia();
	DATE tinhNgayHetHan(int );
	string get_sachMuon();
	
	

	void nhap();
	void xuat();

	 int tinhTienPhat(DATE);
	 virtual int tienPhatCuaLoaiSach()
	 {
		 return 0;
	 };
	 friend ostream& operator<<(ostream& outDev, phieuMuonTra* phieu);
};


class phieuMuonTra_sachTiengViet :public phieuMuonTra
{
public:
	int tienPhatCuaLoaiSach();
	friend ostream& operator<<(ostream& outDev, phieuMuonTra_sachTiengViet* phieu);
};

class phieuMuonTra_sachNgoaiVan :public phieuMuonTra
{
public:
	int tienPhatCuaLoaiSach();
	friend ostream& operator<<(ostream& outDev, phieuMuonTra_sachNgoaiVan* phieu);
};


#endif