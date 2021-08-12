#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 82
#define HEIGHT 27

void DrawField(char gen[LENGTH][HEIGHT]);
void Rewrite();
void RewriteOldGen(char gen[LENGTH][HEIGHT], char oldgen[LENGTH][HEIGHT]);
int GetCellsCount(int x, int y);
int GetCell(int x, int y);
void Generate(char gen[LENGTH][HEIGHT]);
char Getch();
void Bezshovnost(char oldgen[LENGTH][HEIGHT]);
void Greetings();
void Menu();
void Start_init_1(char *str);
void Move(int *flag);
void Zeros();
void Ispolnyaet();
void Post_menu();

char gen[LENGTH][HEIGHT];
char oldgen[LENGTH][HEIGHT];
int px = 100;
int py = 100;

int main() {
  system("clear");
  Zeros();
  Menu();

  return 0;
}

void Greetings() {
  printf("\n\n\t\t\t\tControls\n\n");
  printf("\t\t\t\t ^ \n");
  printf("\t\t\t\t'W'\n");
  printf("\t\t\t  < 'A'\t    'D' >\n");
  printf("\t\t\t\t'S'\n");
  printf("\t\t\t\t v \tPick 'F'\n");
  printf("\t\t\t\t\tStart 'E'\n");
  printf("\n\t\t\t CHOOSE PARAMETERS\n\n");
  printf(
      "\t\t\t1: Random generation \n\t\t\t   Press 'O' for stop "
      "generation\n\n");
  printf("\t\t\t2: Hands pick\n\n");
  printf("\t\t\t3: Start inizialisation \n\n");
  printf("\t\t\t0: \t\tEXIT\n");
}

void Post_greetings() {
    printf("\n\n\n\n\t\t\t1: Start inizialisation \t\n\n");
    printf("\t\t\t2: Start inizialisation \t\n\n");
    printf("\t\t\t3: Start inizialisation  \t\n\n");
    printf("\t\t\t4: Start inizialisation  \t\n\n");
    printf("\t\t\t5: Start inizialisation  \t\n\n");
    printf("\t\t\t0: \t  EXIT\n");
}

void Post_menu() {
  system("clear");
  Post_greetings();
  int pick;
  char str[100];
  int len = 100;
  scanf("%d", &pick);
  switch (pick) {
  case 1:
    snprintf(str, len, "1.txt");
    Start_init_1(str);
    break;
  case 2:
    snprintf(str, len, "1.txt");
    Start_init_1(str);
    break;
  case 3:
    snprintf(str, len, "1.txt");
    Start_init_1(str);
    break;
  case 4:
    snprintf(str, len, "1.txt");
    Start_init_1(str);
    break;
  case 5:
    snprintf(str, len, "1.txt");
    Start_init_1(str);
    break;
  case 0:
    system("clear");
    Menu();
    break;
  default:
    break;
  }
}

void Menu() {
    system("clear");
    int pick = 0;
    int flag = 0;
    Greetings();
    scanf("%d", &pick);
    switch (pick) {
    case 1:
      Generate(gen);
      Ispolnyaet();
      break;
    case 2:
      px = 1;
      py = 1;
      DrawField(gen);
      while (flag != 5) {
        Move(&flag);
      }
      Ispolnyaet();
      break;
    case 3:
      Post_menu();
      break;
    case 0:
      system("clear");
      break;
    case 9136:  // GLEB
      break;
    default:
      Menu();
    }
}

void Ispolnyaet() {
  px = 100;
  py = 100;
  while (Getch() != 'o') {
        DrawField(gen);
        Rewrite();
      }
  Menu();
}

void Generate(char gen[LENGTH][HEIGHT]) {  // генерация поля
  for (int y = 1; y < HEIGHT - 1; y++) {
    for (int x = 1; x < LENGTH - 1; x++) {
      if ((arc4random() % 5) == 1) {
        gen[x][y] = '1';
      } else {
        gen[x][y] = '0';
      }
    }
  }
}

