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
	DATE tinhNgayHetHan(int han=7);
	string get_sachMuon();
	string get_ngayMuon();
	string get_ngayHetHan();
	
	

	void nhap();
	
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
	
};

class phieuMuonTra_sachNgoaiVan :public phieuMuonTra
{
public:
	int tienPhatCuaLoaiSach();
	
};


#endif