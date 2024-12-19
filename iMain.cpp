#include "iGraphics.h"
#include <math.h>
#include<string.h>
#include <windows.h>
#include <mmsystem.h>
#include<unistd.h>
#define ROWS 25
#define COLS 21

int maze[ROWS][COLS] =
{
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //0
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //1
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //2

 {1, 1, 1,  0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 3, 0, 0, 0,  1, 1, 1}, //3
 {1, 1, 1,  0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0,  1, 1, 1}, //4
 {1, 1, 1,  0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0,  1, 1, 1}, //5
 {1, 1, 1,  2, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0,  1, 1, 1}, //6
 {1, 1, 1,  0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0,  1, 1, 1}, //7
 {1, 1, 1,  0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0,  1, 1, 1}, //8
 {1, 1, 1,  1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1,  1, 1, 1}, //9
 {1, 1, 1,  1, 1, 1, 0, 1, 0, 0, 0, 3, 0, 1, 0, 1, 1, 1,  1, 1, 1},//10
 {1, 1, 1,  0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0,  1, 1, 1},//11
 {1, 1, 1,  0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0,  1, 1, 1},//12
 {1, 1, 1,  1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1,  1, 1, 1},//13
 {1, 1, 1,  1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1,  1, 1, 1},//14
 {1, 1, 1,  0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0,  1, 1, 1},//15
 {1, 1, 1,  0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0,  1, 1, 1},//16
 {1, 1, 1,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 4,  1, 1, 1},//17
 {1, 1, 1,  1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1,  1, 1, 1},//18
 {1, 1, 1,  0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0,  1, 1, 1},//19
 {1, 1, 1,  0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0,  1, 1, 1},//20
 {1, 1, 1,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  1, 1, 1},//21

 {1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},//22
 {1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},//23
 {1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} //24
};
int point[ROWS][COLS]=
{
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //0
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //1
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //2

 {1, 1, 1,  0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,  1, 1, 1}, //3
 {1, 1, 1,  0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0,  1, 1, 1}, //4
 {1, 1, 1,  0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0,  1, 1, 1}, //5
 {1, 1, 1,  2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0,  1, 1, 1}, //6
 {1, 1, 1,  0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0,  1, 1, 1}, //7
 {1, 1, 1,  0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0,  1, 1, 1}, //8
 {1, 1, 1,  1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1,  1, 1, 1}, //9
 {1, 1, 1,  1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1,  1, 1, 1},//10
 {1, 1, 1,  1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1,  1, 1, 1},//11
 {1, 1, 1,  1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1,  1, 1, 1},//12
 {1, 1, 1,  1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1,  1, 1, 1},//13
 {1, 1, 1,  1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1,  1, 1, 1},//14
 {1, 1, 1,  0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0,  1, 1, 1},//15
 {1, 1, 1,  0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0,  1, 1, 1},//16
 {1, 1, 1,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 4,  1, 1, 1},//17
 {1, 1, 1,  1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1,  1, 1, 1},//18
 {1, 1, 1,  0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0,  1, 1, 1},//19
 {1, 1, 1,  0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0,  1, 1, 1},//20
 {1, 1, 1,  0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,  1, 1, 1},//21

 {1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},//22
 {1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},//23
 {1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} //24
};
int g1[ROWS][COLS]=
{
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //0
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //1
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //2

 {1, 1, 1,  0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 3, 0, 0, 0,  1, 1, 1}, //3
 {1, 1, 1,  0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0,  1, 1, 1}, //4
 {1, 1, 1,  0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0,  1, 1, 1}, //5
 {1, 1, 1,  0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 0, 0, 0,  1, 1, 1}, //6
 {1, 1, 1,  0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0,  1, 1, 1}, //7
 {1, 1, 1,  0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0,  1, 1, 1}, //8
 {1, 1, 1,  1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1,  1, 1, 1}, //9
 {1, 1, 1,  1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1,  1, 1, 1},//10
 {1, 1, 1,  0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0,  1, 1, 1},//11
 {1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,  1, 1, 1},//12
 {1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1,  1, 1, 1},//13
 {1, 1, 1,  1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1,  1, 1, 1},//14
 {1, 1, 1,  0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0,  1, 1, 1},//15
 {1, 1, 1,  0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0,  1, 1, 1},//16
 {1, 1, 1,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 4,  1, 1, 1},//17
 {1, 1, 1,  1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1,  1, 1, 1},//18
 {1, 1, 1,  0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0,  1, 1, 1},//19
 {1, 1, 1,  0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0,  1, 1, 1},//20
 {1, 1, 1,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  1, 1, 1},//21

 {1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},//22
 {1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},//23
 {1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} //24
};
int g2[ROWS][COLS]=
{
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //0
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //1
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //2

 {1, 1, 1,  0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 3, 0, 0, 0,  1, 1, 1}, //3
 {1, 1, 1,  0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0,  1, 1, 1}, //4
 {1, 1, 1,  0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0,  1, 1, 1}, //5
 {1, 1, 1,  2, 0, 0, 5, 0, 0, 1, 0, 0, 0, 0, 2, 0, 0, 0,  1, 1, 1}, //6
 {1, 1, 1,  0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0,  1, 1, 1}, //7
 {1, 1, 1,  0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0,  1, 1, 1}, //8
 {1, 1, 1,  1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1,  1, 1, 1}, //9
 {1, 1, 1,  1, 1, 1, 0, 1, 0, 1, 0, 3, 0, 1, 0, 1, 1, 1,  1, 1, 1},//10
 {1, 1, 1,  0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1,  1, 1, 1},//11
 {1, 1, 1,  0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,  1, 1, 1},//12
 {1, 1, 1,  1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1,  1, 1, 1},//13
 {1, 1, 1,  1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1,  1, 1, 1},//14
 {1, 1, 1,  0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0,  1, 1, 1},//15
 {1, 1, 1,  0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0,  1, 1, 1},//16
 {1, 1, 1,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 4,  1, 1, 1},//17
 {1, 1, 1,  1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1,  1, 1, 1},//18
 {1, 1, 1,  0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0,  1, 1, 1},//19
 {1, 1, 1,  0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0,  1, 1, 1},//20
 {1, 1, 1,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  1, 1, 1},//21

 {1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},//22
 {1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},//23
 {1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} //24
};
int g3[ROWS][COLS]=
{
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //0
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //1
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //2

 {1, 1, 1,  0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 3, 0, 0, 0,  1, 1, 1}, //3
 {1, 1, 1,  0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0,  1, 1, 1}, //4
 {1, 1, 1,  0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0,  1, 1, 1}, //5
 {1, 1, 1,  2, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0,  1, 1, 1}, //6
 {1, 1, 1,  0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0,  1, 1, 1}, //7
 {1, 1, 1,  0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0,  1, 1, 1}, //8
 {1, 1, 1,  1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1,  1, 1, 1}, //9
 {1, 1, 1,  1, 1, 1, 0, 1, 0, 0, 0, 3, 0, 1, 0, 1, 1, 1,  1, 1, 1},//10
 {1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,  1, 1, 1},//11
 {1, 1, 1,  0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0,  1, 1, 1},//12
 {1, 1, 1,  1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1,  1, 1, 1},//13
 {1, 1, 1,  1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1,  1, 1, 1},//14
 {1, 1, 1,  0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0,  1, 1, 1},//15
 {1, 1, 1,  0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0,  1, 1, 1},//16
 {1, 1, 1,  0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 4,  1, 1, 1},//17
 {1, 1, 1,  1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1,  1, 1, 1},//18
 {1, 1, 1,  0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0,  1, 1, 1},//19
 {1, 1, 1,  0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0,  1, 1, 1},//20
 {1, 1, 1,  0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,  1, 1, 1},//21

 {1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},//22
 {1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},//23
 {1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} //24
};
int g4[ROWS][COLS]=
{
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //0
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //1
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //2

 {1, 1, 1,  0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 3, 0, 0, 0,  1, 1, 1}, //3
 {1, 1, 1,  0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0,  1, 1, 1}, //4
 {1, 1, 1,  0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0,  1, 1, 1}, //5
 {1, 1, 1,  2, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0,  1, 1, 1}, //6
 {1, 1, 1,  0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0,  1, 1, 1}, //7
 {1, 1, 1,  0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0,  1, 1, 1}, //8
 {1, 1, 1,  1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1,  1, 1, 1}, //9
 {1, 1, 1,  1, 1, 1, 0, 1, 0, 0, 0, 3, 0, 1, 0, 1, 1, 1,  1, 1, 1},//10
 {1, 1, 1,  0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,  1, 1, 1},//11
 {1, 1, 1,  0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0,  1, 1, 1},//12
 {1, 1, 1,  1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1,  1, 1, 1},//13
 {1, 1, 1,  1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1,  1, 1, 1},//14
 {1, 1, 1,  0, 0, 0, 2, 0, 0, 1, 1, 0, 0, 0, 2, 0, 0, 0,  1, 1, 1},//15
 {1, 1, 1,  0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0,  1, 1, 1},//16
 {1, 1, 1,  0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 4,  1, 1, 1},//17
 {1, 1, 1,  1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1,  1, 1, 1},//18
 {1, 1, 1,  0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0,  1, 1, 1},//19
 {1, 1, 1,  0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0,  1, 1, 1},//20
 {1, 1, 1,  0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,  1, 1, 1},//21

 {1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},//22
 {1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},//23
 {1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} //24
};



