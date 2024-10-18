#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <cstdlib>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

struct Coordinate {
    int x;
    int y;
};

Coordinate head, food;
Coordinate body[30];
int length = 5;
int life = 3;

void gotoxy(int x, int y) {
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Boarder() {
    system("cls");
    for (int i = 10; i < 71; i++) {
        gotoxy(i, 10); printf("!");
        gotoxy(i, 30); printf("!");
    }
    for (int i = 10; i < 31; i++) {
        gotoxy(10, i); printf("!");
        gotoxy(70, i); printf("!");
    }
}

void Food() {
    srand(time(0));
    food.x = rand() % 60 + 11; // Ensure food is within bounds
    food.y = rand() % 20 + 11; // Ensure food is within bounds
}

void DrawFood() {
    gotoxy(food.x, food.y);
    printf("F");
}

void DrawSnake() {
    for (int i = 0; i < length; i++) {
        gotoxy(body[i].x, body[i].y);
        printf("*");
    }
}

void Move() {
    char key;
    while (true) {
        if (_kbhit()) {
            key = _getch();
            if (key == 27) break; // Exit game if ESC is pressed
        }

        // Move the snake
        DrawSnake();
        gotoxy(head.x, head.y);
        printf(" ");

        // Update the position of the snake's head
        if (key == UP) head.y--;
        else if (key == DOWN) head.y++;
        else if (key == LEFT) head.x--;
        else if (key == RIGHT) head.x++;

        // Check for collision with borders
        if (head.x <= 10 || head.x >= 70 || head.y <= 10 || head.y >= 30) {
            life--;
            if (life <= 0) {
                printf("Game Over! No lives left.\n");
                break;
            }
            head.x = 25; head.y = 20; // Reset position
            length = 5; // Reset length
        }

        // Check if snake eats the food
        if (head.x == food.x && head.y == food.y) {
            length++;
            Food(); // Generate new food
        }

        // Delay for snake movement
        Sleep(100);
        DrawFood();
        DrawSnake();
    }
}

int main() {
    head.x = 25; head.y = 20;
    Food(); // Generate initial food
    Boarder(); // Draw the border
    Move(); // Start the game loop
    return 0;
}
