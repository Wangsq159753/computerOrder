#include<iostream>
using namespace std;
#include"Identity.h"
#include<string>
#include<fstream>
#include"Globalfile.h"
#include"student.h"
#include"Teacher.h"
#include"manager.h"
void TeacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->Show_Menu();

		Teacher* tea = (Teacher*)teacher;
		int select;
		cin >> select;
		if (select == 1)
		{
			tea->Show_AllOrder();
		}
		else if (select == 2)
		{
			tea->Check_Order();
		}
		else
		{
			delete teacher;
			cout << "ע����¼�ɹ�!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}


}

void StudentMenu(Identity*& student)
{
	while (true)
	{
		student->Show_Menu();

		Student* stu = (Student*)student;
		int select;
		cin >> select;
		if (select == 1)
		{
			stu->Apply_Order();
		}
		else if (select == 2)
		{
			stu->Show_MyOrder();
		}
		else if (select == 3)
		{
			stu->Show_AllOrder();
		}
		else if (select == 4)
		{
			stu->Cancel_Order();
		}
		else
		{
			delete student;
			cout << "ע����¼�ɹ�!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}


}


void ManagerMenu(Identity* &manager)
{
	while (true)
	{
		manager->Show_Menu();

		Manager* man = (Manager*)manager;
		int select;
		cin >> select;
		if (select == 1)
		{
			man->Add_Person();
		}
		else if (select == 2)
		{
			man->Show_Person();
		}
		else if (select == 3)
		{
			man->Show_Computer();
		}
		else if (select == 4)
		{
			man->Clean_File();
		}
		else
		{
			delete manager;
			cout << "ע����¼�ɹ�!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	

}


void LoginIn(string filename, int type)
{
	Identity* person = NULL;
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�Ϊ�ջ��ļ�������!" << endl;
		ifs.close();
		return;
	}
	int id;
	int tt_id;
	string name;
	string pwd;
	if (type==1)
	{
		cout << "����������ѧ��: " << endl;
		cin >> id;
	}
	else if (type==2)
	{
		cout << "����������ְ����: " << endl;
		cin >> tt_id;
	}
	cout << "�����������û���: " << endl;
	cin >> name;
	cout << "��������������: " << endl;
	cin >> pwd;

	if (type==1)
	{
		int m_id;
		string m_name;
		string m_pwd;
		while (ifs>>m_id&&ifs>>m_name&&ifs>>m_pwd)
		{
			if (m_id == id&&m_name == name && m_pwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				StudentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		int t_id;
		string t_name;
		string t_pwd;
		while (ifs >> t_id && ifs >> t_name && ifs >> t_pwd)
		{
			if (t_id == tt_id && t_name == name && t_pwd == pwd)
			{
				cout << "��ʦ��֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(tt_id, name, pwd);
				TeacherMenu(person);
				return;
			}
		}
	}
	else if(type==3)
	{
		string adminname;
		string adminpwd;
		while (ifs>>adminname&&ifs>>adminpwd)
		{
			if (adminname==name&&adminpwd==pwd)
			{
				cout << "����Ա��֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				ManagerMenu(person);

				return;
			}
		}
	}
	cout << "��֤��¼ʧ��!" << endl;
	system("pause");
	system("cls");

}



int main()
{



	int select = 0;

	while (true)
	{
		cout << "=================== ��ӭ����ţ�ӻ���ԤԼϵͳ ====================" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t  ------------------------------\n";
		cout << "\t\t |                               |\n";
		cout << "\t\t |         1��ѧ������           |\n";
		cout << "\t\t |                               |\n";
		cout << "\t\t |         2����   ʦ            |\n";
		cout << "\t\t |                               |\n";
		cout << "\t\t |         3���� �� Ա           |\n";
		cout << "\t\t |                               |\n";
		cout << "\t\t |         0����   ��            |\n";
		cout << "\t\t |                               |\n";
		cout << "\t\t  ------------------------------\n";
		cout << "��������ѡ��: ";
		cin >> select;
		switch (select)
		{
		case 1:                                 //ѧ�����
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:                                 //��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:                                 //����Ա���
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:                                  //�˳�ϵͳ
			cout << "��ӭ�´�ʹ��!" << endl;
			system("pause");
			exit(0);
			break;
		default:
			cout << "��������,������ѡ��!" << endl;
			system("pause");
			system("cls");
			break;
		}

	}

	system("pause");




	return 0;
}