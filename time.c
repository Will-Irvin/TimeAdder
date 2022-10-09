#include <stdio.h>

#define SECONDS_IN_MINUTE (60)
#define MINUTES_IN_HOUR (60)
#define SCAN_INPUT_1 (3)
#define SCAN_INPUT_2 (2)

struct time {
  int hours;
  int minutes;
  float seconds;
};

int main() {
  printf("Enter the number corresponding to the input format you would like to give:\n");
  printf("1. Include hours with each input\n");
  printf("2. Do not include hours with each input\n");
  int input_num = 0;
  int scan = scanf("%d", &input_num);
  if (scan != 1) {
    printf("Invalid input, please run the program again.");
    return -1;
  }
  struct time result = {0, 0, 0};
  struct time input = {0, 0, 0};
  while (1) {
    if (input_num == 1) {
      printf("Enter the next time in the form #hrs:#min:#s (the seconds can be a decimal)\n");
      printf("Enter something that doesn't match this format when you are finished.\n");
      scan = scanf("%d:%d:%f", &input.hours, &input.minutes, &input.seconds);
      if (scan != SCAN_INPUT_1) {
        break;
      }
    }
    else if (input_num == 2) {
      printf("Enter the next time in the form #min:#s (the seconds can be a decimal)\n");
      printf("Enter something that is not in this format when you are finished.\n");
      scan = scanf("%d:%f", &input.minutes, &input.seconds);
      if (scan != SCAN_INPUT_2) {
        break;
      }
    }
    else {
      printf("Please run the program again and enter a valid format number\n");
      return -1;
    }
    if (input.seconds >= 60 || input.minutes >= 60 || input.hours < 0
        || input.minutes < 0 || input.seconds < 0) {
      printf("Invalid input, no addition was made\n");
      continue;
    }
    result.seconds += input.seconds;
    if (result.seconds >= SECONDS_IN_MINUTE) {
      result.minutes++;
      result.seconds = result.seconds - SECONDS_IN_MINUTE;
    }
    result.minutes += input.minutes;
    if (result.minutes >= MINUTES_IN_HOUR) {
      result.hours += result.minutes / MINUTES_IN_HOUR;
      result.minutes = result.minutes % MINUTES_IN_HOUR;
    }
    result.hours += input.hours;
    printf("Current total: %d:%d:%.3f\n", result.hours, result.minutes, result.seconds);
  }
  printf("Final Result: %d:%d:%.3f\n", result.hours, result.minutes, result.seconds);
  return 0;
}