int cellSize = 40; //Size of each maze cell
int playerX = 10; //Starting strictly outside maze
int playerY = 3;
int pU=0,pD=0,pR=1,pL=1;

int ghostX1=6,ghostX3=6,ghostX2=14,ghostX4=14,ghostL1X=15,ghostLX=14;
int ghostY1=19,ghostY3=6,ghostY2=19,ghostY4=3,ghostL1Y=16,ghostLY=19;
int gX,gY;
int ExGx=10;
int ExGy=13;


int cursor=135;
int Key=0;
int midRow=ROWS/2;
int midCol=COLS/2;
int num;
int play=0;
int points=0;
int homePage=1;
int startGame=0,aboutus=0,inst=0,Hscore=0;
int gameover=0;
int score=0;
int click=0;
int lives=3;
int level=3;
int backbutton=0;
int nameindex=0;
int panic=0;
int panicMoveCount=0;
int eName=0;
int gameWon=0;
char name[100];
int extraGhost=0;
int invertMove=0;
int timer1;
int timer2;
int timer3;
int warningMessage=0;
int countW=0;
int ngame=0;
int rgame=0;
int gquit=0;
int pauseButton=0;
int musicOn=0;


int stateU=1;
int stateD=0;
int stateL=0;
int stateR=0;

int stateU1=1;
int stateD1=0;
int stateL1=0;
int stateR1=0;

int stateU111=0;
int stateD111=1;
int stateL111=0;
int stateR111=0;

int stateU2=0;
int stateD2=0;
int stateL2=1;
int stateR2=0;

int stateU3=0;
int stateD3=0;
int stateL3=0;
int stateR3=1;

int stateU4=0;
int stateD4=1;
int stateL4=0;
int stateR4=0;

int Interval=0;

typedef struct
{
    char Hname[100];
    int Hscore;
}highScore;
highScore S[10];

void aboutUs();
void instruction();
void HighScore();
void enterName();



