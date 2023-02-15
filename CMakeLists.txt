set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -v")
cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 17)
project(CoastalOasis)

# Find wxWidgets package
find_package(wxWidgets COMPONENTS core base REQUIRED)
include("${wxWidgets_USE_FILE}")

# Include headers
include_directories(
        HotelClasses/Clients
        HotelClasses/Clients/External
        HotelClasses/Clients/Internal
        HotelClasses/GlobalUtils
        HotelClasses/Schedule
        HotelClasses/Rooms
        HotelClasses/Bookings
        Frames
        DataBase
        DataBase/Data
        )

# Include all source files in hotelClasses and Frames subfolders
file(GLOB_RECURSE SOURCE_FILES
        "${PROJECT_SOURCE_DIR}/HotelClasses/*.h"
        "${PROJECT_SOURCE_DIR}/HotelClasses/*.cpp"
        "${PROJECT_SOURCE_DIR}/HotelClasses/*.cpp"
        "${PROJECT_SOURCE_DIR}/HotelClasses/*.h"
        "${PROJECT_SOURCE_DIR}/HotelClasses/GlobalUtils/*.cpp"
        "${PROJECT_SOURCE_DIR}/HotelClasses/GlobalUtils/*.h"
        "${PROJECT_SOURCE_DIR}/HotelClasses/Schedule/*.cpp"
        "${PROJECT_SOURCE_DIR}/HotelClasses/Schedule/*.h"
        "${PROJECT_SOURCE_DIR}/HotelClasses/Rooms/*.cpp"
        "${PROJECT_SOURCE_DIR}/HotelClasses/Rooms/*.h"
        "${PROJECT_SOURCE_DIR}/HotelClasses/Bookings/*.cpp"
        "${PROJECT_SOURCE_DIR}/HotelClasses/Bookings/*.h"
        "${PROJECT_SOURCE_DIR}/Frames/*.cpp"
        "${PROJECT_SOURCE_DIR}/Frames/*.h"
        "${PROJECT_SOURCE_DIR}/DataBase/*.cpp"
        "${PROJECT_SOURCE_DIR}/DataBase/*.h"
        )

# Add main.cpp as the only source file that is not in subfolders
list(APPEND SOURCE_FILES "${PROJECT_SOURCE_DIR}/main.cpp")

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES} Frames/FrameSwitcher.cpp Frames/Home.cpp Frames/Login.cpp Frames/UserDashBoard.cpp)

# Link the executable with the wxWidgets libraries
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
