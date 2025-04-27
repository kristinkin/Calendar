#include"Calendar.hpp"

Calendar::Calendar(int month, int year) {
	month_1 = month;
	month_2 = month;
	year_1 = year;
	year_2 = year;
}

Calendar::Calendar(int year) {
	month_1 = 1;
	month_2 = 12;
	year_1 = year;
	year_2 = year;
}

Calendar::Calendar(int _month_1, int _year_1, int _month_2, int _year_2) {
	month_1 = _month_1;
	month_2 = _month_2;
	year_1 = _year_1;
	year_2 = _year_2;
}

bool DaysFormatter::is_leap_year(int year) {
	bool is_leap_year;
	if (year % 4 != 0)
		is_leap_year = false;
	else {
		if (year % 100 == 0) {
			if (year % 400 == 0)
				is_leap_year = true;
			else
				is_leap_year = false;
		}
		else
			is_leap_year = true;
	}
	return is_leap_year;
}

int DaysFormatter::get_week_day(int month, int year) {
	std::map<int, int> month_code = {
		{1, 1},
		{2, 4},
		{3, 4},
		{4, 0},
		{5, 2},
		{6, 5},
		{7, 0},
		{8, 3},
		{9, 6},
		{10, 1},
		{11, 4},
		{12, 6}
	};

	if (is_leap_year(year)) {
		month_code[1] = 0;
		month_code[2] = 3;
	}
	int year_code = (6 + year % 100 + (year % 100) / 4) % 7;
	int week_day = (1 + month_code[month] + year_code) % 7 - 1;
	if (week_day == -1)
		week_day = 6;
	if (week_day == 0)
		week_day = 7;
	return week_day;
}

std::vector<std::string> HorizontalDaysFormatter::make_days(int month, int year) {
	int first_week_day = get_week_day(month, year);
	if (is_leap_year(year))
		how_many_days[2-1] = 29;

	std::vector<std::string> one_month;
	std::string line;
	for (int i = 0; i < 7; i++) {
		line += (days_of_week[i] + "  ");
	}
	one_month.push_back(line);
	int n = 1;
	
	line.clear();
	for (int i = 1; i <= 42; i++) {
		if (i >= first_week_day && n <= how_many_days[month-1]) {
			line += std::to_string(n);
			if (n % 10 == n)
				line += "   ";
			else
				line += "  ";
			n++;
		}
		else {
			line += "    ";
		}
		if (i % 7 == 0) {
			one_month.push_back(line);
			line.clear();
		}
	}
	one_month.push_back(line);
	how_many_days[2-1] = 28;
	return one_month;
}

std::vector<std::string> VerticalDaysFormatter::make_days(int month, int year) {
	int first_week_day = get_week_day(month, year);
	if (is_leap_year(year))
		how_many_days[2-1] = 29;

	std::vector<std::string> one_month;
	for (int i = 1; i <= 7; i++) {
		std::string line = days_of_week[i-1] + "  ";
		if (i < first_week_day) {
			line += "   ";
		}
		else {
			line += std::to_string(i - first_week_day + 1) + "  ";
		}
		for (int n = 8 - first_week_day + i; n <= 35 + i; n += 7) {
			if (n <= how_many_days[month-1])
				line += std::to_string(n);
			else
				line += "  ";
			if (n % 10 == n)
				line += " ";
			line += "  ";
		}
		one_month.push_back(line);
	}
	how_many_days[2-1] = 28;
	return one_month;
}

std::vector<std::string> CalendarGui::make_month(int month, int year) {
	std::vector<std::string> one_month;

	one_month = days_formatter->make_days(month, year);

	one_month.insert(one_month.begin(), "    " + month_number_to_name[month-1] + " ");

	if (year_type == YearType::year_for_every_month)
		one_month[0] += std::to_string(year);

	for (int i = 0; i < 23 - month_number_to_name[month-1].size() - std::to_string(year).size() * (year_type == YearType::year_for_every_month); i++)
		one_month[0] += " ";

	return one_month;
}

void CalendarGui::draw_formatted_calendar(std::ostream& stream) {
	for (int year = calendar.get_year_1(); year <= calendar.get_year_2(); year++) {
		if (year_type == YearType::year_once) {
			stream << "                                        " + std::to_string(year) << std::endl;
			stream << std::endl;
		}
		int month_lower = 1;
		int month_upper = 12;
		if (year == calendar.get_year_1()) {
			month_lower = calendar.get_month_1();
		}
		if (year == calendar.get_year_2()) {
			month_upper = calendar.get_month_2();
		}
		for (int month = month_lower; month <= month_upper;) {
			std::vector<std::vector<std::string>> months_to_draw;
			int size = 0;
			while (size < 3 && month + size <= month_upper) {
				months_to_draw.push_back(make_month(month + size, year));
				size++;
			}
			for (int i_line = 0; i_line < 9; i_line++) {
				for (int i = 0; i < size; i++) {
					if(i_line < months_to_draw[i].size())
						stream << months_to_draw[i][i_line] + "   ";
				}
				stream << std::endl;
			}
			month += size;
		}
	}
	
	
}