void enterName()
{
    iShowBMP(0,0,"images\\Numbers\\Namepage.bmp");
}
void ShowText()
{
    char a[26][35]=
    {
        "images\\Alpha\\a.bmp","images\\Alpha\\b.bmp","images\\Alpha\\c.bmp","images\\Alpha\\d.bmp","images\\Alpha\\e.bmp","images\\Alpha\\f.bmp",
		"images\\Alpha\\g.bmp","images\\Alpha\\h.bmp","images\\Alpha\\i.bmp","images\\Alpha\\j.bmp","images\\Alpha\\k.bmp","images\\Alpha\\l.bmp",
		"images\\Alpha\\m.bmp","images\\Alpha\\n.bmp","images\\Alpha\\o.bmp","images\\Alpha\\p.bmp","images\\Alpha\\q.bmp","images\\Alpha\\r.bmp",
		"images\\Alpha\\s.bmp","images\\Alpha\\t.bmp","images\\Alpha\\u.bmp","images\\Alpha\\v.bmp","images\\Alpha\\w.bmp","images\\Alpha\\x.bmp",
		"images\\Alpha\\y.bmp","images\\Alpha\\z.bmp"
    };

    char num[10][22]=
    {
        "images\\Numbers\\0.bmp", "images\\Numbers\\1.bmp", "images\\Numbers\\2.bmp", "images\\Numbers\\3.bmp", "images\\Numbers\\4.bmp",
		"images\\Numbers\\5.bmp", "images\\Numbers\\6.bmp", "images\\Numbers\\7.bmp", "images\\Numbers\\8.bmp", "images\\Numbers\\9.bmp"
    };

    cursor=135;
    for(int i=0;i<strlen(name);i++)
    {
        for(int j=0;j<26;j++)
        {
            if(name[i]%97==(j)&&name[i]>=97)
            {
                iShowBMP2(cursor,480,a[j],0);
                cursor+=35;
            }
            else if(name[i]>=48&&name[i]<=57&&name[i]%48==(j))
            {
                iShowBMP(cursor,480,num[j]);
                cursor+=35;
            }
        }
    }

}
void saveInfo(char *name,int score)
{
    int i=0,j;
    FILE *fp;
    strncpy(S[10].Hname,name,sizeof(S[10].Hname)-1);
    S[10].Hname[sizeof(S[10].Hname)-1]='\0';
    S[10].Hscore=score;
    fp=fopen("Highscore.txt","r");
    if(fp==NULL)
    {
        printf("Error");
        exit(0);
    }
    while(fscanf(fp,"%99s %d",&S[i].Hname,&S[i].Hscore)==2&&i<10)
    {
        i++;
    }
    fclose(fp);
    for(i=1;i<11;i++)
    {
        for(j=0;j<11-i;j++)
        {
            if(S[j].Hscore<S[j+1].Hscore)
            {
                highScore temp=S[j];
                S[j]=S[j+1];
                S[j+1]=temp;
            }
        }
    }
    fp=fopen("Highscore.txt","w");
    if(fp==NULL)
    {
        exit(0);
    }
    for(i=0;i<10;i++)
    {
        fprintf(fp,"%s\t\t%d\n",S[i].Hname,S[i].Hscore);
    }
    fclose(fp);
}
void showScore()
{
	char str[30]={0};

	char num[10][22]={"images\\Numbers\\0.bmp", "images\\Numbers\\1.bmp", "images\\Numbers\\2.bmp", "images\\Numbers\\3.bmp", "images\\Numbers\\4.bmp",
		"images\\Numbers\\5.bmp", "images\\Numbers\\6.bmp", "images\\Numbers\\7.bmp", "images\\Numbers\\8.bmp", "images\\Numbers\\9.bmp" };

	if (score==0)
	{
		iShowBMP2(500, 905, num[0], 0);
		iShowBMP2(540, 905, num[0], 0);
		iShowBMP2(580, 905, num[0], 0);
		iShowBMP2(620, 905, num[0], 0);
		iShowBMP2(660, 905, num[0], 0);
	}


	int a=score;

	int n4=a/pow(10,4);
	a=a%(int)pow(10,4);
	iShowBMP2(500, 905, num[n4], 0);
	int n3 =a/pow(10, 3);
	a =a%(int)pow(10, 3);
	iShowBMP2(540, 905, num[n3], 0);
	int n2=a/pow(10, 2);
	a =a%(int)pow(10, 2);
	iShowBMP2(580, 905, num[n2], 0);
	int n1=a/pow(10, 1);
	a =a%(int)pow(10, 1);
	iShowBMP2(620, 905, num[n1], 0);
	int n0=a;
	iShowBMP2(660, 905, num[n0], 0);
}
void showLives()
{
	for (int l=0;l<lives;l++)
	{
        iShowBMP2(220-40*l,60,"images\\Numbers\\paclife.bmp", 0);
	}
}
void GameWon()
{
    iShowBMP(0,0,"images\\Numbers\\winPage.bmp");
    iShowBMP2(0,920,"images\\Numbers\\homebutton.bmp",1);
}
void Gamover()
{
    iSetColor(0,0,0);
    iFilledRectangle(0,0,cellSize*COLS,cellSize*ROWS);
    iShowBMP(0,0,"images\\gameover.bmp");
    iShowBMP2(0,920,"images\\Numbers\\homebutton.bmp",1);
}
void message()
{
    iShowBMP2(300,350,"images\\warning.bmp",0);
}
void Reset()
{
    if(gameWon==1||gameover==1)
    {
        lives=3;
        score=0;
        level=1;
        cursor=135;
    }
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            if(maze[i][j]!=1)
            {
                point[i][j]=maze[i][j];
            }
            if(maze[i][j]==4&&level==2)
            {
                point[i][j]=0;
            }
            else if(maze[i][j]==4&&level==2)
            {
                point[i][j]=maze[i][j];
            }
            if(maze[i][j]==5&&level==2)
            {
                point[i][j]=0;
            }
            else if(maze[i][j]==5&&level==3)
            {
                point[i][j]=maze[i][j];
            }
        }
    }
    ExGx=10;
    ExGy=13;
    playerX=10;ghostX1=6;ghostX3=6;ghostX2=14;ghostX4=12,ghostL1X=15;
    playerY=3;ghostY1=19;ghostY3=6;ghostY2=19;ghostY4=8,ghostL1Y=16;
}
void RandomMove(int *GX,int *GY,int *StateU11,int *StateD11,int *StateR11,int *StateL11,int g1[][COLS])
{
    int gX=*GX;
    int gY=*GY;
    int stateU11=*StateU11;
    int stateD11=*StateD11;
    int stateR11=*StateR11;
    int stateL11=*StateL11;
        if(g1[ROWS-gY-1-1][gX]!=1&&stateU11==1)
        {
            gY++;
            stateU11=1;
        }
        else if(g1[ROWS-gY-1-1][gX]==1&&stateU11==1)
        {
            stateU11=0;
            int n=rand()%2;
            if(n==1)
            {
                if(g1[ROWS-gY-1][gX+1]!=1)
                {
                    gX++;
                    stateR11=1;
                }
                else if(g1[ROWS-gY-1][gX+1]==1)
                {
                    if(g1[ROWS-gY-1][gX-1]!=1)
                    {
                        gX--;
                        stateL11=1;
                    }
                    else if(g1[ROWS-gY-1][gX-1]==1)
                    {
                        gY--;
                        stateD11=1;
                    }
                }
            }
            else
            {
                if(g1[ROWS-gY-1][gX-1]!=1)
                {
                    gX--;
                    stateL11=1;
                }
                else if(g1[ROWS-gY-1][gX-1]==1)
                {
                    if(g1[ROWS-gY-1][gX+1]!=1)
                    {
                        gX++;
                        stateR11=1;
                    }
                    else if(g1[ROWS-gY-1][gX-1]==1)
                    {
                        gY--;
                        stateD11=1;
                    }
                }
            }
        }
        else if(g1[ROWS-gY-1+1][gX]!=1&&stateD11==1)
        {
            gY--;
            stateD11=1;
        }
        else if(g1[ROWS-gY-1+1][gX]==1&&stateD11==1)
        {
            stateD11=0;
            int n=rand()%2;
            if(n==1)
            {
                if(g1[ROWS-gY-1][gX+1]!=1)
                {
                    gX++;
                    stateR11=1;
                }
                else if(g1[ROWS-gY-1][gX+1]==1)
                {
                    if(g1[ROWS-gY-1][gX-1]!=1)
                    {
                        gX--;
                        stateL11=1;
                    }
                    else if(g1[ROWS-gY-1][gX-1]==1)
                    {
                        gY++;
                        stateU11=1;
                    }
                }
            }
            else
            {
                if(g1[ROWS-gY-1][gX-1]!=1)
                {
                    gX--;
                    stateL11=1;
                }
                else if(g1[ROWS-gY-1][gX-1]==1)
                {
                    if(g1[ROWS-gY-1][gX+1]!=1)
                    {
                        gX++;
                        stateR11=1;
                    }
                    else if(maze[ROWS-gY-1][gX-1]==1)
                    {
                        gY++;
                        stateU11=1;
                    }
                }
            }
        }
        else if(g1[ROWS-gY-1][gX+1]!=1&&stateR11==1)
        {
            gX++;
            stateR11=1;
        }
        else if(g1[ROWS-gY-1][gX+1]==1&&stateR11==1)
        {
            stateR11=0;
            int n=rand()%2;
            if(n==1)
            {
                if(g1[ROWS-gY-1+1][gX]!=1)
                {
                    gY--;
                    stateD11=1;
                }
                else if(g1[ROWS-gY-1+1][gX]==1)
                {
                    if(g1[ROWS-gY-1-1][gX]!=1)
                    {
                        gY++;
                        stateU11=1;
                    }
                    else if(g1[ROWS-gY-1-1][gX]==1)
                    {
                        gX--;
                        stateL11=1;
                    }
                }
            }
            else
            {
                if(g1[ROWS-gY-1-1][gX]!=1)
                {
                    gY++;
                    stateU11=1;
                }
                else if(g1[ROWS-gY-1-1][gX]==1)
                {
                    if(g1[ROWS-gY-1+1][gX]!=1)
                    {
                        gY--;
                        stateD11=1;
                    }
                    else if(g1[ROWS-gY-1+1][gX]==1)
                    {
                        gX++;
                        stateR11=1;
                    }
                }
            }
        }
        else if(g1[ROWS-gY-1][gX-1]!=1&&stateL11==1)
        {
            gX--;
            stateL11=1;
        }
        else if(g1[ROWS-gY-1][gX-1]==1&&stateL11==1)
        {
            stateL11=0;
            int n=rand()%2;
            if(n==1)
            {
                if(g1[ROWS-gY-1+1][gX]!=1)
                {
                    gY--;
                    stateD11=1;
                }
                else if(g1[ROWS-gY-1+1][gX]==1)
                {
                    if(g1[ROWS-gY-1-1][gX]!=1)
                    {
                        gY++;
                        stateU11=1;
                    }
                    else if(g1[ROWS-gY-1-1][gX]==1)
                    {
                        gX++;
                        stateR11=1;
                    }
                }
            }
            else
            {
                if(g1[ROWS-gY-1-1][gX]!=1)
                {
                    gY++;
                    stateU11=1;
                }
                else if(g1[ROWS-gY-1-1][gX]==1)
                {
                    if(g1[ROWS-gY-1+1][gX]!=1)
                    {
                        gY--;
                        stateD11=1;
                    }
                    else if(g1[ROWS-gY-1+1][gX]==1)
                    {
                        gX++;
                        stateR11=1;
                    }
                }
            }
        }
        *GX=gX;
        *GY=gY;
        *StateU11=stateU11;
        *StateD11=stateD11;
        *StateR11=stateR11;
        *StateL11=stateL11;
}

