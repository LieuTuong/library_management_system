#include"DATE.h"

DATE::DATE()
{
	ngay = thang = nam = 0;
}

DATE::DATE(int ngay, int thang, int nam)
{
	this->ngay = ngay;
	this->thang = thang;
	this->nam = nam;
}

void DATE::set_ngay()
{
	do{
		cin >> ngay;
		if (ngay > 31||ngay <0){
			cout << "\nNgay khong hop le. Moi nhap lai.";
		}
	} while (ngay>31 || ngay < 0);
}

void DATE::set_thang()
{
	do{
		cin >> thang;
		if (thang > 12 || thang < 1)
		{
			cout << "\nKhong hop le. Moi nhap lai.";
		}
	} while (thang>12 || thang < 1);
}

void DATE::set_nam()
{
	do{
		cin >> nam;
		if (nam < 0)
		{
			cout << "\nKhong hop le. Moi nhap lai.";
		}
	} while (nam < 0);
}

int DATE::get_ngay()
{
	return ngay;
}

int DATE::get_thang()
{
	return thang;
}

int DATE::get_nam()
{
	return nam;
}

bool laNamNhuan(int nam)
{
	return  (nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0);		
}

int tinhSoNgayTrongThang(int thang,int nam)
{
	int soNgay=0;
	switch (thang)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		soNgay = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		soNgay = 30;
		break;
	case 2:
		if (laNamNhuan(nam))
			soNgay = 29;
		else
			soNgay = 28;
		break;
	default:
		break;
	}
	return soNgay;
}

bool laNgayHopLe(int ngay, int thang,int nam)
{
	if (ngay > tinhSoNgayTrongThang(thang,nam))
		return false;
	return true;
}

void DATE::nhap()
{
	do{
		cout << "\n\tNhap ngay: "; set_ngay();
		cout << "\n\tNhap thang: "; set_thang();
		cout << "\n\tNhap nam: "; set_nam();
		if (laNgayHopLe(ngay, thang, nam) == false)
		{
			cout << "\nKhong hop le. Moi nhap lai.";
		}
	} while (laNgayHopLe(ngay, thang, nam)==false);
}

void DATE::xuat()
{
	cout << ngay << "/" << thang << "/" << nam;
}

//ostream& operator<<(ostream& outDev, const DATE& x)
//{
//	outDev <<"\n" <<x.ngay << "/" << x.thang << "/" << x.nam;
//	return outDev;
//}

int offsetDays(int d, int m, int y)
{
	int offset = d;
	switch (m - 1)
	{
	case 11:
		offset += 30;
	case 10:
		offset += 31;
	case 9:
		offset += 30;
	case 8:
		offset += 31;
	case 7:
		offset += 31;
	case 6:
		offset += 30;
	case 5:
		offset += 31;
	case 4:
		offset += 30;
	case 3:
		offset += 31;
	case 2:
		offset += 28;
	case 1:
		offset += 31;
	}

	if (laNamNhuan(y) && m > 2)
		offset += 1;

	return offset;
}

void revoffsetDays(int offset, int y, int *d, int *m)
{
	int i;
	for (i = 1; i <= 12; i++)
	{
		if (offset <= tinhSoNgayTrongThang(i, y))
			break;
		offset = offset - tinhSoNgayTrongThang(i, y);
	}
	*d = offset;
	*m = i;
}

DATE DATE::tinhNgayHetHan(int hanNgay)
{
	DATE ngayHetHan(*this);
	int offset1 = offsetDays(ngayHetHan.ngay, ngayHetHan.thang, ngayHetHan.nam);
	int remDays = laNamNhuan(ngayHetHan.nam) ? (366 - offset1) : (365 - offset1);

	int offset2 = 0;
	if (hanNgay <= remDays)
	{
		ngayHetHan.nam = nam;
		offset2 += hanNgay;
	}
	else
	{
		hanNgay -= remDays;
		ngayHetHan.nam = nam + 1;
		int SoNgayCuaNamHetHan = laNamNhuan(ngayHetHan.nam) ? 366 : 365;
		while (hanNgay >= SoNgayCuaNamHetHan)
		{
			hanNgay -= SoNgayCuaNamHetHan;
			ngayHetHan.nam++;
			SoNgayCuaNamHetHan = laNamNhuan(ngayHetHan.nam) ? 366 : 365;
		}

		offset2 = hanNgay;
	}


	revoffsetDays(offset2, ngayHetHan.nam, &ngayHetHan.ngay, &ngayHetHan.thang);
	return ngayHetHan;
}

int demNamNhuan(DATE d)
{
	int nam = d.get_nam();
	if (d.get_thang() <= 2)
		nam--;
	return nam / 4 - nam / 100 + nam / 400;
}

int khoangCachNgay(DATE d1, DATE d2)
{
	int n1 = d1.get_nam() * 365 + d1.get_ngay();

	for (int i = 0; i < d1.get_thang() - 1; i++)
	{
		n1 += tinhSoNgayTrongThang(i, d1.get_nam());
	}

	n1 += demNamNhuan(d1);

	int n2 = d2.get_nam() * 365 + d2.get_ngay();
	for (int i = 0; i < d2.get_thang(); i++)
	{
		n2 += tinhSoNgayTrongThang(i, d2.get_nam());
	}
	n2 += demNamNhuan(d2);

	return n2 - n1;
}