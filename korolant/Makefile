TARGET = korolant

CXX = g++
LD = g++
MKDIR = mkdir -p

CXXFLAGS = -Wall -pedantic -Wextra -std=c++14 -g

SOURCE_DIR = src
BUILD_DIR = build

SOURCES = $(wildcard $(SOURCE_DIR)/*.cpp)
SOURCES+=$(wildcard $(SOURCE_DIR)/**/*.cpp)
HEADERS = $(wildcard $(SOURCE_DIR)/*.h)
OBJECTS = $(SOURCES:$(SOURCE_DIR)/%.cpp=$(BUILD_DIR)/%.o) # % is pattern matching

#.PHONY  is one that is not really the name of a file;
#rather it is just a name for a recipe to be executed when you make an explicit request.

.PHONY: all
all: compile doc

.PHONY: compile
compile: $(TARGET)

.PHONY: run
run: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJECTS)
	$(LD) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: **/%.cpp
	$(MKDIR) $(@D)
	$(CXX) $(CXXFLAGS) $< -c -o $@

.PHONY: doc
doc: Doxyfile
	doxygen Doxyfile

PHONY: clean
clean:
	rm -rf doc/ $(BUILD_DIR)/ $(TARGET)


# Requirements / Dependencies
#g++ -MM src/*.cpp | sed -r 's|^(.*\.o)|build/\1| for main
#g++ -MM src/*/*.cpp | sed -r 's|^(.*\.o)|build/\1| for other dirs
build/main.o: src/main.cpp src/Application/CApplication.h \
 src/Application/../Interface/CInterface.h \
 src/Application/../Interface/../View/CView.h \
 src/Application/../Interface/../View/../Calendar/CCalendar.h \
 src/Application/../Interface/../View/../Calendar/CEvent.h \
 src/Application/../Interface/../View/../Calendar/CDate.h \
 src/Application/../Interface/../View/../Calendar/COptional.h \
 src/Application/../Interface/../View/../Calendar/CRequired.h \
 src/Application/../Interface/../ImportExport/CImportExport.h \
 src/Application/../Interface/../Postpone/CPostpone.h \
 src/Application/../Interface/../Repeat/CRepeat.h \
 src/Application/../View/CDaily.h src/Application/../View/CWeekly.h \
 src/Application/../View/CMonthly.h src/Application/../View/CYearly.h
build/CApplication.o: src/Application/CApplication.cpp \
 src/Application/CApplication.h src/Application/../Interface/CInterface.h \
 src/Application/../Interface/../View/CView.h \
 src/Application/../Interface/../View/../Calendar/CCalendar.h \
 src/Application/../Interface/../View/../Calendar/CEvent.h \
 src/Application/../Interface/../View/../Calendar/CDate.h \
 src/Application/../Interface/../View/../Calendar/COptional.h \
 src/Application/../Interface/../View/../Calendar/CRequired.h \
 src/Application/../Interface/../ImportExport/CImportExport.h \
 src/Application/../Interface/../Postpone/CPostpone.h \
 src/Application/../Interface/../Repeat/CRepeat.h \
 src/Application/../View/CDaily.h src/Application/../View/CWeekly.h \
 src/Application/../View/CMonthly.h src/Application/../View/CYearly.h
build/CCalendar.o: src/Calendar/CCalendar.cpp src/Calendar/CCalendar.h \
 src/Calendar/CEvent.h src/Calendar/CDate.h src/Calendar/COptional.h \
 src/Calendar/CRequired.h
build/CDate.o: src/Calendar/CDate.cpp src/Calendar/CDate.h
build/CEvent.o: src/Calendar/CEvent.cpp src/Calendar/CEvent.h \
 src/Calendar/CDate.h
build/COptional.o: src/Calendar/COptional.cpp src/Calendar/COptional.h \
 src/Calendar/CCalendar.h src/Calendar/CEvent.h src/Calendar/CDate.h \
 src/Calendar/CRequired.h
build/CRequired.o: src/Calendar/CRequired.cpp src/Calendar/CRequired.h \
 src/Calendar/CCalendar.h src/Calendar/CEvent.h src/Calendar/CDate.h \
 src/Calendar/COptional.h
build/CImportExport.o: src/ImportExport/CImportExport.cpp \
 src/ImportExport/CImportExport.h \
 src/ImportExport/../Calendar/CCalendar.h \
 src/ImportExport/../Calendar/CEvent.h \
 src/ImportExport/../Calendar/CDate.h \
 src/ImportExport/../Calendar/COptional.h \
 src/ImportExport/../Calendar/CRequired.h
build/CInterface.o: src/Interface/CInterface.cpp src/Interface/CInterface.h \
 src/Interface/../View/CView.h \
 src/Interface/../View/../Calendar/CCalendar.h \
 src/Interface/../View/../Calendar/CEvent.h \
 src/Interface/../View/../Calendar/CDate.h \
 src/Interface/../View/../Calendar/COptional.h \
 src/Interface/../View/../Calendar/CRequired.h \
 src/Interface/../ImportExport/CImportExport.h \
 src/Interface/../Postpone/CPostpone.h src/Interface/../Repeat/CRepeat.h
build/CPostpone.o: src/Postpone/CPostpone.cpp src/Postpone/CPostpone.h \
 src/Postpone/../Calendar/CCalendar.h src/Postpone/../Calendar/CEvent.h \
 src/Postpone/../Calendar/CDate.h src/Postpone/../Calendar/COptional.h \
 src/Postpone/../Calendar/CRequired.h
build/CRepeat.o: src/Repeat/CRepeat.cpp src/Repeat/CRepeat.h \
 src/Repeat/../Calendar/CCalendar.h src/Repeat/../Calendar/CEvent.h \
 src/Repeat/../Calendar/CDate.h src/Repeat/../Calendar/COptional.h \
 src/Repeat/../Calendar/CRequired.h
build/CDaily.o: src/View/CDaily.cpp src/View/CDaily.h src/View/CView.h \
 src/View/../Calendar/CCalendar.h src/View/../Calendar/CEvent.h \
 src/View/../Calendar/CDate.h src/View/../Calendar/COptional.h \
 src/View/../Calendar/CRequired.h
build/CMonthly.o: src/View/CMonthly.cpp src/View/CMonthly.h src/View/CView.h \
 src/View/../Calendar/CCalendar.h src/View/../Calendar/CEvent.h \
 src/View/../Calendar/CDate.h src/View/../Calendar/COptional.h \
 src/View/../Calendar/CRequired.h
build/CWeekly.o: src/View/CWeekly.cpp src/View/CWeekly.h src/View/CView.h \
 src/View/../Calendar/CCalendar.h src/View/../Calendar/CEvent.h \
 src/View/../Calendar/CDate.h src/View/../Calendar/COptional.h \
 src/View/../Calendar/CRequired.h
build/CYearly.o: src/View/CYearly.cpp src/View/CYearly.h src/View/CView.h \
 src/View/../Calendar/CCalendar.h src/View/../Calendar/CEvent.h \
 src/View/../Calendar/CDate.h src/View/../Calendar/COptional.h \
 src/View/../Calendar/CRequired.h