#include<string>
#include<vector>
#include"CEmployee.h"


int main()
{
	string name_;
	int id_, type_, num;
	vector<CEmployee*> employee;
	cout << "雇员人数：" << endl;
	cin >> num;
	CEmployee *q;
	CDate::SetThisMonth();
	for (int i = 0; i < num; ++i)
	{
		cout << "第" << i + 1 << "个雇员类型为：" << endl;
		cout << "1.周薪雇员 2.时薪雇员 3.佣金雇员 4.带底薪佣金雇员\n";
		cin >> type_;
		cout << "姓名和工号：\n";
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