int distance(int gX,int gY)
{
    if(maze[ROWS-gY-1][gX]!=1)
    {
        return (playerX-gX)*(playerX-gX)+(playerY-gY)*(playerY-gY);
    }
    if(panic==1)
    {
        return -1;
    }
    else
    {
        return 100000;
    }

}
void ghost1()
{
    gX=ghostX1;
    gY=ghostY1;
    bool isQuadrant=(playerX<=midCol&&playerY>=midRow);
    if(isQuadrant)
    {
        int D[4];
        D[0]=distance(gX+1,gY);
        D[1]=distance(gX,gY+1);
        D[2]=distance(gX,gY-1);
        D[3]=distance(gX-1,gY);
        int Min=D[0],mindex=0;
        if(panic==1)
        {
            for(int i=0;i<4;i++)
            {
                if(D[i]>Min)
                {
                    Min=D[i];
                    mindex=i;
                }
            }
        }
        else
        {
            for(int i=0;i<4;i++)
            {
                if(D[i]<Min)
                {
                    Min=D[i];
                    mindex=i;
                }
            }
        }
        switch(mindex)
        {
            case 0:
                gX++;
                break;
            case 1:
                gY++;
                break;
            case 2:
                gY--;
                break;
            case 3:
                gX--;
                break;
        }
        ghostX1=gX;
        ghostY1=gY;
    }
    else
    {
        RandomMove(&ghostX1,&ghostY1,&stateU111,&stateD111,&stateR111,&stateL111,g1);
    }
}
void ghost2()
{
    gX=ghostX2;
    gY=ghostY2;
    bool isQuadrant=(playerX>midCol&&playerY>=midRow);
    if(isQuadrant)
    {
        int D[4];
        D[0]=distance(gX+1,gY);
        D[1]=distance(gX,gY+1);
        D[2]=distance(gX,gY-1);
        D[3]=distance(gX-1,gY);
        int Min=D[0],mindex=0;
        if(panic==1)
        {
            for(int i=0;i<4;i++)
            {
                if(D[i]>Min)
                {
                    Min=D[i];
                    mindex=i;
                }
            }
        }
        else
        {
            for(int i=0;i<4;i++)
            {
                if(D[i]<Min)
                {
                    Min=D[i];
                    mindex=i;
                }
            }
        }
        switch(mindex)
        {
            case 0:
                gX++;
                break;
            case 1:
                gY++;
                break;
            case 2:
                gY--;
                break;
            case 3:
                gX--;
                break;
        }
        ghostX2=gX;
        ghostY2=gY;
    }
    else
    {
        RandomMove(&ghostX2,&ghostY2,&stateU2,&stateD2,&stateR2,&stateL2,g2);
    }

}
void ghost3()
{
    gX=ghostX3;
    gY=ghostY3;
    bool isQuadrant=(playerX<=midCol&&playerY<midRow);
    if(isQuadrant)
    {
        int D[4];
        D[0]=distance(gX+1,gY);
        D[1]=distance(gX,gY+1);
        D[2]=distance(gX,gY-1);
        D[3]=distance(gX-1,gY);
        int Min=D[0],mindex=0;
        if(panic==1)
        {
            for(int i=0;i<4;i++)
            {
                if(D[i]>Min)
                {
                    Min=D[i];
                    mindex=i;
                }
            }
        }
        else
        {
            for(int i=0;i<4;i++)
            {
                if(D[i]<Min)
                {
                    Min=D[i];
                    mindex=i;
                }
            }
        }
        switch(mindex)
        {
            case 0:
                gX++;
                break;
            case 1:
                gY++;
                break;
            case 2:
                gY--;
                break;
            case 3:
                gX--;
                break;
        }
        ghostX3=gX;
        ghostY3=gY;
    }
    else
    {
        RandomMove(&ghostX3,&ghostY3,&stateU3,&stateD3,&stateR3,&stateL3,g3);
    }
}
void ghost4()
{
    gX=ghostX4;
    gY=ghostY4;
    bool isQuadrant=(playerX>midCol&&playerY<=midRow);
    if(isQuadrant)
    {
        int D[4];
        D[0]=distance(gX+1,gY);
        D[1]=distance(gX,gY+1);
        D[2]=distance(gX,gY-1);
        D[3]=distance(gX-1,gY);
        int Min=D[0],mindex=0;
        if(panic==1)
        {
            for(int i=0;i<4;i++)
            {
                if(D[i]>Min)
                {
                    Min=D[i];
                    mindex=i;
                }
            }
        }
        else
        {
            for(int i=0;i<4;i++)
            {
                if(D[i]<Min)
                {
                    Min=D[i];
                    mindex=i;
                }
            }
        }
        switch(mindex)
        {
            case 0:
                gX++;
                break;
            case 1:
                gY++;
                break;
            case 2:
                gY--;
                break;
            case 3:
                gX--;
                break;
        }
        ghostX4=gX;
        ghostY4=gY;
    }
    else
    {
        RandomMove(&ghostX4,&ghostY4,&stateU4,&stateD4,&stateR4,&stateL4,g4);
    }

}
void ExGhost()
{
    RandomMove(&ExGx,&ExGy,&stateU,&stateD,&stateR,&stateL,maze);
}