void Start_init_1(char *str) {
  FILE *fp;
  fp = fopen(str, "r");
  for (int y = 1; y < HEIGHT - 1; y++) {
    for (int x = 1; x < LENGTH - 1; x++) fscanf(fp, "%c ", &gen[x][y]);
  }
  fclose(fp);
  Ispolnyaet();
}

void Rewrite() {
  RewriteOldGen(gen, oldgen);
  Bezshovnost(oldgen);
  for (int y = 1; y < HEIGHT - 1; y++) {
    for (int x = 1; x < LENGTH - 1; x++) {
      int cellscount = GetCellsCount(x, y);
      if (oldgen[x][y] == '0') {
        if (cellscount == 3) {
          gen[x][y] = '1';
        }
      } else {
        if ((cellscount < 2) || (cellscount > 3)) {
          gen[x][y] = '0';
        }
      }
    }
  }
}

int GetCellsCount(int x, int y) {
  int g;
  g = GetCell(x - 1, y - 1) + GetCell(x - 1, y) + GetCell(x - 1, y + 1) +
      GetCell(x, y - 1) + GetCell(x, y + 1) + GetCell(x + 1, y - 1) +
      GetCell(x + 1, y) + GetCell(x + 1, y + 1);
  return (g);
}

int GetCell(int x, int y) {
  int f = oldgen[x][y] - '0';
  return (f);
}

void DrawField(char gen[LENGTH][HEIGHT]) {
  system("clear");
  int border_row = LENGTH - 1;
  int border_clm = HEIGHT - 1;
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < LENGTH; x++) {
      if ((px == x) && (py == y)) {
        printf("\033[0;32m*\033[0;37m");
      } else if (y == 0 || y == border_clm || x == 0 || x == border_row) {
        printf("\033[1;34m#\033[0;37m");
      } else if (gen[x][y] == '1') {
        printf("\033[1;31m1\033[0;37m");
      } else {
        printf("\033[0;30m0\033[0;37m");
      }
      if (x == border_row) {
        printf("\n");
      }
    }
  }
}

char Getch() {
  char c;
  system("/bin/stty raw");
  scanf("%c", &c);
  system("/bin/stty cooked");
  return c;
}
void RewriteOldGen(char gen[LENGTH][HEIGHT], char oldgen[LENGTH][HEIGHT]) {
  memcpy(oldgen, gen, 2214);
}
void Bezshovnost(char oldgen[LENGTH][HEIGHT]) {
  for (int i = 1; i < LENGTH - 1; i++) {
    oldgen[i][0] = oldgen[i][25];
    oldgen[i][26] = oldgen[i][1];
  }
  for (int j = 1; j < HEIGHT - 1; j++) {
    oldgen[0][j] = oldgen[80][j];
    oldgen[81][j] = oldgen[1][j];
  }
  oldgen[81][26] = oldgen[1][1];
  oldgen[0][0] = oldgen[80][25];
  oldgen[81][0] = oldgen[1][25];
  oldgen[0][26] = oldgen[80][1];
}

void Move(int *flag) {
  char c;
  c = Getch();
  if (((c == 'w') || (c == 'W')) && py > 1) {
    py = py - 1;
    DrawField(gen);
  } else if (((c == 'a') || (c == 'A')) && px > 1) {
    px = px - 1;
    DrawField(gen);
  } else if (((c == 's') || (c == 'S')) && py < 26) {
    py = py + 1;
    DrawField(gen);
  } else if (((c == 'd') || (c == 'D')) && px < 81) {
    px = px + 1;
    DrawField(gen);
  } else if ((c == 'f') || (c == 'F')) {
    gen[px][py] = '1';
  } else if ((c == 'e') || (c == 'E')) {
    gen[px][py] = '0';
  } else if ((c == 'q') || (c == 'Q')) {
    *flag = 5;
  }
}

void Zeros() {
  for (int y = 1; y < HEIGHT - 1; y++) {
    for (int x = 1; x < LENGTH - 1; x++) {
      gen[x][y] = '0';
    }
  }
}
