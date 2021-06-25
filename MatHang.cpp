#include "MatHang.h"
int ktNhuan(Ngay d)
{
	if (d.nm % 4 == 0 && d.nm & 100 != 0)
		return 1;
	if (d.nm % 400 == 0)
		return 1;
	return 0;
}
int SoNgayToiDaTrongThang(Ngay d)
{
	int sum[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (ktNhuan(d))
		sum[1] = 29;
	return sum[d.th - 1];
}
int SttTrongNam(Ngay d)
{
	int stt = 0;
	for (int i = 0; i <= d.th - 1; i++)
	{
		Ngay temp = { 1,i,d.nm };
		stt += SoNgayToiDaTrongThang(temp);
	}
	return (stt + d.ng);
}
int SoNgayToiDaTrongNam(Ngay d)
{
	if (ktNhuan(d))
		return 366;
	return 365;
}

int Stt(Ngay d)
{
	int stt = 0;
	for (int i = 0; i <= d.nm - 1; i++)
	{
		Ngay temp = { 1,1,i };
		stt += SoNgayToiDaTrongNam(temp);
	}
	return stt + SttTrongNam(d);
}

Ngay TimNgay(int nam, int stt)
{
	Ngay temp = { 1,1,nam };
	temp.th = 1;
	while (stt - SoNgayToiDaTrongThang(temp) > 0)
	{
		stt = stt - SoNgayToiDaTrongThang(temp);
		temp.th++;
	}
	temp.ng = stt;
	return temp;
}

Ngay TimNgay(int stt)
{
	int nam = 1;
	int sn = 365;
	while (stt - sn > 0)
	{
		stt = stt - sn;
		nam++;
		Ngay temp = { 1,1,nam };
		sn = SoNgayToiDaTrongNam(temp);
	}
	return TimNgay(nam, stt);
}


void NhapNgay(Ngay& d)
{
	cout << "Nhap ngay: ";
	cin >> d.ng;
	cout << "Nhap thang: ";
	cin >> d.th;
	cout << "Nhap nam: ";
	cin >> d.nm;
}
void XuatNgay(Ngay& d)
{
	cout << d.ng << " / " << d.th << " / " << d.nm;
}


MatHang::MatHang()
{
	MaHang = TenHang = '\0';
	Gia = 0;

}

void MatHang::Nhap()
{
	cin.ignore();
	cout << "\nNhap ma hang: ";
	getline(cin, MaHang);
	cout << "Nhap ten hang: ";
	getline(cin, TenHang);
	cout << "Nhap gia: ";
	cin >> Gia;
	cout << "Nhap ngay trung bay: ";
	NhapNgay(NgayTrungBay);


}

void MatHang::Xuat()
{
	cout << "Ma hang: " << MaHang;
	cout << "Ten mat hang: " << TenHang;
	cout << "Gia: " << Gia;
	cout << "Ngay trung bay: ";
	XuatNgay(NgayTrungBay);

}

void MatHang::XuatNgayHetHan(Ngay d)
{
	if (ktHetHan(d))
		NgayTrungBay.ng += 3;
	int stt = Stt(NgayTrungBay);
	Ngay kq = TimNgay(stt);
	XuatNgay(kq);
}