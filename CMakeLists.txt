cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 11)
project(CoastalOasis)

# Find wxWidgets package
find_package(wxWidgets COMPONENTS core base REQUIRED)
include("${wxWidgets_USE_FILE}")

# Include headers
include_directories(
        hotelClasses/Clients
        hotelClasses/Clients/External
        hotelClasses/Clients/Internal
        hotelClasses/GlobalsAndNecessities
        hotelClasses/Schedule

        Frames
        )

# Include all source files in hotelClasses and Frames subfolders
file(GLOB_RECURSE SOURCE_FILES
        "${PROJECT_SOURCE_DIR}/hotelClasses/*.h"
        "${PROJECT_SOURCE_DIR}/hotelClasses/*.cpp"
        "${PROJECT_SOURCE_DIR}/Frames/*.h"
        "${PROJECT_SOURCE_DIR}/Frames/*.cpp"
        )

# Add main.cpp as the only source file that is not in subfolders
list(APPEND SOURCE_FILES "${PROJECT_SOURCE_DIR}/main.cpp")

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES} HotelClasses/Schedule/employee_scheduleitem.cpp HotelClasses/Schedule/employee_scheduleitem.h HotelClasses/Schedule/WeeklySchedule.cpp HotelClasses/Schedule/WeeklySchedule.h)

# Link the executable with the wxWidgets libraries
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
