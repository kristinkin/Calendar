#pragma once
#include"Calendar.hpp"

class invalid_input : public std::exception {
public:
	invalid_input(const std::string& _str) : exception{ ("invalid input in string: " + _str).c_str() } {};
};

class CalendarParser {
public:
	static Calendar string_to_calendar(std::string str);
};

class CalendarGuiParser {
public:
	static CalendarGui string_to_calendar_gui(Calendar& calendar, std::string str);
};

class CalendarStreamReader {
public:
	static std::vector<CalendarGui> get_calendar_guis(std::istream& stream);
};

