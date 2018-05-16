#pragma once
#include<iostream>
#include<string>
using namespace std;


const int weeklyWage = 2000;//��н
const int hourWage = 20;//ʱн
const int salesCommission = 2;//����Ӷ��
const int basicSalary = 3000 * 1.1;//��н



class CDate
{
protected:
	int year, month, day;
	static int thisMonth;
public:
	CDate()
	{
		cout << "��Ա���գ���/��/�գ���" << endl;
		cin >> year >> month >> day;
	}
	static void SetThisMonth()
	{
		cout << "����Ϊ��" << endl;
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
	string name;//����
	int id;//����
public:
	CDate birthDate;
	CEmployee()
	{
	}
	CEmployee(const string name_, const int id_) :name(name_), id(id_)
	{
	}
	virtual void tellInf() = 0;//�������
	friend class CSalariedEmployee;
	friend class CHourlyEmployee;
	friend class CCommissionEmployee;
	friend class CBasePlusCommissionEmployee;
};


class CSalariedEmployee :public CEmployee
{
	int salary;
	const string type = "��н��Ա";
public:
	CSalariedEmployee(const string name_, const int id_) :CEmployee(name_, id_)
	{
		salary = weeklyWage + birthDate.award();
	}
	void tellInf()//�����Ϣ
	{
		cout << "��Ա���ͣ�" << type << endl
			<< "������" << name << endl
			<< "���ţ�" << id << endl
			<< "������ϸ��" << endl
			<< "��н��" << weeklyWage << endl;
		if (birthDate.thisMonth == birthDate.month)
			cout << "���ս���100" << endl;
		cout << "�ܹ��ʣ�" << salary << endl;
	}
};


class CHourlyEmployee :public CEmployee
{
protected:
	int salary, hour;
	const string type = "ʱн��Ա";
public:
	CHourlyEmployee(const string name_, const int id_) :CEmployee(name_, id_)
	{
		cout << "����ʱ����" << endl;
		cin >> hour;
		if (hour <= 40)
			salary = hour * hourWage + birthDate.award();
		else
			salary = (int)(40 * hourWage + (hour - 40)*hourWage*1.5) + birthDate.award();
	}
	virtual void tellInf()//�����Ϣ
	{
		cout << "��Ա���ͣ�" << type << endl
			<< "������" << name << endl
			<< "���ţ�" << id << endl
			<< "������ϸ��" << endl
			<< "ʱн��" << hourWage << endl
			<< "����ʱ����" << hour << endl;
		if (birthDate.thisMonth == birthDate.month)
			cout << "���ս���100" << endl;
		cout << "�ܹ��ʣ�" << salary << endl;
	}
};


class CCommissionEmployee :public CEmployee
{
protected:
	int salary, salesVolume;
	const string type = "Ӷ���Ա";
public:
	CCommissionEmployee(const string name_, const int id_) :CEmployee(name_, id_)
	{
		cout << "��������" << endl;
		cin >> salesVolume;
		salary = salesVolume * salesCommission + birthDate.award();
	}
	virtual void tellInf()//�����Ϣ
	{
		cout << "��Ա���ͣ�" << type << endl
			<< "������" << name << endl
			<< "���ţ�" << id << endl
			<< "������ϸ��" << endl
			<< "��������" << salesVolume << endl
			<< "����Ӷ��" << salesCommission << endl;
		if (birthDate.thisMonth == birthDate.month)
			cout << "���ս���100" << endl;
		cout << "�ܹ��ʣ�" << salary << endl;
	}
	friend class BasePlusCommissionEmployee;
};


class CBasePlusCommissionEmployee :public CCommissionEmployee
{
protected:
	const string type = "��нӶ���Ա";
public:
	CBasePlusCommissionEmployee(const string name_, const int id_) :CCommissionEmployee(name_, id_)
	{
		salary = basicSalary + salesVolume * salesCommission + birthDate.award();
	}
	virtual void tellInf()//�����Ϣ
	{
		cout << "��Ա���ͣ�" << type << endl
			<< "������" << name << endl
			<< "���ţ�" << id << endl
			<< "������ϸ��" << endl
			<< "��н��" << basicSalary << endl
			<< "��������" << salesVolume << endl
			<< "����Ӷ��" << salesCommission << endl;
		if (birthDate.thisMonth == birthDate.month)
			cout << "���ս���100" << endl;
		cout << "�ܹ��ʣ�" << salary << endl;
	}
};