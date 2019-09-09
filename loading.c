#include<windows.h>
#include<stdio.h>
#include<string.h>

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
void load()
{
    int i;
    for(i=1; i<=100000000; i++);
}
int main()
{
    hidecursor();
    int i;
    char str[] = "\|/-";
    int j=0;
    gotoxy(52, 10);
    printf("Loading...");
    for(i=1; i<=100000; i++)
    {
        gotoxy(50, 10);
        printf("%c", str[j++]);
        load();

        if(j == strlen(str))
            j = 0;
    }
    return 0;
}
