#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include <string>

void fullscreen();
void GotoXY(int, int);
void gotoxy(int, int);
const std::string currentDateTime();

struct car 
{
    char plate[16];
    char brand[32];
    char model[32];
    float capacity;
    int year;
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

struct password 
{
    int id;
    char password[32];
};

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
    tstruct = *localtime(&now);
    //convert tm structure to 
    strftime(buf, sizeof(buf), "%d-%m-%y-T-%X", &tstruct);

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
        Sleep(900);
        system("cls");
        i++;
    }
    menu();
}

void printDate()
{
    std::cout << "\n\t |\t\t\t\t\tDATE: " << currentDateTime() << std::endl;
}

void gotoxy(int x, int y)
{
    COORD coord;

    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
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

    std::ifstream ifs("art.txt");
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

void menu()
{
    int x;
    art();
}

int main()
{
    std::cout << "Hello World!\n";
}
