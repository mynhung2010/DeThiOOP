#pragma once
#include<iostream>
#include<string>
using namespace std;

struct Ngay
{
	int ng;
	int th;
	int nm;
};

class MatHang
{
protected:
	string MaHang;
	string TenHang;
	float Gia;
	Ngay NgayTrungBay;
public:
	MatHang();
	string getMaHang()
	{
		return MaHang;
	}
	string getTenHang()
	{
		return TenHang;
	}
	float getGia()
	{
		return Gia;
	}
	Ngay getNgayTrungBay()
	{
		return NgayTrungBay;
	}
	friend void NhapNgay(Ngay&);
	friend void XuatNgay(Ngay);
	friend int ktNhuan(Ngay);
	friend int SoNgayToiDaTrongThang(Ngay);
	friend int SoNgayToiDaTrongNam(Ngay);
	friend int SttTrongNam(Ngay);
	friend int Stt(Ngay);
	friend Ngay TimNgay(int, int);
	friend Ngay TimNgay(int);
	friend int SttTrongNam(Ngay);
	virtual void Nhap();
	virtual void Xuat();
	virtual bool ktHetHan(Ngay)
	{
		return false;
	}
	virtual void XuatNgayHetHan(Ngay);
	virtual bool ktGiamGia(Ngay) { return false; }
	virtual void CapNhatGia(Ngay) { }
	~MatHang(){}
};


