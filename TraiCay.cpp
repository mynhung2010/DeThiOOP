#include "TraiCay.h"
#include "MatHang.h"

TraiCay::TraiCay()
{
	XuatXu = '\0';

}

TraiCay::~TraiCay()
{
}

void TraiCay::Nhap()
{
	MatHang::Nhap();
	cin.ignore();
	cout << "Nhap xuat xu: ";
	getline(cin, XuatXu);
}

void TraiCay::Xuat()
{
	MatHang::Xuat();
	cout << "\nXuat xu: " << XuatXu;
}

bool TraiCay::ktHetHan(Ngay d)
{
	int s1 = Stt(this->NgayTrungBay);
	int s2 = Stt(d);
	if ((s2 - s1) > 10)
		return true;
	return false;
}

bool TraiCay::ktGiamGia(Ngay d)
{
	int s1 = Stt(this->NgayTrungBay);
	int s2 = Stt(d);
	if ((s2 - s1) > 7)
		return true;
	return false;
}

void TraiCay::CapNhatGia(Ngay d)
{
		if (this->ktGiamGia(d))
		Gia = Gia - Gia * 0.2;
}

