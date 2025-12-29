/**
 * @file RegistrationManager.h
 * @brief Workshop registration and capacity management
 * 
 * Tech Wizards - Workshop Hub
 * CS A250 - C++ 2 | Spring 2025
 * 
 * @authors Iuliana Cherevko (Team Leader), Anastasia Sviridova, Long Nguyen
 */

#ifndef REGISTRATIONMANAGER_H
#define REGISTRATIONMANAGER_H

#include "ParticipantList.h"
#include "WorkshopList.h"

#include <string>
#include <map>
#include <set>

/**
 * @class RegistrationManager
 * @brief Handles workshop registrations and capacity control
 * 
 * Manages the relationship between participants and workshops,
 * automatically closing workshops when capacity is reached and
 * reopening them when spots become available.
 */
class RegistrationManager
{
public:
    /**
     * @brief Constructs manager with workshop and participant references
     * @param workshopList Reference to the workshop collection
     * @param participantList Reference to the participant collection
     */
    RegistrationManager(const WorkshopList& workshopList,
        ParticipantList& participantList)
        : workshopList(workshopList),
        participantList(participantList) {}

    /** @brief Marks a workshop as open for registration */
    void addOpenWorkshop(int workshopNo);
    /** @brief Registers a participant for a workshop */
    void registerParticipant(int workshopNo, int participantID);
    /** @brief Removes a participant's registration */
    void unregisterParticipant(int workshopNo, int participantID);

    /** @brief Closes a workshop to new registrations */
    void closeWorkshop(int workshopNo);
    /** @brief Reopens a workshop for registrations */
    void reopenWorkshop(int workshopNo);

    /** @brief Checks if a workshop is open for registration */
    bool isOpen(int workshopNo) const;
    /** @brief Returns all currently open workshops */
    const std::set<int>& getOpenWorkshops() const;

private:
    std::map<int, std::set<int>> registration;  ///< Workshop-to-participants mapping
    std::set<int> openWorkshops;                ///< Set of open workshop numbers
    const WorkshopList& workshopList;           ///< Reference to workshops
    ParticipantList& participantList;           ///< Reference to participants
};

#endif