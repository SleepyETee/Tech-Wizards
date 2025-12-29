/**
 * @file DataLoader.h
 * @brief File I/O operations for loading data from text files
 * 
 * Tech Wizards - Workshop Hub
 * CS A250 - C++ 2 | Spring 2025
 * 
 * @authors Iuliana Cherevko (Team Leader), Anastasia Sviridova, Long Nguyen
 */

#ifndef DATALOADER_H
#define DATALOADER_H

#include "WorkshopList.h"
#include "RegistrationManager.h"
#include "ParticipantList.h"

#include <string>

/**
 * @class DataLoader
 * @brief Static utility class for loading data from pipe-delimited files
 * 
 * Provides methods to populate application data structures from
 * text files. All methods are static as no instance state is needed.
 */
class DataLoader
{
public:
    /**
     * @brief Loads workshops from a file
     * @param workshopList List to populate with workshops
     * @param filename Path to the workshop data file
     */
    static void loadWorkshops(WorkshopList& workshopList,
        const std::string& filename);
    
    /**
     * @brief Loads participants from a file
     * @param participantList List to populate with participants
     * @param filename Path to the participant data file
     */
    static void loadParticipants(ParticipantList& participantList,
        const std::string& filename);
    
    /**
     * @brief Loads registration data from a file
     * @param registrationManager Manager to populate with registrations
     * @param filename Path to the registration data file
     */
    static void loadRegistration(
        RegistrationManager& registrationManager,
        const std::string& filename);
};

#endif
