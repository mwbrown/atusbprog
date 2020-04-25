cmake_minimum_required(VERSION 3.10)
project(atusbprog)

set(REPO_ROOT_DIR ${CMAKE_SOURCE_DIR}/../)
set(LIBUSB_CONTRIB_DIR ${REPO_ROOT_DIR}/deps/libusb_windows)

# If on Windows, use the libusb contrib directory
if(WIN32)
  set(LIBUSB_INCLUDE_DIRS ${LIBUSB_CONTRIB_DIR}/include/libusb-1.0)

  # Set the library dirs depending on compiler
  # TODO: support other than 64-bit msvc
  set(LIBUSB_LIBRARY_DIRS ${LIBUSB_CONTRIB_DIR}/MS64/dll)
  set(LIBUSB_LIBRARIES libusb-1.0)

else()
  find_package(PkgConfig REQUIRED)
  pkg_check_modules(LIBUSB REQUIRED libusb-1.0)
endif()

set(ATUSBPROG_SRC
  src/main.c
  src/cmdline.c
)

# Add LibUSB information
include_directories(${LIBUSB_INCLUDE_DIRS})
link_directories(${LIBUSB_LIBRARY_DIRS})

# Add other include directories
set(FW_COMMON_INCDIR ${REPO_ROOT_DIR}/fw/inc_common)
include_directories(${FW_COMMON_INCDIR})

add_executable(atusbprog ${ATUSBPROG_SRC})
target_link_libraries(atusbprog ${LIBUSB_LIBRARIES})
