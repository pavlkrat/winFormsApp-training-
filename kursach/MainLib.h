#include <string>
#include <vector>

#pragma once

class Date {
private:
	int month, day, year;
public:
	Date() :month(0), day(0), year(0) {}
	Date(int d, int m, int y) :month(m), day(d), year(y) {}
	Date(System::DateTime dt) :month(dt.Month), day(dt.Day), year(dt.Year) {}
	int getDay() { return day; }
	int getMonth() { return month; }
	int getYear() { return year; }
	std::string toString();
	std::string toFileString();
	bool operator==(const Date& otherDate) const;
	struct Hash
	{
		size_t operator()(const Date& date) const;
	};
};

class Person {
protected:
	std::string name, phone;
	Date birthday;
public:
	Person() :name("unknown"), phone("+375291234567"), birthday(Date()) {}
	Person(std::string n, std::string p, Date b) :name(n), phone(p), birthday(b) {}
	std::string getName() { return name; }
	std::string getPhone() { return phone; }
	Date getBirthday() { return birthday; }
	virtual std::string toString();
	virtual ~Person() = default;
};

class Client : public Person {
private:
	int idx, price;
	std::string proc;
public:
	Client(std::string n, std::string p, Date b, int i, std::string pro, int pri) :Person(n, p, b), idx(i), proc(pro), price(pri) {}
	int getIdx() { return idx; }
	std::string getProc() { return proc; }
	int getPrice() { return price; }
	bool isBd(Date);
	std::string toString() override;
	~Client() override = default;
};

std::string SysToStd(System::String^);
System::String^ StdToSys(std::string);
bool checkNumber(std::string);