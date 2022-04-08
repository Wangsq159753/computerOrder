#include"Teacher.h"

Teacher::Teacher()
{

}

Teacher::Teacher(int id, string name, string pwd)
{
	this->t_id = id;
	this->m_UserName = name;
	this->m_Pwd = pwd;
}

void Teacher::Show_AllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼!" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		for (int i = 0; i < of.m_Size; i++)
		{

			cout << "ԤԼ����: �� " << of.m1[i]["week"];
			cout << " ʱ���: " << (of.m1[i]["interval"] == "1" ? "����" : "����");
			cout << " ѧ��: " << of.m1[i]["stuId"];
			cout << " ����: " << of.m1[i]["stuName"];
			cout << " ������: " << of.m1[i]["roomId"];
			string status = " ״̬: ";
			if (of.m1[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m1[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.m1[i]["status"] == "-1")
			{
				status += "ԤԼʧ��,���δͨ��";
			}
			else
			{
				status += "ȡ��ԤԼ";
			}
			cout << status << endl;
		}


	}
	system("pause");
	system("cls");
}

void Teacher::Check_Order()
{

	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼!" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "����˵ļ�¼����: " << endl;
		vector<int>v;
		int index = 1;

		for (int i = 0; i < of.m_Size; i++)
		{
			
				if (of.m1[i]["status"] == "1" )
				{
					v.push_back(i);
					cout << index++ << "��";
					cout << "ԤԼ����: �� " << of.m1[i]["week"];
					cout << " ʱ���: " << (of.m1[i]["interval"] == "1" ? "����" : "����");
					cout << " ������: " << of.m1[i]["roomId"];
					string status = " ״̬: ";
					if (of.m1[i]["status"] == "1")
					{
						status += "�����";
					}
					
					cout << status << endl;
				}
			
		}
		cout << "��ѡ��Ҫ��˵ļ�¼(�����밴0):" << endl;
		cout << "����������ѡ��: ";
		int select;
		while (true)
		{
			cin >> select;
			if (select == 0)
			{
				break;
			}
			else if (select==1)
			{
				of.m1[v[select - 1]]["status"] = "2";
				of.updateOrder();
				cout << "���ͨ����" << endl;
				break;
			}
			else if (select==2)
			{
				of.m1[v[select - 1]]["status"] = "-1";
				of.updateOrder();
				cout << "���δͨ����" << endl;
				break;
			}
			else
			{
				cout << "��������,����������:" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}

void Teacher::Show_Menu()
{
	cout << "��ӭ��ʦ: " << this->m_UserName << " ��¼! " << endl;
	cout << "\t\t  ------------------------------\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t |         1���鿴����ԤԼ       |\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t |         2�����ԤԼ           |\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t |         0��ע����¼           |\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t  ------------------------------\n";
	cout << "��ѡ�����Ĳ���: ";

 }