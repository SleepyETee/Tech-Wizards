/**
 * @file Workshop.h
 * @brief Workshop entity class definition
 * 
 * Tech Wizards - Workshop Hub
 * CS A250 - C++ 2 | Spring 2025
 * 
 * @authors Iuliana Cherevko (Team Leader), Anastasia Sviridova, Long Nguyen
 */

#ifndef WORKSHOP_H
#define WORKSHOP_H

#include <string>

/**
 * @class Workshop
 * @brief Represents a workshop with its details and pricing
 * 
 * Immutable value class that stores workshop information including
 * identification number, title, duration, capacity, and price.
 * Supports comparison operations for use in STL containers.
 */
class Workshop {
public:
    /**
     * @brief Constructs a Workshop with all required attributes
     * @param theNumber Unique workshop identifier
     * @param theTitle Workshop name/title
     * @param theHours Duration in hours
     * @param theCapacity Maximum participant capacity
     * @param thePrice Workshop cost
     */
    Workshop(int theNumber, const std::string& theTitle,
        int theHours, int theCapacity, double thePrice)
        : number(theNumber), title(theTitle), hours(theHours),
        capacity(theCapacity), price(thePrice) {}

    /** @brief Returns the workshop number */
    int getNumber() const { return number; }
    /** @brief Returns the workshop title */
    std::string getTitle() const { return title; }
    /** @brief Returns the workshop duration in hours */
    int getHours() const { return hours; }
    /** @brief Returns the maximum participant capacity */
    int getCapacity() const { return capacity; }
    /** @brief Returns the workshop price */
    double getPrice() const { return price; }

    /** @brief Comparison operator for STL container ordering */
    bool operator<(const Workshop& workshop) const
        { return (number < workshop.number); }
    /** @brief Equality operator based on workshop number */
    bool operator== (const Workshop& workshop) const
        { return (number == workshop.number); }

private:
    int number;          ///< Unique workshop identifier
    std::string title;   ///< Workshop name
    int hours;           ///< Duration in hours
    int capacity;        ///< Maximum participants
    double price;        ///< Cost in dollars
};

#endif