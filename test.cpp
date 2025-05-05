#include<gtest/gtest.h>
#include<fstream>
#include"Calendar.hpp"
TEST(OneMonth, Horiz_YearOnce) {
	std::string str_expected =
		"                                        2024\n"
		"\n"
		"    February                   \n"
		"Mo  Tu  We  Th  Fr  Sa  Su     \n"
		"            1   2   3   4      \n"
		"5   6   7   8   9   10  11     \n"
		"12  13  14  15  16  17  18     \n"
		"19  20  21  22  23  24  25     \n"
		"26  27  28  29                 \n"
		"                               \n"
		"   \n";
	std::stringstream str_real;
	CalendarGui calendar_gui = CalendarGui(Calendar(2, 2024), Orientation::horizontal, YearType::year_once);
	calendar_gui.draw_formatted_calendar(str_real);
	EXPECT_EQ(str_real.str(), str_expected);
}

TEST(OneMonth, Horiz_YearForEveryMonth) {
	std::string str_expected =
		"    February 2024              \n"
		"Mo  Tu  We  Th  Fr  Sa  Su     \n"
		"            1   2   3   4      \n"
		"5   6   7   8   9   10  11     \n"
		"12  13  14  15  16  17  18     \n"
		"19  20  21  22  23  24  25     \n"
		"26  27  28  29                 \n"
		"                               \n"
		"   \n";
	std::stringstream str_real;
	CalendarGui calendar_gui = CalendarGui(Calendar(2, 2024), Orientation::horizontal, YearType::year_for_every_month);
	calendar_gui.draw_formatted_calendar(str_real);
	EXPECT_EQ(str_real.str(), str_expected);
}

TEST(OneMonth, Vert_YearOnce) {
	std::string str_expected =
		"                                        2024\n"
		"\n"
		"    February                   \n"
		"Mo     5   12  19  26         \n"
		"Tu     6   13  20  27         \n"
		"We     7   14  21  28         \n"
		"Th  1  8   15  22  29         \n"
		"Fr  2  9   16  23             \n"
		"Sa  3  10  17  24             \n"
		"Su  4  11  18  25             \n"
		"\n";
	std::stringstream str_real;
	CalendarGui calendar_gui = CalendarGui(Calendar(2, 2024), Orientation::vertical, YearType::year_once);
	calendar_gui.draw_formatted_calendar(str_real);
	EXPECT_EQ(str_real.str(), str_expected);
}

TEST(OneMonth, Vert_YearForEveryMonth) {
	std::string str_expected = 
		"    February 2024              \n"
		"Mo     5   12  19  26         \n"
		"Tu     6   13  20  27         \n"
		"We     7   14  21  28         \n"
		"Th  1  8   15  22  29         \n"
		"Fr  2  9   16  23             \n"
		"Sa  3  10  17  24             \n"
		"Su  4  11  18  25             \n"
		"\n";
	std::stringstream str_real;
	CalendarGui calendar_gui = CalendarGui(Calendar(2, 2024), Orientation::vertical, YearType::year_for_every_month);
	calendar_gui.draw_formatted_calendar(str_real);
	EXPECT_EQ(str_real.str(), str_expected);
}

