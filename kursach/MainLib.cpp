#include "MainLib.h"
#include <msclr\marshal_cppstd.h>

std::string Date::toString() {
	std::string sd = (day < 10 ? "0" : "") + std::to_string(day);
	std::string sm = (month < 10 ? "0" : "") + std::to_string(month);
	std::string sy = std::to_string(year);
	return sd + "." + sm + "." + sy;
}

std::string Date::toFileString() {
	return std::to_string(day) + " " + std::to_string(month) + " " + std::to_string(year);
}

std::string Person::toString() {
	return "Name: " + name + "\nPhone: " + phone + "\nBirthday: " + birthday.toString() + "\n";
}

std::string Client::toString() {
	return "Name: " + name + "\nPhone: " + phone + "\nProcedure: " + proc + "\nPrice: " + std::to_string(price) + "\n";
}

bool Client::isBd(Date d) {
	Date cur = getBirthday();
	return d.getDay() == cur.getDay() && d.getMonth() == cur.getMonth();
}

std::string SysToStd(System::String^ s) {
	return msclr::interop::marshal_as<std::string>(s);
}

System::String^ StdToSys(std::string s) {
	return gcnew System::String(s.data());
}

bool checkNumber(std::string s) {
	for (int i = 1;i < s.length();i++)
		if (s[i] < '0' || s[i] > '9')
			return false;
	return (s.length() == 13 && s.substr(0, 4) == "+375" && (s.substr(4, 2) == "29" || s.substr(4, 2) == "44"));
}

bool Date::operator==(const Date& otherDate) const {
	return (year == otherDate.year && month == otherDate.month && day == otherDate.day);
}

size_t Date::Hash::operator()(const Date& date) const {
	return date.year + (date.month << 12) + (date.day << 16);
}