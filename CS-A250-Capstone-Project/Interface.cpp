/*
    Tech Wizards

    Cherevko, Iuliana (Team Leader)
    Sviridova, Anastasia
    Nguyen, Long

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub
*/

#include "Interface.h"
#include "Formatter.h"

#include <iostream>
#include <limits>

using namespace std;

namespace
{
    void clearInvalidInput()
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int getValidInt(const string& prompt)
    {
        int value;
        cout << prompt;
        while (!(cin >> value))
        {
            clearInvalidInput();
            cout << "Invalid input. Please enter a number: ";
        }
        return value;
    }

    double getValidDouble(const string& prompt)
    {
        double value;
        cout << prompt;
        while (!(cin >> value))
        {
            clearInvalidInput();
            cout << "Invalid input. Please enter a number: ";
        }
        return value;
    }
}

void processMenu(const WorkshopList& workshopList,
    ParticipantList& participantList, RegistrationManager& registration)
{
    int selection = 0;

    do
    {
        Formatter::displayMenu();

        selection = getValidInt("\nPlease make a selection: ");
        cout << endl;

        switch (selection)
        {
            case 1:
                viewAllWorkshops(workshopList);
                break;
            case 2:
                viewOpenWorkshops(workshopList, registration);
                break;
            case 3:
                viewWorkshopsByPrice(workshopList);
                break;
            case 4:
                registerForWorkshop(workshopList, participantList,
                    registration);
                break;
            case 5:
                viewParticipantWorkshops(participantList);
                break;
            case 6:
                cancelRegistration(workshopList, participantList,
                    registration);
                break;
            case 7:
                cout << "Thank you for visiting!";
                break;
            default:
                break;
        }

        if (selection != 7)
        {
            Formatter::pauseAndWait();
        }
    } while (selection != 7);
}

void getIdentification(int &participantID, string& firstName,
    string& lastName)
{
    participantID = getValidInt("Enter your ID: ");
    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your last name: ";
    cin >> lastName;
    cout << endl;
}

bool verifyIdentification(const ParticipantList& participantList,
    int participantID, const string& firstName, const string& lastName)
{
    if (!participantList.participantExists(participantID))
    {
        return false;
    }
    return participantList.getFirstName(participantID) == firstName &&
        participantList.getLastName(participantID) == lastName;
}

void viewAllWorkshops(const WorkshopList& workshopList)
{
    Formatter::printAllWorkshops(workshopList);
}

void viewOpenWorkshops(const WorkshopList& workshopList,
                       const RegistrationManager& registration)
{
    Formatter::printOpenWorkshops(workshopList, registration);
}

void viewWorkshopsByPrice(const WorkshopList& workshopList)
{
    double maxPrice = getValidDouble("Enter max price: $");
    Formatter::printWorkshopsByPrice(workshopList, maxPrice);
}

void viewParticipantWorkshops(const ParticipantList& participantList)
{
    int id = 0;
    string firstName, lastName;
    getIdentification(id, firstName, lastName);

    if (verifyIdentification(participantList, id, firstName, lastName))
    {
        Formatter::printParticipantWorkshops(participantList, id);
    }
    else
    {
        cout << "The ID number does not match the name provided." << endl;
    }
}

void registerForWorkshop(const WorkshopList& workshopList,
    ParticipantList& participantList, RegistrationManager& registration)
{
    cout << "\tLet's register you for a workshop!\n\n";

    viewOpenWorkshops(workshopList, registration);

    int selection = getValidInt("\nEnter the workshop number or '0' to cancel: ");

    if (selection != 0)
    {
        cout << endl;

        int id = 0;
        string firstName, lastName;
        getIdentification(id, firstName, lastName);

        if (verifyIdentification(
            participantList, id, firstName, lastName))
        {
            registration.registerParticipant(selection, id);

            cout << "You are registered for the following workshop:"
                << "\n\n";

            Formatter::printWorkshop(
                workshopList.getWorkshop(selection));

            cout << "\nA confirmation email with payment details has"
                " been sent to you." << endl;
        }
        else
        {
            cout << "The ID number does not match the name provided."
                 << endl;
        }
    }
}

void cancelRegistration(const WorkshopList& workshopList,
    ParticipantList& participantList, RegistrationManager& registration)
{
    int id = 0;
    string firstName, lastName;
    getIdentification(id, firstName, lastName);

    if (verifyIdentification(
        participantList, id, firstName, lastName))
    {
        Formatter::printParticipantWorkshops(participantList, id);
        int selection = getValidInt("\nWhich workshop number would you like to cancel? ");

        registration.unregisterParticipant(selection, id);

        cout << "\nYour registration for the following workshop "
             << "has been cancelled:\n\n";

        Formatter::printWorkshop(
            workshopList.getWorkshop(selection));

        cout << "\nA confirmation email with refund details "
             << "has been sent to you." << endl;
    }
    else
    {
        cout << "\nThe ID number does not match the name provided."
             << endl;
    }
}