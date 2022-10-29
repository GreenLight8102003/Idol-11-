#include <iostream>
using namespace std;

// Tạo giao diện ban đầu
void GiaoDienBanDau()
{
	cout << "*********************************" << endl;
	cout << "*            ";
	textcolor(14);
	cout << "DANG NHAP          ";
	textcolor(15);
	cout << "*" << endl;
	cout << "*********************************" << endl;
	cout << "      1. Admin                   " << endl;
	cout << "      2. Employee                " << endl;
	cout << "      3. Thoat                   " << endl;
	cout << "*********************************" << endl;
	cout << "Thao tac so: ";
}

//////////////////////////////////////////////////////////////////////////////// TẠO GIAO DIỆN ADMIN //////////////////////////////////////////////////////////////////////////////////////////

// Giao diện đăng nhập Admin
void GiaoDienAdmin()
{
	cout << "**********************************" << endl;
	cout << "*         ";
	textcolor(14);
	cout << "DANG NHAP ADMIN";
	cout << "        *" << endl;
	textcolor(15);
	cout << "**********************************" << endl;
	cout << "User:                    "          << endl;
	cout << "Pass:                    "          << endl;
}


// Giao diện chức năng Admin
void GiaoDienMenuAdmin()
{
	cout << "**************";
	textcolor(14); 
	cout << "MENU";
	textcolor(15);
	cout << "****************" << endl;
	cout << "   1. Them Employee               " << endl;
	cout << "   2. Xoa Employee                " << endl;
	cout << "   3. Tim Employee                " << endl;
	cout << "   4. Cap nhat Employee           " << endl;
	cout << "   5. Hien thi thong tin Employee " << endl;
	cout << "   6. Thoat!                      " << endl;
	cout << "**********************************" << endl;
	cout << "Thao tac so: ";
}

// Giao diện chức năng Them Employee
void GiaoDienAddEmployee()
{
	cout << "**************";
	textcolor(14);
	cout << "THEM EMPLOYEE";
	textcolor(15);
	cout << "****************" << endl;
	cout << "   Username:                               " << endl;
	cout << "   Ho va ten:                              " << endl;
	cout << "   Dia chi:                                " << endl;
	cout << "   So dien thoai:                          " << endl;
	cout << "   Dia chi email:                          " << endl;
	cout << "*******************************************" << endl;
}

void GiaoDienDeleteEmployee()
{
	cout << "**************";
	textcolor(14);
	cout << "XOA EMPLOYEE";
	textcolor(15);
	cout << "****************" << endl;
	cout << "   Nhap Username cua Employee muon xoa    "  << endl;
	cout << "   Username:                              "  << endl;
	cout << "******************************************"  << endl << endl << endl << endl << endl;
}

void GiaoDienDanhSachCacUser()
{
	cout << "*************";

	textcolor(14);
	cout << "DANH SACH CAC USER";
	textcolor(15);

	cout << "*****************" << endl;

}

void GiaoDienTimUser()
{
	cout << "********************";
	textcolor(14);
	cout << "TIM USER";
	textcolor(15);
	cout << "******************" << endl;
	cout << "     Nhap Username:                           " << endl;
	cout << "**********************************************" << endl;
}

void GiaoDienCapNhatLaiThongTin()
{
	cout << "**************";
	textcolor(14);
	cout << "CAP NHAT LAI THONG TIN";
	textcolor(15);
	cout << "****************" << endl;
	cout << "Nhap Username:							             " << endl;
	cout << "****************************************************" << endl;
	cout << "1. Ho va ten:                                       " << endl;
	cout << "2. Dia Chi:                                         " << endl;
	cout << "3. So dien thoai:                                   " << endl;
	cout << "4. Dia Chi Email:                                   " << endl;
	cout << "****************************************************" << endl;
	
}

//////////////////////////////////////////////////////////////////////////////// TẠO GIAO DIỆN EMPLOYEE //////////////////////////////////////////////////////////////////////////////////////////

// Giao diện đăng nhập Employee

void GiaoDienEmployee()
{
	cout << "**********************************" << endl;
	cout << "*      ";
	textcolor(14);
	cout << "DANG NHAP EMPLOYEE";
	textcolor(15);
	cout << "        *" << endl;
	cout << "**********************************" << endl;
	cout << "User:                    " << endl;
	cout << "Pass:                    " << endl;
}

// Giao diện lần đầu đăng nhập

void GiaoDienLanDauDangNhap()
{
	cout << "*******************************************************" << endl;

	textcolor(14);
	cout << " Dang nhap lan dau tien, yeu cau nhap Password moi!" << endl;
	textcolor(15);

	cout << endl;

	cout << " Password moi: " << endl;

	cout << endl;

	cout << " Nhap lai Password moi: " << endl;

	cout << endl;

	cout << "*******************************************************";
}

// Giao diện chức năng Employee
void GiaoDienMenuEmployee()
{
	cout << "**********";
	textcolor(14);
	cout << "MENU EMPLOYEE";
	textcolor(15);
	cout << "***********" << endl;
	cout << "   1. Xem thong tin tai khoan     " << endl;
	cout << "   2. Doi password                " << endl;
	cout << "   3. Thoat                       " << endl;
	cout << "**********************************" << endl;
	cout << "Thao tac so: ";
}


// Giao dien hien thi thong tin cua Employee
void GiaoDienHienThiThongTin()
{
	cout << "***************";
	textcolor(14);
	cout << "THONG TIN CUA EMPLOYEE";
	textcolor(15);
	cout << "************" << endl;
	cout << "Username:                                        " << endl;
	cout << "*************************************************" << endl;
}

// Giao diện đổi Password của Employee
void GiaoDienDoiPassword()
{
	cout << "****************";
	textcolor(14);
	cout << "DOI PASSWORD";
	textcolor(15);
	cout << "**************" << endl;
	cout << "Nhap password:                            " << endl << endl;
	cout << "Nhap password moi:                        " << endl << endl;
	cout << "Nhap lai password moi:                    " << endl << endl;
	cout << "******************************************" << endl;
}