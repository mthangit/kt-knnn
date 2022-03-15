
#include <iostream>
using namespace std;

struct Date
{
	int Ngay;
	int Thang;
	int Nam;
};

bool KiemTraNam(int a)
{
	if (a % 400 == 0 || (a % 4 == 0 && a % 100 != 0))
		return true;
	else
		return false;
}

int SoNgayTrongThang(Date a)
{
	switch (a.Thang)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		return 31;
		break;
	}
	case 4:
	case 6:
	case 9:
	case 11:
	{
		return 30;
		break;
	}
	case 2:
	{
		if (KiemTraNam(a.Nam) == true)
		{
			return 29;
			break;
		}
		else
		{
			return 28;
			break;
		}
	}
	}
}

void NhapNgayThangNam(Date &a)
{
	cout << "Nhap ngay: ";
	cin >> a.Ngay;
	cout << "Nhap thang: ";
	cin >> a.Thang;
	cout << "Nhap nam: ";
	cin >> a.Nam;
}

void KiemTraTinhHople(Date &a)
{
	while (a.Ngay < 0 || a.Ngay > 31 || a.Thang > 12 || a.Thang < 0 || a.Nam < 0 || a.Ngay > SoNgayTrongThang(a))
	{
		cout << "Nhap sai, vui long nhap lai: " << "\n";
		cout << "Nhap ngay: ";
		cin >> a.Ngay;
		cout << "Nhap thang: ";
		cin >> a.Thang;
		cout << "Nhap nam: ";
		cin >> a.Nam;
	}
}
void XuatNgayThangNam(Date a)
{
	cout << a.Ngay << "/" << a.Thang << "/" << a.Nam << "\n";
}

Date NgayTiepTheo(Date &a)
{
	a.Ngay += 1;
	if (a.Ngay <= SoNgayTrongThang(a))
		return a;
	else
	{
		a.Ngay = 1;
		a.Thang += 1;
		if (a.Thang > 12)
		{
			a.Thang = 1;
			a.Nam += 1;
		}
	}
	return a;
}

int main()
{
	Date a;
	NhapNgayThangNam(a);
	KiemTraTinhHople(a);
	XuatNgayThangNam(a);
	XuatNgayThangNam(NgayTiepTheo(a));
}