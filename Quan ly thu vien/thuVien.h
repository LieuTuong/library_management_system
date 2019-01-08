
#ifndef __THUVIEN_H__
#define __THUVIEN_H__
#pragma once
#include "Sach.h"
#include "docGia.h"
#include"phieuMuonTra.h"

namespace tt_docGia{
	enum thongTinDocGia
	{
		ma_doc_gia = 1,
		ho_ten,
		CMND,
		ngay_sinh,
		ngay_lap_the,
	};
}

namespace tt_sach{
	enum thongTinSach
	{
		ma_sach = 1,
		ten_sach,
		tac_gia,
		NXB,
		gia_sach,
		ISBN
	};
}

namespace tt_phieu{
	enum thongTinPhieuMuon
	{
		ma_phieu = 1,
		ma_doc_gia,
		ngay_muon,
		ma_sach_muon	
	};

}

bool kiemTraMaSachTiengViet(string maSach, sachTiengViet* sach)
{
	return sach->get_maSach() == maSach;
}

bool kiemTraMaSachNgoaiVan(string maSach, sachNgoaiVan* sach)
{
	return sach->get_maSach() == maSach;
}

bool kiemTraMaDocGia(string maDocGia, DocGia* x)
{
	return x->get_maDocGia() == maDocGia;
}

bool kiemTraMaPhieuSachTiengViet(string maPhieu, phieuMuonTra_sachTiengViet* phieu)
{
	return phieu->get_maPhieu() == maPhieu;
}

bool kiemTraMaPhieuSachNgoaiVan(string maPhieu, phieuMuonTra_sachNgoaiVan* phieu)
{
	return phieu->get_maPhieu() == maPhieu;
}

bool isFileEmpty(fstream& f)
{
	return (f.peek() == fstream::traits_type::eof());
}

template<class T>
class xuLiChung
{
private:
	vector<T*> ds;
public:

	void them(T* x)
	{
		ds.push_back(x);
	}

	bool xoa(string ma, bool(*kt)(string, T*))
	{
		bool flag = 0;
		for (size_t i = 0; i < ds.size(); i++)
		{
			if (kt(ma, ds[i]) == 1)
			{
				ds.erase(ds.begin() + i);
				flag = 1;
				break;
			}
		}
		return flag;
	}

	void xuat()
	{
		for (size_t i = 0; i < ds.size(); i++)
		{
			cout << ds.at(i);
		}
	}

	T* timKiem(string ma,bool(*kt)(string,T*))
	{
		for (size_t i = 0; i < ds.size(); i++)
		{
			if (kt(ma, ds[i]) == 1)
				return ds[i];
		}
		return NULL;
	}

	size_t size()
	{
		return ds.size();
	}

	T* at(int i)
	{
		return ds.at(i);
	}
};


class thuVien
{
private:

	xuLiChung<sachTiengViet> ds_SachTiengViet;
	xuLiChung<sachNgoaiVan> ds_SachNgoaiVan;
	xuLiChung<DocGia> ds_docGia;
	xuLiChung<phieuMuonTra_sachTiengViet> ds_phieuSachTiengViet;
	xuLiChung<phieuMuonTra_sachNgoaiVan> ds_phieuSachNgoaiVan;
	
public:
	
	void themSach(SACH* x)
	{
		if (dynamic_cast<sachTiengViet*>(x))
		{
			ds_SachTiengViet.them(dynamic_cast<sachTiengViet*>(x));
			File_themSachTiengViet("sachTiengViet", dynamic_cast<sachTiengViet*>(x));
		}
			
		else
		{
			ds_SachNgoaiVan.them(dynamic_cast<sachNgoaiVan*>(x));
			File_themSachNgoaiVan("sachNgoaiVan", dynamic_cast<sachNgoaiVan*>(x));
		}
		
			
	}

	bool xoaSachTiengViet(string maSachCanXoa)
	{
		return ds_SachTiengViet.xoa(maSachCanXoa,kiemTraMaSachTiengViet);
	}

	bool xoaSachNgoaiVan(string maSachCanXoa)
	{
		return ds_SachNgoaiVan.xoa(maSachCanXoa, kiemTraMaSachNgoaiVan);
	}

	void Xuat_dsSachTiengViet()
	{
		ds_SachTiengViet.xuat();
	}

	void Xuat_dsSachNgoaiVan()
	{
		ds_SachNgoaiVan.xuat();
	}

	sachTiengViet* timSachTiengViet(string maSach)
	{
		return ds_SachTiengViet.timKiem(maSach, kiemTraMaSachTiengViet);
	}

	sachNgoaiVan* timSachNgoaiVan(string maSach)
	{
		return ds_SachNgoaiVan.timKiem(maSach, kiemTraMaSachNgoaiVan);
	}