TEST(OneYear, Horiz_YearOnce) {
	std::string str_expected =
		"                                        2025\n"
		"\n"
		"    January                        February                       March                      \n"
		"Mo  Tu  We  Th  Fr  Sa  Su     Mo  Tu  We  Th  Fr  Sa  Su     Mo  Tu  We  Th  Fr  Sa  Su     \n"
		"        1   2   3   4   5                          1   2                          1   2      \n"
		"6   7   8   9   10  11  12     3   4   5   6   7   8   9      3   4   5   6   7   8   9      \n"
		"13  14  15  16  17  18  19     10  11  12  13  14  15  16     10  11  12  13  14  15  16     \n"
		"20  21  22  23  24  25  26     17  18  19  20  21  22  23     17  18  19  20  21  22  23     \n"
		"27  28  29  30  31             24  25  26  27  28             24  25  26  27  28  29  30     \n"
		"                                                              31                             \n"
		"         \n"
		"    April                          May                            June                       \n"
		"Mo  Tu  We  Th  Fr  Sa  Su     Mo  Tu  We  Th  Fr  Sa  Su     Mo  Tu  We  Th  Fr  Sa  Su     \n"
		"    1   2   3   4   5   6                  1   2   3   4                              1      \n"
		"7   8   9   10  11  12  13     5   6   7   8   9   10  11     2   3   4   5   6   7   8      \n"
		"14  15  16  17  18  19  20     12  13  14  15  16  17  18     9   10  11  12  13  14  15     \n"
		"21  22  23  24  25  26  27     19  20  21  22  23  24  25     16  17  18  19  20  21  22     \n"
		"28  29  30                     26  27  28  29  30  31         23  24  25  26  27  28  29     \n"
		"                                                              30                             \n"
		"         \n"
		"    July                           August                         September                  \n"
		"Mo  Tu  We  Th  Fr  Sa  Su     Mo  Tu  We  Th  Fr  Sa  Su     Mo  Tu  We  Th  Fr  Sa  Su     \n"
		"    1   2   3   4   5   6                      1   2   3      1   2   3   4   5   6   7      \n"
		"7   8   9   10  11  12  13     4   5   6   7   8   9   10     8   9   10  11  12  13  14     \n"
		"14  15  16  17  18  19  20     11  12  13  14  15  16  17     15  16  17  18  19  20  21     \n"
		"21  22  23  24  25  26  27     18  19  20  21  22  23  24     22  23  24  25  26  27  28     \n"
		"28  29  30  31                 25  26  27  28  29  30  31     29  30                         \n"
		"                                                                                             \n"
		"         \n"
		"    October                        November                       December                   \n"
		"Mo  Tu  We  Th  Fr  Sa  Su     Mo  Tu  We  Th  Fr  Sa  Su     Mo  Tu  We  Th  Fr  Sa  Su     \n"
		"        1   2   3   4   5                          1   2      1   2   3   4   5   6   7      \n"
		"6   7   8   9   10  11  12     3   4   5   6   7   8   9      8   9   10  11  12  13  14     \n"
		"13  14  15  16  17  18  19     10  11  12  13  14  15  16     15  16  17  18  19  20  21     \n"
		"20  21  22  23  24  25  26     17  18  19  20  21  22  23     22  23  24  25  26  27  28     \n"
		"27  28  29  30  31             24  25  26  27  28  29  30     29  30  31                     \n"
		"                                                                                             \n"
		"         \n";
	std::stringstream str_real;
	CalendarGui calendar_gui = CalendarGui(Calendar(2025), Orientation::horizontal, YearType::year_once);
	calendar_gui.draw_formatted_calendar(str_real);
	EXPECT_EQ(str_real.str(), str_expected);
}

