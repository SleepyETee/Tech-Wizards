/**
 * @file Participant.h
 * @brief Participant entity class definition
 * 
 * Tech Wizards - Workshop Hub
 * CS A250 - C++ 2 | Spring 2025
 * 
 * @authors Iuliana Cherevko (Team Leader), Anastasia Sviridova, Long Nguyen
 */

#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <string>

/**
 * @class Participant
 * @brief Represents a workshop participant with identification details
 * 
 * Immutable value class storing participant ID and name information.
 * Supports comparison for use as keys in STL containers.
 */
class Participant
{
public:
    /**
     * @brief Constructs a Participant with ID and name
     * @param id Unique participant identifier
     * @param theFirstName Participant's first name
     * @param theLastName Participant's last name
     */
    Participant(int id, const std::string& theFirstName,
        const std::string& theLastName)
        : id(id), firstName(theFirstName), lastName(theLastName) {}

    /** @brief Returns the participant ID */
    int getID() const { return id; }
    /** @brief Returns the participant's first name */
    std::string getFirstName() const { return firstName; }
    /** @brief Returns the participant's last name */
    std::string getLastName() const { return lastName; }

    /** @brief Comparison operator for STL container ordering */
    bool operator<(const Participant& participant) const
        { return (id < participant.id); }

private:
    int id;                  ///< Unique participant identifier
    std::string firstName;   ///< First name
    std::string lastName;    ///< Last name
};

#endif