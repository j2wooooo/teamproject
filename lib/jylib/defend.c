#include <stdio.h>
#include "../../include/jjinclude/gotoxy.h"

#define BLACK -2
#define WHITE 2

extern int map_info[20][20];

struct black_info
{
        int start_x, start_y;
        int end_x, end_y;
        int cont;
        int dir;
        // 가로: 0, 세로: 1, 오른쪽 아래 대각: 2, 왼쪽 아래 대각: 3
};
extern struct black_info blk[500];
extern int blkidx;
extern int blknum;

struct white_info
{
        int start_x, start_y;
        int end_x, end_y;
        int cont;
        int dir;
        // 가로: 0, 세로: 1, 오른쪽 아래 대각: 2, 왼쪽 아래 대$
};
extern struct white_info wht[500];
extern int whtidx; // 백돌 정보 구조체 배열 인덱스
extern int whtnum; // 백돌의 총 개수

struct white_map 
{
        int put; // 백돌 유무
        int df[8]; // 팔방으로 막는 흑돌의 수
        int at[8]; // 팔방으로 만드는 백돌의 수
        // 0부터 왼, 오, 위, 아래, 왼위, 오아, 오위, 왼아
};
extern struct white_map whtmap[20][20];

int dx, dy; // 수비 좌표

void defend()
{
	int big = 0;

	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			for(int k = 0; k < 8; k++)
			{
				if((whtmap[i][j].df[k]) && (map_info[i][j] == 0))
				{
					if(big < whtmap[i][j].df[k])
					{
						big = whtmap[i][j].df[k];
						dx = i;
						dy = j;
					}
				}
			}
		}
	}

	gotoxy(dx, dy*2);
	map_info[dx][dy] = WHITE;
	printf("○");
}
