CXX=g++
LD=g++
CXXFLAGS=-Wall -pedantic

all: app

app: main.o Application\CApplication.o Calendar\CCalendar.o Calendar\CDate.o Calendar\CEvent.o Calendar\COptional.o 
	 Calendar\CRequired.o ImportExport\CImportExport.o Interface\CInterface.o Postpone\CPostpone.o 
	 Repeat\CRepeat.o View\CDaily.o View\CMonthly.o View\CWeekly.o View\CYearly.o
$(LD) $(CXXFLAGS) -o $@ $^

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	
clean:
	rm -f *.o app

deps:
	$(CXX) -MM *cpp > Makefile.d

-include Makefile.d