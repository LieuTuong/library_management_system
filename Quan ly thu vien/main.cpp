#include"thuVien.h"

enum luaChon
{
	thoat=0,
	them_sach=1,
	xoa_sach=2,
	sua_sach=3,
	tim_kiem_sach=4,
	xuat_ds_sach=5,
	them_doc_gia=6,
	xoa_doc_gia=7,
	sua_thong_tin_doc_gia=8,
	tim_doc_gia=9,
	xuat_ds_doc_gia=10,
	them_phieu_muon=11,
	xoa_phieu_muon=12,
	sua_thong_tin_phieu_muon=13,
	tim_phieu_muon=14,
	xuat_ds_phieu_muon=15,
	xuat_ds_muon_sach_tre_han=16
};

void menu()
{
	cout << "\n0. Thoat.";
	cout << "\n1. Them sach";
	cout << "\n2. Xoa sach";
	cout << "\n3. Sua sach ";
	cout << "\n4. Tim kiem sach";
	cout << "\n5. Xuat tat ca sach trong thu vien";
	cout << "\n6. Them doc gia";
	cout << "\n7. Xoa doc gia";
	cout << "\n8. Sua thong tin doc gia";
	cout << "\n9. Tim kiem doc gia";
	cout << "\n10. Xuat danh sach doc gia";
	cout << "\n11. Them phieu muon";
	cout << "\n12. Xoa phieu muon";
	cout << "\n13. Sua phieu muon";
	cout << "\n14. Tim kiem phieu muon";
	cout << "\n15. Xuat tat ca danh sach phieu muon";
	cout << "\n11. Danh sach doc gia muon sach qua gioi han";
	cout << "\n-----------------------------------------------";
}

void menuSach()
{
	cout << "\n0. Thoat";
	cout << "\n1. Sach tieng viet";
	cout << "\n2. Sach ngoai van";
}

void menuPhieu()
{
	cout << "\n0. Thoat";
	cout << "\n1. Phieu cho sach tieng viet.";
	cout << "\n2. Phieu cho sach ngoai van.";
}

void menuSuaThongTinDocGia()
{
	cout << "\n0. Thoat";
	cout << "\n1. Sua ma doc gia";
	cout << "\n2. Sau ho ten";
	cout << "\n3. Sua CMND";
	cout << "\n4. Sua ngay sinh";
	cout << "\n5. Sua ngay lap the";
	cout << "\n-----------------------------------";
}

void menuSuaThongTinSach()
{
	cout << "\n0. Thoat";
	cout << "\n1. Sua ma sach";
	cout << "\n2. Sua ten sach";
	cout << "\n3. Sua ten tac gia";
	cout << "\n4. Sua nha xuat ban";
	cout << "\n5. Sua gia sach";
	cout << "\n6. Sua ISBN";
	cout << "\n-------------------------";
}

void menuSuaThongTinPhieu()
{
	cout << "\n0. Thoat";
	cout << "\n1. Sua ma phieu";
	cout << "\n2. Sua ma doc gia";
	cout << "\n3. Sua ngay muon (gia han ngay muon)";
	cout << "\n4. Sua sach muon";
	cout << "\n5. Sua tinh trang";
}

