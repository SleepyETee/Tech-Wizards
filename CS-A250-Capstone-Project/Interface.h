/**
 * @file Interface.h
 * @brief User interface and menu handling functions
 * 
 * Tech Wizards - Workshop Hub
 * CS A250 - C++ 2 | Spring 2025
 * 
 * @authors Iuliana Cherevko (Team Leader), Anastasia Sviridova, Long Nguyen
 */

#ifndef INTERFACE_H
#define INTERFACE_H

#include "WorkshopList.h"
#include "ParticipantList.h"
#include "RegistrationManager.h"

#include <string>

/**
 * @brief Main menu loop - processes user selections until exit
 * @param workshopList Reference to workshop data
 * @param participantList Reference to participant data
 * @param registration Reference to registration manager
 */
void processMenu(const WorkshopList& workshopList,
                 ParticipantList& participantList,
                 RegistrationManager& registration);

/**
 * @brief Prompts user for identification information
 * @param[out] participantID User's participant ID
 * @param[out] firstName User's first name
 * @param[out] lastName User's last name
 */
void getIdentification(int& participantID,
                       std::string& firstName,
                       std::string& lastName);

/**
 * @brief Verifies that ID matches the provided name
 * @param participantList List to verify against
 * @param participantID ID to verify
 * @param firstName First name to match
 * @param lastName Last name to match
 * @return true if ID and name match, false otherwise
 */
bool verifyIdentification(const ParticipantList& participantList,
                          int participantID,
                          const std::string& firstName,
                          const std::string& lastName);

/** @brief Displays all available workshops */
void viewAllWorkshops(const WorkshopList& workshopList);

/** @brief Displays workshops currently open for registration */
void viewOpenWorkshops(const WorkshopList& workshopList,
                       const RegistrationManager& registration);

/** @brief Displays workshops filtered by maximum price */
void viewWorkshopsByPrice(const WorkshopList& workshopList);

/** @brief Displays workshops for a verified participant */
void viewParticipantWorkshops(const ParticipantList& participantList);

/** @brief Handles workshop registration workflow */
void registerForWorkshop(const WorkshopList& workshopList,
                        ParticipantList& participantList,
                        RegistrationManager& registration);

/** @brief Handles registration cancellation workflow */
void cancelRegistration(const WorkshopList& workshopList,
                    ParticipantList& participantList,
                    RegistrationManager& registration);

#endif
