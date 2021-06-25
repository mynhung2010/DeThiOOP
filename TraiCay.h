#pragma once
#include "MatHang.h"

class TraiCay:public MatHang
{
private: 
	string XuatXu;
public:
	TraiCay();
	~TraiCay();
	friend void NhapNgay(Ngay&);
	friend void XuatNgay(Ngay);
	void Nhap();
	void Xuat();
	friend int Stt(Ngay);
	bool ktHetHan(Ngay);
	bool ktGiamGia(Ngay);
	void CapNhatGia(Ngay);
};

