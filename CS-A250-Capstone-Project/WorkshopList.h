/**
 * @file WorkshopList.h
 * @brief Workshop collection management class
 * 
 * Tech Wizards - Workshop Hub
 * CS A250 - C++ 2 | Spring 2025
 * 
 * @authors Iuliana Cherevko (Team Leader), Anastasia Sviridova, Long Nguyen
 */

#ifndef WORKSHOPLIST_H
#define WORKSHOPLIST_H

#include "Workshop.h"

#include <set>

/**
 * @class WorkshopList
 * @brief Manages a collection of Workshop objects
 * 
 * Provides CRUD operations and queries for workshops stored
 * in an ordered set container for efficient lookup.
 */
class WorkshopList {
public:
    /** @brief Adds a workshop to the collection */
    void addWorkshop(const Workshop& workshop);

    /** @brief Gets workshop number from a Workshop object */
    int getNumber(const Workshop& workshop) const;
    /** @brief Gets workshop title by number */
    std::string getTitle(int workshopNo) const;
    /** @brief Gets workshop hours by number */
    int getHours(int workshopNo) const;
    /** @brief Gets workshop capacity by number */
    int getCapacity(int workshopNo) const;
    /** @brief Gets workshop price by number */
    double getPrice(int workshopNo) const;
    /** @brief Gets a workshop reference by number */
    const Workshop& getWorkshop(int workshopNo) const;
    /** @brief Returns the complete workshop collection */
    const std::set<Workshop>& getAllWorkshops() const;

    /** @brief Checks if the list is empty */
    bool isEmpty() const;
    /** @brief Removes all workshops from the list */
    void clearList();

private:
    std::set<Workshop> workshopList;  ///< Ordered workshop collection

    /**
     * @brief Finds a workshop by its number
     * @param workshopNo Workshop number to search for
     * @return Iterator to the found workshop
     */
    std::set<Workshop>::iterator findByNumber(int workshopNo) const;
};

#endif
