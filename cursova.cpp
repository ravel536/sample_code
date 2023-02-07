#include <iostream>
#include<fstream>
#include<string.h>
#include <conio.h>
using namespace std;
char load = 219;


class student  
{
private: 
	char name[50];
	char date[15];
	int group;
	float marks[5];
	char grade;
	float per;
	int rno;
	
public: 

	void getper()
	{
		per = ((marks[0] + marks[1] + marks[2] + marks[3] + marks[4]) / 5);
	}
	void getgrade()
	{
		if (per >= 90)
			grade = 'A';
		else if ((per >= 80) && (per <= 89))
			grade = 'B';
		else if ((per >= 70) && (per <= 79))
			grade = 'C';
		else if ((per >= 60) && (per <= 69))
			grade = 'D';
		else if ((per >= 50) && (per <= 59))
			grade = 'E';
		else if (per <= 49)
			grade = 'F';
	}
	void display_report()
	{
		cout << "---------------------------------------\n\n";
		cout << "                         ------------------------\n";
		cout << "                             PERSONAL DETAILS\n";
		cout << "                         ------------------------\n\n";
		cout << "NAME: " << name << "\t\t";
		cout << "ROLL NO: " << rno << "\n\n";
		cout << "DATE OF BIRTH: " << date << "\t";
		cout << "                        ----------------------------\n";
		cout << "                            ACADEMIC PERFORMANCE\n";
		cout << "                        ----------------------------\n\n";
		cout << "                 ---------------------------------------\n";
		cout << "                                  MARKS\n";
		cout << "                 ---------------------------------------\n";
		{
			cout << "\t\t\t  PHYSICS\t" << marks[0] << "\n";
			cout << "\t\t\t  INFORMATION TECHNOLOGIES\t" << marks[1] << "\n";
			cout << "\t\t\t  MATHS\t\t" << marks[2] << "\n";
			cout << "\t\t\t  OOP\t" << marks[3] << "\n";
			cout << "\t\t\t  ENGLISH\t" << marks[4] << "\n";
		}
		cout << "                -------------------        ------------\n";
		cout << "                 PERCENTAGE: " << per << "%" << "           ";
		cout << "GRADE: " << grade << "\n";
		cout << "                -------------------        ------------\n\n";
	}
	void enter()
	{
		cout << "\t\t\t  -------------------------------" << "\n";
		cout << "\t\t\t     ENTER THE STUDENT DETAILS" << "\n";
		cout << "\t\t\t  -------------------------------" << "\n\n";
		cout << "\t\tNAME OF THE STUDENT: " ;
		cin.ignore();
		cin.getline(name, 50);
		cout << "\t\tDATE OF BIRTH(DD/MM/YY): ";
		cin.getline(date, 15);
		cout << "\t\tGroup: ";
		cin >> group;
		cout << "\t\tROLL NUMBER: ";
		cin >> rno;
		cout << "\t\tPHYSICS: " ;
		cin >> marks[0];
		cout << "\t\t2. INFORMATION TECHNOLOGIES" << "\n";
		cin >> marks[1];
		cout << "\t\tMATHEMATICS: ";
		cin >> marks[2];
		cout << "\t\tOOP: ";
		cin >> marks[3];
		cout << "\t\tENGLISH: ";
		cin >> marks[4];
		cout << "\n\n";
		getper();
		getgrade();
	}

	void display_all()
	{
		cout << "\t\tNAME: " << name << "\n";
		cout << "\t\tROLL NO: " << rno << "\t" << "GROUP: " << group << "\n";
		cout << "\t\t                     MARKS" << "\n";
		cout << "\t\tPHY\tIT\tMATHS\tOOP\tENG" << endl;
		cout << "\t\t"<<marks[0] << "\t" << marks[1] << "\t" << marks[2] << "\t";
		cout << marks[3] << "\t" << marks[4] << "\n\n";
		cout << "\t\tPERCENTAGE: " << per << "%\t" << "GRADE: " << grade << "\n";
	}
	void add()
	{
		student s;
		ofstream f("Record.txt", ios::binary | ios::app);
		s.enter();
		f.write((char*)&s, sizeof(s));
		f.close();
	}
	void display()
	{
		student s;
		ifstream f("Record.txt");
		if (!f)
		{
			"\t\t\tFILE NOT FOUND!";
		}
		else
		{
			cout << "\t\t\t  ---------------------------" << "\n";
			cout << "\t\t\t     LIST OF CLASS RECORDS" << "\n";
			cout << "\t\t\t  ---------------------------" << "\n\n";
			while (f.read((char*)&s, sizeof(s)))
			{
				s.display_all();
				cout << "\n\n\n\t\t---------------------------------------------\n\n\n";
			}
		}
		f.close();
	}
	void del()
	{
		student s;
		ifstream f1("Record.txt");
		ofstream f2("Temp.txt", ios::binary);
		int n, flag = 0;
		if (!f1)
		{
			"\t\t\tFILE NOT FOUND!";
		}
		else
		{
			cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t";
			cout << "ENTER THE ROLL NUMBER OF THE STUDENT: ";
			cin >> n;
			system("cls");
			while (f1.read((char*)&s, sizeof(s)))
			{
				if (n != s.rno)
				{
					f2.write((char*)&s, sizeof(s));
					flag = 1;
				}
			}
			if (flag == 0)
			{
				cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tRECORD NOT FOUND!";
				cout << "\n\n\n\n\n\n\n\n";
			}
			else
			{
				cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t";
				cout << "THE RECORD WAS DELETED SUCCESSFULLY";
				cout << "\n\n\n\n\n\n\n\n";
			}
		}
		f1.close();
		f2.close();
		remove("Record.txt");
		rename("Temp.txt", "Record.txt");
	}

