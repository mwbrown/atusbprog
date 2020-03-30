cmake_minimum_required(VERSION 3.10)
project(atusbprog)

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBUSB REQUIRED libusb-1.0)

set(ATUSBPROG_SRC
	src/main.c
)

# Add LibUSB information
include_directories(${LIBUSB_INCLUDE_DIRS})
link_directories(${LIBUSB_LIBRARY_DIRS})

# Add other include directories
set(FW_COMMON_INCDIR ${CMAKE_SOURCE_DIR}/../../fw/inc_common)
include_directories(${FW_COMMON_INCDIR})

add_executable(atusbprog ${ATUSBPROG_SRC})
target_link_libraries(atusbprog ${LIBUSB_LIBRARIES})