void ghostL1()
{
    if(level==1&&startGame==1)
    {
        gX=ghostL1X;
        gY=ghostL1Y;
        int D[4];
        D[0]=distance(gX+1,gY);
        D[1]=distance(gX,gY+1);
        D[2]=distance(gX,gY-1);
        D[3]=distance(gX-1,gY);
        int Min=D[0],mindex=0;
        if(panic==1)
        {
            for(int i=0;i<4;i++)
            {
                if(D[i]>Min)
                {
                    Min=D[i];
                    mindex=i;
                }
            }
        }
        else
        {
            for(int i=0;i<4;i++)
            {
                if(D[i]<Min)
                {
                    Min=D[i];
                    mindex=i;
                }
            }
        }
        switch(mindex)
        {
            case 0:
                gX++;
                break;
            case 1:
                gY++;
                break;
            case 2:
                gY--;
                break;
            case 3:
                gX--;
                break;
        }
        ghostL1X=gX;
        ghostL1Y=gY;
        RandomMove(&ghostLX,&ghostLY,&stateU1,&stateD1,&stateR1,&stateL1,maze);
    }
}
void ghostL2()  //ghost movement
{
    if(startGame==1&&level==2)
    {
        ghost1();
        ghost2();
        ghost3();
        ghost4();
    }
}
void ghostL3()
{
    if(level==3&&startGame==1)
    {
        ghost1();
        ghost2();
        ghost3();
        ghost4();
    }
    if(level==3&&startGame==1&&extraGhost==1)
    {
        ExGhost();
    }
}
void pacman()
{
    if(pU==1)
    {
        iShowBMP((playerX*(cellSize)+cellSize/2)-15, playerY*(cellSize)+ cellSize/2-15,"images\\pacmanU.bmp");
    }
    else if(pD==1)
    {
        iShowBMP((playerX*(cellSize)+cellSize/2)-15, playerY*(cellSize)+ cellSize/2-15,"images\\pacmanD.bmp");
    }
    else if(pR==1)
    {
        iShowBMP((playerX*(cellSize)+cellSize/2)-15, playerY*(cellSize)+ cellSize/2-15,"images\\pacmanR.bmp");
    }
    else if(pL==1)
    {
        iShowBMP((playerX*(cellSize)+cellSize/2)-15, playerY*(cellSize)+cellSize/2-15,"images\\pacmanL.bmp");
    }
}

