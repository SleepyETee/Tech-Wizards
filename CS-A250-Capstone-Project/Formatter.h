/**
 * @file Formatter.h
 * @brief Display formatting and output utilities
 * 
 * Tech Wizards - Workshop Hub
 * CS A250 - C++ 2 | Spring 2025
 * 
 * @authors Iuliana Cherevko (Team Leader), Anastasia Sviridova, Long Nguyen
 */

#ifndef FORMATTER_H
#define FORMATTER_H

#include "WorkshopList.h"
#include "ParticipantList.h"
#include "RegistrationManager.h"

/**
 * @class Formatter
 * @brief Static utility class for console output formatting
 * 
 * Provides formatted display methods for menus, workshop listings,
 * and participant information. All methods are static.
 */
class Formatter
{
public:
    /** @brief Displays the main menu options */
    static void displayMenu();

    /** @brief Prints all workshops in the system */
    static void printAllWorkshops(const WorkshopList& workshopList);
    
    /** @brief Prints only workshops open for registration */
    static void printOpenWorkshops(const WorkshopList& workshopList,
        const RegistrationManager& registration);
    
    /** @brief Prints workshops at or below a price threshold */
    static void printWorkshopsByPrice(
        const WorkshopList& workshopList, double price);
    
    /** @brief Prints workshops a specific participant is enrolled in */
    static void printParticipantWorkshops(
        const ParticipantList& participantList, int participantID);
    
    /** @brief Prints detailed information for a single workshop */
    static void printWorkshop(const Workshop& workshop);

    /** @brief Pauses execution until user presses Enter */
    static void pauseAndWait();
};
#endif