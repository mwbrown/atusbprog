cmake_minimum_required(VERSION 3.10)
project(atusbprog)

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBUSB REQUIRED libusb-1.0)

set(ATUSBPROG_SRC
	src/main.c
)

include_directories(${LIBUSB_INCLUDE_DIRS})
link_directories(${LIBUSB_LIBRARY_DIRS})

add_executable(atusbprog ${ATUSBPROG_SRC})
target_link_libraries(atusbprog ${LIBUSB_LIBRARIES})
