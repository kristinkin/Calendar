#include"MakeCalendar.hpp"
#include<sstream>

std::vector<CalendarGui> CalendarStreamReader::get_calendar_guis(std::istream& stream) {
	std::string str;
	std::vector<CalendarGui> calendar_guis;
	while (std::getline(stream, str)) {
		if (str.empty()) {
			if (&stream == &std::cin)
				break;
			continue;
		}
		try {
			Calendar new_calendar = CalendarParser::string_to_calendar(str.substr(0, str.find("|") - 1));
			CalendarGui new_calendar_gui = CalendarGuiParser::string_to_calendar_gui(new_calendar, str.substr(str.find("|") + 1, str.length() - str.find("|")));
			calendar_guis.push_back(new_calendar_gui);
		}
		catch (invalid_input& error) {
			std::cerr << error.get_message() << error.get_string() << std::endl;
		}
	}
	return calendar_guis;
}

std::vector<std::string> split_on_words(std::string str) {
	std::stringstream s_str(str);
	std::string word;
	std::vector<std::string> words{};
	while (s_str >> word) {
		words.push_back(word);
	}
	return words;
}

Calendar CalendarParser::string_to_calendar(std::string str) {
	size_t num_success = 0;
	int month_1 = 0;
	int year_1 = 0;
	int month_2 = 0;
	int year_2 = 0;
	std::vector<std::string> words = split_on_words(str);

	if (words[0] == "month") {
		if (isdigit(words[1][0])) {
			month_1 = std::stoi(words[1], &num_success, 10);
			if (num_success == 0 || num_success > 2) {
				throw invalid_input("invalid input in string: ", str);
			}
		}
		if (isdigit(words[2][0])) {
			year_1 = std::stoi(words[2], &num_success, 10);
			if (num_success == 0) {
				throw invalid_input("invalid input in string: ", str);
			}
		}
		else {
			throw invalid_input("invalid input in string: ", str);
		}
		return Calendar(month_1, year_1);
	}
	else if (words[0] == "year") {
		if (isdigit(words[1][0])) {
			year_1 = std::stoi(words[1], &num_success, 10);
			if (num_success == 0) {
				throw invalid_input("invalid input in string: ", str);
			}
			return Calendar(year_1);
		}
		else {
			throw invalid_input("invalid input in string: ", str);
		}
	}
	else if (words[0] == "range") {
		if (isdigit(words[1][0])) {
			month_1 = std::stoi(words[1], &num_success, 10);
			if (num_success == 0 || num_success > 2) {
				throw invalid_input("invalid input in string: ", str);
			}
		}
		else { throw invalid_input("invalid input in string: ", str); }
		if (isdigit(words[2][0])) {
			year_1 = std::stoi(words[2], &num_success, 10);
			if (num_success == 0) {
				throw invalid_input("invalid input in string: ", str);
			}
		}
		else { throw invalid_input("invalid input in string: ", str); }
		if (isdigit(words[3][0])) {
			month_2 = std::stoi(words[3], &num_success, 10);
			if (num_success == 0 || num_success > 2) {
				throw invalid_input("invalid input in string: ", str);
			}
		}
		else { throw invalid_input("invalid input in string: ", str); }
		if (isdigit(words[4][0])) {
			year_2 = std::stoi(words[4], &num_success, 10);
			if (num_success == 0) {
				throw invalid_input("invalid input in string: ", str);
			}
		}
		else { throw invalid_input("invalid input in string: ", str); }
		return Calendar(month_1, year_1, month_2, year_2);
	}
	else {
		throw invalid_input("invalid input in string: ", str);
	}
}

CalendarGui CalendarGuiParser::string_to_calendar_gui(Calendar& calendar, std::string str) {

	std::vector<std::string> words = split_on_words(str);

	if (words.size() > 1) {
		if ((words[0] == "vert" && words[1] == "year_once") || (words[1] == "vert" && words[0] == "year_once")) {
			return CalendarGui(calendar, new VerticalDaysFormatter, YearType::year_once);
		}
		else if ((words[0] == "horiz" && words[1] == "year_once") || (words[1] == "horiz" && words[0] == "year_once")) {
			return CalendarGui(calendar, new HorizontalDaysFormatter, YearType::year_once);
		}
		if ((words[0] == "vert" && words[1] == "year_for_every_month") || (words[1] == "vert" && words[0] == "year_for_every_month")) {
			return CalendarGui(calendar, new VerticalDaysFormatter, YearType::year_for_every_month);
		}
		else if ((words[0] == "horiz" && words[1] == "year_for_every_month") || (words[1] == "horiz" && words[0] == "year_for_every_month")) {
			return CalendarGui(calendar, new HorizontalDaysFormatter, YearType::year_for_every_month);
		}
		else {
			throw invalid_input("invalid input in string: ", str);
		}
	}
	else {
		throw invalid_input("invalid input in string: ", str);
	}
}