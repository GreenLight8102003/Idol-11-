#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "DoHoa.h"
#include "GiaoDien.h"
#include "Class.h"
using namespace std;


// Hàm cập nhập danh sách Admin từ File Administrators.txt
void CapNhatDanhSachAdmin(DanhSachAdmin& a)
{

	ifstream in("Administrators.txt");

	int n = 0;

	while (in >> a.a[n]) n++;

	a.SoLuong = n;

	in.close();

}

// Hàm cập nhập danh sách Employee từ File Employees.txt
void CapNhatDanhSachEmployee(DanhSachEmployee& a)
{
	ifstream in("Employees.txt");

	int n = 0;

	while (in >> a.a[n]) n++;

	a.SoLuong = n;

	in.close();

	ifstream in2("DangNhapLanDau.txt");

	for (int i = 0; i < a.SoLuong; i++)
	{
		in2 >> a.a[i].DangNhapLanDau;
	}

	in2.close();

}


int main()
{
	int ThaoTac;

	DanhSachAdmin DS;

	CapNhatDanhSachAdmin(DS);

	DanhSachEmployee DSE;

	CapNhatDanhSachEmployee(DSE);

	do
	{
	//////////////////////////////////////////////////     Lựa chọn Đăng nhập Admin hay Employee     /////////////////////////////////////////////////////////////////
	// 
		// Xóa màn hình
			system("cls");

		// Sử dung giao diện ban đầu
			GiaoDienBanDau();

		// Kiểm tra thao tác
			do 
			{
				// Nhập thao tác
				textcolor(14);  cin >> ThaoTac; textcolor(15);

				if (ThaoTac < 1 || ThaoTac > 3)
				{

					cout << endl;

					cout << "Khong co thao tac ";

					textcolor(14);
					cout << ThaoTac;
					textcolor(15);

					cout << ". Xin vui long nhap lai!" << endl << endl;

					cout << "Thao tac so: ";
				}

	
			} while (ThaoTac < 1 || ThaoTac > 3);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////         Xử lý Đăng nhập Admin              //////////////////////////////////////////???????///////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		if (ThaoTac == 1) 
		{
		// Kiểm tra đăng nhập Admin
			string Username;
			string Password = "";

			bool ok = false;

			do
			{
				if (DS.SoLuong < 3)
				{

					// Xóa màn hình
					system("cls");

					cout << "*****************************************************************" << endl;
					cout << "            Danh sach phai toi thieu 3 nguoi quan li!            " << endl;
					cout << "*****************************************************************" << endl;

					delay(1000);

					break;
				}

				// Xóa màn hình
				system("cls");

				// Tạo giao diện Admin
				GiaoDienAdmin();


				// Đăng nhập Admin
				gotoxy(7, 4); 
				
				textcolor(14);
				cin >> Username;
				textcolor(15);
				gotoxy(7, 5); 

				// Nhập Password có mã hóa

				Password = "";

				int dem = 6;

				char ch;
				do
				{
					ch = _getch();

					if (ch != 32 && ch != 13 && ch != 8) 
					{
						dem = dem + 1;
						textcolor(14);
						cout << '*';
						textcolor(15);
						Password = Password + ch;
					}

					if (ch == 8) 
					{
						if (dem > 6)
						{
							gotoxy(dem, 5);
							cout << ' ';
							gotoxy(dem, 5);

							Password.erase(Password.size() - 1);

							dem = dem - 1;
						}

					}

				} while (ch != 13);

				cout << endl;

				for (int i = 0; i < DS.SoLuong; i++)
				{
					if (Admin(Username, Password) == DS.a[i])
					{
						ok = true;

						cout << endl;

						cout << "Dang nhap thanh cong!" << endl << endl;

						delay(1000);
					}
				}

				if (ok == false)
				{

					cout << endl;

					cout << "Nhap lai Username va Password!" << endl;

					string x;

					do
					{

						cout << endl;
						cout << "Ban co muon tiep tuc (nhap CO hoac KHONG): ";
						textcolor(14);
						cin >> x;
						textcolor(15);

					} while (x != "CO" && x != "KHONG");

					if (x == "KHONG") break;

				}


			} while (ok == false);
			
		// Sử dụng chức năng Admin

			if (ok == true)
			{
				do
				{

					// Kiểm tra thao tác

					// Xóa màn hình
					system("cls");

					// Tạo giao diện chức năng của Admin
					GiaoDienMenuAdmin();

					// Nhập thao tác
					do
					{
						textcolor(14);
						cin >> ThaoTac;
						textcolor(15);

						if (ThaoTac < 1 || ThaoTac > 6)
						{
							cout << endl;

							cout << "Khong co thao tac ";
							textcolor(14);
							cout << ThaoTac;
							textcolor(15);
							cout << ". Xin vui long nhap lai!" << endl << endl;

							cout << "Thao tac so: ";
						}

					} while (ThaoTac < 1 || ThaoTac > 6);

					// Xử lý thao tác
						// Thao tác 1 _ Thêm Employee
					if (ThaoTac == 1)
					{
						do
						{
							// Xóa màn hình
							system("cls");

							// Tạo giao diện chức năng thêm Employee
							GiaoDienAddEmployee();

							// Khai báo danh sách các biến
							string Username;
							string HoVaTen;
							string DiaChi;
							string SDT;
							string Email;

							gotoxy(20, 2); 
							
							textcolor(14);
								
							cin >> Username;

							textcolor(15);

							bool ok = false;

							for (int i = 0; i < DSE.SoLuong; i++)
							{

								if (Username == DSE.a[i].Username)
								{
									gotoxy(1, 8);  cout << "Username da ton tai!" << endl;
									ok = true;
									break;
								}

							}

							if (ok == false)
							{
								cin.ignore();

								gotoxy(20, 3); 
								
								textcolor(14);
								getline(cin, HoVaTen);
								textcolor(15);

								gotoxy(20, 4); 

								textcolor(14);
								getline(cin, DiaChi);
								textcolor(15);

								gotoxy(20, 5); 
								
								textcolor(14);
								cin >> SDT;
								textcolor(15);

								gotoxy(20, 6);

								textcolor(14);
								cin >> Email;
								textcolor(15);

								// Admin xác nhận có muốn thêm Employee

								string x;

								do
								{
									cout << endl;

									cout << "Ban muon them Employee này (nhap CO hoac KHONG): ";

									textcolor(14);
									cin >> x;
									textcolor(15);

								} while (x != "CO" && x != "KHONG");

								if (x == "CO")
								{

									// Thêm Employee

									DSE.a[DSE.SoLuong].Username = Username;
									DSE.a[DSE.SoLuong].Password = "111111";
									DSE.a[DSE.SoLuong++].DangNhapLanDau = false;

									ofstream out("Employees.txt");

									ofstream out3("DangNhapLanDau.txt");

									for (int i = 0; i < DSE.SoLuong; i++)
									{
										out << DSE.a[i].Username;
										out << endl;
										out << DSE.a[i].Password;
										out << endl;
										out3 << DSE.a[i].DangNhapLanDau;
										out3 << endl;
									}

									out.close();

									out3.close();

									ofstream out2(Username + ".txt");

									out2 << HoVaTen << endl;
									out2 << DiaChi << endl;
									out2 << SDT << endl;
									out2 << Email;

									out2.close();

									gotoxy(1, 10);  cout << "Cap nhat thanh cong!" << endl;

								}


							}

							string x;

							do
							{

								cout << endl;
								cout << "Ban co muon tiep tuc (nhap CO hoac KHONG): ";
								textcolor(14);
								cin >> x;
								textcolor(15);

							} while (x != "CO" && x != "KHONG");

							if (x == "KHONG") break;

						} while (true);
					}

					// Chức năng 2 _ Xóa một User
					if (ThaoTac == 2)
					{
						do
						{
							string Username;
							// Xử lý
								// Xóa màn hình
								system("cls");

								// Tạo giao diện
								GiaoDienDeleteEmployee();

								gotoxy(14, 3); 
								
								textcolor(14);
								cin >> Username;
								textcolor(15);

								ThaoTac = DSE.TimUser(Username);

							// Xóa Employee trong DSE
							if (ThaoTac != -1)
							{
								string x;

								do
								{
									cout << endl;

									cout << "Ban muon xoa Employee này (nhap CO hoac KHONG): ";

									textcolor(14);
									cin >> x;
									textcolor(15);

								} while (x != "CO" && x != "KHONG");

								if (x == "CO")
								{
									// Xóa file [Username].txt

									// Chuyển chuỗi string sang char* để sử dụng hàm remove
									string line = DSE.a[ThaoTac].Username + ".txt";
									char* File = new char[line.size() + 1];
									copy(line.begin(), line.end(), File);
									File[line.size()] = '\0';

									remove(File);

									// Xóa User ra khỏi danh sách
									gotoxy(1, 7);

									cout << "Cap nhat lai thong tin cua file ";

									textcolor(14);
									cout << "Employees.txt";
									textcolor(15);

									cout << " va xoa file ";

									textcolor(14);
									cout << DSE.a[ThaoTac].Username;
									cout << ".txt";
									textcolor(15);

									cout << endl << endl;

									DSE.XoaEmployee(ThaoTac);
								}
							}

							else
							{
								gotoxy(1, 5);
								cout << "Username khong ton tai!" << endl;
							}

							ofstream out("Employees.txt");
							
							ofstream out3("DangNhapLanDau.txt");

							for (int i = 0; i < DSE.SoLuong; i++)
							{
								out << DSE.a[i].Username << endl << DSE.a[i].Password << endl;

								out3 << DSE.a[i].DangNhapLanDau << endl;
							}

							out.close();

							out3.close();

							string x;

							do
							{
								cout << "Ban co muon tiep tuc (nhap CO hoac KHONG): ";

								textcolor(14);
								cin >> x;
								textcolor(15);

							} while (x != "CO" && x != "KHONG");

							if (x == "KHONG") break;

						} while (true);
					}

					// Chức năng 3 _ Tìm và hiển thị thông tin employee theo username
					if (ThaoTac == 3)
					{
						string Username;
						do
						{
							// Xóa màn hình
							system("cls");

							// Tạo giao diện tìm User thông qua Username
							GiaoDienTimUser();

							gotoxy(22, 2); 
							
							textcolor(14);
							cin >> Username;
							textcolor(15);

							int vitri = DSE.TimUser(Username);

							if (vitri != -1)
							{
								DSE.HienThiUser(vitri);
							}
							else
							{
								cout << endl << "Username khong ton tai!" << endl << endl;
							}

							string x;

							do
							{
								cout << "Ban co muon tiep tuc (nhap CO hoac KHONG): ";

								textcolor(14);
								cin >> x;
								textcolor(15);

							} while (x != "CO" && x != "KHONG");

							if (x == "KHONG") break;

						} while (true);
					}

					// Chức năng 4 _ Cập nhật lại thông tin của Employee
					if (ThaoTac == 4)
					{

						do
						{
							// Xóa màn hình
							system("cls");

							// Tạo giao diện cập nhât lại thông tin
							GiaoDienCapNhatLaiThongTin();

							string Username;

							gotoxy(16, 2); 
							
							textcolor(14);
							cin >> Username;
							textcolor(15);

							int k = DSE.TimUser(Username);

							if (k == -1)
							{
								gotoxy(1, 9);
								cout << "Username khong ton tai!" << endl << endl;
							}
							else
							{
								string HoVaTen, DiaChi, SoDienThoai, Email;

								// Lấy dữ liệu từ file [Username].txt;
								ifstream in(Username + ".txt");

								getline(in, HoVaTen);
								    
								gotoxy(19, 4); 
								
								textcolor(14);
								cout << HoVaTen;
								textcolor(15);

								getline(in, DiaChi);

								gotoxy(19, 5); 
								
								textcolor(14);
								cout << DiaChi;
								textcolor(15);

								getline(in, SoDienThoai);

								textcolor(14);
								gotoxy(19, 6); cout << SoDienThoai;
								textcolor(15);

								getline(in, Email);

								textcolor(14);
								gotoxy(19, 7); cout << Email;
								textcolor(15);

								in.close();

								int SoThuTu;
								do
								{
									gotoxy(1, 9);

									cout << "So thu tu thong tin muon cap nhat:                                             " << endl << endl;
									cout << "                                                                               ";

									gotoxy(36, 9);

									textcolor(14);
									cin >> SoThuTu;
									textcolor(15);

									if (SoThuTu < 1 || SoThuTu > 4)
									{
										cout << endl;
										cout << "Khong co so thu tu so: ";

										textcolor(14);
										cout << SoThuTu;
										textcolor(15);

										cout << ". Xin vui long nhap lai!";
										delay(1000);
									}
									else
									{
										// Xóa màn hình
										system("cls");

										// Tạo giao diện cập nhât lại thông tin
										GiaoDienCapNhatLaiThongTin();

										gotoxy(16, 2); 
										
										textcolor(14);
										cout << Username;
										textcolor(15);

										gotoxy(19, 4); 
										
										textcolor(14);
										cout << HoVaTen;
										textcolor(15);

										gotoxy(19, 5); 
										
										textcolor(14);
										cout << DiaChi;
										textcolor(15);

										gotoxy(19, 6); 
										
										textcolor(14);
										cout << SoDienThoai;
										textcolor(15);

										gotoxy(19, 7); 
										
										textcolor(14);
										cout << Email;
										textcolor(15);

										gotoxy(1, 9);

										if (SoThuTu == 1)
										{
											cout << "Ho va ten dang su dung: ";
											
											textcolor(14);
											cout << HoVaTen << endl << endl;
											textcolor(15);

											cout << "Nhap ho va ten moi:     ";

											cin.ignore();

											textcolor(14);
											getline(cin, HoVaTen);
											textcolor(15);

											cout << endl;
										}

										if (SoThuTu == 2)
										{
											cout << "Dia chi dang su dung: ";
											
											textcolor(14);
											cout << DiaChi << endl << endl;
											textcolor(15);
											
											cout << "Nhap dia chi moi:     ";

											cin.ignore();

											textcolor(14);
											getline(cin, DiaChi);
											textcolor(15);

											cout << endl;
										}

										if (SoThuTu == 3)
										{
											cout << "So dien thoai dang su dung: ";
											
											textcolor(14);
											cout << SoDienThoai << endl << endl;
											textcolor(15);

											cout << "Nhap so dien thoai:         ";

											textcolor(14);
											cin >> SoDienThoai;
											textcolor(15);

											cout << endl;
										}

										if (SoThuTu == 4)
										{
											cout << "Dia chi Email dang su dung: ";
											
											textcolor(14);
											cout << Email << endl << endl;
											textcolor(15);
											
											cout << "Nhap dia chi Email moi:     ";

											textcolor(14);
											cin >> Email;
											textcolor(15);

											cout << endl;
										}


										string x;

										do
										{

											cout << "Ban muon cap nhat thong tin tren (nhap CO hoac KHONG): ";
											
											textcolor(14);
											cin >> x;
											textcolor(15);

										} while (x != "CO" && x != "KHONG");

										if (x == "CO")
										{
											ofstream out(Username + ".txt");

											out << HoVaTen << endl;
											out << DiaChi << endl;
											out << SoDienThoai << endl;
											out << Email << endl;

											out.close();
										}

										cout << endl;
									}

								} while (SoThuTu < 1 || SoThuTu > 4);

							}

							string x;

							do
							{

								cout << "Ban co muon tiep tuc (nhap CO hoac KHONG): ";
								
								textcolor(14);
								cin >> x;
								textcolor(15);

							} while (x != "CO" && x != "KHONG");

							if (x == "KHONG") break;
						} while (true);
					}

					// Chức năng 5 _ Hiển thị Danh Sách Employee
					if (ThaoTac == 5)
					{
						// Xóa màn hình
						system("cls");


						// Tạo giao diện danh sách các User
						GiaoDienDanhSachCacUser();

						DSE.HienThiDanhSachCacUser();

						cout << "************************************************" << endl;

						string x;

						do
						{
							cout << endl << "Nhap OK de quay lai: ";

							textcolor(14);
							cin >> x;
							textcolor(15);

						} while (x != "OK");

					}

				} while (ThaoTac != 6);
			}
		}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////     Xử lý Đăng nhập Employee                 ////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if (ThaoTac == 2) 
		{

			// Kiểm tra đăng nhập Employee
			string Username;
			string Password = "";

			bool ok = false;

			int ViTri;

			int count = 0;

			do
			{
				count = count + 1;

				// Xóa màn hình
				system("cls");

				// Tạo giao diện Employee
				GiaoDienEmployee();

				if (count == 4)
				{
					gotoxy(1, 6);

					cout << "Dang nhap sai 3 lan!";

					delay(1000);

					break;
				}

				// Đăng nhập Admin
				gotoxy(7, 4); 
				
				textcolor(14);
				cin >> Username;
				textcolor(15);

				gotoxy(7, 5);

				// Nhập Password có mã hóa

				Password = "";

				int dem = 6;

				char ch;

				textcolor(14);
				do
				{
					ch = _getch();

					if (ch != 32 && ch != 13 && ch != 8)
					{
						dem = dem + 1;
						cout << '*';
						Password = Password + ch;
					}

					if (ch == 8)
					{
						if (dem > 6)
						{
							gotoxy(dem, 5);
							cout << ' ';
							gotoxy(dem, 5);

							Password.erase(Password.size() - 1);

							dem = dem - 1;
						}

					}

				} while (ch != 13);
				textcolor(15);

				for (int i = 0; i < DSE.SoLuong; i++)
				{
					if (Employee(Username, Password) == DSE.a[i])
					{

						ok = true;

						ViTri = i;

						cout << endl;

						cout << "Dang nhap thanh cong!";

						delay(1000);

					}
				}

				if (ok == false)
				{

					cout << endl;
					
					cout << "Nhap lai Username va Password!" << endl;

					string x;

					do
					{

						cout << endl;
						cout << "Ban co muon tiep tuc (nhap CO hoac KHONG): ";

						textcolor(14);
						cin >> x;
						textcolor(15);

					} while (x != "CO" && x != "KHONG");

					if (x == "KHONG") break;

				}

			} while (ok == false);

			if (ok == true)
			{

				string Password1;

				string Password2;

			// Kiểm tra đăng nhập lần đầu
				if (DSE.a[ViTri].DangNhapLanDau == false)
				{

					do
					{

						// Xóa màn hình
						system("cls");

						GiaoDienLanDauDangNhap();

						// Nhập Password mới
						Password1 = "";

						gotoxy(16, 4);

						int dem = 15;

						char ch;

						textcolor(14);
						do
						{
							ch = _getch();

							if (ch != 32 && ch != 13 && ch != 8)
							{
								dem = dem + 1;
								cout << '*';
								Password1 = Password1 + ch;
							}

							if (ch == 8)
							{
								if (dem > 15)
								{
									gotoxy(dem, 4);
									cout << ' ';
									gotoxy(dem, 4);

									Password1.erase(Password1.size() - 1);

									dem = dem - 1;
								}

							}

						} while (ch != 13);
						textcolor(15);

						// Nhập Password mới lần 2
						Password2 = "";

						gotoxy(25, 6);

						dem = 24;

						textcolor(14);
						do
						{
							ch = _getch();

							if (ch != 32 && ch != 13 && ch != 8)
							{
								dem = dem + 1;
								cout << '*';
								Password2 = Password2 + ch;
							}

							if (ch == 8)
							{
								if (dem > 24)
								{
									gotoxy(dem, 6);
									cout << ' ';
									gotoxy(dem, 6);

									Password2.erase(Password2.size() - 1);

									dem = dem - 1;
								}

							}

						} while (ch != 13);
						textcolor(15);

						if (Password1 != Password2)
						{
							gotoxy(1,9);
							cout << "Password khong khop!";
							delay(1000);
						}

					} while (Password1 != Password2);

					gotoxy(1, 9);

					cout << "Cap nhat file ";
					
					textcolor(14);
					cout << "Employees.txt";
					textcolor(15);

					DSE.a[ViTri].Password = Password1;

					DSE.a[ViTri].DangNhapLanDau = true;

					ofstream out("Employees.txt");

					ofstream out2("DangNhapLanDau.txt");

					for (int i = 0; i < DSE.SoLuong; i++)
					{
						out << DSE.a[i].Username << endl;

						out << DSE.a[i].Password << endl;

						out2 << DSE.a[i].DangNhapLanDau << endl;
					}

					out.close();

					out2.close();

					delay(1000);
				}

			// Thực thi chức năng của Employee
				int ThaoTac;

				do
				{
					// Xóa màn hình
					system("cls");

					// Tạo giao diện chức năng Employee
					GiaoDienMenuEmployee();

					// Nhập thao tác
					do
					{
						textcolor(14);
						cin >> ThaoTac;
						textcolor(15);

						if (ThaoTac < 1 || ThaoTac > 3)
						{
							cout << endl;

							cout << "Khong co thao tac ";
							
							textcolor(14);
							cout << ThaoTac;
							textcolor(15);

							cout << ". Xin vui long nhap lai!" << endl << endl;

							cout << "Thao tac so: ";
						}

					} while (ThaoTac < 1 || ThaoTac > 3);

					// Xử lý thao tác

					if (ThaoTac == 1)
					{
						// Xóa màn hình
						system("cls");

						// Tạo giao diện hiển thị thông tin của Employee
						GiaoDienHienThiThongTin();

						gotoxy(11, 2); 
						
						textcolor(14);
						cout << Username;
						textcolor(15);

						gotoxy(1, 4);

						string HoVaTen, DiaChi, SoDienThoai, Email;

						ifstream in (Username + ".txt");

						getline(in, HoVaTen);
						getline(in, DiaChi);
						getline(in, SoDienThoai);
						getline(in, Email);

						in.close();
						

						cout << "Ho va ten: ";
						textcolor(14);
						cout << HoVaTen;
						textcolor(15);
						cout << endl;
						cout << "Dia chi: ";
						textcolor(14);
						cout << DiaChi;
						textcolor(15);
						cout << endl;
						cout << "So dien thoai: ";
						textcolor(14);
						cout << SoDienThoai;
						textcolor(15);
						cout << endl;
						cout << "Dia chi Email: ";
						textcolor(14);
						cout << Email;
						textcolor(15);
						cout << endl;
						cout << "*************************************************" << endl;

						string x;

						do
						{
							cout << endl << "Nhap OK de quay lai: ";

							textcolor(14);
							cin >> x;
							textcolor(15);

						} while (x != "OK");

					}

					string keyPassword = Password;

					// Chức năng đổi mật khẩu
					if (ThaoTac == 2)
					{
						do
						{
							// Xóa màn hình
							system("cls");

							// Tạo giao diện đổi Password
							GiaoDienDoiPassword();

							gotoxy(24, 2);

							Password = "";

							int dem = 23;

							char ch;

							textcolor(14);
							do
							{
								ch = _getch();

								if (ch != 32 && ch != 13 && ch != 8)
								{
									dem = dem + 1;
									cout << '*';
									Password = Password + ch;
								}

								if (ch == 8)
								{
									if (dem > 23)
									{
										gotoxy(dem, 2);
										cout << ' ';
										gotoxy(dem, 2);

										Password.erase(Password.size() - 1);

										dem = dem - 1;
									}

								}

							} while (ch != 13);
							textcolor(15);

							if (Password == DSE.a[ViTri].Password)
							{
							
								do
								{
								// Password mới lần 1
									gotoxy(24, 4);

									cout << "                                                                                                               ";

									gotoxy(24, 6);

									cout << "                                                                                                               ";

									gotoxy(24, 4);

									Password = "";

									int dem = 23;

									textcolor(14);
									char ch;
									do
									{
										ch = _getch();

										if (ch != 32 && ch != 13 && ch != 8)
										{
											dem = dem + 1;
											cout << '*';
											Password = Password + ch;
										}

										if (ch == 8)
										{
											if (dem > 23)
											{
												gotoxy(dem, 4);
												cout << ' ';
												gotoxy(dem, 4);

												Password.erase(Password.size() - 1);

												dem = dem - 1;
											}

										}

									} while (ch != 13);
									textcolor(15);

								// Password mới lần 2
									gotoxy(24, 6);

									cout << "                                                                                                               ";

									gotoxy(24, 6);

									Password2 = "";

									dem = 23;

									textcolor(14);
									do
									{
										ch = _getch();

										if (ch != 32 && ch != 13 && ch != 8)
										{
											dem = dem + 1;
											cout << '*';
											Password2 = Password2 + ch;
										}

										if (ch == 8)
										{
											if (dem > 23)
											{
												gotoxy(dem, 6);
												cout << ' ';
												gotoxy(dem, 6);

												Password2.erase(Password2.size() - 1);

												dem = dem - 1;
											}

										}

									} while (ch != 13);
									textcolor(15);

									if (Password == Password2)
									{
										gotoxy(1, 9);

										cout << "                                                                                                               ";

										gotoxy(1, 9);

										cout << "Cap nhat file ";
										
										textcolor(14);
										cout << "Employees.txt";
										textcolor(15);

										delay(1000);

										DSE.a[ViTri].Password = Password2;


										ofstream out("Employees.txt");

										for (int i = 0; i < DSE.SoLuong; i++)
										{

											out << DSE.a[i].Username << endl;

											out << DSE.a[i].Password << endl;

										}

										out.close();

										break;
									}
									else
									{
										gotoxy(1, 9);

										cout << "Nhap lai Password moi khong khop!";

									}

								} while (true);

								break;
							}
							else
							{

								gotoxy(1, 9);

								cout << "Nhap sai Password!";

								string x;

								gotoxy(1, 11);

								do
								{

									cout << "Ban co muon tiep tuc (nhap CO hoac KHONG): ";
									
									textcolor(14);
									cin >> x;
									textcolor(15);

									cout << endl;

								} while (x != "CO" && x != "KHONG");

								if (x == "KHONG") break;
							}

						} while (true);

					}

				} while (ThaoTac != 3);

				ThaoTac = 0;
			}
		}

	} while (ThaoTac != 3);

	system("pause");
	return 0;
}