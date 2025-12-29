# Workshop Hub

![C++](https://img.shields.io/badge/C%2B%2B-17-blue.svg)
![CMake](https://img.shields.io/badge/CMake-3.10%2B-green.svg)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20macOS%20%7C%20Linux-lightgrey.svg)
![License](https://img.shields.io/badge/License-MIT-yellow.svg)

A C++ console application for managing workshop registrations. Built as a capstone project demonstrating object-oriented programming principles, data structures, and file I/O operations.

## Features

- **View All Workshops** - Browse the complete catalog of available workshops
- **View Open Workshops** - See workshops that still have available spots
- **Filter by Price** - Find workshops within your budget
- **Register for Workshops** - Sign up for workshops with automatic capacity management
- **View Your Registrations** - See all workshops you're enrolled in
- **Cancel Registration** - Unregister from workshops with automatic spot reopening

## Project Structure

```
CS-A250-Capstone-Project/
├── Main.cpp                 # Application entry point
├── Interface.h/cpp          # User interface and menu handling
├── Formatter.h/cpp          # Display formatting utilities
├── DataLoader.h/cpp         # File I/O operations
├── Workshop.h               # Workshop entity class
├── WorkshopList.h/cpp       # Workshop collection management
├── Participant.h            # Participant entity class
├── ParticipantList.h/cpp    # Participant collection management
├── RegistrationManager.h/cpp # Registration logic and capacity control
├── *_database.txt           # Sample data files
└── CMakeLists.txt           # Cross-platform build configuration
```

## Technical Highlights

- **Modern C++17** - Uses modern C++ features including lambdas, auto, and range-based loops
- **STL Containers** - Leverages `std::set`, `std::map`, and `std::vector` for efficient data management
- **Clean Architecture** - Separation of concerns with dedicated classes for data, business logic, and presentation
- **File-Based Persistence** - Pipe-delimited text files for data storage
- **Cross-Platform** - Works on Windows, macOS, and Linux

## Building the Project

### Using CMake (Recommended)

```bash
cd CS-A250-Capstone-Project
mkdir build && cd build
cmake ..
cmake --build .
./WorkshopHub
```

### Using Visual Studio (Windows)

Open `CS-A250-Capstone-Project.sln` in Visual Studio and build the solution.

### Using g++ (Manual)

```bash
cd CS-A250-Capstone-Project
g++ -std=c++17 -o WorkshopHub Main.cpp DataLoader.cpp Formatter.cpp Interface.cpp ParticipantList.cpp RegistrationManager.cpp WorkshopList.cpp
./WorkshopHub
```

## Sample Data

The project includes sample data files:
- `participant_database.txt` - Pre-registered participants
- `workshop_database.txt` - Available workshops
- `registration_database.txt` - Existing registrations

## Usage

Run the application and follow the interactive menu:

```
*********************************************
		WORKSHOP HUB
*********************************************
	1. View all workshops
	2. View open workshops
	3. View workshops by price
	4. Register for a workshop
	5. List all your workshops
	6. Cancel registration
	7. Exit

Please make a selection:
```

## Authors

**Tech Wizards Team**
- Iuliana Cherevko (Team Leader)
- Anastasia Sviridova
- Long Nguyen

## Course

CS A250 - C++ 2 | Spring 2025

## What I Learned

This project reinforced several key software development concepts:

- **Object-Oriented Design** - Applying encapsulation, separation of concerns, and clean class interfaces
- **STL Mastery** - Practical use of `std::set`, `std::map`, and iterators with custom comparators
- **Lambda Expressions** - Using C++11/17 lambdas for flexible searching and filtering
- **File I/O** - Parsing structured data files and handling potential errors gracefully
- **Input Validation** - Building robust user interfaces that handle invalid input
- **Team Collaboration** - Working effectively in a team with code reviews and version control

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
