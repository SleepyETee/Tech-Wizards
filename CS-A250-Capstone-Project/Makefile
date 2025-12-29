# Workshop Hub - Makefile
# Cross-platform build configuration

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
TARGET = WorkshopHub

SRCS = Main.cpp DataLoader.cpp Formatter.cpp Interface.cpp \
       ParticipantList.cpp RegistrationManager.cpp WorkshopList.cpp

OBJS = $(SRCS:.cpp=.o)

DATA_FILES = participant_database.txt workshop_database.txt registration_database.txt

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

# Dependencies
Main.o: Main.cpp WorkshopList.h ParticipantList.h RegistrationManager.h DataLoader.h Interface.h Formatter.h
DataLoader.o: DataLoader.cpp DataLoader.h WorkshopList.h ParticipantList.h RegistrationManager.h
Formatter.o: Formatter.cpp Formatter.h WorkshopList.h ParticipantList.h RegistrationManager.h
Interface.o: Interface.cpp Interface.h Formatter.h WorkshopList.h ParticipantList.h RegistrationManager.h
ParticipantList.o: ParticipantList.cpp ParticipantList.h Participant.h Workshop.h
RegistrationManager.o: RegistrationManager.cpp RegistrationManager.h ParticipantList.h WorkshopList.h
WorkshopList.o: WorkshopList.cpp WorkshopList.h Workshop.h
