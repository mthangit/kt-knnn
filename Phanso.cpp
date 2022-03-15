
#include <iostream>
#include <cmath>
using namespace std;

struct PhanSo
{
	int TuSo;
	int MauSo;
};
void NhapPhanSo(PhanSo &ps) // Hàm nhập Phân Số
{
	cout << "Nhap tu so: ";
	cin >> ps.TuSo;

	cout << "Nhap mau so: ";
	cin >> ps.MauSo;
}
void XuatPhanSo(PhanSo ps) // Hàm xuất Phân Số
{
	if (ps.MauSo == 1)
		cout << ps.TuSo;

	else
		cout << ps.TuSo << "/" << ps.MauSo << "\n";
}
float UCLN(int a, int b) // Tìm Ước chung lớn nhất
{
	a = abs(a);
	b = abs(b);
	while (a * b != 0)
	{
		if (a > b)
			a -= b;

		else
			b -= a;
	}
	return a + b;
}
PhanSo RutGonPhanSo(PhanSo &ps) // Rút gọn phân số
{
	int ucln = UCLN(ps.TuSo, ps.MauSo);

	ps.TuSo = ps.TuSo / ucln;

	ps.MauSo = ps.MauSo / ucln;

	if (ps.MauSo < 0)
	{
		ps.TuSo = -ps.TuSo;
		ps.MauSo = -ps.MauSo;
	}
	return ps;
}
PhanSo TimPhanSolonNhat(PhanSo ps1, PhanSo ps2) // Tìm phân số lớn nhất
{
	float phanso1 = (float)ps1.TuSo / ps1.MauSo;

	float phanso2 = (float)ps2.TuSo / ps2.MauSo;

	if (phanso1 > phanso2)
		return ps1;

	else
		return ps2;
}
PhanSo TongHaiPhanSo(PhanSo ps1, PhanSo ps2)
{
	PhanSo tong;

	tong.TuSo = (ps1.TuSo * ps2.MauSo) + (ps2.TuSo * ps1.MauSo);

	tong.MauSo = ps1.MauSo * ps2.MauSo;

	return RutGonPhanSo(tong);
}

PhanSo HieuHaiPhanSo(PhanSo ps1, PhanSo ps2)
{
	PhanSo hieu;

	hieu.TuSo = (ps1.TuSo * ps2.MauSo) - (ps2.TuSo * ps1.MauSo);

	hieu.MauSo = ps1.MauSo * ps2.MauSo;

	return RutGonPhanSo(hieu);
}

PhanSo TichHaiPhanSo(PhanSo ps1, PhanSo ps2)
{
	PhanSo tich;
	tich.TuSo = ps1.TuSo * ps2.TuSo;

	tich.MauSo = ps1.MauSo * ps2.MauSo;

	return RutGonPhanSo(tich);
}

PhanSo ThuongHaiPhanSo(PhanSo ps1, PhanSo ps2)
{
	PhanSo thuong;

	thuong.TuSo = ps1.TuSo * ps2.MauSo;

	thuong.MauSo = ps1.MauSo * ps2.TuSo;

	return RutGonPhanSo(thuong);
}
int main()
{
	PhanSo ps1, ps2;
	cout << "Nhap Phan So thu nhat: " << "\n";
	NhapPhanSo(ps1);
	// Câu 1
	cout << "Phan so sau khi rut gon la: ";
	XuatPhanSo(RutGonPhanSo(ps1));
	// Câu 2
	cout << "Nhap Phan so thu hai: ";
	NhapPhanSo(ps2);
	
	cout << "Phan so lon nhat la: ";
	XuatPhanSo(TimPhanSolonNhat(ps1, ps2));
	// Câu 3
	cout << "Tong 2 phan so: ";
	XuatPhanSo(TongHaiPhanSo(ps1, ps2));

	cout << "Hieu 2 phan so: ";
	XuatPhanSo(HieuHaiPhanSo(ps1, ps2));

	cout << "Tich 2 phan so: ";
	XuatPhanSo(TichHaiPhanSo(ps1, ps2));

	cout << "Thuong 2 phan so: ";
	XuatPhanSo(ThuongHaiPhanSo(ps1, ps2));
	return 0;
}