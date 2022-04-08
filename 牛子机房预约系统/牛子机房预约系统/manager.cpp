#include"manager.h"

Manager::Manager()
{

}

Manager::Manager(string name, string pwd)
{
	this->m_UserName = name;
	this->m_Pwd = pwd;
	this->Init_Vector();

	ifstream ifs;
	ifs.open(COMPUTERROOM_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ������ڻ����ļ�Ϊ��!" << endl;
		ifs.close();
		return;
	}
	ComputerRoom com;
	while (ifs>>com.Com_Id&&ifs>>com.ComputerMax_Capacity)
	{
		v_Com.push_back(com);
	}
	cout << "��ǰ��������: " << v_Com.size() << endl;
	ifs.close();
}
bool  Manager::Check_Repeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it =v_Stu.begin(); it !=v_Stu.end(); it++)
		{
			if (id == it->m_id)
			{
				return true;
			}
		}
	}
	else if (type == 2)
	{
		for (vector<Teacher>::iterator it = v_Tea.begin(); it != v_Tea.end(); it++)
		{
			if (id == it->t_id)
			{
				return true;
			}
		}
	}
	return false;
}

void  Manager::Init_Vector()
{
	v_Stu.clear();
	v_Tea.clear();
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�Ϊ�ջ����ļ�������!" << endl;
		ifs.close();
		return;
	}
	Student s;
	while (ifs>>s.m_id&&ifs>>s.m_UserName&&ifs>>s.m_Pwd)
	{
		v_Stu.push_back(s);
	}
	cout << "��ǰѧ������: " << v_Stu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�Ϊ�ջ����ļ�������!" << endl;
		ifs.close();
		return;
	}
	Teacher t;
	while (ifs >> t.t_id&& ifs >> t.m_UserName && ifs >> t.m_Pwd)
	{
		v_Tea.push_back(t);
	}
	cout << "��ǰ��ʦ����: " << v_Tea.size() << endl;
	ifs.close();


}
void Manager::Add_Person()
{
	cout << "������Ҫ��ӵ��˺�����: " << endl;
	cout << "1�����ѧ���˺�" << endl;
	cout << "2�������ʦ�˺�" << endl;
	int select;
	string filename;
	string tip;
	string errortip;
	ofstream ofs;
	while (true)
	{
		cin >> select;
		if (select == 1)
		{
			filename = STUDENT_FILE;
			tip = "������ѧ��ѧ��: ";
			errortip = "ѧ���ظ�,����������: ";
			break;
		}
		else if(select==2)
		{
			filename = TEACHER_FILE;
			tip = "�������ʦְ����: ";
			errortip = "ְ�����ظ�,����������: ";
			break;
		}
		else
		{
			cout << "��������,����������: " << endl;
		}
	}
	ofs.open(filename, ios::out | ios::app);
	int id;
	string username;
	string pwd;
	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret = this->Check_Repeat(id, select);
		if (ret)
		{
			cout << errortip << endl;
		}
		else
		{
			break;
		}
	}
	cout << "�������û���: " << endl;
	cin >> username;
	cout << "����������: " << endl;
	cin >> pwd;
	ofs << id << " " << username << " " << pwd<<" "<<endl;
	cout << "��ӳɹ�!" << endl;
	system("pause");
	system("cls");
	ofs.close();
	this->Init_Vector();
}
void StudentPrintf(Student& s)
{
	cout << "ѧ��: " << s.m_id << " �˺�: " << s.m_UserName << " ����: " << s.m_Pwd << endl;
}
void TeacherPrintf(Teacher& t)
{
	cout << "ѧ��: " << t.t_id << " �˺�: " << t.m_UserName << " ����: " << t.m_Pwd << endl;
}
void Manager::Show_Person()
{
	cout << "������Ҫ�鿴���˺�����: " << endl;
	cout << "1��ѧ���˺�" << endl;
	cout << "2����ʦ�˺�" << endl;
	int select;
	cin >> select;
	if (select==1)
	{
		cout << "����ѧ������Ϣ����: " << endl;
		for_each(v_Stu.begin(), v_Stu.end(), StudentPrintf);
	}
	else
	{
		cout << "������ʦ����Ϣ����: " << endl;
		for_each(v_Tea.begin(), v_Tea.end(), TeacherPrintf);
	}
	system("pause");
	system("cls");
}
void ComputerRoomPrintf(ComputerRoom& com)
{
	cout << "����ID: " << com.Com_Id << " ��������: " << com.ComputerMax_Capacity << endl;
}
void Manager::Show_Computer()
{
	cout << "������Ϣ����: " << endl;
	for_each(v_Com.begin(), v_Com.end(), ComputerRoomPrintf);
	system("pause");
	system("cls");
}

void Manager::Clean_File()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "��ճɹ�!" << endl;
	system("pause");
	system("cls");
}

void Manager::Show_Menu()
{
	cout << "��ӭ����Ա: " << this->m_UserName << " ��¼! " << endl;
	cout << "\t\t  ------------------------------\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t |         1������˺�           |\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t |         2���鿴�˺�           |\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t |         3���鿴����           |\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t |         4�����ԤԼ��¼       |\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t |         0��ע����¼           |\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t  ------------------------------\n";
	cout << "��ѡ�����Ĳ���: ";
}