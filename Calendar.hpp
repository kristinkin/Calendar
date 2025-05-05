#pragma once
#include<string>
#include<iostream>
#include<map>
#include<vector>
#include<array>

enum class YearType {year_once, year_for_every_month};
enum class Orientation {horizontal, vertical};

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

class CalendarGui {
private:
	class DaysFormatter;
	class VerticalDaysFormatter;
	class HorizontalDaysFormatter;

	std::shared_ptr<DaysFormatter> days_formatter{};
	YearType year_type{};
	Calendar calendar{};
	const std::array<std::string, 12> month_number_to_name{ "January", "February", "March", "April",
														"May", "June", "July", "August", "September",
														"October", "November", "December" };
	std::vector<std::string> make_month(int month, int year);
public:
	CalendarGui() = default;
	CalendarGui(Calendar& _calendar, Orientation orientation, YearType _year_type);

	void draw_formatted_calendar(std::ostream& stream);
};



