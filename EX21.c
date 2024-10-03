/*
Ex21
Write a program that asks user to enter a file name. Program opens the file in text mode. The file is supposed to contain NMEA (GPS) data. Program looks for lines that start with ‘$’ and have an asterisk ‘*’ later on the line. If a line meeting the condition is found the program verifies the checksum of the line. If checksum is ok line is printed prefixed with [ OK ] otherwise line is prefixed with [FAIL].

Checksum is calculated by XORing all characters after ‘$’ and before ‘*’. The result is checked against the two-digit hexadecimal value that follows ‘*’. If they are equal line is ok.

For example:
$GPGGA,092750.000,5321.6802,N,00630.3372,W,1,8,1.03,61.7,M,55.2,M,,*76
$GPGSA,A,3,10,07,05,02,29,04,08,13,,NOT,OK,,1.72,1.03,1.38*0A
$GPGSV,3,1,11,10,63,137,17,07,61,098,15,05,59,290,20,08,54,157,30*70
$GPGSV,3,2,11,02,39,223,19,13,28,070,17,26,23,252,,04,14,186,14*79
$GPGSV,3,3,11,29,09,301,24,16,09,020,,36,,,*76
$GPRMC,092750.000,A,5321.6802,N,00630.3372,W,0.02,31.66,280511,,,A*43
$GPGGA,092751.000,5321.6802,N,00630.3371,W,1,8,1.03,61.7,M,55.3,M,,*75
$GPGSA,A,3,10,07,05,02,29,04,08,13,BAD,,,,1.72,1.03,1.38*0A
$GPGSV,3,1,11,10,63,137,17,07,61,098,15,05,59,290,20,08,54,157,30*70
$GPGSV,3,2,11,02,39,223,16,13,28,070,17,26,23,252,,04,14,186,15*77
$GPGSV,3,3,11,29,09,301,24,16,09,020,BROKEN,36,,,*76
$GPRMC,092751.000,A,5321.6802,N,00630.3371,W,0.06,31.66,280511,,,A*45

Above the lines that read “NOT,OK”, “BAD” and “BROKEN” have a failing checksum.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_FILENAME 100
#define MAX_LINE 1000

int main() {
  char filename[MAX_FILENAME];
  char line[MAX_LINE];
  char *token, *checksum_str;
  int checksum;
  FILE *file;

  // Get the filename
  printf("Enter the filename: ");
  scanf("%s", filename);

  // Open the file
  file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  // Read the file line by line
  while (fgets(line, MAX_LINE, file) != NULL) {
    
    // Find the checksum
    token = strtok(line, "*");
    checksum_str = strtok(NULL, "\0");

    // Invalid line
    if (line[0] != '$' || checksum_str==NULL) {
      continue;
    }

    // Calculate the checksum
    checksum = 0;
    for(int i=1; i<strlen(token); i++) {
      checksum ^= token[i];
    }
    
    // Check the checksum
    if (checksum == strtol(checksum_str, NULL, 16)) {
      printf("[ OK ] %s\n", line);
    } else {
      printf("[FAIL] %s\n", line);
    }
  }
}