void ghostDraw()
{
    if(level==1)
    {
        iShowBMP(ghostL1X*cellSize+cellSize/2-20, ghostL1Y*cellSize+cellSize/2-20,"images\\Numbers\\pghost.bmp");
        iShowBMP(ghostLX*cellSize+cellSize/2-20, ghostLY*cellSize+cellSize/2-20,"images\\Numbers\\rghost.bmp");
    }
    else if(level==2)
    {
        if(panic==0)
        {
            iShowBMP(ghostX1*cellSize+cellSize/2-20, ghostY1*cellSize+cellSize/2-20,"images\\Numbers\\gghost.bmp");
            iShowBMP(ghostX2*cellSize+cellSize/2-20, ghostY2*cellSize+cellSize/2-20,"images\\Numbers\\pghost.bmp");
            iShowBMP(ghostX3*cellSize+cellSize/2-20, ghostY3*cellSize+cellSize/2-20,"images\\Numbers\\bghost.bmp");
            iShowBMP(ghostX4*cellSize+cellSize/2-20, ghostY4*cellSize+cellSize/2-20,"images\\Numbers\\rghost.bmp");
        }
        else
        {
            iShowBMP(ghostX1*cellSize+cellSize/2-20, ghostY1*cellSize+cellSize/2-20,"images\\Numbers\\afraid ghost.bmp");
            iShowBMP(ghostX2*cellSize+cellSize/2-20, ghostY2*cellSize+cellSize/2-20,"images\\Numbers\\afraid ghost.bmp");
            iShowBMP(ghostX3*cellSize+cellSize/2-20, ghostY3*cellSize+cellSize/2-20,"images\\Numbers\\afraid ghost.bmp");
            iShowBMP(ghostX4*cellSize+cellSize/2-20, ghostY4*cellSize+cellSize/2-20,"images\\Numbers\\afraid ghost.bmp");
        }
    }
    else if(level==3)
    {
        if(panic==0)
        {
            iShowBMP(ghostX1*cellSize+cellSize/2-20, ghostY1*cellSize+cellSize/2-20,"images\\Numbers\\gghost.bmp");
            iShowBMP(ghostX2*cellSize+cellSize/2-20, ghostY2*cellSize+cellSize/2-20,"images\\Numbers\\pghost.bmp");
            iShowBMP(ghostX3*cellSize+cellSize/2-20, ghostY3*cellSize+cellSize/2-20,"images\\Numbers\\bghost.bmp");
            iShowBMP(ghostX4*cellSize+cellSize/2-20, ghostY4*cellSize+cellSize/2-20,"images\\Numbers\\rghost.bmp");
        }
        else
        {
            iShowBMP(ghostX1*cellSize+cellSize/2-20, ghostY1*cellSize+cellSize/2-20,"images\\Numbers\\afraid ghost.bmp");
            iShowBMP(ghostX2*cellSize+cellSize/2-20, ghostY2*cellSize+cellSize/2-20,"images\\Numbers\\afraid ghost.bmp");
            iShowBMP(ghostX3*cellSize+cellSize/2-20, ghostY3*cellSize+cellSize/2-20,"images\\Numbers\\afraid ghost.bmp");
            iShowBMP(ghostX4*cellSize+cellSize/2-20, ghostY4*cellSize+cellSize/2-20,"images\\Numbers\\afraid ghost.bmp");
        }
    }
    if(level==3&&extraGhost==1)
    {
        iShowBMP(ExGx*cellSize+cellSize/2-20, ExGy*cellSize+cellSize/2-20,"images\\joker1.bmp");
    }
}
void HOME()
{
    iShowBMP(0,0,"images\\homePage.bmp");
}

void Game()
{
    if(level==1)
    {
        iShowBMP(0,0,"images\\LVL1.bmp");
    }
    else if(level==2)
    {
        iShowBMP(0,0,"images\\LVL2.bmp");
    }
    else if(level==3)
    {
        iShowBMP(0,0,"images\\LVL3.bmp");
    }
    iShowBMP(10,910,"images\\pausebutton.bmp");
    for(int i =0; i<ROWS ; i++)
    {
		for(int j = 0; j<COLS; j++)
		{
            if(point[i][j]!=1&&(level==2||level==1)&&point[i][j]!=2)
            {
                iSetColor(231,199,31);//points color
                iFilledCircle(j*cellSize+cellSize/2,(ROWS-1-i)*cellSize+cellSize/2,cellSize/10,1000);//changing the coordinate with the array
            }
            if(point[i][j]==0&&level==3)
            {
                iSetColor(231,199,31);//points color
                iFilledCircle(j*cellSize+cellSize/2,(ROWS-1-i)*cellSize+cellSize/2,cellSize/10,1000);
            }
            if(point[i][j]==2)
            {
                iShowBMP2(j*cellSize,(ROWS-1-i)*cellSize,"images\\Numbers\\Energizer.bmp",0);
            }
            if(point[i][j]==5&&level==3)
            {
                iShowBMP2(j*cellSize,(ROWS-1-i)*cellSize,"images\\extraLife.bmp",0);
            }
            if(point[i][j]==4&&level==3)
            {
                iShowBMP2(j*cellSize,(ROWS-1-i)*cellSize,"images\\magicpoint.bmp",0);
            }

		}
	}
	//Draw the player
    pacman();

    int flag=0;
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            if(point[i][j]==1)
            {
                flag++;
            }
        }
    }
    if(flag==23*21-5&&level==3&&warningMessage==0&&countW==0)
    {
        warningMessage=1;
        countW=1;
        iPauseTimer(timer3);
    }
    if(flag==23*21&&level==3)
    {
        invertMove=1;
    }

    //Draw Ghost
    ghostDraw();

    if(((ghostX1==playerX&&ghostY1==playerY)||(ghostX2==playerX&&ghostY2==playerY)||(ghostX3==playerX&&ghostY3==playerY)||(ghostX4==playerX&&ghostY4==playerY))&&(level==2||level==3))
    {
        if(panic==1)
        {
            if(playerX<=midCol)
            {
                if(playerY>=midRow)
                {
                    ghostX1=6;
                    ghostY2=19;
                }
                else
                {
                    ghostX3=6;
                    ghostY3=15;
                }
            }
            else
            {
                if(playerY>=midRow)
                {
                    ghostX2=14;
                    ghostY2=19;
                }
                else
                {
                    ghostX4=12;
                    ghostY4=8;
                }
            }
            score=score+100;
        }
        else
        {
            playerX=10;
            playerY=3;
            if(lives!=0)
            {
                lives--;
            }
        }
    }
    if(((ghostL1X==playerX&&ghostL1Y==playerY)||(ghostLX==playerX&&ghostLY==playerY))&&level==1)
    {
        if(panic==1)
        {
            ghostL1X=15;
            ghostL1Y=16;
            score=score+100;
        }
        else
        {
            playerX=10;
            playerY=3;
            ghostL1X=15;
            ghostL1Y=16;
            if(lives!=0)
            {
                lives--;
            }
        }
    }
    if(ExGx==playerX&&ExGy==playerY&&extraGhost==1)
    {
        lives--;
        playerX=10;
        playerY=3;
        ExGx=10;
        ExGy=13;
    }
    showScore();
    showLives();
    if(flag==25*21&&level==1)
    {
        level=2;
        Reset();
        Interval=1;
        iPauseTimer(timer2);
        //interval();
    }
    else if(flag==25*21&&level==2)
    {
        level=3;
        Reset();
        Interval=1;
        iPauseTimer(timer3);
        //saveName(name);
    }
    else if(flag==25*21&&level==3)
    {
        gameWon=1;
        saveInfo(name,score);
        Reset();
    }
    if(lives==0&&gameover==0)
    {
        gameover=1;
        saveInfo(name,score);
        name[0]='\0';
        Reset();
    }
}

