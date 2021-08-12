#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void menu(char *str);
void welcome();
void read(int flag, char *str);
void write(char *str);
int checker(int flag, char *str);

int main() {
  char str[128];
  menu(str);

  return 0;
}

// void menu(char *str) {
//     int flag = 0;
//     int pick = 0;
//     int check_i = 0;
//     char check = ' ';
//     check_i = scanf("%d%c", &pick, &check);
//     if (check != '\n' || check_i != 2) {
//         flag++;
//         checker(flag, str);
//         menu(str);
//     } else if (pick == 1 || pick == 2  || pick == 3) {
//         if (pick == 1) {
//             scanf("%s", str);
//             read(flag, str);
//             menu(str);
//         } else if (pick == 2) {
//               write(str);
//               menu(str);
//         } else if (pick == -1) {
//               exit(0);
//         }
//     }
//     else {
//       flag++;
//       checker(flag, str);
//       menu(str);
//     }
// }



void menu(char *str) {
  int flag = 0;
  int pick = 0;
  char check = ' ';
  scanf("%d%c", &pick, &check);
  if (check != '\n') {
      check = ' ';
      flag++;
      checker(flag, str);
      rewind(stdin);
  } else {
  switch (pick) {
    case 1:
      scanf("%50s", str);
      read(flag, str);
      menu(str);
      break;
    case 2:
      write(str);
      menu(str);
      break;
    case 3:
      menu(str);
      break;
    case (-1):
      break;
    default:
      checker(flag, str);
      rewind(stdin);
      break;
    }
  }
}

void input();

void read(int flag, char *str) {
    FILE *fp;
    char data[128];
    if ((fp = fopen(str, "r") ) == NULL) {
        flag++;
        checker(flag, str);
    }
    while (!feof(fp)) {
        if (fgets(data, 126, fp)) {
            printf("%s\n", data);
        }
    }
    fclose(fp);
  }
  void write(char *str) {
    FILE *fp;
    if ((fp = fopen(str, "r+")) != NULL) {
        fseek(fp, 0L, SEEK_END);
        scanf("%50s", str);
        fputs(str, fp);
  }
  fclose(fp);
  }

int checker(int flag, char *str) {
    if (flag != 0) {
      printf("n/a\n");
    }
    menu(str);
  return 0;
}

