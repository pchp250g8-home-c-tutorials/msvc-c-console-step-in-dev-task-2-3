// Task-2-3-en.c : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
    // Variable initialization
    int direction = 0; // 0: direction unknown, 1: up, -1: down
    unsigned int changes = 0; // Counter for direction changes
    int new_direction = direction; // New direction
    unsigned int prev, current; // Floor numbers where the elevator stopped
    bool b_done = false; // Flag variable for loop exit condition
    // Data input
    printf("Enter the floor numbers where the elevator stopped.\r\n");
    printf("0 - end of data input.\r\n");
    // Read the first floor
    scanf("%u", &prev);
    b_done = (prev == 0); // Flag variable for loop exit condition
    while (!b_done)
    {
        scanf("%d",&current); // Enter the remaining floors
        b_done = (current == 0); // Exit loop if 0 is entered
        // If floors are the same, direction doesn't change;
        // simply skip
        if (!b_done && current != prev)
        {
            // Determine the new current direction
            // between prev and current
            new_direction = 1;
            if (current > prev)
            {
                new_direction = -1;
            }
        }
        // If the direction was already known (i.e., not 0)
        // and it does not match the new direction, then a change has occurred
        if (!b_done && direction != 0 && new_direction != direction)
        {
            changes += 1;
        }
        // Update the history for the next step
        direction = new_direction;
        prev = current;
    }
    // Display information on the screen
    printf("Number of times the elevator changed direction: %u\r\n", changes);
    // Pause the output until the "Enter" key is pressed
    getchar();
    getc(stdin);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item 
//      to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