	void modify()
	{
		student s;
		ifstream f1("Record.txt");
		ofstream f2("Temp.txt", ios::binary);
		int n, flag = 0;
		if (!f1)
		{
			"\t\t\tFILE NOT FOUND!";
		}
		else
		{
			cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t";
			cout << "ENTER THE ROLL NUMBER OF THE STUDENT: ";
			cin >> n;
			system("cls");
			while (f1.read((char*)&s, sizeof(s)))
			{
				if (n == s.rno)
				{
					cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t";
					cout << "ENTER THE MODIFIED DETAILS OF THE STUDENT";
					system("cls");
					s.enter();

					f2.write((char*)&s, sizeof(s));
					flag = 1;
				}
				else
				{
					f2.write((char*)&s, sizeof(s));
				}
			}
			if (flag == 0)
			{
				cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tRECORD NOT FOUND!";
				cout << "\n\n\n\n\n\n\n\n";
			}
		}
		f1.close();
		f2.close();
		remove("Record.txt");
		rename("Temp.txt", "Record.txt");
	}
	void search()
	{
		student s;
		ifstream f("Record.txt");
		int n, flag = 0;
		if (!f)
		{
			"\t\t\tFILE NOT FOUND!";
		}
		else
		{
			cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t";
			cout << "ENTER THE ROLL NUMBER OF THE STUDENT: ";
			cin >> n;
			system("cls");
			while (f.read((char*)&s, sizeof(s)))
			{
				if (n == s.rno)
				{
					flag = 1;
					s.display_report();
				}
			}
			if (flag == 0)
			{
				cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tRECORD NOT FOUND!";
				cout << "\n\n\n\n\n\n\n\n";
			}
		}
		f.close();
	}
	void sortmark()
	{
		student s, t[100], temp;
		ifstream f("Record.txt");
		int x, y, n = 0;
		char ch[25];
		if (!f)
		{
			"\t\t\tFILE NOT FOUND!";
		}
		else
		{
			{
				while (f.read((char*)&s, sizeof(s)))
				{
					t[n++] = s;
				}
			}
			f.close();

			cout << "\n\n\n\n\n\n";
			cout << "\t\t\t  ----------------------" << "\n";
			cout << "\t\t\t     SELECT A SUBJECT" << "\n";
			cout << "\t\t\t  ----------------------" << "\n";
			cout << "\t\t\t       1. PHYSICS" << "\n";
			cout << "\t\t\t       2. INFORMATION TECHNOLOGIES" << "\n";
			cout << "\t\t\t       3. MATHS" << "\n";
			cout << "\t\t\t       4. OOP" << "\n";
			cout << "\t\t\t       5. ENGLISH" << "\n\n";
			cout << "\t\t\t     ENTER YOUR OPTION: ";
			cin >> y;
			system("cls");
			cout << endl;
			if (y > 5)
			{
				cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tWRONG OPTION!";
				cout << "\n\n\n\n\n\n\n\n";
			}
			else
				x = y - 1;

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n - 1; j++)
				{
					if (t[j].marks[x] < t[j + 1].marks[x])
					{
						temp = t[j];
						t[j] = t[j + 1];
						t[j + 1] = temp;
					}
				}
			}

