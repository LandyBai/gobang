//五子棋

#include <stdio.h>
#include <stdlib.h>
#include <getch.h>

int x = 8, x1 = 8;
int y = 8, y1 = 8;//初始化坐标位置
int player = 1; //1为黑棋，0为白棋
int line = 0; //用于判断相连棋子数量
int pieces = 15*15+1;//用于平局判定 成功落子 则-1

int main()
{
	//定义数组并赋值28
	char board[15][15] = {};
	for (int i = 0;i<15;i++)
	{
		for(int j = 0;j<15;j++)	
		{
			board[i][j] = 46;	
		}
	}
	
	//进入死循环 游戏本体
	for (;;)
	{
		system("clear");	//清屏
		
		//打印棋盘
		for (int i = 0;i<15;i++)
		{
			for(int j = 0;j<15;j++)	
			{
				printf("%c ",board[i][j]);
			}
			printf("\n");
		}


		//是否五子相连的判断 应该放在打印完毕后，且在下次落子之前检验
		if ( board[x-1][y-1] == board[x-1][y-1+1] && (15 != y ) ) //左右方向 右边先判断	边界已加
		{
			do
			{
				++line;
				++y;
			}
			while (board[x-1][y-1] == board[x-1][y-1+1] && (15 != y) );

			y -= line; //棋子坐标回归起点位置 开始判断左边

			while (board[x-1][y-1] == board[x-1][y-1-1] && (1 != y) )
			{
				++line;
				--y;
			}
		}
		else if (board[x-1][y-1] == board[x-1][y-1-1] && (1 != y) ) //这种情况下 落子右边没有相同棋子，之需要判断左边即可
		{
			do
			{
				++line;
				--y;
			}
			while (board[x-1][y-1] == board[x-1][y-1-1] && (1 != y) );
		}
		if (4 == line)  //左右方向判断完毕 看看有无胜出，有则结束，没有就继续判断另外方向，再重复三次
		{
			printf("游戏结束，%s棋获胜！",player?"白":"黑");	
			return 0;
		}
		else
		{
			line = 0;	
		}

		
		if (board[x-1][y-1] == board[x-1+1][y-1] && (15 != x) ) //上下方向 下边先判断	边界没有判断 稍后再加
		{
			do
			{
				++line;
				++x;
			}
			while (board[x-1][y-1] == board[x-1+1][y-1] && (15 != x) );

			x -= line; //棋子坐标回归起点位置 开始判断上边(x-1)

			while (board[x-1][y-1] == board[x-1-1][y-1] && (1 != x))
			{
				++line;
				--x;
			}
		}
		else if (board[x-1][y-1] == board[x-1-1][y-1] && (1 != x) ) //这种情况下 落子下边没有相同棋子，之需要判断上边即可
		{
			do
			{
				++line;
				--x;
			}
			while (board[x-1][y-1] == board[x-1-1][y-1] &&(1 != x) );
		}
		if (4 == line)  //上下方向判断完毕 看看有无胜出，有则结束，没有就继续判断另外方向，再重复两次
		{
			printf("游戏结束，%s棋获胜！",player?"白":"黑");	
			return 0;
		}
		else
		{
			line = 0;	
		}


		if (board[x-1][y-1] == board[x-1+1][y-1+1] && (15 != x) && (15 != y) ) //左斜方向 下右(x+1,y+1)先判断 边界没有判断 稍后再加
		{
			do
			{
				++line;
				++y;
				++x;
			}
			while (board[x-1][y-1] == board[x-1+1][y-1+1] && (15 != x) && (15 != y) );

			y -= line;
			x -= line;  //棋子坐标回归起点位置 开始判断上左(x-1,y-1)

			while (board[x-1][y-1] == board[x-1-1][y-1-1] && (1 != x) && (1 != y) )
			{
				++line;
				--y;
				--x;
			}
		}
		else if (board[x-1][y-1] == board[x-1-1][y-1-1] && (1 != x) && (1 != y) ) //这种情况下 落子下右没有相同棋子，之需要判断上左即可
		{
			do
			{
				++line;
				--y;
				--x;
			}
			while (board[x-1][y-1] == board[x-1-1][y-1-1] && (1 != x) && (1 != y) );
		}
		if (4 == line)  //左斜方向判断完毕 看看有无胜出，有则结束，没有就继续判断另外方向，再重复两次
		{
			printf("游戏结束，%s棋获胜！",player?"白":"黑");	
			return 0;
		}
		else
		{
			line = 0;	
		}


		if (board[x-1][y-1] == board[x-1-1][y-1+1] && (1 != x) && (15 != y) ) //右斜方向 上右(x-1,y+1)先判断	边界没有判断 稍后再加
		{
			do
			{
				++line;
				++y;
				--x;
			}
			while (board[x-1][y-1] == board[x-1-1][y-1+1] && (1 != x) && (15 != y) );

			y -= line;
			x += line;  //棋子坐标回归起点位置 开始判断下左(x+1,y-1)

			while (board[x-1][y-1] == board[x-1+1][y-1-1] && (15 != x) && (1 != y) )
			{
				++line;
				--y;
				++x;
			}
		}
		else if (board[x-1][y-1] == board[x-1+1][y-1-1] && (15 != x) && (1 != y) ) //这种情况下 落子上右没有相同棋子，之需要判断下左即可
		{
			do
			{
				++line;
				--y;
				++x;
			}
			while (board[x-1][y-1] == board[x-1+1][y-1-1] && (15 != x) && (1 != y) );
		}
		if (4 == line)  //左右方向判断完毕 看看有无胜出，有则结束，没有就继续判断另外方向，再重复三次
		{
			printf("游戏结束，%s棋获胜！",player?"白":"黑");	
			return 0;
		}
		else
		{
			line = 0;	
		}

		//平局判定
		--pieces; //除了第一次，到达这里，证明落子成功，所以初始值为棋盘格数+1
		if (0 == pieces)
		{
			printf("棋盘没有可落之处，本局为平局！");	
			return 0;
		}
		x = x1;
		y = y1; //重置光标位置为上一个落子点

		//开始落子,落子坐标=数组编号+1
		printf("黑棋为X，白棋为@,现在轮到%s棋落子\n",player?"黑":"白");

		for(;;) //进入死循环，保证可以一直移动光标直至敲下回车
		{
			printf("\33[%d;%dH",x,2*y-1);
			int ch = getch();
			switch(ch)
			{
				case 183:if(x>1)  --x;break;
				case 184:if(x<15) ++x;break;
				case 185:if(y<15) ++y;break;
				case 186:if(y>1)  --y;break;
			}
			if (10 == ch)
			{
				if (board[x-1][y-1] == 46)
				{
					board[x-1][y-1] = (player?88:64);
					player = !player;
					x1 = x;
					y1 = y;
					break;
				}
				else 
				{
					printf("\33[18;1H");
					printf("该位置已有棋子，请选择其他位置\n");
					printf("\33[%d;%dH",x,2*y-1);
				}
			}
		}
		

/*原版本坐标落子内容

		printf("黑棋为X，白棋为@,现在轮到%s棋落子，请输入您想下的位置x y\n",player?"黑":"白");
		scanf("%d%d",&x,&y);
		
		while(x>0 && x<16 && y>0 && y<16)
		{
			if (board[x-1][y-1] == 46)
			{
				board[x-1][y-1] = (player?88:64);
				player = !player;
				break;
			}
			else 
			{
				printf("该位置已有棋子，请选择其他位置\n");
				scanf("%d%d",&x,&y);
			}
		}
		
		//输入超出范围时的显示
		while(!(x>0 && x<16 && y>0 && y<16))
		{
			printf("无效的坐标位置，请重新输入\n");
			scanf("%d%d",&x,&y);
		}

		if (board[x-1][y-1] == 46)
		{
			board[x-1][y-1] = (player?88:64);
			player = !player;
		}
*/

	}

	return 0;
}
