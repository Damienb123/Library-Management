// RootCauseAnalysis.h
#ifndef ROOTCAUSEANALYSIS_H
#define ROOTCAUSEANALYSIS_H

#include <stdio.h>

#define MAX_LOG_ENTRIES 100

typedef struct {
    char timestamp[20];  // Assuming timestamp format YYYY-MM-DD HH:MM:SS
    char message[256];
} LogEntry;

typedef struct {
    LogEntry entries[MAX_LOG_ENTRIES];
    int count;
} ErrorLog;

void initializeErrorLog(ErrorLog* errorLog);
void logError(ErrorLog* errorLog, const char* message);
void displayErrorLog(const ErrorLog* errorLog);

#endif // ROOTCAUSEANALYSIS_H
