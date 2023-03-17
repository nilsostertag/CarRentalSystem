#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include <string>

void fullscreen();
void Border();
void menu();
void GotoXY(int, int);
void gotoxy(int, int);
const std::string currentDateTime();

struct car 
{
    char plate[16];
    char brand[32];
    char model[32];
    float capacity;
    int make;
    char color[16];
    float pricePerHour;
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

struct pass
{
    int id;
    char password[32];
};

pass userPass[1000];
car rent[1000];
customer customers[1000];
car available[1000];

/*
    Simulates keyboard input "Alt + Enter" to toggle fullscreen mode
*/
void fullscreen() 
{
    keybd_event(VK_MENU, 0x38, 0, 0);
    keybd_event(VK_RETURN, 0x1c, 0, 0);
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}

const std::string currentDateTime() 
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

void time()
{
    int i = 0;

    while (i < 5)
    {
        Border();
        gotoxy(20, 20);
        std::cout << "\n\n\n\n\n\t  |\t\t\t\tDATE: " << currentDateTime() << std::endl;
        Sleep(1000);
        system("cls");
        i++;
    }
    menu();
}

void printDate()
{
    std::cout << "\n\t |\t\t\t\t\tDATE: " << currentDateTime() << std::endl;
}

void readUserPass()
{
    std::ifstream ifs;
    ifs.open("UserPass.txt");

    int i;
    while (!ifs.eof())
    {
        ifs >> userPass[i].id;
        ifs.ignore();
        ifs.getline(userPass[i].password, 20);
        i++;
    }
    ifs.close();
}

void password()
{
    Border();

    countUsers();

    std::string password;
    char c;
    gotoxy(40, 40);
    std::cout << "\n\n\n\n\t |\t\t\tPASSWORD: ";

    while (c != '\r') 
    {
        c = getch();
        if (c == 0)
        {
            switch (getch())
            {
            default:
                break;
            };
        }
        else if (c == '\b')
        {
            if (password.size() != 0)
            {
                std::cout << "\b \b";
                password.erase(password.size() - 1, 1);
            }
            continue;
        }
        else if (c <= '9' && c >= '0' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
        {
            password += c;
            std::cout << "*";
        }
        else
            continue;
    }

    for (int i = 0; i < countUsers(); i++)
    {
        if (password.compare(userPass[i].password) == 0)
        {
            system("cls");
            loadCheck();
            admin();
        }
    }

    if (password == "a")
    {
        system("cls");
        loadCheck();
        admin();
    }
    else
    {
        std::cout << "\n\t  |\t\t\tWrong password!";
        std::cout << "\n\t  |\t\t\tReturning to main menu..." << std::endl;
        std::cout << "\n\t  |\t\t\t";
        Sleep(1000);
        std::cout << "\n\t  |\t\t\tPress Enter to continue...";
        std::cout << "\n\t  |\t\t\t";
        getch();
        menu();
    }
}

void gotoxy(int x, int y)
{
    COORD coord;

    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void loadCheck()
{
    Border();
    int timer = rand() % 5 + 1;
    int row, col, r, c, q;
    gotoxy(60, 36);

    for (r = 1; r <= timer; r++) 
    {
        for (q = 0; q <= 100000000; q++)
        {
            printf("%c", 177);
        }
        Sleep(100);
        system("cls");
    }
}

void loadUpdate()
{
    Border();
    int timer = rand() % 25 + 1;
    int row, col, r, c, q;
    gotoxy(65, 34);
    printf("UPDATING DATABASE...");
    gotoxy(60, 36);

    for (r = 1; r <= timer; r++)
    {
        for (q = 0; q <= 100000000; q++)
        {
            printf("%c", 177);
        }
        Sleep(100);
        system("cls");
    }
}

void loadExit()
{
    Border();
    int timer = rand() % 5 + 1;
    int row, col, r, c, q;
    gotoxy(65, 34);
    printf("LOGGING OFF...");
    gotoxy(60, 36);

    for (r = 1; r <= timer; r++)
    {
        for (q = 0; q <= 100000000; q++)
        {
            printf("%c", 177);
        }
        Sleep(100);
        system("cls");
    }
}

/*
*   Move cursor position to specified x and y coordinates in the window
*/
void GotoXY(int x, int y)
{
    //declare handle to console screen buffer
    HANDLE a;
    //represent two-dimensional coordinate in console screen buffer
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    //assign handle to the console window
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    //set cursor position to specified coordinates 
    SetConsoleCursorPosition(a, b);
}

void Border()
{
    int i;
    system("cls");
    for (i = 10; i < 140; i++)
    {
        GotoXY(i, 10);
        std::cout << "=";
        GotoXY(i, 58);
        std::cout << "=";
    }
    for (i = 10; i < 58; i++)
    {
        GotoXY(10, i);
        std::cout << "=";
        GotoXY(140, i);
        std::cout << "=";
    }
}

void art() 
{
    Border();
    gotoxy(0, 20);

    std::ifstream ifs("logo.txt");
    std::string Lines = "";

    if (ifs)
    {
        while (ifs.good())
        {
            std::string tempLine;
            getline(ifs, tempLine);
            tempLine += "\n";

            Lines += tempLine;
        }
        std::cout << Lines;
        printDate();
    }
    ifs.close();
}

int countCars()
{
    int numberOfCars = 0;
    std::ifstream ifs("CarRental.txt");

    std::string word;
    while (getline(ifs, word))
    {
        if (!word.empty())
        {
            numberOfCars++;
        }
    }
    ifs.close();

    return numberOfCars;
}

int countUsers()
{
    int numOfCustomers = 0;
    std::ifstream ifs("UserPass.txt");

    std::string word;
    while (getline(ifs, word))
    {
        if (!word.empty())
        {
            numOfCustomers++;
        }

        ifs.close();

        return numOfCustomers;
    }
}

void existingCustomer()
{
    int tempCustomer, hours, userID;
    char carSelect[16];

    tempCustomer = countUsers() - 1;
    std::ofstream log;
    log.open("Log.txt", std::fstream::app);
    std::ofstream ofs;
    ofs.open("temp.txt");
    std::cout << "\n\n\n\n" << std::endl;

    std::cout << "\n\n";
    art();
    std::cout << std::endl;

    std::cout << "\n\t |\t\t\t\tPlease enter user ID: ";
    std::cin >> userID;

    for (int i = 0; i < countUsers(); i++)
    {
        if (userID == customers[i].id)
        {
            std::cout << "\n\t  |\t\t\t\t\tWELCOME BACK, " << customers[i].name << "!";
            std::cout << "\t  |\tID: " << customers[i].id;
            std::cout << "\n\n";

            log << "\nNAME: " << customers[i].surname << ", " << customers[i].name;
            log << "\nPHONE: " << customers[i].phone;
        }

        displayAvailableCars();

        std::cout << "\n\n\t |\t\t\t\t\tPlease select a car";
        std::cout << "\n\t |\t\t\t\t\tPlate ID: ";
        std::cin >> carSelect;
        std::cin.getline(carSelect, 16);

        int x = countAvailableCars();

        for (int i = 0; i < countAvailableCars(); i++) 
        {
            if (strcmp(carSelect, available[i].plate) != 0)
            {
                ofs << available[i].plate;
                ofs << " ";
                ofs << available[i].brand;
                ofs << " ";
                ofs << available[i].model;
                ofs << " ";
                ofs << available[i].capacity;
                ofs << " ";
                ofs << available[i].make;
                ofs << " ";
                ofs << available[i].color;
                ofs << " ";
                ofs << available[i].pricePerHour;

                if (i != countAvailableCars())
                    ofs << std::endl;
            }
        }
    }

    ofs.close();

    remove("available.txt");
    rename("temp.txt", "available.txt");

    std::cout << "\t |\t\t\t\t\tHours to rent: ";
    std::cin >> hours;

    int j;
    for (int i = 0; i < countCars(); i++)
    {
        if (strcmp(carSelect, rent[i].plate) == 0)
        {
            j = i;

            log << "\nCAR: " << rent[i].plate;
            log << "\nCAR: " << rent[i].plate;
            log << "\nCAR: " << rent[i].plate;
            log << "\nCAR: " << rent[i].plate;
        }
    }
}

void newUserPass()
{
    Border();

    std::ofstream ofs;
    ofs.open("Users.txt", std::fstream::app);

    userPass[countUsers()].id = countUsers() + 1;

    std::string password;
    char c;

    gotoxy(40, 20);

    std::cout << "\n\n\n\n\t |\t\t\tID(DEFAULT): " << userPass[countUsers()].id;
    std::cout << "\n\t |\t\t\tADD PASSWORD: ";

    while (c != '\r')
    {
        c = getch();
        if (c == 0)
        {
            switch (getch())
            {
            default:
                break;
            };
        }
        else if (c == '\b')   
        {
            if (password.size() != 0)  
            {
                std::cout << "\b \b";
                password.erase(password.size() - 1, 1);
            }
            continue;
        }
        else if (c <= '9' && c >= '0' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')  
        {
            password += c;
            std::cout << "*";
        }
        else
            continue;
    }

    strcpy(userPass[countUsers()].password, password.c_str());

    ofs << userPass[countUsers()].id;
    ofs << ";";
    ofs << userPass[countUsers()].password;
    ofs << std::endl;
    ofs.close();

    system("cls");
    admin();
}

void showCarData()
{
    int x;

    std::cout << "\n\n";
    art();
    std::cout << std::endl;

    std::cout << "\t | Plate\tBrand\tModel\tCapacity\tMake\tColor\tPrice Per Hour |" << std::endl;
    std::cout << "\t | ========================================================== |" << std::endl;

    for (int i = 0; i < countCars(); i++)
    {
        std::cout << "\t | " << rent[i].plate << "\t" << rent[i].brand << "\t" << rent[i].model << "\t" << rent[i].capacity << "\t" << rent[i].make << "\t" << rent[i].color << "\t" << rent[i].pricePerHour << std::endl;
    }

    std::cout << "\n\n";
    std::cout << "\n\t  |\t\t\t\t\t  1. BACK";
    std::cout << "\n\t  |\t\t\t\t\t  2. MAIN MENU" << std::endl << "\n\n";
    std::cout << "\t  |\t\t\t\t\tINPUT :";
    std::cin >> x;

    system("cls");

    if (x == 1)
    {
        admin();
    }
    else if (x == 2)
    {
        menu();
    }
}

void admin()
{
    int x;
    std::cout << "\n\n\n\n\n";
    art();
    std::cout << std::endl;

    std::cout << "\n\t  |\t\t\t\t\t\t\t  1. ADD ADMIN";
    std::cout << "\n\t  |\t\t\t\t\t\t\t  2. SHOW DATA";
    std::cout << "\n\t  |\t\t\t\t\t\t\t  3. ADD CAR";
    std::cout << "\n\t  |\t\t\t\t\t\t\t  4. DELETE CAR";
    std::cout << "\n\t  |\t\t\t\t\t\t\t  5. RESET AVAILABLE CAR";
    std::cout << "\n\t  |\t\t\t\t\t\t\t  6. LOG OUT" << std::endl << "\n";
    std::cout << "\t  |\t\t\t\t\t\t\tINPUT :";
    std::cin >> x;

    if (x == 1)
    {
        newUserPass();
    }
    else if (x == 2)
    {
        showCarData();
    }
    else if (x == 3)
    {
        newCarData();
    }
    else if (x == 4)
    {
        deleteCar();
    }
    else if (x == 5)
    {
        system("cls");
        resetAvail();
    }
    else if (x == 6)
    {
        loadExit();
        menu();
    }
}

void user()
{
    int x;

    art();

    std::cout << std::endl;

    std::cout << "\n\t  |\t\t\t\t\t\t\t  1. NEW USER";
    std::cout << "\n\t  |\t\t\t\t\t\t\t  2. LOG IN";
    std::cout << "\n\t  |\t\t\t\t\t\t\t  3. MAIN MENU" << std::endl;
    std::cout << "\n\n\t  |\t\t\t\t\t\t\tINPUT :";
    std::cin >> x;

    system("cls");

    if (x == 1)
    {
        newCustomerData();
    }

    else if (x == 2)
    {
        system("cls");
        loadUpdate();
        existingCustomer();
    }

    else if (x == 3)
    {
        menu();
    }
}

void menu()
{
    int x;
    art();

    std::cout << std::endl;
    std::cout << "\n\t |\t\t\t\t\t\t\t 1. ADMIN";
    std::cout << "\n\t |\t\t\t\t\t\t\t 2. USER";
    std::cout << "\n\t |\t\t\t\t\t\t\t 3. T%C";
    std::cout << "\n\t |\t\t\t\t\t\t\t 4. EXIT";
    std::cout << "\n\t |\t\t\t\t\t\t\tINPUT: ";
    std::cin >> x;

    system("cls");

    if (x == 1)
    {
        password();
    }
    else if (x == 2)
    {
        user();
    }
    else if (x == 3)
    {
        tNc();
        getch();
    }
    else if (x == 4)
    {
        std::cout << "\n\n\n\n\n";
        exitArt();
        Sleep(2000);
        exit(0);
    }
    else if (x == 5)
    {
        time();
    }
    else if (x == 6)
    {
        fullscreen();
        menu();
    }
}

void tNc()
{
    art();
    std::cout << std::endl;
    std::cout << "\n\t  |\t\t\t1. MINIMUM RENT TIME IS 3 HOURS";
    std::cout << "\n\t  |\t\t\t2. RISK BY YOUR OWN";
    std::cout << "\n\t  |\t\t\t3. INCASE ACCIDENT, ALL COSTING IS PAID BY THE DRIVER";
    std::cout << "\n\t  |\t\t\t4. PREPARE ITEM AS BELOW";
    std::cout << "\n\t  |\t\t\t     \3COPY OF IC, LICENSE";
    std::cout << "\n\t  |\t\t\t     \3DEPOSIT (BASED ON CAR TYPE)";
    std::cout << "\n\t  |\t\t\t5. ADDITIONAL CHARGE IF LATE";
    std::cout << "\n\t  |\t\t\t6. SAFE DRIVE!";
    std::cout << "\n\n\n\n\t  |\t\t\t                             PRESS ANY KEY TO CONTINUE :)";
    std::cout << "\n\t  |\t\t\t                                                            ";

    getch();
    menu();
}

main()
{
    std::cout << "Hello World!\n";
    printDate();
}
