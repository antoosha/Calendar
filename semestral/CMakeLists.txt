project(semestralka)

set(CMAKE_CXX_STANDARD 14)

add_executable(korolant
        korolant/src/main.cpp
        korolant/src/Application/CApplication.cpp
        korolant/src/Application/CApplication.h
        korolant/src/ImportExport/CImportExport.cpp
        korolant/src/ImportExport/CImportExport.h
        korolant/src/Interface/CInterface.cpp
        korolant/src/Interface/CInterface.h
        korolant/src/Calendar/CCalendar.cpp
        korolant/src/Calendar/CCalendar.h
        korolant/src/Calendar/CRequired.cpp
        korolant/src/Calendar/CRequired.h
        korolant/src/Calendar/COptional.cpp
        korolant/src/Calendar/COptional.h
        korolant/src/Calendar/CDate.cpp
        korolant/src/Calendar/CDate.h
        korolant/src/Postpone/CPostpone.h
        korolant/src/View/CView.h
        korolant/src/View/CDay.cpp
        korolant/src/View/CDay.h
        korolant/src/View/CWeekly.cpp
        korolant/src/View/CWeekly.h
        korolant/src/View/CMonthly.cpp
        korolant/src/View/CMonthly.h
        korolant/src/Calendar/CEvent.h
        korolant/src/Postpone/CPostpone.cpp korolant/src/Calendar/CEvent.cpp korolant/src/Repeat/CRepeat.cpp korolant/src/Repeat/CRepeat.h)
