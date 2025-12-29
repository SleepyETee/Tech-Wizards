/**
 * @file ParticipantList.h
 * @brief Participant collection and workshop enrollment management
 * 
 * Tech Wizards - Workshop Hub
 * CS A250 - C++ 2 | Spring 2025
 * 
 * @authors Iuliana Cherevko (Team Leader), Anastasia Sviridova, Long Nguyen
 */

#ifndef PARTICIPANTLIST_H
#define PARTICIPANTLIST_H

#include "Participant.h"
#include "Workshop.h"

#include <string>
#include <map>
#include <vector>

/**
 * @class ParticipantList
 * @brief Manages participants and their workshop enrollments
 * 
 * Stores participants mapped to their enrolled workshops,
 * providing enrollment and cancellation operations.
 */
class ParticipantList
{
public:
    /** @brief Adds a new participant to the system */
    void addParticipant(const Participant& participant);
    /** @brief Enrolls a participant in a workshop */
    void addWorkshopToParticipant(const Participant& participant,
        const Workshop& workshop);
    
    /** @brief Gets participant ID from object */
    int getID(const Participant& participant) const;
    /** @brief Gets participant's first name by ID */
    std::string getFirstName(int participantID) const;
    /** @brief Gets participant's last name by ID */
    std::string getLastName(int participantID) const;
    /** @brief Gets participant reference by ID */
    const Participant& getParticipant(int participantID) const;
    /** @brief Gets all workshops a participant is enrolled in */
    std::vector<Workshop> getWorkshops(int participantID) const;
    
    /** @brief Removes a workshop enrollment for a participant */
    void cancelWorkshop(int participantID, int workshopNo);
    
    /** @brief Checks if a participant exists by ID */
    bool participantExists(int participantID) const;
    /** @brief Checks if the list is empty */
    bool isEmpty() const;
    /** @brief Removes all participants */
    void clearList();

private:
    std::map<Participant, std::vector<Workshop>> participantList;  ///< Participant-to-workshops mapping

    /**
     * @brief Finds a participant by ID
     * @param participantID The ID to search for
     * @return Iterator to the found participant entry
     */
    std::map<Participant, std::vector<Workshop>>::const_iterator 
        findByID(int participantID) const;    
};

#endif
