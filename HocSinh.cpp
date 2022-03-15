
#include <iostream>
#include <string>
using namespace std;

struct HocSinh
{
	string HoTen;
	double DiemToan;
	double DiemVan;
};

void NhapHocSinh(HocSinh &hs1)
{
	cout << "Nhap ten Hoc Sinh: ";
	getline(cin, hs1.HoTen);
	cout << "Nhap diem Toan: ";
	cin >> hs1.DiemToan;
	cout << "Nhap diem Van: ";
	cin >> hs1.DiemVan;
}

double DTB(HocSinh hs1)
{
	return (hs1.DiemToan + hs1.DiemVan) / 2;
}

void XuatHocSinh(HocSinh hs1)
{
	cout << "Ho va Ten: ";
	cout << hs1.HoTen << "\n";
	cout << "Diem Toan: ";
	cout << hs1.DiemToan << "\n";
	cout << "Diem Van: ";
	cout << hs1.DiemVan << "\n";
	cout << "Diem Trung Binh: " << DTB(hs1);
}

int main()
{
	HocSinh hs1;
	NhapHocSinh(hs1);
	XuatHocSinh(hs1);
	return 0;
}