void playMusic(const char *path)
{
    PlaySound(path,NULL,SND_LOOP|SND_ASYNC);
}
void switchMusic()
{
    if(musicOn==1)
    {
        playMusic("Music\\Menumusic.WAV");
    }
    if(musicOn==0)
    {
        playMusic("Music\\musicoff.WAV");
    }
}

void pauseGame()
{
    iShowBMP2(345,660,"images\\resume.bmp",0);
    iShowBMP2(270,550,"images\\ngame.bmp",0);
    iShowBMP2(270,440,"images\\Quit1.bmp",0);
}
void iDraw()
{
	iClear();
    if(homePage==1)
    {
        HOME();

    }
    else if(startGame==1)
    {
        homePage=0;
        Game();
    }
    else if(eName==1)
    {
        enterName();
        ShowText();
    }
    else if(aboutus==1)
    {
        aboutUs();
    }
    else if(inst==1)
    {
        instruction();
    }
    else if(Hscore==1)
    {
        HighScore();
        //ShowHighscore();
    }
    if(gameover==1)
    {
        Gamover();
        Reset();
    }
    else if(gameWon==1)
    {
        GameWon();
        Reset();
    }
    if(pauseButton==1)
    {
        pauseGame();
    }
    if(warningMessage==1&&level==3)
    {
        message();
    }
    if(Interval==1)
    {
        iShowBMP(270,470,"images\\getready.bmp");
    }
    iShowBMP2(720,920,"images\\musicButton.bmp",0);
    if(musicOn==0)
    {
        iShowBMP2(720,920,"images\\slash.bmp",0);
    }

}

void iMouseMove(int mx, int my)
{
	printf("x = %d, y= %d\n",mx,my);
}

void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if((mx>=720&&mx<=820)&&(my>=920&&my<=1000))
        {
           musicOn=1-musicOn;
           switchMusic();
        }
        if(homePage==1&&(mx>=105&&mx<=215)&&(my>=150&&my<=270))
        {
            eName=1;
            homePage=0;
        }
        if(homePage==1&&(mx>=280&&mx<=390)&&(my>=150&&my<=270))
        {
            aboutus=1;
            homePage=0;
            startGame=0;
        }
        if(homePage==1&&(mx>=450&&mx<=560)&&(my>=150&&my<=270))
        {
            inst=1;
            homePage=0;
            startGame=0;
        }
        if(homePage==1&&(mx>=625&&mx<=735)&&(my>=150&&my<=270))
        {
            Hscore=1;
            homePage=0;
            startGame=0;
        }
        if(homePage==0&&(mx>=30&&mx<=150)&&(my>=900&&my<=960)&&startGame==0)
        {
            homePage=1;
            backbutton=1;
            if(backbutton==1)
            {
                inst=0;
                aboutus=0;
                Hscore=0;
                startGame=0;
                eName=0;
            }
        }
        if(startGame==1&&(mx>=10&&mx<=80)&&(my>=910&&my<=980)&&(gameover==0&&gameWon==0))
        {
            pauseButton=1;
            //startGame=0;
            if(level==1)
            {
                iPauseTimer(timer1);
            }
            else if(level==2)
            {
                iPauseTimer(timer2);
            }
            else
            {
                iPauseTimer(timer3);
            }
        }
        if(pauseButton==1)
        {
            if((mx>=345&&mx<=495)&&(my>=660&&my<=760))
            {
                if(level==1)
                {
                    iResumeTimer(timer1);
                }
                else if(level==2)
                {
                    iResumeTimer(timer2);
                }
                else
                {
                    iResumeTimer(timer3);
                }
                startGame=1;
                pauseButton=0;
            }
            else if((mx>=270&&mx<=570)&&(my>=550&&my<=650))
            {
                ngame=1;
                pauseButton=0;
            }
            else if((mx>=270&&mx<=570)&&(my>=440&&my<=540))
            {
                gquit=1;
                pauseButton=0;
            }
        }

        if(gquit==1&&pauseButton==0)
        {
            Reset();
            level=1;
            homePage=1;
            gquit=0;
            saveInfo(name,score);
            if(level==1)
            {
                iResumeTimer(timer1);
            }
            else if(level==2)
            {
                iResumeTimer(timer2);
            }
            else
            {
                iResumeTimer(timer3);
            }
        }
        if(ngame==1&&pauseButton==0)
        {
            Reset();
            startGame=1;
            ngame=0;
            level=1;
            if(level==1)
            {
                iResumeTimer(timer1);
            }
            else if(level==2)
            {
                iResumeTimer(timer2);
            }
            else
            {
                iResumeTimer(timer3);
            }
        }
        if(warningMessage==1&&(mx>=300&&mx<=600)&&(my>=350&&my<=650))
        {
            warningMessage=0;
            iResumeTimer(timer3);
        }
        if(gameover==1&&(mx>=0&&mx<=80)&&(my>=920&&my<=1000))
        {
            gameover=0;
            startGame=0;
            Reset();
            homePage=1;
        }
        if(gameWon==1&&(mx>=0&&mx<=80)&&(my>=920&&my<=1000))
        {
            gameWon=0;
            startGame=0;
            Reset();
            homePage=1;
        }
        if(level==2&&Interval==1&&(mx>=270&&mx<=570)&&(my>=470&&my<=545))
        {
            iResumeTimer(timer2);
            Interval=0;
        }
        if(level==3&&Interval==1&&(mx>=270&&mx<=570)&&(my>=470&&my<=545))
        {
            iResumeTimer(timer3);
            Interval=0;
        }


        printf("x=%d y=%d\n",mx,my);
	}
}

