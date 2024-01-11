#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *file;
	file = fopen("schedule.csv", "w");

	if (file == NULL){
		printf("File Open Failed! \n");
		return 0;
	}
	fprintf(file, "Schedule Task \tDate \tTime(am/pm) \n");
	return 0;
}
