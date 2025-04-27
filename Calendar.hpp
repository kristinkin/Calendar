#pragma once
#include<string>
#include<iostream>
#include<map>
#include<vector>
#include<array>

enum class YearType {year_once, year_for_every_month};

class Calendar {
	int month_1{};
	int year_1{};
	int month_2{};
	int year_2{};
public:
	Calendar() = default;
	Calendar(int month, int year);
	Calendar(int year);
	Calendar(int _month_1, int _year_1, int _month_2, int _year_2);
	int get_month_1() { return month_1; }
	int get_month_2() { return month_2; }
	int get_year_1() { return year_1; }
	int get_year_2() { return year_2; }
};

class DaysFormatter {
protected:
	int get_week_day(int month, int year);
	bool is_leap_year(int year);
	std::array<int, 12> how_many_days{ 31, 28, 31, 30,31, 30, 31, 31, 30, 31, 30, 31 };
	const std::array<std::string, 7> days_of_week{ "Mo", "Tu", "We", "Th", "Fr", "Sa", "Su" };
public:
	virtual std::vector<std::string> make_days(int month, int year) = 0;
};

class VerticalDaysFormatter : public DaysFormatter {
public:
	virtual std::vector<std::string> make_days(int month, int year);
};

class HorizontalDaysFormatter : public DaysFormatter {
public:
	virtual std::vector<std::string> make_days(int month, int year);
};

class CalendarGui {
private:
	DaysFormatter* days_formatter;
	YearType year_type{};
	Calendar calendar{};
	const std::array<std::string, 12> month_number_to_name{ "January", "February", "March", "April",
														"May", "June", "July", "August", "September",
														"October", "November", "December" };
	std::vector<std::string> make_month(int month, int year);
public:
	CalendarGui() = default;
	CalendarGui(Calendar _calendar, DaysFormatter* _days_formatter, YearType _year_type) : days_formatter(_days_formatter) {
		calendar = _calendar; year_type = _year_type; 
	};

	void draw_formatted_calendar(std::ostream& stream);
};



