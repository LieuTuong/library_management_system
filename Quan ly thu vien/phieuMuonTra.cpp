#include"phieuMuonTra.h"

phieuMuonTra::phieuMuonTra()
{
	maDocGia  = "";
	maSach = "";
}

void phieuMuonTra::set_maPhieu()
{
	getline(cin, maPhieu);
}

void phieuMuonTra::set_maDocGia()
{
	getline(cin, maDocGia);
}

void phieuMuonTra::set_ngayMuon()
{
	ngayMuon.nhap();
}





string phieuMuonTra::get_maDocGia()
{
	return maDocGia;
}

string phieuMuonTra::get_maPhieu()
{
	return maPhieu;
}





void phieuMuonTra::set_sachMuon()
{
	getline(cin, maSach);
}

string phieuMuonTra::get_sachMuon()
{
	return maSach;
}

void menuTinhTrang()
{
	cout << "\n\t1. Muon da tra.";
	cout << "\n\t2. Chua tra con han.";
	cout << "\n\t3. Chua tra het han.";
}

void menuLoaiSach()
{
	cout << "\n1. Sach tieng viet";
	cout << "\n2. Sach ngoai van";
}

void phieuMuonTra::nhap()
{
	cout << "\nMa phieu: "; set_maPhieu();
	cout << "\nMa doc gia: "; set_maDocGia();
	cout << "\nNgay muon: "; set_ngayMuon();
	cin.ignore();
	cout << "\nSach muon: "; set_sachMuon();
		
}

DATE phieuMuonTra::tinhNgayHetHan(int hanNgay=7)
{
	return ngayMuon.tinhNgayHetHan(hanNgay);
}

void phieuMuonTra::xuat()
{
	cout << "\nMa phieu: " << get_maPhieu();
	cout << "\nMa doc gia: " << get_maDocGia();
	cout << "\nNgay muon: "; ngayMuon.xuat();
	cout << "\nSach muon: " << get_sachMuon();
	cout << "\nNgay tra sach: "; tinhNgayHetHan().xuat();
	
}

int phieuMuonTra::tinhTienPhat(DATE now)
{
	return tienPhatCuaLoaiSach()*khoangCachNgay(tinhNgayHetHan(),now);
}

int phieuMuonTra_sachNgoaiVan::tienPhatCuaLoaiSach()
{
	return 20000;
}

int phieuMuonTra_sachTiengViet::tienPhatCuaLoaiSach()
{
	return 10000;
}

ostream& operator<<(ostream& outDev, phieuMuonTra* phieu)
{
	outDev << "\nMa doc gia: " << phieu->get_maDocGia();
	outDev << "\nNgay muon: "; phieu->ngayMuon.xuat();
	outDev << "\nNgay tra sach: "; phieu->tinhNgayHetHan().xuat();
	outDev << "\nSach dang muon: " << phieu->get_sachMuon();
	
	return outDev;
}


ostream& operator<<(ostream& outDev, phieuMuonTra_sachTiengViet* phieu)
{
	outDev << "\nMa doc gia: " << phieu->get_maDocGia();
	outDev << "\nNgay muon: "; phieu->ngayMuon.xuat();
	outDev << "\nNgay tra sach: "; phieu->tinhNgayHetHan().xuat();
	outDev << "\nSach dang muon: " << phieu->get_sachMuon();

	return outDev;
}

ostream& operator<<(ostream& outDev, phieuMuonTra_sachNgoaiVan* phieu)
{
	outDev << "\nMa doc gia: " << phieu->get_maDocGia();
	outDev << "\nNgay muon: "; phieu->ngayMuon.xuat();
	outDev << "\nNgay tra sach: "; phieu->tinhNgayHetHan().xuat();
	outDev << "\nSach dang muon: " << phieu->get_sachMuon();

	return outDev;
}
