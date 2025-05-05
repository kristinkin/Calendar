#include <fstream>
#include"Calendar.hpp"
#include"MakeCalendar.hpp"

int main(int argc, char** argv){
	std::ifstream ifile;
	std::ofstream ofile;
	if (argc >= 3) {
		ifile.open(argv[1]);
		if (!ifile.is_open()) {
			std::cerr << "Can't open input file: " << argv[1] << std::endl;
			return 1;
		}
		ofile.open(argv[2]);
		if (!ofile.is_open()) {
			std::cerr << "Can't open output file: " << argv[2] << std::endl;
			return 1;
		}
	}
	else if (argc != 1) {
		std::cerr << "Invalid input" << std::endl;
		return 1;
	}

	std::istream& istream = (argc >= 3) ? ifile : std::cin;
	std::ostream& ostream = (argc >= 3) ? ofile : std::cout;

	//std::vector<CalendarGui> calendars_to_draw = CalendarStreamReader::get_calendar_guis(istream);

	/*for (auto &calendar : calendars_to_draw) {
		calendar.draw_formatted_calendar(ostream);
	}*/

	if (ifile.is_open())
		ifile.close();
	if (ofile.is_open())
		ofile.close();
	return 0;
}