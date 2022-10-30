cmake_minimum_required(VERSION 3.23)
project(schedule)

include_directories(src)

set(SOURCE

        src/Filereader.cpp
        src/Filereader.h
        src/Class_Hour.cpp
        src/Class_Hour.h
        src/Lecture.h
        src/Lecture.cpp
        src/main.cpp
        src/overloads.cpp
        src/Student.h
        src/Timetable.cpp
        src/Timetable.h
        src/Uc.cpp
        src/Uc.h
        src/Class_Hour.cpp
        src/Class_Hour.h
        src/overloads.h
        src/Student.cpp
        src/Filereader.cpp
        src/class_change.h
        src/class_change.cpp
        src/Program_data.h
        src/Program_data.cpp)


add_executable(${PROJECT_NAME} ${SOURCE})

add_definitions("-g")

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
