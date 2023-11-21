#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
 
void importFile(FITNESS_DATA *fitData, int *count){
    char filename[100]; 
    printf("Input filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not find or open file.\n");
        return;
    }

    int buffer_size = 250;
    char line_buffer[buffer_size];
    printf("File successfully loaded.\n");

    while (fgets(line_buffer, buffer_size, file) != NULL){
        char date_buffer[buffer_size];
        char time_buffer[buffer_size];
        char steps_buffer[buffer_size];
        tokeniseRecord(line_buffer, ",", date_buffer, time_buffer, steps_buffer);
        strcpy(fitData[*count].date , date_buffer);
        strcpy(fitData[*count].time , time_buffer);
        fitData[*count].steps = atoi(steps_buffer);
        (*count)++;
    }
    fclose(file);   
}

void displayTotalRecords(int count){
    printf("Total records: %d\n", count);
}

void findFewestSteps(FITNESS_DATA *fitData, int count){
    int min_steps = fitData[0].steps;
    int right_steps = 0;

    for (int i = 1; i < count; i++) {
        if (fitData[i].steps < min_steps) {
            min_steps = fitData[i].steps;
            right_steps = i;
        }
    }
    printf("Fewest steps: %s %s \n", fitData[right_steps].date, fitData[right_steps].time);
}

void findLargestSteps(FITNESS_DATA *fitData, int count){
    int max_steps = fitData[0].steps;
    int right_steps = 0;

    for (int i = 1; i < count; i++) {
        if (fitData[i].steps > max_steps) {
            max_steps = fitData[i].steps;
            right_steps = i;
        }
    }
    printf("Largest steps: %s %s \n", fitData[right_steps].date, fitData[right_steps].time);
}

void findMeanSteps(FITNESS_DATA *fitData, int count){
    float total_steps = 0;
    int mean_steps = 0;

    for (int i = 0; i < count; i++){
        total_steps += fitData[i].steps;
    }
    mean_steps = total_steps / count;
    int rounded_mean = (int)(mean_steps + 0.5);
    printf("Mean step count: %d \n", rounded_mean);
}

void findLongestPeriod(FITNESS_DATA *fitData, int count){
    int length = 0;
    int longest = 0;
    int firstIndex = 0;
    int lastIndex = 0;
    int currentFirstIndex = 0;
     
    for (int i = 0; i < count; i++) {
        if (fitData[i].steps > 500) {
            length = 1; 
            currentFirstIndex = i;
            for (int j = i + 1; j < count && fitData[j].steps > 500; j++) {
                length++;
                i = j; 
            }
            if (length > longest) {
                longest = length;
                firstIndex = currentFirstIndex;
                lastIndex = i; 
            }
        }
    }
    printf("Longest period start: %s %s \n", fitData[firstIndex].date, fitData[firstIndex].time);
    printf("Longest period end: %s %s \n", fitData[lastIndex].date, fitData[lastIndex].time);
}

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }




// Complete the main function
int main() {
    FITNESS_DATA fitData[1000];
    int count = 0;
    char option = '.';

    while (option != 'Q') {
        printf("\nMenu Options:\n");
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Exit\n");
        printf("Enter choice: ");
        scanf(" %c", &option);

        switch (option) {
            case 'A':
                importFile(fitData, &count);
                break;
            case 'B':
                displayTotalRecords(count);
                break;
            case 'C':
                findFewestSteps(fitData, count);
                break;
            case 'D':
                findLargestSteps(fitData, count);
                break;
            case 'E':
                findMeanSteps(fitData, count);
                break;
            case 'F':
                findLongestPeriod(fitData, count);
                break;
            case 'Q':
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
   }