			cout << "\n\n\n\n\n\n";
			cout << "\t\t\t" << "-------------------------------" << "\n";
			cout << "\t\t\t" << "   SL. NO:" << "\t" << "MARKS" << "\t" << "NAME" << "\n";
			cout << "\t\t\t" << "-------------------------------" << "\n\n";
			for (int i = 0; i < 5; ++i)
			{
				cout << "\t\t\t   ";
				cout << i + 1 << ". " << "\t\t";
				cout << t[i].marks[x] << "\t" << t[i].name;
				cout << endl;
			}
			cout << "\n\n\n";
			
		}
	}
	void sortper()
	{
		student s, t[100], temp;
		ifstream f("Record.txt");
		int n = 0;
		if (!f)
		{
			"\t\t\tFILE NOT FOUND!";
		}
		else
		{
			{
				while (f.read((char*)&s, sizeof(s)))
				{
					t[n++] = s;
				}
			}
			f.close();

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n - 1; j++)
				{
					if (t[j].per < t[j + 1].per)
					{
						temp = t[j];
						t[j] = t[j + 1];
						t[j + 1] = temp;
					}
				}
			}
			cout << "\t\t\t  -----------------------------------" << "\n";
			cout << "\t\t\t     LIST OF CLASS RECORDS        " << "\n";
			cout << "\t\t\t  -----------------------------------" << "\n\n";
			for (int i = 0; i < n; i++)
			{
				t[i].display_all();
				cout << "\n\n\n\t\t---------------------------------------------\n\n\n";
			}
		}
		system("PAUSE");
	}
};
class login
{
public:
	bool user_login()
	{
		string user_id, pin, compare_id, compare_pin;
		char password{};
	start:
		system("cls");
		cout << "\n";
		cout << "\t\t\t\t\t" << load << "                               " << load << endl;
		cout << "\t\t\t\t\t" << load << "                               " << load << endl;
		cout << "\t\t\t\t\t" << load << "      ------------------       " << load << endl;
		cout << "\t\t\t\t\t" << load << "             Login             " << load << endl;
		cout << "\t\t\t\t\t" << load << "      ------------------       " << load << endl;
		cout << "\t\t\t\t\t" << load << "                               " << load << endl;
		cout << "\t\t\t\t\t" << load << "       Please enter your       " << load << endl;
		cout << "\t\t\t\t\t" << load << "      User id and Password     " << load << endl;
		cout << "\t\t\t\t\t" << load << "    For login this Software    " << load << endl;
		cout << "\t\t\t\t\t" << load << "                               " << load << endl;
		cout << "\t\t\t\t\t" << load << "                               " << load << endl;
		cout << "\t\t\t\t\t";
		cout << load;
		cout << "\n";
		ifstream rd("user login.txt");
		if (!rd.is_open())
		{
			ofstream wrt("user login.txt");
			wrt << "root\n";
			wrt << "1234";
		}
		else
		{
			rd >> compare_id;
			rd >> compare_pin;
			cout << "\n\t\t\t\t\t  User ID:   ";
			cin >> user_id;
			cout << "\t\t\t\t\t      PIN:   ";


			while (password != 13) 
			{
				if (password >= 48 && password <= 57) 
				{
					pin.push_back(password);
					cout << '*';
				}
				password = _getch(); 

			}
			
		}

		if (user_id == compare_id && pin == compare_pin) 
			return true;
		else
			return false;
		system("cls");
	goto start;
	};
};
class  menu : public student
{
public:
	int c;
	void showmenu()
	{
	start:
		system("cls");
		cout << "\n\n\n\n\n\n";
		cout << "\t\t\t\t\t" << load << "      ------------------       " << load << endl;
		cout << "\t\t\t\t\t" << load << "             MENU              " << load << endl;
		cout << "\t\t\t\t\t" << load << "      ------------------       " << load << endl;
		cout << "\t\t\t\t\t" << load << "      1. ADD A NEW RECORD      "<< load << endl;
		cout << "\t\t\t\t\t" << load << "      2. SEARCH FOR A RECORD   " << load << endl;
		cout << "\t\t\t\t\t" << load << "      3. MODIFY A RECORD       " << load << endl;
		cout << "\t\t\t\t\t" << load << "      4. DELETE A RECORD       " << load << endl;
		cout << "\t\t\t\t\t" << load << "   5. DISPLAY ALL THE RECORDS  " << load << endl;
		cout << "\t\t\t\t\t" << load << "      6. CLASS STATISTICS      " << load << endl;
		cout << "\t\t\t\t\t       ENTER YOUR OPTION: ";
		cin >> c;
		system("cls");
		switch (c)
		{
		case 1: add();
			break;
		case 2: search();
			break;
		case 3: modify();
			break;
		case 4: del();
			break;
		case 5: display();
			break;
		case 6: sortper();
			break;
		}
		system("PAUSE");
	goto start;
	}
};


int main()
{
	system("COLOR F0");
	int a;
	login log;
	menu men;
	student stud;
start:
	system("cls");
	cout << "\n\n\n\n\n\n";
	cout << "\t\t\t\t\t" << load << "      -------------       " << load << endl;
	cout << "\t\t\t\t\t" << load << "        MAIN MENU         " << load << endl;
	cout << "\t\t\t\t\t" << load << "      -------------       " << load << endl;
	cout << "\t\t\t\t\t" << load << "       1. TEACHER         " << load << endl;
	cout << "\t\t\t\t\t" << load << "       2. STUDENT         " << load << endl;
	cout << "\t\t\t\t\t     ENTER YOUR OPTION: ";
	cin >> a;
	switch (a)
	{
	case 1:
		log.user_login();
		men.showmenu();
		break;
	case 2:
		stud.sortper();
		break;
	}
	system("cls");
goto start;
}
