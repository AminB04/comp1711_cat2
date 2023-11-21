#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



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
    // opens the file
    char filename [] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    // checks if the file is opened correctly
    if (file == NULL){
        perror("Error\n");
        return 1;
    }
    
    // declares the variables 
    FITNESS_DATA fitData[1000];
    int count = 0; 
    int buffer_size = 250;
    char line_buffer[buffer_size];
    
    // iterates through and reads the lines from the file
    while (fgets(line_buffer, buffer_size, file) != NULL){
        char date_buffer[buffer_size];
        char time_buffer[buffer_size];
        char steps_buffer[buffer_size];
        // tokenises the data and copies them into a new array structure (fitData)
        tokeniseRecord(line_buffer, ",", date_buffer, time_buffer, steps_buffer);
        strcpy(fitData[count].date , date_buffer);
        strcpy(fitData[count].time , time_buffer);
        fitData[count].steps = atoi(steps_buffer);
        // increment the count to keep track of the number of lines
        count++;
    }
    // prints the number of records in the file
    printf("Number of records in file: %d\n", count);

    // prints the first 3 records
    for (int i = 0; i < 3 ; i++) {
        printf("%s/%s/%d\n", fitData[i].date, fitData[i].time, fitData[i].steps);
    }
    // closes the file
    fclose(file);
    return 0;

}