TEST(OneYear, Horiz_YearForEveryMonth) {
	std::string str_expected = 
		"    January 2025                   February 2025                  March 2025                 \n"
		"Mo  Tu  We  Th  Fr  Sa  Su     Mo  Tu  We  Th  Fr  Sa  Su     Mo  Tu  We  Th  Fr  Sa  Su     \n"
		"        1   2   3   4   5                          1   2                          1   2      \n"
		"6   7   8   9   10  11  12     3   4   5   6   7   8   9      3   4   5   6   7   8   9      \n"
		"13  14  15  16  17  18  19     10  11  12  13  14  15  16     10  11  12  13  14  15  16     \n"
		"20  21  22  23  24  25  26     17  18  19  20  21  22  23     17  18  19  20  21  22  23     \n"
		"27  28  29  30  31             24  25  26  27  28             24  25  26  27  28  29  30     \n"
		"                                                              31                             \n"
		"         \n"																					  
		"    April 2025                     May 2025                       June 2025                  \n"
		"Mo  Tu  We  Th  Fr  Sa  Su     Mo  Tu  We  Th  Fr  Sa  Su     Mo  Tu  We  Th  Fr  Sa  Su     \n"
		"    1   2   3   4   5   6                  1   2   3   4                              1      \n"
		"7   8   9   10  11  12  13     5   6   7   8   9   10  11     2   3   4   5   6   7   8      \n"
		"14  15  16  17  18  19  20     12  13  14  15  16  17  18     9   10  11  12  13  14  15     \n"
		"21  22  23  24  25  26  27     19  20  21  22  23  24  25     16  17  18  19  20  21  22     \n"
		"28  29  30                     26  27  28  29  30  31         23  24  25  26  27  28  29     \n"
		"                                                              30                             \n"
		"         \n"																					  
		"    July 2025                      August 2025                    September 2025             \n"
		"Mo  Tu  We  Th  Fr  Sa  Su     Mo  Tu  We  Th  Fr  Sa  Su     Mo  Tu  We  Th  Fr  Sa  Su     \n"
		"    1   2   3   4   5   6                      1   2   3      1   2   3   4   5   6   7      \n"
		"7   8   9   10  11  12  13     4   5   6   7   8   9   10     8   9   10  11  12  13  14     \n"
		"14  15  16  17  18  19  20     11  12  13  14  15  16  17     15  16  17  18  19  20  21     \n"
		"21  22  23  24  25  26  27     18  19  20  21  22  23  24     22  23  24  25  26  27  28     \n"
		"28  29  30  31                 25  26  27  28  29  30  31     29  30                         \n"
		"                                                                                             \n"
		"         \n"																					  
		"    October 2025                   November 2025                  December 2025              \n"
		"Mo  Tu  We  Th  Fr  Sa  Su     Mo  Tu  We  Th  Fr  Sa  Su     Mo  Tu  We  Th  Fr  Sa  Su     \n"
		"        1   2   3   4   5                          1   2      1   2   3   4   5   6   7      \n"
		"6   7   8   9   10  11  12     3   4   5   6   7   8   9      8   9   10  11  12  13  14     \n"
		"13  14  15  16  17  18  19     10  11  12  13  14  15  16     15  16  17  18  19  20  21     \n"
		"20  21  22  23  24  25  26     17  18  19  20  21  22  23     22  23  24  25  26  27  28     \n"
		"27  28  29  30  31             24  25  26  27  28  29  30     29  30  31                     \n"
		"                                                                                             \n"
		"         \n";
	std::stringstream str_real;
	CalendarGui calendar_gui = CalendarGui(Calendar(2025), Orientation::horizontal, YearType::year_for_every_month);
	calendar_gui.draw_formatted_calendar(str_real);
	EXPECT_EQ(str_real.str(), str_expected);
}

TEST(OneYear, Vert_YearOnce) {
	std::string str_expected =
		"                                        2025\n"
		"\n"
		"    January                        February                       March                      \n"
		"Mo     6   13  20  27         Mo     3   10  17  24         Mo     3   10  17  24  31     \n"
		"Tu     7   14  21  28         Tu     4   11  18  25         Tu     4   11  18  25         \n"
		"We  1  8   15  22  29         We     5   12  19  26         We     5   12  19  26         \n"
		"Th  2  9   16  23  30         Th     6   13  20  27         Th     6   13  20  27         \n"
		"Fr  3  10  17  24  31         Fr     7   14  21  28         Fr     7   14  21  28         \n"
		"Sa  4  11  18  25             Sa  1  8   15  22             Sa  1  8   15  22  29         \n"
		"Su  5  12  19  26             Su  2  9   16  23             Su  2  9   16  23  30         \n"
		"\n"
		"    April                          May                            June                       \n"
		"Mo     7   14  21  28         Mo     5   12  19  26         Mo     2   9   16  23  30     \n"
		"Tu  1  8   15  22  29         Tu     6   13  20  27         Tu     3   10  17  24         \n"
		"We  2  9   16  23  30         We     7   14  21  28         We     4   11  18  25         \n"
		"Th  3  10  17  24             Th  1  8   15  22  29         Th     5   12  19  26         \n"
		"Fr  4  11  18  25             Fr  2  9   16  23  30         Fr     6   13  20  27         \n"
		"Sa  5  12  19  26             Sa  3  10  17  24  31         Sa     7   14  21  28         \n"
		"Su  6  13  20  27             Su  4  11  18  25             Su  1  8   15  22  29         \n"
		"\n"
		"    July                           August                         September                  \n"
		"Mo     7   14  21  28         Mo     4   11  18  25         Mo  1  8   15  22  29         \n"
		"Tu  1  8   15  22  29         Tu     5   12  19  26         Tu  2  9   16  23  30         \n"
		"We  2  9   16  23  30         We     6   13  20  27         We  3  10  17  24             \n"
		"Th  3  10  17  24  31         Th     7   14  21  28         Th  4  11  18  25             \n"
		"Fr  4  11  18  25             Fr  1  8   15  22  29         Fr  5  12  19  26             \n"
		"Sa  5  12  19  26             Sa  2  9   16  23  30         Sa  6  13  20  27             \n"
		"Su  6  13  20  27             Su  3  10  17  24  31         Su  7  14  21  28             \n"
		"\n"
		"    October                        November                       December                   \n"
		"Mo     6   13  20  27         Mo     3   10  17  24         Mo  1  8   15  22  29         \n"
		"Tu     7   14  21  28         Tu     4   11  18  25         Tu  2  9   16  23  30         \n"
		"We  1  8   15  22  29         We     5   12  19  26         We  3  10  17  24  31         \n"
		"Th  2  9   16  23  30         Th     6   13  20  27         Th  4  11  18  25             \n"
		"Fr  3  10  17  24  31         Fr     7   14  21  28         Fr  5  12  19  26             \n"
		"Sa  4  11  18  25             Sa  1  8   15  22  29         Sa  6  13  20  27             \n"
		"Su  5  12  19  26             Su  2  9   16  23  30         Su  7  14  21  28             \n"
		"\n";
	std::stringstream str_real;
	CalendarGui calendar_gui = CalendarGui(Calendar(2025), Orientation::vertical, YearType::year_once);
	calendar_gui.draw_formatted_calendar(str_real);
	EXPECT_EQ(str_real.str(), str_expected);
}