	SACH* timSach(string maSach, int lc)
	{
		if (lc == sach_tieng_viet)
		{
			return timSachTiengViet(maSach);
		}
		else if (lc == sach_ngoai_van)
		{
			return timSachNgoaiVan(maSach);
		}
	}

	void suaThongTinSach(SACH* x, int lc)
	{
		if (lc == tt_sach::ma_sach)
		{
			cout << "\nMa sach: ";
			cin.ignore();
			x->set_maSach();
		}
		else if (lc == tt_sach::ten_sach)
		{
			cout << "\nTen sach: ";
			cin.ignore();
			x->set_tenSach();
		}
		else if (lc == tt_sach::tac_gia)
		{
			cout << "\nTac gia: ";
			cin.ignore();
			x->set_tacGia();
		}
		else if (lc == tt_sach::NXB)
		{
			cout << "\nNha xuat ban: ";
			cin.ignore();
			x->set_nhaXuatBan();
		}
		else if (lc == tt_sach::gia_sach)
		{
			cout << "\nGia sach: ";
			cin.ignore();
			x->set_giaSach();
		}
		else if (lc == tt_sach::ISBN&& dynamic_cast<sachNgoaiVan*>(x))
		{
			cout << "\nISBN: ";
			cin.ignore();
			dynamic_cast<sachNgoaiVan*>(x)->set_ISBN();
		}
	}

	void themDocGia(DocGia* x)
	{
		ds_docGia.them(x);
		File_themDocGia("docGia", x);
	}

	bool xoaDocGia(string maDocGiaCanXoa)
	{
		return ds_docGia.xoa(maDocGiaCanXoa, kiemTraMaDocGia);
	}

	void Xuat_dsDocGia()
	{
		ds_docGia.xuat();
	}

	void suaThongTinDocGia(DocGia*& x,int lc)
	{
		if (lc == tt_docGia::ma_doc_gia)
		{
			cout << "\nMa doc gia: ";
			cin.ignore();
			x->set_maDocGia();			
		}
		else if (lc == tt_docGia::ho_ten)
		{
			cout << "\nHo ten: ";
			cin.ignore();
			x->set_hoTen();
		}
		else if (lc == tt_docGia::CMND)
		{
			cout << "\nCMND: ";
			cin.ignore();
			x->set_CMND();		
		}
		else if (lc == tt_docGia::ngay_sinh)
		{
			cout << "\nNgay sinh: ";
			cin.ignore();
			x->set_ngaySinh();		
		}
		else if (lc == tt_docGia::ngay_lap_the)
		{
			cout << "\nNgay lap the: ";
			cin.ignore();
			x->set_ngayLapThe();		
		}	
	}

	DocGia* timDocGia(string maDocGia)
	{
		return ds_docGia.timKiem(maDocGia, kiemTraMaDocGia);
	}

	void themPhieu(phieuMuonTra* phieu)
	{
		if (dynamic_cast<phieuMuonTra_sachTiengViet*>(phieu))
		{
			ds_phieuSachTiengViet.them(dynamic_cast<phieuMuonTra_sachTiengViet*>(phieu));
			File_themPhieu("phieuSachTiengViet", dynamic_cast<phieuMuonTra_sachTiengViet*>(phieu));
		}
			
		else
		{
			ds_phieuSachNgoaiVan.them(dynamic_cast<phieuMuonTra_sachNgoaiVan*>(phieu));
			File_themPhieu("phieuSachNgoaiVan", dynamic_cast<phieuMuonTra_sachNgoaiVan*>(phieu));
		}
			
	}

	bool xoaPhieuSachTiengViet(string maPhieu)
	{
		return ds_phieuSachTiengViet.xoa(maPhieu, kiemTraMaPhieuSachTiengViet);
	}

	bool xoaPhieuSachNGoaiVan(string maPhieu)
	{
		return ds_phieuSachNgoaiVan.xoa(maPhieu, kiemTraMaPhieuSachNgoaiVan);
	}

	phieuMuonTra_sachTiengViet* timPhieuSachTiengViet(string maPhieu)
	{
		return ds_phieuSachTiengViet.timKiem(maPhieu, kiemTraMaPhieuSachTiengViet);
	}

	phieuMuonTra_sachNgoaiVan* timPhieuSachNgoaiVan(string maPhieu)
	{
		return ds_phieuSachNgoaiVan.timKiem(maPhieu, kiemTraMaPhieuSachNgoaiVan);
	}

	void Xuat_dsPhieuSachTiengViet()
	{
		ds_phieuSachTiengViet.xuat();
	}

	void Xuat_dsPhieuSachNgoaiVan()
	{
		ds_phieuSachNgoaiVan.xuat();
	}

