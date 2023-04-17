#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <conio.h>

std::string resourceLink = "R:\\VSProjekte\\c++\\CarRentalSystem\\CarRentalSystem\\Resources\\";

void Fullscreen();
void StartupMenu();
void Login();
void Register();
void Menu(int adm, std::string username);
void ViewCars();
void EditCar();
void DeleteCar(int adm, std::string username);

const std::string CurrentDateTime();

struct car
{
    char plate[16];
    char brand[32];
    char model[32];
    float capacity;
    int make;
    char color[16];
    float pricePerHour;
    bool available;
};

struct customer
{
    int id;
    char name[32];
    char surname[32];
    char phone[16];
    char zip[8];
    char city[32];
    char address[64];
};
/*
struct profile
{
    char username[32];
    char password[32];
    bool admin;
};
*/

void Fullscreen()
{
    keybd_event(VK_MENU, 0x38, 0, 0);
    keybd_event(VK_RETURN, 0x1c, 0, 0);
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}

const std::string CurrentDateTime()
{
    //get the current time in seconds since the Unix epoch
    time_t now = time(0);
    //date and time broken down to components
    struct tm tstruct;
    char buf[80];
    //convert to local time zone
    localtime_s(&tstruct, &now);
    //convert tm structure to 
    strftime(buf, sizeof(buf), "%y-%m-%dT%X+00Z", &tstruct);

    return buf;
}

void RentACar()
{

}

void ReturnACar()
{

}

void DeleteMyAccount(std::string username)
{

}

void ManageCars(int adm, std::string username)
{
    system("cls");
    if (adm == 0)
        Menu(0, username);
    std::cout << "\n\n\n\n\n\t\t";
    std::cout << "Car Rental System - Manage Cars\n\n";
    std::cout << "\n\t\t\t\t1. View Cars";
    std::cout << "\n\t\t\t\t2. Edit Car";
    std::cout << "\n\t\t\t\t3. Delete Car";
    std::cout << "\n\t\t\t\t0. Back";
    std::cout << "\n\n\t\t\t\t   Input: ";
    int choice;
    std::cin >> choice;

    if (choice == 0)
    {
        Menu(1, username);
    }
    else if (choice == 1)
    {
        ViewCars();
    }
    else if (choice == 2)
    {
        EditCar();
    }
    else if (choice == 3)
    {
        DeleteCar(1, username);
    }
}

void ViewCars()
{

}

void EditCar()
{

}

void DeleteCar(int adm, std::string username)
{
    system("cls");
    if (adm == 0)
        Menu(0, username);
    std::cout << "\n\n\n\n\n\t\t";
    std::cout << "Car Rental System - Delete Car\n\n";
    std::cout << "\n\t\t\t\t1. Please enter the license plate id of the car you want to remove from the system.\nEnter 0 to abort.";
    std::cout << "\n\n\t\t\t\t   Input: ";
    std::string plate;
    std::cin >> plate;
    if (plate == "0")
        ManageCars(1, username);
    std::cout << "Following car will be removed from the system: " << plate << "please enter password to confirm.\n" << username << "'s password: ";
    std::string password;
    std::cin >> password;
}

void ManageUsers(int adm)
{

}

void Menu(int adm, std::string username)
{
    system("cls");
    std::cout << "\n\n\n\n\n\t\t";
    std::cout << "Welcome " << username << "!\n\n\n\n\n\t\tPlease select a function of the Car Rental System you want to lose.\n\n";
    std::cout << "\n\t\t\t\t1. Rent a car";
    std::cout << "\n\t\t\t\t2. Return a car";
    std::cout << "\n\t\t\t\t3. Delete my Account";
    std::cout << "\n\t\t\t\t0. Exit";
    if (adm == 1) 
    {
        std::cout << "\n\n\n\t\t\tAdmin functions";
        std::cout << "\n\n\t\t\t\t4. Manage cars";
        std::cout << "\n\t\t\t\t5. Manage users";
    }
    std::cout << "\n\n\t\t\t\t   Input: ";
    int choice;
    std::cin >> choice;

    if (choice == 0) 
    {
        StartupMenu();
    }
    else if (choice == 1)
    {
        RentACar();
    }
    else if (choice == 2)
    {
        ReturnACar();
    }
    else if (choice == 3)
    {
        DeleteMyAccount(username);
    }
    else if (choice == 4 && adm == 1)
    {
        ManageCars(1, username);
    }
    else if (choice == 5 && adm == 1)
    {
        ManageUsers(1);
    }
}

void Login()
{
    std::string username, password, un, pw, adm;

    system("cls");
    std::cout << "\n\n\n\n\n\t\t";
    std::cout << "User Login\n\n";
    std::cout << "\n\t\t\t\tEnter your username: ";
    std::cin >> username;
    std::cout << "\n\t\t\t\tEnter your password: ";
    std::cin >> password;

    std::ifstream read(resourceLink + "RegisteredUsers\\" + username + ".txt");
    if (read.is_open()) 
    {
        getline(read, un);
        getline(read, pw);
        getline(read, adm);
        if (un == username && pw == password)
        {
            std::cout << "\n\n\t\t\t\tLogin successful.";
            
            if (adm == "0")
                Menu(0, username);
            else if (adm == "1")
                Menu(1, username);
        }
    }
    else
    {
        std::cout << "\n\n\t\t\t\tWrong username or password.";
        StartupMenu();
    }
}

void Register()
{
    std::string username, password;

    system("cls");
    std::cout << "\n\n\n\n\n\t\t";
    std::cout << "User Registration\n\n";
    std::cout << "\n\t\t\t\tEnter a username: ";
    std::cin >> username;
    std::cout << "\n\t\t\t\tEnter a password: ";
    std::cin >> password;

    std::ofstream file;
    file.open(resourceLink + "RegisteredUsers\\" + username + ".txt", std::ofstream::out);

    file << username << std::endl << password <<std::endl << false << std::endl;
    file.close();

    std::cout << "\n\n\t\t\t\tUser registration successful.";

    
    StartupMenu();
}

void StartupMenu()
{
    int choice;

    system("cls");
    std::cout << "\n\n\n\n\n\t\t";
    std::cout << "Welcome! Please select whether you want to log in or register as a new user in the Car Rental System.\n\n";
    std::cout << "\n\t\t\t\t1. User Login";
    std::cout << "\n\t\t\t\t2. Register";
    std::cout << "\n\t\t\t\t0. Exit";
    std::cout << "\n\n\t\t\t\t   Input: ";

    std::cin >> choice;

    if (choice == 0) 
    {
        exit(0);
    }
    else if (choice == 1)
    {
        Login();
    }
    else if (choice == 2)
    {
        Register();
    }
}

int main()
{
    Fullscreen();
    StartupMenu();
}