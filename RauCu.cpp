#include "RauCu.h"
#include "MatHang.h"

void NhapNgay(Ngay& a)
{
	cout << "Nhap ngay: ";
	cin >> a.ng;
	cout << "Nhap thang: ";
	cin >> a.th;
	cout << "Nhap nam: ";
	cin >> a.nm;
}

void XuatNgay(Ngay a)
{
	cout << a.ng << " / " << a.th << " / " << a.nm;
}

RauCu::RauCu()
{
	NgayThuHoach.ng = NgayThuHoach.th = NgayThuHoach.nm = 1;

}

RauCu::~RauCu()
{

}

void RauCu::Nhap()
{
	MatHang::Nhap();
	cout << "Nhap ngay thu hoach: ";
	NhapNgay(NgayThuHoach);

}

void RauCu::Xuat()
{
	MatHang::Xuat();
	cout << "\nNgay thu hoach: ";
	XuatNgay(NgayThuHoach);

}

bool RauCu::ktHetHan(Ngay d)
{
	int s1 = Stt(this->NgayTrungBay);
	int s2 = Stt(d);
	if ((s2 - s1) > 3)
		return true;
	return false;
}

bool RauCu::ktGiamGia(Ngay d)
{
	int s1 = Stt(this->NgayTrungBay);
	int s2 = Stt(d);
	if ((s2 - s1) > 2)
		return true;
	return false;
}

void RauCu::CapNhatGia(Ngay d)
{
	if (this->ktGiamGia(d))
		Gia = Gia - Gia * 0.2;
}