	void suaThongTinPhieuMuon(phieuMuonTra* phieu, int lc)
	{
		if (lc == tt_phieu::ma_phieu)
		{
			cout << "\nMa phieu: ";
			cin.ignore();
			phieu->set_maPhieu();
		}
		else if (lc == tt_phieu::ma_doc_gia)
		{
			cout << "\nMa doc gia: ";
			cin.ignore();
			phieu->set_maDocGia();
		}
		else if (lc == tt_phieu::ngay_muon)
		{
			cout << "\nNgay muon: ";
			cin.ignore();
			phieu->set_ngayMuon();
		}
		else if (lc == tt_phieu::ma_sach_muon)
		{
			cout << "\nSach muon: ";
			cin.ignore();
			phieu->set_sachMuon();
		}
		
	}

	

	void Xuat_dsMuonSachTiengVietTreHan(DATE now)
	{
		int treHan;
		for (size_t i = 0; i < ds_phieuSachTiengViet.size(); i++)
		{
			 treHan = khoangCachNgay(ds_phieuSachTiengViet.at(i)->tinhNgayHetHan(), now);
			if (treHan > 0)
			{
				ds_phieuSachTiengViet.at(i)->xuat();
				cout << "\nTre han " << treHan << " ngay";
				cout << "\n\nTien phat tre han phai dong: " << ds_phieuSachTiengViet.at(i)->tinhTienPhat(now);
			}
		}
	}

	void Xuat_dsMuonSachNgoaiVanTreHan(DATE now)
	{
		for (size_t i = 0; i < ds_phieuSachNgoaiVan.size(); i++)
		{
			 int treHan = khoangCachNgay(ds_phieuSachNgoaiVan.at(i)->tinhNgayHetHan(), now);
			if (treHan > 0)
			{
				ds_phieuSachNgoaiVan.at(i)->xuat();
				cout << "\nTre han " << treHan << " ngay";
				cout << "\nTien phat tre han phai dong: " << ds_phieuSachNgoaiVan.at(i)->tinhTienPhat(now);
			}
		}
	}


	void File_themSachTiengViet(string tenFile,sachTiengViet* x)
	{
		fstream fo(tenFile+".csv", ios::app);
		if (fo.fail())
		{
			cout << "\nLoi khong mo duoc file";
			return;
		}
		else
		{
			// neu file rong thi ghi may chu nay vao
			/*if (isFileEmpty)
			{
				fo << "ma sach,ten sach,tac gia,NXB,gia sach" << endl;
				isFileEmpty = false;
			}	*/			
				fo << x->get_maSach() << "," << x->get_tenSach() << "," << x->get_tacGia() << "," << x->get_nhaXuatBan() << "," << x->get_giaSach() << endl;
			
		}
		fo.close();
	}

	void File_themSachNgoaiVan(string tenFile, sachNgoaiVan* x)
	{
		fstream fo(tenFile + ".csv", ios::app);
		if (fo.fail())
		{
			cout << "\nLoi khong mo duoc file";
			return;
		}
		else
		{
			// neu file rong thi ghi may chu nay vao
			/*if (isFileEmpty)
			{
				fo << "ma sach,ten sach,tac gia,NXB,gia sach,ISBN"<< endl;
			}	*/
				fo << x->get_maSach() << "," << x->get_tenSach() << "," << x->get_tacGia() << "," << x->get_nhaXuatBan() << "," << x->get_giaSach() << ","<<x->get_ISBN()<<endl;		
		}
		fo.close();
	}

	void File_themDocGia(string tenFile, DocGia* x)
	{
		fstream fo(tenFile + ".csv", ios::app);
		if (fo.fail())
		{
			cout << "\nLoi khong mo duoc file";
			return;
		}
		else
		{
			// neu file rong thi ghi may chu nay vao
			/*if (isFileEmpty)
			{
			fo << "ma sach,ten sach,tac gia,NXB,gia sach,ISBN"<< endl;
			}	*/
			fo << x->get_maDocGia() << "," << x->get_hoTen() << "," << x->get_CMND() << "," << x->get_ngaySinh2() << "," << x->get_ngayLapThe2() << endl;
		}
		fo.close();
	}

	void File_themPhieu(string tenFile, phieuMuonTra* x)
	{
		fstream fo(tenFile + ".csv", ios::app);
		if (fo.fail())
		{
			cout << "\nLoi khong mo duoc file";
			return;
		}
		else
		{
			// neu file rong thi ghi may chu nay vao
			/*if (isFileEmpty)
			{
			fo << "ma sach,ten sach,tac gia,NXB,gia sach,ISBN"<< endl;
			}	*/
			fo << x->get_maPhieu() << "," << x->get_maDocGia() << "," << x->get_ngayMuon() << "," << x->get_ngayHetHan() << "," << x->get_sachMuon() << endl;
		}
		fo.close();
	}

	void update_File_sach(string maSach)
	{

	}
};

 

#endif __THUVIEN_H__




