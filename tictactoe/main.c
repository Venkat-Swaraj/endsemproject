#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>
#include <string.h>
#include <fcntl.h>
#include <io.h>


int main()
{

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	_setmode(_fileno(stdout), _O_U16TEXT);
    wchar_t star = 0x2605;

	for (int i = 1;i < (rows / 2)-4;i++)
	{
		wprintf(L"\n");
	}
	char* Heading = "xoxoxoxoxoxoxox-TICTACTOE-xoxoxoxoxoxoxox";
    

	wprintf(L"%*hs\n\n",((columns / 2) + strlen(Heading)/2),Heading);

    wprintf(L"%*lc MAIN-MENU %lc\n\n",((columns / 2)-5 ),star,star);
    
    for (int i = 1;i < columns / 2-4;i++){wprintf(L" ");}

    wprintf(L"1 Star game\n\n");
    for (int i = 1;i < columns / 2-4;i++){wprintf(L" ");}
    wprintf(L"2 Instructions\n\n");
    for (int i = 1;i < columns / 2-4;i++){wprintf(L" ");}
    wprintf(L"3 Team members\n\n");
    for (int i = 1;i < columns / 3 -2;i++){wprintf(L" ");}
    wprintf(L"Please press the corresponding number to continue ....");
    
	return 0;
}
