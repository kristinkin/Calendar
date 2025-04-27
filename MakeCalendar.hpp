#pragma once
#include"Calendar.hpp"

class invalid_input : public std::exception {
private:
	const char* message;
	std::string str;
public:
	invalid_input(const char* _message, std::string _str) : message(_message) { str = _str; };
	const char* get_message() { return message; };
	std::string get_string() { return str; };
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

