cmake_minimum_required(VERSION 3.10)
project(WorkshopHub VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCES
    Main.cpp
    DataLoader.cpp
    Formatter.cpp
    Interface.cpp
    ParticipantList.cpp
    RegistrationManager.cpp
    WorkshopList.cpp
)

# Header files
set(HEADERS
    DataLoader.h
    Formatter.h
    Interface.h
    Participant.h
    ParticipantList.h
    RegistrationManager.h
    Workshop.h
    WorkshopList.h
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Copy data files to build directory
configure_file(participant_database.txt ${CMAKE_CURRENT_BINARY_DIR}/participant_database.txt COPYONLY)
configure_file(workshop_database.txt ${CMAKE_CURRENT_BINARY_DIR}/workshop_database.txt COPYONLY)
configure_file(registration_database.txt ${CMAKE_CURRENT_BINARY_DIR}/registration_database.txt COPYONLY)