TEST(OneYear, Vert_YearForEveryMonth) {
	std::string str_expected =
		"    January 2025                   February 2025                  March 2025                 \n"
		"Mo     6   13  20  27         Mo     3   10  17  24         Mo     3   10  17  24  31     \n"
		"Tu     7   14  21  28         Tu     4   11  18  25         Tu     4   11  18  25         \n"
		"We  1  8   15  22  29         We     5   12  19  26         We     5   12  19  26         \n"
		"Th  2  9   16  23  30         Th     6   13  20  27         Th     6   13  20  27         \n"
		"Fr  3  10  17  24  31         Fr     7   14  21  28         Fr     7   14  21  28         \n"
		"Sa  4  11  18  25             Sa  1  8   15  22             Sa  1  8   15  22  29         \n"
		"Su  5  12  19  26             Su  2  9   16  23             Su  2  9   16  23  30         \n"
		"\n"																					   
		"    April 2025                     May 2025                       June 2025                  \n"
		"Mo     7   14  21  28         Mo     5   12  19  26         Mo     2   9   16  23  30     \n"
		"Tu  1  8   15  22  29         Tu     6   13  20  27         Tu     3   10  17  24         \n"
		"We  2  9   16  23  30         We     7   14  21  28         We     4   11  18  25         \n"
		"Th  3  10  17  24             Th  1  8   15  22  29         Th     5   12  19  26         \n"
		"Fr  4  11  18  25             Fr  2  9   16  23  30         Fr     6   13  20  27         \n"
		"Sa  5  12  19  26             Sa  3  10  17  24  31         Sa     7   14  21  28         \n"
		"Su  6  13  20  27             Su  4  11  18  25             Su  1  8   15  22  29         \n"
		"\n"																					   
		"    July 2025                      August 2025                    September 2025             \n"
		"Mo     7   14  21  28         Mo     4   11  18  25         Mo  1  8   15  22  29         \n"
		"Tu  1  8   15  22  29         Tu     5   12  19  26         Tu  2  9   16  23  30         \n"
		"We  2  9   16  23  30         We     6   13  20  27         We  3  10  17  24             \n"
		"Th  3  10  17  24  31         Th     7   14  21  28         Th  4  11  18  25             \n"
		"Fr  4  11  18  25             Fr  1  8   15  22  29         Fr  5  12  19  26             \n"
		"Sa  5  12  19  26             Sa  2  9   16  23  30         Sa  6  13  20  27             \n"
		"Su  6  13  20  27             Su  3  10  17  24  31         Su  7  14  21  28             \n"
		"\n"																					   
		"    October 2025                   November 2025                  December 2025              \n"
		"Mo     6   13  20  27         Mo     3   10  17  24         Mo  1  8   15  22  29         \n"
		"Tu     7   14  21  28         Tu     4   11  18  25         Tu  2  9   16  23  30         \n"
		"We  1  8   15  22  29         We     5   12  19  26         We  3  10  17  24  31         \n"
		"Th  2  9   16  23  30         Th     6   13  20  27         Th  4  11  18  25             \n"
		"Fr  3  10  17  24  31         Fr     7   14  21  28         Fr  5  12  19  26             \n"
		"Sa  4  11  18  25             Sa  1  8   15  22  29         Sa  6  13  20  27             \n"
		"Su  5  12  19  26             Su  2  9   16  23  30         Su  7  14  21  28             \n"
		"\n";
	std::stringstream str_real;
	CalendarGui calendar_gui = CalendarGui(Calendar(2025), Orientation::vertical, YearType::year_for_every_month);
	calendar_gui.draw_formatted_calendar(str_real);
	EXPECT_EQ(str_real.str(), str_expected);
}

