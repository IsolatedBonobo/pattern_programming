#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

// Console window size
const int WIDTH = 40;
const int HEIGHT = 20;

// Car dimensions
const int CAR_WIDTH = 4;
const int CAR_HEIGHT = 2;

// Car position and speed
int car_x = WIDTH / 2 - CAR_WIDTH / 2;
int car_y = HEIGHT - CAR_HEIGHT - 1;
int car_speed = 1;

// Obstacle position and speed
int obstacle_x = rand() % (WIDTH - 3) + 1;
int obstacle_y = 0;
int obstacle_speed = 1;

// Score
int score = 0;

// Function to draw the game screen
void draw_screen() {
    system("cls");
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            if(i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1)
                cout << "*";
            else if(i == car_y && j >= car_x && j < car_x + CAR_WIDTH)
                cout << "=";
            else if(i == obstacle_y && j >= obstacle_x && j < obstacle_x + 3)
                cout << "@";
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << "Score: " << score << endl;
}

// Function to update the game state
void update_game() {
    // Move the car
    if(_kbhit()) {
        switch(_getch()) {
            case 'a': car_x--; break;
            case 'd': car_x++; break;
        }
    }
    // Move the obstacle
    obstacle_y += obstacle_speed;
    if(obstacle_y >= HEIGHT - 1) {
        obstacle_x = rand() % (WIDTH - 3) + 1;
        obstacle_y = 0;
        score++;
    }
    // Check for collision
    if(obstacle_y == car_y + 1 && obstacle_x <= car_x + CAR_WIDTH - 1 && obstacle_x + 2 >= car_x) {
        cout << "Game over!" << endl;
        exit(0);
    }
}

// Main function
int main() {
    // Set console window size
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT windowSize = {0, 0, WIDTH - 1, HEIGHT - 1};
    SetConsoleWindowInfo(hConsole, true, &windowSize);

    // Set console buffer size
    COORD bufferSize = {WIDTH, HEIGHT};
    SetConsoleScreenBufferSize(hConsole, bufferSize);

    // Hide the cursor
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.bVisible = false;
    cursorInfo.dwSize = 1;
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    // Game loop
    while(true) {
        draw_screen();
        update_game();
        Sleep(50);
    }

    return 0;
}
