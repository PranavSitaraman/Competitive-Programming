#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<iostream>
#include<vector>
using namespace std;
typedef struct
{
	int fill;
	char letter;
	int x;
	int y;
} tile;
int movex[4] = { 0, 1, 0, -1 };
int movey[4] = { -1, 0, 1, 0 };
vector<char> tictactoe = { '.', '.', '.', '.', '.', '.', '.', '.', '.' };
vector<vector<char>> options;
int num;
int depth;
int counter = 0;
void movetile(int a, int b, tile* board, int in)
{
    if (in == depth)
    {
        return;
    }
	if (board[a * num + b].fill == 2)
	{
        if (tictactoe[(board[a * num + b].x - 1) * 3 + board[a * num + b].y - 1] == '.')
        {
            tictactoe[(board[a * num + b].x - 1) * 3 + board[a * num + b].y - 1] = board[a * num + b].letter;
        }
	}
    bool good = false;
    if (tictactoe[2] == 'M' && tictactoe[4] == 'O' && tictactoe[6] == 'O')
    {
        good = true;
    }
    else if (tictactoe[0] == 'M' && tictactoe[4] == 'O' && tictactoe[8] == 'O')
    {
        good = true;
    }
    else if (tictactoe[0] == 'M' && tictactoe[1] == 'O' && tictactoe[2] == 'O')
    {
        good = true;
    }
    else if (tictactoe[3] == 'M' && tictactoe[4] == 'O' && tictactoe[5] == 'O')
    {
        good = true;
    }
    else if (tictactoe[6] == 'M' && tictactoe[7] == 'O' && tictactoe[8] == 'O')
    {
        good = true;
    }
    else if (tictactoe[0] == 'M' && tictactoe[3] == 'O' && tictactoe[6] == 'O')
    {
        good = true;
    }
    else if (tictactoe[1] == 'M' && tictactoe[4] == 'O' && tictactoe[7] == 'O')
    {
        good = true;
    }
    else if (tictactoe[2] == 'M' && tictactoe[5] == 'O' && tictactoe[8] == 'O')
    {
        good = true;
    }
    else if (tictactoe[2] == 'O' && tictactoe[4] == 'O' && tictactoe[6] == 'M')
    {
        good = true;
    }
    else if (tictactoe[0] == 'O' && tictactoe[4] == 'O' && tictactoe[8] == 'M')
    {
        good = true;
    }
    else if (tictactoe[0] == 'O' && tictactoe[1] == 'O' && tictactoe[2] == 'M')
    {
        good = true;
    }
    else if (tictactoe[3] == 'O' && tictactoe[4] == 'O' && tictactoe[5] == 'M')
    {
        good = true;
    }
    else if (tictactoe[6] == 'O' && tictactoe[7] == 'O' && tictactoe[8] == 'M')
    {
        good = true;
    }
    else if (tictactoe[0] == 'O' && tictactoe[3] == 'O' && tictactoe[6] == 'M')
    {
        good = true;
    }
    else if (tictactoe[1] == 'O' && tictactoe[4] == 'O' && tictactoe[7] == 'M')
    {
        good = true;
    }
    else if (tictactoe[2] == 'O' && tictactoe[5] == 'O' && tictactoe[8] == 'M')
    {
        good = true;
    }
    if (good == true)
    {
        bool newone = true;
        for (int h = 0; h < options.size(); h++)
        {
            if (options[h] == tictactoe)
            {
                newone = false;
                break;
            }
        }
        if (newone == true)
        {
            counter++;
            for (int h = 0; h < 9; h++)
            {
                cout << tictactoe[h] << " ";
                if (h % 3 == 2)
                {
                    cout << endl;
                }
            }
            cout << endl;
            options.push_back(tictactoe);
        }
        return;
    }
	for (int i = 0; i < 4; i++)
	{
		if (board[(a + movex[i]) * num + b + movey[i]].fill != 0)
		{
            vector<char> newtictactoe;
            for (int q = 0; q < 9; q++)
            {
                newtictactoe.push_back(tictactoe[q]);
            }
            movetile(a + movex[i], b + movey[i], board, in + 1);
            for (int q = 0; q < 9; q++)
            {
                tictactoe[q] = newtictactoe[q];
            }
		}
	}
}
void usacomazetactoerun()
{
    int count = 0;
    cin >> num;
    cin.ignore();
    tile* board = (tile*)calloc(num * num, sizeof(tile));
    int startx, starty;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            char ch = getchar();
            if (ch == '#')
            {
                board[i * num + j].fill = 0;
                getchar();
                getchar();
            }
            else if (ch == '.')
            {
                board[i * num + j].fill = 1;
                getchar();
                getchar();
                count++;
            }
            else if (ch == 'B')
            {
                startx = i;
                starty = j;
                board[i * num + j].fill = 1;
                getchar();
                getchar();
                count++;
            }
            else
            {
                board[i * num + j].fill = 2;
                board[i * num + j].letter = ch;
                int a;
                scanf("%d", &a);
                board[i * num + j].y = a % 10;
                board[i * num + j].x = a / 10;
                count++;
            }
        }
        cin.ignore();
    }
    depth = count * 2;
    movetile(startx, starty, board, 0);
    cout << counter;
}