void iKeyboard(unsigned char key)
{
	if (key == 'q'&&homePage==1)
    {
		exit(0);
	}
	if(key=='\r'&&eName==1)
    {
        startGame=1;
        eName=0;
        nameindex=0;
        switchMusic();
    }
    else if(key=='\b'&&eName==1)
    {
        if(nameindex>0)
        {
            nameindex--;
            name[nameindex]='\0';
        }
    }
    else if(nameindex<sizeof(name)-1&&eName==1)
    {
        name[nameindex]=key;
        nameindex++;
        name[nameindex]='\0';
    }

    //place your codes for other keys here
}

void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END) {
		exit(0);
	}
	//place your codes for other keys here
    //Temporary variables to store the next positions
    int nextX = playerX;
    int nextY = playerY;

    if(invertMove==0)
    {
        if(key == GLUT_KEY_UP){
            nextY++; //Move up
            pU=1;
            pD=0;
            pR=0;
            pL=0;
        }else if(key == GLUT_KEY_DOWN){
            nextY--;
            pU=0;
            pD=1;
            pR=0;
            pL=0; //Move down
        }else if(key == GLUT_KEY_LEFT){
            nextX--;
            pU=0;
            pD=0;
            pR=0;
            pL=1; //Move left
        }else if(key == GLUT_KEY_RIGHT){
            nextX++;
            pU=0;
            pD=0;
            pR=1;
            pL=0;
        }
    }
    else
    {
        if(key == GLUT_KEY_UP){
            nextY--; //Move up
            pU=0;
            pD=1;
            pR=0;
            pL=0;
        }else if(key == GLUT_KEY_DOWN){
            nextY++;
            pU=1;
            pD=0;
            pR=0;
            pL=0; //Move down
        }else if(key == GLUT_KEY_LEFT){
            nextX++;
            pU=0;
            pD=0;
            pR=1;
            pL=0; //Move left
        }else if(key == GLUT_KEY_RIGHT){
            nextX--;
            pU=0;
            pD=0;
            pR=0;
            pL=1;
        }
    }
    // Validate movement: allow movement only if next position is outside maze or on a valid path
    if(nextX >= 0 && nextX < COLS && nextY >= 0 && nextY < ROWS && maze[ROWS-nextY-1][nextX] != 1&&pauseButton==0&&startGame==1&&warningMessage==0&&Interval==0)
    {
        playerX = nextX;
        playerY = nextY;
        if(point[ROWS-nextY-1][nextX]==0)
        {
            score=score+10;
            play=1;
        }
        if(point[ROWS-nextY-1][nextX]==2)
        {
            score=score+25;
            if(level!=1)
            {
                panic=1;
            }
            panicMoveCount=0;
        }
        if(point[ROWS-nextY-1][nextX]==5&&level==3)
        {
            lives++;
        }
        if(point[ROWS-nextY-1][nextX]==4&&level==3)
        {
            extraGhost=1;
            score=score+500;
        }
        if(panic==1&&panicMoveCount<10)
        {
            panicMoveCount++;

        }
        else
        {
            panic=0;
            panicMoveCount=0;
        }
        point[ROWS-nextY-1][nextX]=1;//removing points as collition.
    }
    printf("Updated Player Position:(%d, %d)\n", playerX, playerY);

}


void instruction()
{
    iSetColor(0,0,0);
    iFilledRectangle(0,0,40*COLS,40*ROWS);
    iSetColor(255,255,255);
    iText(30,850,"As you progress through the Pacman game, the challenges become even",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(30,825,"more thrilling! In the second level, eating a cherry causes the ghosts",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(30,800,"to enter panic mode, giving you an opportunity to gain the upper hand. ",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(30,775,"In the third level, a new ghost appears after you collect a bonus point, adding",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(30,750,"to the excitement. Additionally, after a certain amount of time passes,",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(30,725,"the movement controls invert, testing your adaptability and focus. Stay alert and",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(30,700,"strategize wisely to conquer these twists and advance further in the game!",GLUT_BITMAP_TIMES_ROMAN_24);
    iShowBMP(0,900,"images\\Numbers\\back.bmp");
}
void aboutUs()
{
    iSetColor(0,0,0);
    iFilledRectangle(0,0,40*COLS,40*ROWS);
    iSetColor(255,255,255);
    iText(30,850,"At Pacman, we strive to bring innovation and creativity to everything we do,",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(30,825,"inspired by the values and guidance imparted by our mentor, Rabib Jahin.",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(30,800,"His unwavering support and visionary leadership have been instrumental in ",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(30,775,"shaping our journey.With his deep expertise and passion for excellence,",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(30,750,"Rabib Jahin has been a source of motivation, pushing us to break ",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(30,725,"boundaries and reach new heights.We owe much of our progress ",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(30,700,"to his mentorship,which continues to guide us as we grow and evolve. ",GLUT_BITMAP_TIMES_ROMAN_24);
    //iText(30,675,"",GLUT_BITMAP_TIMES_ROMAN_24);
    iShowBMP(0,900,"images\\Numbers\\back.bmp");
}
void HighScore()
{
    int i=0;
    iShowBMP2(0,0,"images\\hscore.bmp",0);
    FILE *fp=fopen("Highscore.txt","r");
    if(fp==NULL)
    {
        exit(0);
    }
    while(fscanf(fp,"%99s%d",&S[i].Hname,&S[i].Hscore)==2&&i<10)
    {
        iSetColor(255-i*27,0+i*23,255-i*19);
        char Rank[20];
        sprintf(Rank,"%d",i+1);
        iText(145,670-i*60,Rank,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(380,670-i*60,S[i].Hname,GLUT_BITMAP_TIMES_ROMAN_24);
        char scoretext[20];
        sprintf(scoretext,"%d",S[i].Hscore);
        iText(630,670-i*60,scoretext,GLUT_BITMAP_TIMES_ROMAN_24);
        i++;
    }
    fclose(fp);

    iShowBMP(0,900,"images\\Numbers\\back.bmp");
}

int main()
{
    srand(time(NULL));
    timer1=iSetTimer(350,ghostL1);
    timer2=iSetTimer(500,ghostL2);
    timer3=iSetTimer(350,ghostL3);
	iInitialize(COLS*cellSize, ROWS*cellSize, "Maze Game");
	return 0;
}
