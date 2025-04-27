#include <fstream>
#include"Calendar.hpp"
#include"MakeCalendar.hpp"

int main(int argc, char** argv){
	std::istream* istream;
	std::ostream* ostream;
	std::ifstream ifile;
	std::ofstream ofile;
	if (argc >= 3) {
		ifile.open(argv[1]);
		if (ifile.is_open())
			istream = &ifile;
		else{
			std::cerr << "Can't open input file: " << argv[1] << std::endl;
			return 1;
		}

		ofile.open(argv[2]);
		if(ofile.is_open())
			ostream = &ofile;
		else {
			std::cerr << "Can't open output file: " << argv[2] << std::endl;
			return 1;
		}
	}
	else if (argc == 1) {
		istream = &std::cin;
		ostream = &std::cout;
	}
	else{
		std::cerr << "Invalid input" << std::endl;
		return 1;
	}

	std::vector<CalendarGui> calendars_to_draw = CalendarStreamReader::get_calendar_guis(*istream);

	for (auto calendar : calendars_to_draw) {
		calendar.draw_formatted_calendar(*ostream);
	}

	if (ifile.is_open())
		ifile.close();
	if (ofile.is_open())
		ofile.close();

	return 0;
}