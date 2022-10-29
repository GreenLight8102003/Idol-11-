#include <iostream>
using namespace std;

// Xây dựng class danh sách Admin

	// Xây dựng class Admin
	class Admin
	{

	public:
		string Username;
		string Password;

	public:
	
	// Hàm khởi tạo
	Admin(string Username = "", string Password = "")
	{
		this->Username = Username;
		this->Password = Password;
	}


	// Quá tải toán tử >> cho Admin
	friend istream& operator >> (istream& is, Admin& a)
	{
		is >> a.Username;
		is >> a.Password;
		return is;
	}

	// Quá tải toán tử == cho Admin
	bool operator == (Admin x)
	{
		return Username == x.Username && Password == x.Password;
	}

};

// Xây dựng class danh sách Admin
class DanhSachAdmin
{

	public:
		Admin a[100];
		int SoLuong;

	public:


};

// Xây dựng lớp Employee
class Employee
{
public:

	//  Khai báo các thuộc tính Employee
	string Username;
	string Password;
	bool DangNhapLanDau;

public:

	Employee(string Username = "",
			 string Password = "")
	{
		this->Username = Username;
		this->Password = Password;
	}

	// Quá tải toán tử >> cho Employee
	friend istream& operator >> (istream& is, Employee& a)
	{
		is >> a.Username;
		is >> a.Password;
		return is;
	}

	// Quá tải toán tử == cho Employee
	bool operator == (Employee a)
	{
		return Username == a.Username && Password == a.Password;
	}

};

// Xây dựng lớp DanhSachEmployee
class DanhSachEmployee
{
public:

	Employee a[100];    // Danh sách các Employee
	int SoLuong;		// Số lượng Employee

public:

	void XoaEmployee(int SoThuTu)
	{

		int vitri = SoThuTu;

		for (int i = vitri; i < SoLuong - 1; i++)
		{
			a[i] = a[i+1];
		}

		SoLuong--;
	}

	void HienThiDanhSach()
	{
		cout << "   Danh sach cac User:                   " << endl << endl;

		cout << "0. Khong xoa ai ca                      " << endl;

		for (int i = 0; i < SoLuong; i++)
		{
			cout << i + 1 << ". " << a[i].Username << endl;
		}

		cout << endl;
	}

	void HienThiDanhSachCacUser()
	{
		if (SoLuong == 0)
		{
			cout << endl << "  Chua co User nao trong danh sach";
		}
		else
		{
			for (int i = 0; i < SoLuong; i++)
			{
				cout << endl << endl;

				ifstream in(a[i].Username + ".txt"); // Mở file [Username].txt

				textcolor(14);
				cout << i + 1;
				textcolor(15);

				cout << ". Username: ";
				
				textcolor(14);
				cout << a[i].Username << endl;
				textcolor(15);

				string HoVaTen;
				getline(in,HoVaTen);
				cout << "   Ho va ten: ";

				textcolor(14);
				cout << HoVaTen << endl;
				textcolor(15);

				string DiaChi;
				getline(in, DiaChi);
				cout << "   Dia chi: ";
				
				textcolor(14);
				cout << DiaChi << endl;
				textcolor(15);

				string SDT;
				in >> SDT;
				cout << "   So dien thoai: ";
				
				textcolor(14);
				cout << SDT << endl;
				textcolor(15);

				string Email;
				in >> Email;
				cout << "   Email: ";
				
				textcolor(14);
				cout << Email << endl << endl;
				textcolor(15);

				in.close();
			}
		}
	}

	int TimUser(string Username)
	{
		for (int i = 0; i < SoLuong; i++)
		{
			if (a[i].Username == Username) return i;
		}

		return -1;
	}

	void HienThiUser(int vitri)
	{
		int i = vitri;

		ifstream in(a[i].Username + ".txt"); // Mở file [Username].txt

		cout << endl;

		cout << "   Username: ";
		
		textcolor(14);
		cout << a[i].Username << endl;
		textcolor(15);

		string HoVaTen;
		getline(in, HoVaTen);
		cout << "   Ho va ten: ";

		textcolor(14);
		cout << HoVaTen << endl;
		textcolor(15);

		string DiaChi;
		getline(in, DiaChi);
		cout << "   Dia chi: ";

		textcolor(14);
		cout << DiaChi << endl;
		textcolor(15);

		string SDT;
		in >> SDT;
		cout << "   So dien thoai: ";

		textcolor(14);
		cout << SDT << endl;
		textcolor(15);

		string Email;
		in >> Email;
		cout << "   Email: ";

		textcolor(14);
		cout << Email << endl << endl;
		textcolor(15);

		in.close();
	}

};




