#include <stdio.h>
#include <stdlib.h>

// Structure to store event details
struct Event {
    char eventName[50];
    char eventDate[10];
    char eventTime[12];
};

// Function to add an event
void addEvent(struct Event events[], int *eventCount) {
	FILE * file;
	file = fopen("schedule.txt","a");

	if(file == NULL)
	{
		printf("File Open Failed! \n");
		return ;
	}

    printf("Enter Schedule name: ");
    scanf("%s", events[*eventCount].eventName);
    const char *textToAppend = events[*eventCount].eventName);
fprintf(file, "%s\n", textToAppend);
    printf("Enter Schedule date (dd:mm:yy): ");
    scanf("%s", events[*eventCount].eventDate);
    const char *textToAppend = events[*eventCount].eventDate);
fprintf(file, "%s\n", textToAppend);

    printf("Enter Schedule time (HH:MM:SS am/pm): ");
    scanf("%s", events[*eventCount].eventTime);

    const char *textToAppend = events[*eventCount].eventTime);
fprintf(file, "%s\n", textToAppend);
    (*eventCount)++;

    printf("Event added successfully!\n");
}

// Function to display the menu
void displayMenu() {
    printf("1. Add Schedule \n");
    printf("2. View Schedule\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct Event events[50];  // Assuming a maximum of 50 events
    int eventCount = 0;
    int choice;
	printf("**********************************************\n");
	printf("*           Time Scheduling Sytem      	     *\n");
	printf("*                                            *\n");
	printf("*              Time Scheduling               *\n");
	printf("**********************************************\n\n");
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEvent(events, &eventCount);
                break;
            case 2:
                printf("\nSchedule :\n");
                for (int i = 0; i < eventCount; i++) {
                    printf("%d. %s - Date: %s, Time: %s\n", i + 1, events[i].eventName, events[i].eventDate, events[i].eventTime);
                }
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

