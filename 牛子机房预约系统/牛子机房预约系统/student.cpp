#include"student.h"


Student::Student()
{

}

Student::Student(int id, string name, string pwd)
{
	this->m_id = id;
	this->m_UserName = name;
	this->m_Pwd = pwd;

	ifstream ifs;
	ifs.open(COMPUTERROOM_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ������ڻ����ļ�Ϊ��!" << endl;
		ifs.close();
		return;
	}
	ComputerRoom com;
	while (ifs >> com.Com_Id && ifs >> com.ComputerMax_Capacity)
	{
		v_Com1.push_back(com);
	}
	
	ifs.close();
}

void Student::Apply_Order()
{
	cout << "��������ʱ��Ϊ��һ������!" << endl;
	cout << "����������ԤԼ��ʱ��: " << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;

	int week = 0;        //����
	int interval = 0;    //ʱ���
	int room = 0;        //�������

	while (true)
	{
		cin >> week;
		if (week>=1&&week<=5)
		{
			break;
		}
		else
		{
			cout << "��������ʱ��Ϊ��һ������,����ʱ��β��޿���,����������: " << endl;
		}
	}
	cout << "����������ԤԼ��ʱ���: " << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "��������,����������" << endl;
	}
	cout << "��ѡ�����: " << endl;
	for (int i = 0; i < v_Com1.size(); i++)
	{
		cout << "����ID: " << v_Com1[i].Com_Id << " ��������: " << v_Com1[i].ComputerMax_Capacity << endl;

	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "��������,����������" << endl;
	}
	cout << "ԤԼ�ɹ�,�����..." << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);

	ofs << "week:" << week << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_id << " ";
	ofs << "stuName:" << this->m_UserName << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << " " << endl;

	ofs.close();
	system("pause");
	system("cls");
}

void Student::Show_MyOrder()
{
	OrderFile of;
	if (of.m_Size==0)
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
			if (this->m_id==atoi(of.m1[i]["stuId"].c_str()))
			{
				cout << "ԤԼ����: �� " << of.m1[i]["week"];
				cout<< " ʱ���: " << (of.m1[i]["interval"] == "1" ? "����" : "����");
				cout << " ������: " << of.m1[i]["roomId"];
				string status = " ״̬: ";
				if (of.m1[i]["status"]=="1")
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
					status +="ȡ��ԤԼ";
				}
				cout << status << endl;
			}

		}
		
	}
	system("pause");
	system("cls");
}

void Student::Show_AllOrder()
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
					status +="ȡ��ԤԼ";
				}
				cout << status << endl;
			}


	}
	system("pause");
	system("cls");
}

void Student::Cancel_Order()
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
		cout << "ԤԼ״̬Ϊ����л�����˳ɹ��ļ�¼����ȡ��ԤԼ!" << endl;
		vector<int>v;
		int index = 1;

		for (int i = 0; i <of.m_Size ; i++)
		{
			if (this->m_id == atoi(of.m1[i]["stuId"].c_str()))
			{
				if (of.m1[i]["status"]=="1"||of.m1[i]["status"]=="2")
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
					else if (of.m1[i]["status"] == "2")
					{
						status += "ԤԼ�ɹ�";
					}
					cout << status << endl;
				}
			}
		}
		cout << "��ѡ��Ҫɾ���ļ�¼,�����밴0:" << endl;
		int select;
		while (true)
		{
			cin >> select;
			if (select==0)
			{
				break;
			}
			else if (select > 0 && select <= v.size())
			{
				of.m1[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "ԤԼ�Ѿ�ȡ��!" << endl;

				break;
			}
			else
			{
				cout << "��������,����������!" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}

void Student::Show_Menu()
{
	cout << "��ӭѧ������: " << this->m_UserName << " ��¼! " << endl;
	cout << "\t\t  ------------------------------\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t |         1������ԤԼ           |\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t |         2���鿴�ҵ�ԤԼ       |\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t |         3���鿴����ԤԼ       |\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t |         4��ȡ��ԤԼ           |\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t |         0��ע����¼           |\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t  ------------------------------\n";
	cout << "��ѡ�����Ĳ���: ";
}