int main()
{
	thuVien tv;
	bool thanhCong;
	string maCanTra;
	int loai;
	while (1)
	{	
		system("cls");
		int lc;
		menu();
		cout << "\n\nNhap lua chon: "; cin >> lc;
		if (lc == thoat)
			break;
		else if (lc == them_sach)
		{
			while (1)
			{
				system("cls");
				menuSach();
				int loaiSach;
				cout << "\nNhap loai sach: "; cin >> loaiSach;
				if (loaiSach == thoat)
					break;
				else if (loaiSach == sach_tieng_viet)
				{
					system("cls");
					sachTiengViet* tmp = new sachTiengViet();
					cin.ignore();
					tmp->nhap();
					tv.themSach(tmp);

				}
				else if (loaiSach == sach_ngoai_van)
				{
					system("cls");
					sachNgoaiVan* tmp = new sachNgoaiVan();
					cin.ignore();
					tmp->nhap();
					tv.themSach(tmp);
				}
			}
			
			
		}
		else if (lc == xoa_sach)
		{		
			while (1)
			{
				system("cls");
				menuSach();
				int loaiSach;
				cout << "\nNhap loai sach muon xoa: "; cin >> loaiSach;
				if (loaiSach == thoat)
					break;
				else 
				{
					cout << "\n\nNhap ma sach can xoa: ";
					cin.ignore();
					getline(cin, maCanTra);
					if (loaiSach == sach_tieng_viet)
					{
						thanhCong=tv.xoaSachTiengViet(maCanTra);					
					}
					else if (loaiSach == sach_ngoai_van)
					{
						thanhCong = tv.xoaSachNgoaiVan(maCanTra);
					}
					if (thanhCong)
						cout << "\nDa xoa sach";
					else
						cout << "\nKhong tim thay sach trong thu vien.";
					system("pause");
				}
			}	
			
		}

		else if (lc == sua_sach)
		{
			SACH* x=NULL;
			while (1)
			{
				
				system("cls");
				menuSach();
				cout << "\nChon loai sach can sua: "; cin >> loai;
				if (loai == thoat) break;
				else
				{
					cout << "\nNhap ma sach can sua: ";
					cin.ignore();
					getline(cin, maCanTra);
					if (loai == sach_tieng_viet)
						 x = tv.timSachTiengViet(maCanTra);
					else if (loai == sach_ngoai_van)
						 x = tv.timSachNgoaiVan(maCanTra);
					if (x)
					{
						while (1)
						{
							system("cls");
							menuSuaThongTinSach();
							cout << "\nChon muc muon sua: "; cin >> loai;
							if (loai == thoat)break;
							else
							{
								tv.suaThongTinSach(x, loai);
							}						
						}
					}
					else cout << "\nKhong tim thay sach";
					system("pause");
				}
			}
		}

		else if (lc == tim_kiem_sach)
		{			
			SACH* sach=NULL;
			while (1)
			{
				system("cls");
				menuSach();
				cout << "\nNhap loai sach can tim: ";
				cin >> loai;
				if (loai == thoat)
					break;
				else
				{
					cout << "\nNhap ma sach can tim: ";
					cin.ignore();
					getline(cin, maCanTra);
					if (loai == sach_tieng_viet)
						sach = tv.timSachTiengViet(maCanTra);
					else if (loai == sach_ngoai_van)
						sach = tv.timSachNgoaiVan(maCanTra);		
					if (sach)
						sach->xuat();
					else cout << "\nKhong tim thay sach trong thu vien.";
					system("pause");
				}
			}
			
		}
		else if (lc == xuat_ds_sach)
		{
			system("cls");
			cout << "\n============== SACH TIENG VIET ===============";
			tv.Xuat_dsSachTiengViet();
			cout << "\n============== SACH NGOAI VAN ===============";
			tv.Xuat_dsSachNgoaiVan();
			system("pause");	
		}
		else if (lc == them_doc_gia)
		{
			system("cls");
			cin.ignore();
			DocGia* tmp = new DocGia;
			tmp->nhap();
			tv.themDocGia(tmp);
		}
		else if (lc == xoa_doc_gia)
		{
			system("cls");
			string maDocGiaMuonXoa;
			cout << "\nNhap ma doc gia muon xoa: ";
			cin.ignore();
			getline(cin, maCanTra);
			int thanhCong = tv.xoaDocGia(maCanTra);
			if (thanhCong)
				cout << "\nDa xoa doc gia";
			else
				cout << "\nKhong tim thay doc gia.";
			system("pause");		
		}
		else if (lc == sua_thong_tin_doc_gia)
		{
			system("cls");
			cout << "\nNhap ma doc gia can sua: ";
			cin.ignore();
			getline(cin, maCanTra);
			DocGia* find = tv.timDocGia(maCanTra);
			if (find)
			{
				while (1)
				{
					system("cls");
					menuSuaThongTinDocGia();
					cout << "\n\nNhap lua chon: "; cin >> loai;
					if (loai == thoat) break;
					tv.suaThongTinDocGia(find, loai);
				}
			}
			else cout << "\nKhong tim thay doc gia";
			system("pause");
		}
		else if (lc == tim_doc_gia)
		{
			system("cls");
			string maDocGia;
			cout << "\nNhap ma doc gia can tim: ";
			cin.ignore();
			getline(cin, maDocGia);
			DocGia* x = tv.timDocGia(maDocGia);
			if (x == NULL)
				cout << "\nKhong tim thay doc gia.";
			else
				cout << x;
			system("pause");
		}
		else if (lc == xuat_ds_doc_gia)
		{
			system("cls");
			tv.Xuat_dsDocGia();
			system("pause");
		}
		else if (lc ==them_phieu_muon)
		{
			int loaiPhieu;
			while (1)
			{
				system("cls");
				menuPhieu();
				cout << "\n\nNhap lua chon: "; cin >> loaiPhieu;
				if (loaiPhieu == thoat)
					break;
				else if (loaiPhieu == phieu_sach_tieng_viet)
				{
					phieuMuonTra_sachTiengViet* tmp = new phieuMuonTra_sachTiengViet();
					cin.ignore();
					tmp->nhap();
					tv.themPhieu(tmp);
				}
				else if (loaiPhieu == phieu_sach_ngoai_van)
				{
					phieuMuonTra_sachNgoaiVan* tmp = new phieuMuonTra_sachNgoaiVan();
					cin.ignore();
					tmp->nhap();
					tv.themPhieu(tmp);
				}
			}
			
		}
		else if (lc == xoa_phieu_muon)
		{		
			while (1)
			{
				system("cls");
				menuPhieu();
				cout << "\n\nChon loai phieu: "; cin >> loai;
				if (loai == thoat)
					break;
				else
				{
					cout << "\nNhap ma phieu can xoa: ";
					cin.ignore();
					getline(cin, maCanTra);
					if (loai == phieu_sach_tieng_viet)
						thanhCong=tv.xoaPhieuSachTiengViet(maCanTra);
					else if (loai == phieu_sach_ngoai_van)
						thanhCong=tv.xoaPhieuSachNGoaiVan(maCanTra);

					if (thanhCong)
						cout << "\nDa xoa phieu";
					else cout << "\nKhong tim thay phieu thich hop";
					system("pause");
				}
			}
		}
		else if (lc == sua_thong_tin_phieu_muon)
		{
			phieuMuonTra* find=NULL;
			while (1)
			{
				system("cls");
				menuPhieu();
				cout << "\nChon loai phieu muon sua: "; cin >> loai;
				if (loai == thoat)break;
				else
				{
					cout << "\nNhap ma phieu muon sua: ";
					cin.ignore();
					getline(cin, maCanTra);
					if (loai == phieu_sach_tieng_viet)
						find = tv.timPhieuSachTiengViet(maCanTra);
					else if (loai == phieu_sach_ngoai_van)
						find = tv.timPhieuSachNgoaiVan(maCanTra);
					if (find)
					{
						while (1)
						{
							system("cls");
							menuSuaThongTinPhieu();
							cout << "\nChon muc muon sua: "; cin >> loai;
							if (loai == thoat)break;
							else
							{
								tv.suaThongTinPhieuMuon(find, loai);
							}
						}
					}
					else cout << "\nKhong tim thay phieu.";
					system("pause");
					
				}
			}
		}
		else if (lc == tim_phieu_muon)
		{
			phieuMuonTra* find = NULL;
			while (1)
			{
				system("cls");
				menuPhieu();
				cout << "\n\nChon loai phieu: "; cin >> loai;
				if (loai == thoat)
					break;
				else
				{
					cout << "\n\nNhap ma phieu can tim: ";
					getline(cin, maCanTra);
					if (loai == phieu_sach_tieng_viet)
						find = tv.timPhieuSachTiengViet(maCanTra);
					else if (loai == phieu_sach_ngoai_van)
						find = tv.timPhieuSachNgoaiVan(maCanTra);

					if (thanhCong)
						cout << find;
					else
						cout << "\nKhong tim thay phieu.";
					system("pause");
					
				}
			}
		}
		else if (lc == xuat_ds_phieu_muon)
		{
			system("cls");
			tv.Xuat_dsPhieuSachNgoaiVan();
			tv.Xuat_dsPhieuSachTiengViet();
			system("pause");
		}
		else if (lc == xuat_ds_muon_sach_tre_han)
		{
			while (1)
			{
				menuPhieu();
				cout << "\nChon loai phieu: "; cin >> loai;
				if (loai == 0)break;
				else
				{
					DATE now;
					cout << "\nNhap ngay hom nay: "; now.nhap();
					if (loai == phieu_sach_tieng_viet)
						tv.Xuat_dsMuonSachTiengVietTreHan(now);
					else if (loai == phieu_sach_ngoai_van)
						tv.Xuat_dsMuonSachNgoaiVanTreHan(now);
					system("pause");
				}
			}
		}
	}
}