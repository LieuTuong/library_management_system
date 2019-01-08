//#include"thuVien.h"
//
//thuVien::~thuVien()
//{
//	for (auto& x : ds_docGia)
//		delete x;
//	for (auto& x : ds_Sach)
//		delete x;
//	for (auto& x : ds_phieuMuonTra)
//		delete x;
//}
//
//DocGia* thuVien::timDocGiaQuaMaDocGia(string ma)
//{
//	for (auto& x : ds_docGia)
//	{
//		if (x->get_maDocGia() == ma)
//			return x;		
//	}
//	return NULL;
//}
//
//void thuVien::themDocGia()
//{	
//	ds_docGia.push_back(new DocGia);
//	ds_docGia.back()->nhap();	
//}
//
//int thuVien::xoaDocGia(string ma)
//{
//	int flag = 0;
//	for (size_t i = 0; i < ds_docGia.size(); i++)
//	{
//		if (ds_docGia[i]->get_maDocGia() == ma)
//		{
//			ds_docGia.erase(ds_docGia.begin() + i);
//			flag = 1;
//			break;
//		}
//	}
//	return flag;
//}
//
//void thuVien::danhSachDocGia()
//{
//	for (auto& x : ds_docGia)
//	{
//		x->xuat();
//	}
//}
//
//void thuVien::themSach(int lc)
//{	
//	ds_Sach.push_back(sachFactory::newSach(lc));
//	ds_Sach.back()->nhap();
//}
//
//
//int thuVien::xoaSach(string maSach,int lc)
//{
//	int flag = 0;
//	if (lc==1)
//	for (size_t i = 0; i < ds_Sach.size(); i++)
//	{				
//			if (ds_Sach[i]->get_maSach() == maSach&& dynamic_cast<sachTiengViet*>(ds_Sach[i]))
//			{
//				ds_Sach.erase(ds_Sach.begin() + i);
//				flag = 1;
//				break;
//			}						
//	}
//	else if (lc == 2)
//	{
//		for (size_t i = 0; i < ds_Sach.size(); i++)
//		{
//			if (ds_Sach[i]->get_maSach() == maSach&& dynamic_cast<sachNgoaiVan*>(ds_Sach[i]))
//			{
//				ds_Sach.erase(ds_Sach.begin() + i);
//				flag = 1;
//				break;
//			}
//		}
//	}
//	return flag;
//}
//
//SACH* thuVien::timKiemSachQuaMaSach(string maSach)
//{
//	for (auto& x : ds_Sach)
//	{
//		if (x->get_maSach() == maSach)
//			return x;
//	}
//	return NULL;
//}
//
//void thuVien::danhSachSach()
//{
//	for (auto& x : ds_Sach)
//	{
//		x->xuat();
//	}
//}
//
//void thuVien::themPhieu(int loaiPhieu)
//{	
//	ds_phieuMuonTra.push_back(phieuFactory::newPhieu(loaiPhieu));
//	ds_phieuMuonTra.back()->nhap();
//}
//
//int thuVien::xoaPhieu(string maDocGia)
//{
//	int flag = 0;
//	for (size_t i = 0; i < ds_phieuMuonTra.size(); i++)
//	{
//		if (ds_phieuMuonTra[i]->get_maDocGia() == maDocGia)
//		{
//			ds_phieuMuonTra.erase(ds_phieuMuonTra.begin() + i);
//			flag = 1;
//			break;
//		}
//	}
//	return flag;
//}
//
//phieuMuonTra* thuVien::timKiemPhieuMuon(string maDocGia)
//{
//	for (auto& x : ds_phieuMuonTra)
//	{
//		if (x->get_maDocGia() == maDocGia)
//			return x;
//	}
//	return NULL;
//}
//
//void thuVien::danhSachPhieuMuon()
//{
//	for (auto& x : ds_phieuMuonTra)
//		x->xuat();
//}
//
////int thuVien::tinhTienTreHan(string maDocGia,DATE now)
////{
////	int tienPhat = 0;
////	for (auto& x : ds_phieuMuonTra)
////	{
////		if (x->get_maDocGia() == maDocGia)
////		{
////			tienPhat = x->tinhTienPhat(now);
////		}
////	}
////	return tienPhat;
////}
//
//void thuVien::danhSachTreHan(DATE now)
//{
//	for (auto& x : ds_phieuMuonTra)
//	{
//		DATE ngayHetHan = x->tinhNgayHetHan();
//		int soNgayTreHan = khoangCachNgay(ngayHetHan, now);
//		if (soNgayTreHan > 0)
//		{
//			x->xuat();
//			cout << "\nTien phat la: "<<x->tinhTienPhat(now);
//		}
//	}
//}
//
//void thuVien::suaThongTinSach(int loaiSach,string maSach, int mucCanSua)
//{
//	if (mucCanSua == 1)
//	{
//		cout << "\nMa sach: ";
//		
//	}
//	else if (mucCanSua == 2)
//	{
//		cout << "\nTen sach: ";
//		
//	}
//	else if (mucCanSua == 3)
//	{
//		cout << "\nTac gia: ";
//		
//	}
//	else if (mucCanSua == 4)
//	{
//		cout << "\nNha xuat ban: ";
//		
//	}
//	else if (mucCanSua == 5)
//	{
//		cout << "\nGia sach: ";
//		
//	}
//	
//}
//
//
//