TEST(Range, Horiz_YearOnce) {
	std::string str_expected =
		"                                        2025\n\n"
		"    January                        February                       March                      \n"
		"Mo  Tu  We  Th  Fr  Sa  Su     Mo  Tu  We  Th  Fr  Sa  Su     Mo  Tu  We  Th  Fr  Sa  Su     \n"
		"        1   2   3   4   5                          1   2                          1   2      \n"
		"6   7   8   9   10  11  12     3   4   5   6   7   8   9      3   4   5   6   7   8   9      \n"
		"13  14  15  16  17  18  19     10  11  12  13  14  15  16     10  11  12  13  14  15  16     \n"
		"20  21  22  23  24  25  26     17  18  19  20  21  22  23     17  18  19  20  21  22  23     \n"
		"27  28  29  30  31             24  25  26  27  28             24  25  26  27  28  29  30     \n"
		"                                                              31                             \n"
		"         \n"																				  
		"    April                          May                            June                       \n"
		"Mo  Tu  We  Th  Fr  Sa  Su     Mo  Tu  We  Th  Fr  Sa  Su     Mo  Tu  We  Th  Fr  Sa  Su     \n"
		"    1   2   3   4   5   6                  1   2   3   4                              1      \n"
		"7   8   9   10  11  12  13     5   6   7   8   9   10  11     2   3   4   5   6   7   8      \n"
		"14  15  16  17  18  19  20     12  13  14  15  16  17  18     9   10  11  12  13  14  15     \n"
		"21  22  23  24  25  26  27     19  20  21  22  23  24  25     16  17  18  19  20  21  22     \n"
		"28  29  30                     26  27  28  29  30  31         23  24  25  26  27  28  29     \n"
		"                                                              30                             \n"
		"         \n";
	std::stringstream str_real;
	CalendarGui calendar_gui = CalendarGui(Calendar(1, 2025, 6, 2025), Orientation::horizontal, YearType::year_once);
	calendar_gui.draw_formatted_calendar(str_real);
	EXPECT_EQ(str_real.str(), str_expected);
}

TEST(Range, Horiz_YearForEveryMonth) {
	std::string str_expected =
		"    January 2025                   February 2025                  March 2025                 \n"
		"Mo  Tu  We  Th  Fr  Sa  Su     Mo  Tu  We  Th  Fr  Sa  Su     Mo  Tu  We  Th  Fr  Sa  Su     \n"
		"        1   2   3   4   5                          1   2                          1   2      \n"
		"6   7   8   9   10  11  12     3   4   5   6   7   8   9      3   4   5   6   7   8   9      \n"
		"13  14  15  16  17  18  19     10  11  12  13  14  15  16     10  11  12  13  14  15  16     \n"
		"20  21  22  23  24  25  26     17  18  19  20  21  22  23     17  18  19  20  21  22  23     \n"
		"27  28  29  30  31             24  25  26  27  28             24  25  26  27  28  29  30     \n"
		"                                                              31                             \n"
		"         \n"																					 
		"    April 2025                     May 2025                       June 2025                  \n"
		"Mo  Tu  We  Th  Fr  Sa  Su     Mo  Tu  We  Th  Fr  Sa  Su     Mo  Tu  We  Th  Fr  Sa  Su     \n"
		"    1   2   3   4   5   6                  1   2   3   4                              1      \n"
		"7   8   9   10  11  12  13     5   6   7   8   9   10  11     2   3   4   5   6   7   8      \n"
		"14  15  16  17  18  19  20     12  13  14  15  16  17  18     9   10  11  12  13  14  15     \n"
		"21  22  23  24  25  26  27     19  20  21  22  23  24  25     16  17  18  19  20  21  22     \n"
		"28  29  30                     26  27  28  29  30  31         23  24  25  26  27  28  29     \n"
		"                                                              30                             \n"
		"         \n";
	std::stringstream str_real;
	CalendarGui calendar_gui = CalendarGui(Calendar(1, 2025, 6, 2025), Orientation::horizontal, YearType::year_for_every_month);
	calendar_gui.draw_formatted_calendar(str_real);
	EXPECT_EQ(str_real.str(), str_expected);
}

