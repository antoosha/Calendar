CXX = g++
LD = g++
CXXFLAGS = -Wall -pedantic -Wextra -std=c++14

HEADERS = $(wildcard src/*.h)


all: app

app:  src/main.o src/Application/CApplication.o src/Calendar/CCalendar.o src/Calendar/CDate.o src/Calendar/CEvent.o src/Calendar/COptional.o src/Calendar/CRequired.o src/ImportExport/CImportExport.o src/Interface/CInterface.o src/Postpone/CPostpone.o src/Repeat/CRepeat.o src/View/CDaily.o src/View/CMonthly.o src/View/CWeekly.o src/View/CYearly.o
	$(LD) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

doc: Doxyfile $(HEADERS)
	doxygen Doxyfile
	
clean:
	rm -f *.o app doc/ 2>/dev/null

deps:
	$(CXX) -MM src/main.cpp src/Application/CApplication.cpp src/Calendar/CCalendar.cpp src/Calendar/CDate.cpp src/Calendar/CEvent.cpp src/Calendar/COptional.cpp src/Calendar/CRequired.cpp src/ImportExport/CImportExport.cpp src/Interface/CInterface.cpp src/Postpone/CPostpone.cpp src/Repeat/CRepeat.cpp src/View/CDaily.cpp src/View/CMonthly.cpp src/View/CWeekly.cpp src/View/CYearly.cpp > Makefile.d

-include Makefile.d

# Requirements / Dependencies