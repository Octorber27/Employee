#include<string>
#include<vector>
#include"CEmployee.h"


int main()
{
	string name_;
	int id_, type_, num;
	vector<CEmployee*> employee;
	cout << "��Ա������" << endl;
	cin >> num;
	CEmployee *q;
	CDate::SetThisMonth();
	for (int i = 0; i < num; ++i)
	{
		cout << "��" << i + 1 << "����Ա����Ϊ��" << endl;
		cout << "1.��н��Ա 2.ʱн��Ա 3.Ӷ���Ա 4.����нӶ���Ա\n";
		cin >> type_;
		cout << "�����͹��ţ�\n";
		cin >> name_ >> id_;
		if (type_ == 1)
		{

			CSalariedEmployee * p1 = new CSalariedEmployee(name_, id_);
			employee.push_back(p1);
		}
		if (type_ == 2) 
		{
			CHourlyEmployee * p2 = new CHourlyEmployee(name_, id_);
			employee.push_back(p2);
		}
		if (type_ == 3)
		{
			CCommissionEmployee * p3 = new CCommissionEmployee(name_, id_);
			employee.push_back(p3);
		}
		if (type_ == 4)
		{
			CBasePlusCommissionEmployee * p4 = new CBasePlusCommissionEmployee(name_, id_);
			employee.push_back(p4);
		}
	}
	for (int i = 0; i < num; ++i)
	{
		q = employee[i];
		q->tellInf();
	}
	return 0;
}