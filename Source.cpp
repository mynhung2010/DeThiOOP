#include"MatHang.h"
#include"RauCu.h"
#include "TraiCay.h"


void NhapDS(MatHang* ds[100], int n)
{
	for (int i = 0; i < n; i++)
	{
		int luachon;
		cout << "Bang lua chon: " << endl;
		cout << "1. Rau cu." << endl;
		cout << "2. Trai cay." << endl;
		cout << "Nhap lua chon: ";
		cin >> luachon;

		switch (luachon)
		{
		case 1:
		{
			ds[i] = new RauCu();
			cout << "Nhap thong tin mat hang thu " << i + 1 << ": ";
			ds[i]->Nhap();
			break;
		}
		case 2:
		{
			ds[i] = new TraiCay();
			cout << "Nhap thong tin mat hang thu " << i + 1 << ": ";
			ds[i]->Nhap();
			break;
		}
		default:
			break;
		}
	}
}

int main()
{
	MatHang* ds[100];
	MatHang M;
	int n;
	Ngay D;
	int option;
	do
	{
		cout << "\n0.Thoat chuong trinh.";
		cout << "\n1.Nhap danh sach.";
		cout << "\n2.Xu ly het han.";
		cout << "\n3.Cap nhat gia.";
		cout << "\nNhap chuc nang: ";
		cin >> option;
		switch (option)
		{
		case 1:
		{
			cout << "Nhap vao so luong mat hang: ";
			cin >> n;
			NhapDS(ds, n);
			break;
		}
		case 2:
		{
			cout << "\nNhap ngay hien tai: ";
			cout << "\nNhap ngay: ";
			cin >> D.ng;
			cout << "\nNhap thang: ";
			cin >> D.th;
			cout << "\nNhap nam: ";
			cin >> D.nm;

			for (int i = 0; i < n; i++)
				if (ds[i]->ktHetHan(D))
				{
					ds[i]->Xuat();
					cout << "\nNgay het han: ";
					ds[i]->XuatNgayHetHan(D);
				
				}
			break;
		}
		case 3:
		{
			cout << "\nMat hang duoc giam gia: ";
			for (int i = 0; i < n; i++)
				if (ds[i]->ktGiamGia(D))
				{
					cout << "Ma hang: " << ds[i]->getMaHang() << endl;
					cout << "Ten hang: " << ds[i]->getTenHang() << endl;
					cout << "Ngay trung bay: ";
					Ngay tb = ds[i]->getNgayTrungBay();
					cout << tb.ng << "/" << tb.th << "/"<<tb.nm;
					cout << "\nNgay het han: ";
					ds[i]->XuatNgayHetHan(D);
					cout << "\nGia truoc khi giam: " << ds[i]->getGia() << endl;
					ds[i]->CapNhatGia(D);
					cout << "Gia sau khi giam: " << ds[i]->getGia() << endl;
				}
			break;
		}
		default:
			break;
		}
	} while (option != 0);
	return 0;
}