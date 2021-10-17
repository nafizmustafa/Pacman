#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define H 30
#define W 60
#define SPACE 750
struct coord {
   int x,y;};

struct Pacman {
   struct coord position;
   int vx,vy;
   int food;};

struct Space {
   struct coord position;
   int vx,vy;
   };


struct Space allspace[SPACE];

struct Pacman myPacMan = {
                           {
                              .x = 1,
                              .y = 1
                           },
                              .vx = 0,
                              .vy = 0,
                              .food = 0
                         };


char field[H][W] =
{
   { "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" },
   { "<                                                          >" },
   { "<                                                          >" },
   { "<                                                          >" },
   { "<                                                          >" },
   { "<                                                          >" },
   { "<                                                          >" },
   { "<                                                          >" },
   { "<                                                          >" },
   { "<                                                          >" },
   { "<                                                          >" },
   { "<                                                          >" },
   { "<                                                          >" },
   { "<                                                          >" },
   { "<                                                          >" },
   { "<                                                          >" },
   { "<                                                          >" },
   { "<                                                          >" },
   { "<                                                          >" },
   { "<                                                          >" },
   { "<                                                          >" },
   { "<                                                          >" },
   { "<                                                          >" },
   { "<                                                          >" },
   { "<                                                          >" },
   { "<                                                          >" },
   { "<                                                          >" },
   { "<                                                          >" },
   { "<                                                          >" },
   { "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" }
};

void initialize()
{

   for (int i = 0; i < H; i++)
   {
      for (int j = 0; j < W; j++)
      {
         if (field[i][j]==' ')
            field[i][j] = '-';
      }
   }

   for (int i = 0; i < SPACE; i++)
   {
      allspace[i].vx = 0;
      allspace[i].vy = 0;


      int x,y;
      do
      {
         x = 1 + rand() % (W-1);
         y = 1 + rand() % (H-1);

      } while (field[y][x] != '-');
      allspace[i].position.x = x;
      allspace[i].position.y = y;
      field[y][x] = ' ';

   }


}

void user_input()
{
   if (_kbhit())
   {
      char c1 = _getch();

      if (c1 == -32)
      {
         char c2 = _getch();

         myPacMan.vx = 0;
         myPacMan.vy = 0;

         switch (c2)
         {
            case 72: myPacMan.vy = -1; break; // cursor up
            case 80: myPacMan.vy = +1; break; // cursor down
            case 75: myPacMan.vx = -1; break; // cursor left
            case 77: myPacMan.vx = +1; break; // cursor right
         }
      }

   }
}

void move_figures()
{

   field[myPacMan.position.y][myPacMan.position.x] = ' ';


     int nx = myPacMan.vx + myPacMan.position.x;
     int ny = myPacMan.vy + myPacMan.position.y;


   if (field[ny][nx] == '^')
   {

      myPacMan.vx = 0;
      myPacMan.vy = 0;
   }
   if (field[ny][nx] == '<')
   {

      myPacMan.vx = 0;
      myPacMan.vy = 0;
   }
   if (field[ny][nx] == '>')
   {

      myPacMan.vx = 0;
      myPacMan.vy = 0;
   }
   if (field[ny][nx] == 'v')
   {

      myPacMan.vx = 0;
      myPacMan.vy = 0;
   }

   myPacMan.position.x += myPacMan.vx;
   myPacMan.position.y += myPacMan.vy;

   if (field[ny][nx] == '-')
   {
      myPacMan.food++;
   }

   field[myPacMan.position.y][myPacMan.position.x] = 'C';

}


void show_playfield()
{
   for (int i = 0; i < H; i++)
   {
      for (int j = 0; j < W; j++)
      {
         printf("%c", field[i][j]);
      }
      printf("\n");
   }

   printf("Score: %d\n", myPacMan.food);
}

void set_cursor_position(int x, int y)
{

   COORD coord = { x, y };

   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



int main(){
     int n;
    Beep(500,500);
    Beep(400,500);
    Beep(1000,500);
    Beep(50,500);
    Beep(5000,500);
    printf("\n\n\t\t\t|| ######      ###        #########  ##     ##       ###       ##      # ||\n");
        printf("\t\t\t|| #    #     #   #       #          # #   # #      #   #      # #     # ||\n");
        printf("\t\t\t|| #    #    #     #      #          #  # #  #     #     #     #  #    # ||\n");
  printf("\t\t    ---:|| ######   #########     #          #   #   #    #########    #   #   # || :---\n");
        printf("\t\t\t|| #       #         #    #          #       #   #         #   #    #  # ||\n");
        printf("\t\t\t|| #      #           #   #          #       #  #           #  #     # # ||\n");
        printf("\t\t\t|| #     #             #  #########  #       # #             # #      ## ||\n");


    printf("\n\n\n\n\t\t\t\t\t\t\tINSTRUCTION\n\n");
    printf("\t\t****************************************************************************************\n\n");
    printf("\t\t        'While moving on the predefined path is eaten or erased by the Pacman.\n");
    printf("\t\t\t\t More you eat the path more your score is increased.\n");
    printf("\t\t\t You have to control the behavior and moving direction of the Pacman.'\n");
    printf("\n\t\t\t\t      # ENTER ANY BUTTON TO ENTER INTO THE GAME #\n\n");
    printf("\t\t****************************************************************************************\n\n");
    printf("\t\t\t\t\t\t      ++++++++++++++\n");
   printf("\t\t\t\t\t\t       PRESS 1-EASY");
   printf("\t\t\t\t\t\t\t\t\t\t\t\t      ++++++++++++++");
    printf("\n\n\t\t\t\t\t\t    ++++++++++++++++++");
   printf("\n\t\t\t\t\t\t     PRESS 2-MODERATE");
    printf("\n\t\t\t\t\t\t    ++++++++++++++++++");
    printf("\n\n\t\t\t\t\t\t      ++++++++++++++\n");
   printf("\t\t\t\t\t\t       PRESS 3-HARD\n");
    printf("\t\t\t\t\t\t      ++++++++++++++\n");

   scanf("%d",&n);
    Beep(500,500);
    Beep(400,500);
    Beep(1000,500);
    Beep(50,500);
    Beep(5000,500);


   system("cls");


 initialize();


   while (1){

      user_input();
      move_figures();
      show_playfield();
      Sleep( 1000 / 40 );
      set_cursor_position(0,0);
}
   getch();
}

