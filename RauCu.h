#pragma once
#include "MatHang.h"
class RauCu:public MatHang
{
private: 
	Ngay NgayThuHoach;
public:
	RauCu();
	~RauCu();
	friend void NhapNgay(Ngay&);
	friend void XuatNgay(Ngay);
	void Nhap();
	void Xuat();
	bool ktHetHan(Ngay);
	friend int Stt(Ngay);
	bool ktGiamGia(Ngay);
	void CapNhatGia(Ngay);
};

