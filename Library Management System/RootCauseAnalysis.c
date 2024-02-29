// RootCauseAnalysis.c
#include <stdio.h>
#include <string.h>
#include "RootCauseAnalysis.h"

void initializeErrorLog(ErrorLog* errorLog) {
    errorLog->count = 0;
}
//if log entries hit a max limit present the error
void logError(ErrorLog* errorLog, const char* message) {
    if (errorLog->count < MAX_LOG_ENTRIES) {
        // Log the error with timestamp (you may implement this based on your requirements)
        // For simplicity, using a placeholder timestamp
        sprintf(errorLog->entries[errorLog->count].timestamp, "2024-03-01 12:34:56");
        strncpy(errorLog->entries[errorLog->count].message, message, sizeof(errorLog->entries[errorLog->count].message));

        errorLog->count++;
    } else {
        //when overload is reached present the error
        printf("Error log is full. Unable to log more errors.\n");
    }
}
//display error log message needed
void displayErrorLog(const ErrorLog* errorLog) {
    printf("Error Log:\n");
    for (int i = 0; i < errorLog->count; ++i) {
        printf("[%s] %s\n", errorLog->entries[i].timestamp, errorLog->entries[i].message);
    }
}