TEST(Range, Vert_YearOnce) {
	std::string str_expected =
		"                                        2025\n\n"
		"    January                        February                       March                      \n"
		"Mo     6   13  20  27         Mo     3   10  17  24         Mo     3   10  17  24  31     \n"
		"Tu     7   14  21  28         Tu     4   11  18  25         Tu     4   11  18  25         \n"
		"We  1  8   15  22  29         We     5   12  19  26         We     5   12  19  26         \n"
		"Th  2  9   16  23  30         Th     6   13  20  27         Th     6   13  20  27         \n"
		"Fr  3  10  17  24  31         Fr     7   14  21  28         Fr     7   14  21  28         \n"
		"Sa  4  11  18  25             Sa  1  8   15  22             Sa  1  8   15  22  29         \n"
		"Su  5  12  19  26             Su  2  9   16  23             Su  2  9   16  23  30         \n"
		"\n"																						   
		"    April                          May                            June                       \n"
		"Mo     7   14  21  28         Mo     5   12  19  26         Mo     2   9   16  23  30     \n"
		"Tu  1  8   15  22  29         Tu     6   13  20  27         Tu     3   10  17  24         \n"
		"We  2  9   16  23  30         We     7   14  21  28         We     4   11  18  25         \n"
		"Th  3  10  17  24             Th  1  8   15  22  29         Th     5   12  19  26         \n"
		"Fr  4  11  18  25             Fr  2  9   16  23  30         Fr     6   13  20  27         \n"
		"Sa  5  12  19  26             Sa  3  10  17  24  31         Sa     7   14  21  28         \n"
		"Su  6  13  20  27             Su  4  11  18  25             Su  1  8   15  22  29         \n"
		"\n";
	std::stringstream str_real;
	CalendarGui calendar_gui = CalendarGui(Calendar(1, 2025, 6, 2025), Orientation::vertical, YearType::year_once);
	calendar_gui.draw_formatted_calendar(str_real);
	EXPECT_EQ(str_real.str(), str_expected);
}

TEST(Range, Vert_YearForEveryMonth) {
	std::string str_expected =
		"    January 2025                   February 2025                  March 2025                 \n"
		"Mo     6   13  20  27         Mo     3   10  17  24         Mo     3   10  17  24  31     \n"
		"Tu     7   14  21  28         Tu     4   11  18  25         Tu     4   11  18  25         \n"
		"We  1  8   15  22  29         We     5   12  19  26         We     5   12  19  26         \n"
		"Th  2  9   16  23  30         Th     6   13  20  27         Th     6   13  20  27         \n"
		"Fr  3  10  17  24  31         Fr     7   14  21  28         Fr     7   14  21  28         \n"
		"Sa  4  11  18  25             Sa  1  8   15  22             Sa  1  8   15  22  29         \n"
		"Su  5  12  19  26             Su  2  9   16  23             Su  2  9   16  23  30         \n"
		"\n"																						   
		"    April 2025                     May 2025                       June 2025                  \n"
		"Mo     7   14  21  28         Mo     5   12  19  26         Mo     2   9   16  23  30     \n"
		"Tu  1  8   15  22  29         Tu     6   13  20  27         Tu     3   10  17  24         \n"
		"We  2  9   16  23  30         We     7   14  21  28         We     4   11  18  25         \n"
		"Th  3  10  17  24             Th  1  8   15  22  29         Th     5   12  19  26         \n"
		"Fr  4  11  18  25             Fr  2  9   16  23  30         Fr     6   13  20  27         \n"
		"Sa  5  12  19  26             Sa  3  10  17  24  31         Sa     7   14  21  28         \n"
		"Su  6  13  20  27             Su  4  11  18  25             Su  1  8   15  22  29         \n"
		"\n";
	std::stringstream str_real;
	CalendarGui calendar_gui = CalendarGui(Calendar(1, 2025, 6, 2025), Orientation::vertical, YearType::year_for_every_month);
	calendar_gui.draw_formatted_calendar(str_real);
	EXPECT_EQ(str_real.str(), str_expected);
}



