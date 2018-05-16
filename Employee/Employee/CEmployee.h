#pragma once
#include<iostream>
#include<string>
using namespace std;


const int weeklyWage = 2000;//周薪
const int hourWage = 20;//时薪
const int salesCommission = 2;//销售佣金
const int basicSalary = 3000 * 1.1;//底薪



class CDate
{
protected:
	int year, month, day;
	static int thisMonth;
public:
	CDate()
	{
		cout << "雇员生日（年/月/日）：" << endl;
		cin >> year >> month >> day;
	}
	static void SetThisMonth()
	{
		cout << "本月为：" << endl;
		cin >> thisMonth;
	}
	int award()
	{
		if (thisMonth == month)
			return 100;
		else
			return 0;
	}
	friend class CEmployee;
	friend class CSalariedEmployee;
	friend class CHourlyEmployee;
	friend class CCommissionEmployee;
	friend class CBasePlusCommissionEmployee;
};


int CDate::thisMonth = 0;

class CEmployee
{
protected:
	string name;//姓名
	int id;//工号
public:
	CDate birthDate;
	CEmployee()
	{
	}
	CEmployee(const string name_, const int id_) :name(name_), id(id_)
	{
	}
	virtual void tellInf() = 0;//输出工资
	friend class CSalariedEmployee;
	friend class CHourlyEmployee;
	friend class CCommissionEmployee;
	friend class CBasePlusCommissionEmployee;
};


class CSalariedEmployee :public CEmployee
{
	int salary;
	const string type = "周薪雇员";
public:
	CSalariedEmployee(const string name_, const int id_) :CEmployee(name_, id_)
	{
		salary = weeklyWage + birthDate.award();
	}
	void tellInf()//输出信息
	{
		cout << "雇员类型：" << type << endl
			<< "姓名：" << name << endl
			<< "工号：" << id << endl
			<< "工资明细：" << endl
			<< "周薪：" << weeklyWage << endl;
		if (birthDate.thisMonth == birthDate.month)
			cout << "生日奖金：100" << endl;
		cout << "总工资：" << salary << endl;
	}
};


class CHourlyEmployee :public CEmployee
{
protected:
	int salary, hour;
	const string type = "时薪雇员";
public:
	CHourlyEmployee(const string name_, const int id_) :CEmployee(name_, id_)
	{
		cout << "工作时长：" << endl;
		cin >> hour;
		if (hour <= 40)
			salary = hour * hourWage + birthDate.award();
		else
			salary = (int)(40 * hourWage + (hour - 40)*hourWage*1.5) + birthDate.award();
	}
	virtual void tellInf()//输出信息
	{
		cout << "雇员类型：" << type << endl
			<< "姓名：" << name << endl
			<< "工号：" << id << endl
			<< "工资明细：" << endl
			<< "时薪：" << hourWage << endl
			<< "工作时长：" << hour << endl;
		if (birthDate.thisMonth == birthDate.month)
			cout << "生日奖金：100" << endl;
		cout << "总工资：" << salary << endl;
	}
};


class CCommissionEmployee :public CEmployee
{
protected:
	int salary, salesVolume;
	const string type = "佣金雇员";
public:
	CCommissionEmployee(const string name_, const int id_) :CEmployee(name_, id_)
	{
		cout << "销售量：" << endl;
		cin >> salesVolume;
		salary = salesVolume * salesCommission + birthDate.award();
	}
	virtual void tellInf()//输出信息
	{
		cout << "雇员类型：" << type << endl
			<< "姓名：" << name << endl
			<< "工号：" << id << endl
			<< "工资明细：" << endl
			<< "销售量：" << salesVolume << endl
			<< "销售佣金：" << salesCommission << endl;
		if (birthDate.thisMonth == birthDate.month)
			cout << "生日奖金：100" << endl;
		cout << "总工资：" << salary << endl;
	}
	friend class BasePlusCommissionEmployee;
};


class CBasePlusCommissionEmployee :public CCommissionEmployee
{
protected:
	const string type = "带薪佣金雇员";
public:
	CBasePlusCommissionEmployee(const string name_, const int id_) :CCommissionEmployee(name_, id_)
	{
		salary = basicSalary + salesVolume * salesCommission + birthDate.award();
	}
	virtual void tellInf()//输出信息
	{
		cout << "雇员类型：" << type << endl
			<< "姓名：" << name << endl
			<< "工号：" << id << endl
			<< "工资明细：" << endl
			<< "底薪：" << basicSalary << endl
			<< "销售量：" << salesVolume << endl
			<< "销售佣金：" << salesCommission << endl;
		if (birthDate.thisMonth == birthDate.month)
			cout << "生日奖金：100" << endl;
		cout << "总工资：" << salary << endl;
	}
};