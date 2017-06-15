cmake_minimum_required(VERSION 3.7)
project(Restauracja)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp CPracownik.cpp CPracownik.h CKucharz.cpp CKucharz.h CManager.cpp CManager.h CKelner.cpp CKelner.h CDanie.cpp CDanie.h CKlient.cpp CKlient.h CRestauracja.cpp CRestauracja.h)
add_executable(Restauracja ${SOURCE_FILES})