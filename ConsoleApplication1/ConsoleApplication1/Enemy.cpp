#include "Enemy.h"
void Enemy::init(int type)
{
	if (type == 1)
	{
		attack = 2;
		health = 10;
	}
	if (type == 2)
	{
		attack = 10;
		health = 5;
	}
	if (type == 3)
	{
		attack = 3;
		health = 15;
	}
	if (type == 4)
	{
		attack = 15;
		health = 15;
	}
	if (type == 5)
	{
		attack = 3;
		health = 10;
	}
	if (type == 6)
	{
		attack = 8;
		health = 20;
	}
	if (type == 7)
	{
		attack = 15;
		health = 1;
	}
	if (type == 11)
	{
		attack = 10;
		health = 75;
	}
	if (type == 12)
	{
		attack = 15;
		health = 50;
	}
	if (type == 13)
	{
		attack = 20;
		health = 60;
	}
	if (type == 14)
	{
		attack = 20;
		health = 80;
	}
}

void Enemy::print(int type)
{
	if (type == 1)
	{
		char skeleton[14][14]
		{
	' ',' ',' ',' ',' ',' ',' ','.','-','.',' ',' ',' ',' ',
	' ',' ',' ',' ',' ',' ','(','o','.','o',')',' ',' ',' ',
	' ',' ',' ',' ',' ',' ',' ','|','=','|',' ',' ',' ',' ',
	' ',' ',' ',' ',' ',' ','_','_','|','_','_',' ',' ',' ',
	' ',' ',' ',' ','/','/','.','=','|','=','.','\\','\\',' ',
	' ',' ',' ','/','/',' ','.','=','|','=','.',' ','\\','\\',
	' ',' ',' ','\\','\\',' ','.',' = ','|',' = ','.',' ','/','/',
	' ',' ',' ',' ','\\','\\','(','_','=','_',')','/','/',' ',
	' ',' ',' ',' ',' ','(',':','|',' ','|',':',')',' ',' ',
	' ',' ',' ',' ',' ',' ','|','|',' ','|','|',' ',' ',' ',
	' ',' ',' ',' ',' ',' ','(',')',' ','(',')',' ',' ',' ',
	' ',' ',' ',' ',' ',' ','|','|',' ','|','|',' ',' ',' ',
	' ',' ',' ',' ',' ',' ','|','|',' ','|','|',' ',' ',' ',
	' ',' ',' ',' ',' ','=','=','\'',' ','\'','=','=',' ',' '
		};
		for (int i = 0; i < 14; i++)
		{
			for (int g = 0; g < 14; g++)
			{
				cout << skeleton[i][g];
			}
			cout << endl;
		}
	}
	if (type == 2)
	{
		char minotaur[10][19]
		{
			' ',' ',' ','<','=','=','=','=','=','=','=',']','}','=','=','=','=','=','=',
	' ',' ',' ',' ',' ','-','-','.',' ',' ',' ','/','|',' ',' ',' ',' ',' ',' ',
	' ',' ',' ',' ','_','\\','"','/','_','.','\'','/',' ',' ',' ',' ',' ',' ',' ',
	' ',' ','.','\'','.','_','.','_',',','.','\'',' ',' ',' ',' ',' ',' ',' ',' ',
	' ',' ',':','/',' ','\\','{','}',' / ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
	' ','(','L',' ',' ','/','-','-','\'',',','-','-','-','-','.','_',' ',' ',' ',
	' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\\','\\',' ',
	' ',' ',' ',' ',':',' ','/','-','\\',' ','.','\'','-','\'','\\',' ','/',' ','|',
	' ',' ',' ',' ',' ','\\','\\',',',' ','|','|',' ',' ',' ',' ','\\','|',' ',' ',
	' ',' ',' ',' ',' ',' ','\\','/',' ','|','|',' ',' ',' ',' ','|','|',' ',' '
		};
		for (int i = 0; i < 10; i++)
		{
			for (int g = 0; g < 19; g++)
			{
				cout << minotaur[i][g];
			}
			cout << endl;
		}
	}
	if (type == 3)
	{
		char bat[7][27]
		{
		' ',' ',' ','/','\\',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','/','\\',' ',' ',' ',
		' ',' ',' ','/',' ','\\','\'','.','_',' ',' ',' ','(','\\','_',' / ',')',' ',' ',' ','_','.','\'','/',' ','\\',' ',
		' ',' ','/','_','.','\'','\'','.','_','\'','-','-','(','\'','.','\'',')','-','-','\'','_','.','\'','\'','.','_','\\',
		' ',' ','|',' ','\\','_',' ','/',' ','`',';','=','/',' ','"',' ','\\','=',';','`',' ','\\',' ','_','/',' ','|',
		' ',' ',' ','\\','/',' ','`','\\','_','_','|','`','\\','_','_','_','/','`','|','_','_','/','`',' ',' ','\\','/',
		' ',' ',' ',' ','`',' ',' ',' ',' ',' ',' ','\\','(','/','|','\\',')','/',' ',' ',' ',' ',' ',' ',' ','`',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','"',' ','`',' ','"',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '
		};
		for (int i = 0; i < 7; i++)
		{
			for (int g = 0; g < 27; g++)
			{
				cout << bat[i][g];
			}
			cout << endl;
		}
	}
	if (type == 4)
	{
		char wolf[14][32]
		{
			' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',',',' ',' ',' ',' ',' ',',',
	' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','\\','-','-','-','/','|',
	' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','/',' ',' ',',',' ',',',' ','|',
	' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','_','_','.','-','\'','|',' ',' ','/',' ','\\',' ','/',
	' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','_','_',' ','_','_','_','.','-','\'',' ',' ',' ',' ',' ',' ',' ',' ','.','_','O','|',' ',
	' ',' ',' ',' ',' ',' ',' ','.','-','\'',' ',' ','\'',' ',' ',' ',' ',' ',' ',' ',' ',':',' ',' ',' ',' ',' ',' ','_','/',' ',' ',
	' ',' ',' ',' ',' ',' ','/',' ',',',' ',' ',' ',' ','.',' ',' ',' ',' ',' ',' ',' ',' ','.',' ',' ',' ',' ',' ','|',' ',' ',' ',
	' ',' ',' ',' ',' ',':',' ',' ',';',' ',' ',' ',' ',':',' ',' ',' ',' ',' ',' ',' ',' ',':',' ',' ',' ','_','/',' ',' ',' ',' ',
	' ',' ',' ',' ',' ','|',' ',' ','|',' ',' ',' ','.','\'',' ',' ',' ',' ',' ','_','_',':',' ',' ',' ','/',' ',' ',' ',' ',' ',' ',
	' ',' ',' ',' ',' ','|',' ',' ',':',' ',' ',' ','/','\'','-','-','-','-','\'','|',' ','\\',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',
	' ',' ',' ',' ',' ','\\',' ',' ','|','\\',' ',' ','|',' ',' ',' ',' ',' ',' ','|',' ','/','|',' ','|',' ',' ',' ',' ',' ',' ',' ',
	' ',' ',' ',' ',' ',' ','\'','.','\'','|',' ','/',' ',' ',' ',' ',' ',' ',' ','|','|',' ','\\',' ','|',' ',' ',' ',' ',' ',' ',' ',
	' ',' ',' ',' ',' ',' ','|',' ','/','|','.','\'',' ',' ',' ',' ',' ',' ',' ','\'','.','l',' ','\\','\\','_',' ',' ',' ',' ',' ',' ',
	' ',' ',' ',' ',' ',' ','|','|',' ','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\'',' - ','\'',' ',' ',' ',' ',' '
		};
		for (int i = 0; i < 14; i++)
		{
			for (int g = 0; g < 32; g++)
			{
				cout << wolf[i][g];
			}
			cout << endl;
		}
	}
	if (type == 5)
	{
		char spider[14][27]
		{
	' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','(',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
	' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',')',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
	' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','(',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
	' ',' ',' ',' ',' ',' ',' ',' ',' ','/','\\',' ',' ','.','-','"','"','"','-','.',' ',' ','/','\\',' ',' ',' ',
	' ',' ',' ',' ',' ',' ',' ',' ','/','/','\\','\\','/',' ',' ',',',',',',',' ',' ','\\','/','/','\\','\\',' ',' ',
	' ',' ',' ',' ',' ',' ',' ',' ','|','/','\\','|',' ',',',';',';',';',';',';',',',' ','|','/','\\','|',' ',' ',
	' ',' ',' ',' ',' ',' ',' ',' ','/','/','\\','\\','\\',';','-','"','"','"','-',';','/','/','/','\\','\\',' ',' ',
	' ',' ',' ',' ',' ',' ',' ','/','/',' ',' ','\\','/',' ',' ',' ','.',' ',' ',' ','\\','/',' ',' ','\\','\\',' ',
	' ',' ',' ',' ',' ',' ','(','|',' ',',','-','_','|',' ','\\',' ','|',' ','/',' ','|','_','-',',',' ','|',')',
	' ',' ',' ',' ',' ',' ',' ',' ','/','/','`','_','_','\\','.','-','.','-','.','/','_','_','`','\\','\\',' ',' ',
	' ',' ',' ',' ',' ',' ',' ','/','/',' ','/','.','-','(','(',')',' ','(',')',')','-','.','\\',' ','\\','\\',' ',
	' ',' ',' ',' ',' ',' ','(','\\',' ','|',')',' ',' ',' ','\'','-','-','-','\'',' ',' ',' ','(','|',' ','/',')',
	' ',' ',' ',' ',' ',' ',' ','`',' ','(','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',')',' ','`',' ',
	' ',' ',' ',' ',' ',' ',' ',' ',' ','\\',')',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','(','/',' ',' ',' '
		};
		for (int i = 0; i < 14; i++)
		{
			for (int g = 0; g < 27; g++)
			{
				cout << spider[i][g];
			}
			cout << endl;
		}
	}
	if (type == 6)
	{
		char spider[14][27]
		{
	' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','(',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
	' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',')',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
	' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','(',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
	' ',' ',' ',' ',' ',' ',' ',' ',' ','/','\\',' ',' ','.','-','"','"','"','-','.',' ',' ','/','\\',' ',' ',' ',
	' ',' ',' ',' ',' ',' ',' ',' ','/','/','\\','\\','/',' ',' ',',',',',',',' ',' ','\\','/','/','\\','\\',' ',' ',
	' ',' ',' ',' ',' ',' ',' ',' ','|','/','\\','|',' ',',',';',';',';',';',';',',',' ','|','/','\\','|',' ',' ',
	' ',' ',' ',' ',' ',' ',' ',' ','/','/','\\','\\','\\',';','-','"','"','"','-',';','/','/','/','\\','\\',' ',' ',
	' ',' ',' ',' ',' ',' ',' ','/','/',' ',' ','\\','/',' ',' ',' ','.',' ',' ',' ','\\','/',' ',' ','\\','\\',' ',
	' ',' ',' ',' ',' ',' ','(','|',' ',',','-','_','|',' ','\\',' ','|',' ','/',' ','|','_','-',',',' ','|',')',
	' ',' ',' ',' ',' ',' ',' ',' ','/','/','`','_','_','\\','.','-','.','-','.','/','_','_','`','\\','\\',' ',' ',
	' ',' ',' ',' ',' ',' ',' ','/','/',' ','/','.','-','(','(',')',' ','(',')',')','-','.','\\',' ','\\','\\',' ',
	' ',' ',' ',' ',' ',' ','(','\\',' ','|',')',' ',' ',' ','\'','-','-','-','\'',' ',' ',' ','(','|',' ','/',')',
	' ',' ',' ',' ',' ',' ',' ','`',' ','(','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',')',' ','`',' ',
	' ',' ',' ',' ',' ',' ',' ',' ',' ','\\',')',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','(','/',' ',' ',' '
		};
		for (int i = 0; i < 14; i++)
		{
			for (int g = 0; g < 27; g++)
			{
				cout << spider[i][g];
			}
			cout << endl;
		}
	}
	if (type == 7)
	{
		char ghost[8][14]
		{
	' ',' ',' ',' ',' ',' ',' ','.','-','.',' ',' ',' ',' ',
	' ',' ',' ',' ',' ',' ','(',' ','"',' ',')',' ',' ',' ',
	' ',' ',' ','/','\\','_','.','\'',' ','\'','.','_','/','\\',
	' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
	' ',' ',' ',' ','\\',' ',' ',' ',' ',' ',' ',' ','/',' ',
	' ',' ',' ',' ',' ','\\',' ',' ',' ',' ','/','`',' ',' ',
	' ',' ',' ','(','_','_',')',' ',' ','/',' ',' ',' ',' ',
	' ',' ',' ','`','.','_','_','.','\'',' ',' ',' ',' ',' '
		};
		for (int i = 0; i < 8; i++)
		{
			for (int g = 0; g < 14; g++)
			{
				cout << ghost[i][g];
			}
			cout << endl;
		}
		cout << endl;
	}
	if (type == 11)
	{
		char mermaid[9][38]
		{
			' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','.','-','"','"','-','.',' ',' ',' ',' ',
	' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','(','_','_','_','/','\\',' ','\\',' ',' ',' ',
	' ',' ',' ',' ',' ',' ',' ',' ',' ',',',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','(','|','^',' ','^',' ',')',' ',')',' ',' ',
	' ',' ',' ',' ',' ',' ',' ',' ','/','(',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','_',')','_','\\',' = ','_','/',' ',' ','(',' ',' ',
	' ',' ',',','.','.','_','_','/',' ','`','\\',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','_','_','_','_','(','_','/','_',' ','`',' ','\\',' ',' ',' ',')',' ',
	' ',' ',' ','`','\\',' ',' ',' ',' ','_','/',' ',' ',' ',' ',' ',' ',' ',' ','_','/','-','-','-','.','_','/','(','_',')','_',' ',' ','`','\\',' ','(',' ',
	' ',' ',' ',' ',' ','\'','-','-','\\',' ','`','-','.','_','_','.','.','-','\'',' ',' ',' ',' ','/','.',' ',' ',' ',' ','(','_',')',',',' ','|',' ',' ',')',
	' ',' ',' ',' ',' ',' ',' ',' ',' ','`','.','_',' ',' ',' ',' ',' ',' ',' ',' ','_','_','_','\\','_','_','_','_','_','.','\'','_','|',' ','|','_','_','/',
	' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','`','~','-','-','-','-','"','`',' ',' ',' ','`','-','.','.','.','.','.','.','.','.','.','\'',' ',' ',' '
		};
		for (int i = 0; i < 9; i++)
		{
			for (int g = 0; g < 38; g++)
			{
				cout << mermaid[i][g];
			}
			cout << endl;
		}
	}
	if (type == 12)
	{
		char fairy[18][24]
		{
	' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','.','-','-','-','-','-','.',' ',' ',' ',' ',' ',
	' ',' ','\\',' ','\'',' ','/',' ',' ',' ','_','/',' ',' ',' ',' ',')','/',' ',' ',' ',' ',' ',' ',
	' ','-',' ','(',' ',')',' ','-','(','\'','-','-','-','\'','\'','-','-',')',' ',' ',' ',' ',' ',' ',
	' ',' ','/',' ','.',' ','\\','(','(','(',')','\\','^','_','^','/',')','(',')',' ',' ',' ',' ',' ',
	' ',' ',' ','\\','\\','_','\\',' ','(','(',')','_',')',' - ','(','(','(',')','(',')',' ',' ',' ',' ',
	' ',' ',' ',' ','\'','-',' ','\\',' ',')','/','\\','.','_','.','/','(','(',')',' ',' ',' ',' ',' ',
	' ',' ',' ',' ',' ',' ','\'','/','\\','/','(',' ','X',' ',' ',' ',')',' ','\\',' ',' ',' ',' ',' ',
	' ',' ',' ',' ',' ',' ','(','_','_','_',')','|','_','_','_','/',' ',')',' ','\\',' ',' ',' ',' ',
	' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','.','#','_','|','(','_','_','_',')',' ',' ',' ',
	' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','/','\\',' ',' ',' ',' ','\\',' ','(',' ','(','_',' ',' ',
	' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\\','/','\\','/','\\','/','\\',')',' ','\\','\\',' ',' ',' ',
	' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','/',' ','\\',' ','|',' ',' ',' ',' ',' ',' ',' ',
	' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','(',' ',' ',' ','\\','|',' ',' ',' ',' ',' ',' ',' ',
	' ',' ',' ',' ',' ',' ',' ',' ',' ','_','|','_',')','_','_','|','_','\\','_',' ',' ',' ',' ',' ',
	' ',' ',' ',' ',' ',' ',' ',' ',' ',')','.','.','.','(',')','.','.','.','(',' ',' ',' ',' ',' ',
	' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','(',' ',' ',' ','\\',' ','|',' ',' ',' ',' ',' ',
	' ',' ',' ',' ',' ',' ',' ','.','-','\'','_','_',',',')',' ',' ','(',' ',' ','\\',' ',' ',' ',' ',
	' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\'','\\','_','-',',',' ',' '
		};
		for (int i = 0; i < 18; i++)
		{
			for (int g = 0; g < 24; g++)
			{
				cout << fairy[i][g];
			}
			cout << endl;
		}
	}
	if (type == 13)
	{
		char bosstauros[21][29]
		{
	' ',' ',' ',' ',' ','.',' ',' ',' ',' ',' ',' ','.',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
	' ',' ',' ',' ',' ','|','\\','_','_','_','_','/','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
	' ',' ',' ',' ','(','\\','|','-','-','-','-','|','/',')',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
	' ',' ',' ',' ',' ','\\',' ','0',' ',' ','0',' ','/',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
	' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
	' ',' ',' ','_','_','_','/','\\','.','.',' / ','\\','_','_','_','_',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
	' ',' ','/',' ',' ',' ',' ',' ','-','-',' ',' ',' ',' ',' ',' ',' ','\\',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
	' ','/',' ',' ','\\',' ',' ',' ',' ',' ',' ',' ',' ',' ','/',' ',' ',' ','\\',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
	'|',' ',' ',' ',' ','\\','_','_','_','/','_','_','_','/','(',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
	'\\',' ',' ',' ','/','|',' ',' ',' }','{',' ',' ',' ','|',' ','\\',' ',' ',')',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
	' ', '\\',' ',' ','|','|','_','_','}','{','_','_','|',' ',' ','|',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
	' ', ' ', '\\',' ',' ','|',';',';',';',';',';',';',';','\\',' ',' ','\\',' ','/',' ','\\','_','_','_','_','_','_','_',' ',
	' ', ' ', ' ', '\\',' ','/',';',';',';',';',';',';',';',';','|',' ','[',',',',','[','|','=','=','=','=','=','=','\'', ' ',
	' ', ' ', ' ', ' ', ' ', '|', ';', ';', ';', ';', ';', ';', '/', ' ', '|', ' ', ' ', ' ', ' ', ' ', '/', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', '|', '|', ';', ';', '|', '\\',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
	' ', ' ', ' ', ' ', ' ', '|', '|', ';', ';', '/', '|', ' ', ' ', ' ', '/', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', '\\','_','|',':','|','|','_','_','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
	' ', ' ', ' ', ' ', ' ', ' ', '\\',' ',';','|','|',' ',' ','/',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
	' ', ' ', ' ', ' ', ' ', ' ', '|', '=', ' ', '|', '|', ' ', '=', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', '|', '=', ' ', '/', '\\',' ','=','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
	' ', ' ', ' ', ' ', ' ', ' ', '/', '_', '/', ' ', ' ', '\\','_','\\',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '
		};
		for (int i = 0; i < 21; i++)
		{
			for (int g = 0; g < 29; g++)
			{
				cout << bosstauros[i][g];
			}
			cout << endl;
		}
	}if (type == 14)
	{
		char death[16][22]
		{
	' ',' ','_','_','_','_',',',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
	' ','/','.','-','-','-','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
	' ','`',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','_','_','_',' ',' ',' ',' ',' ',' ',' ',
	' ',' ',' ',' ',' ','(','=','\\','.',' ',' ','/','-','.',' ','\\',' ',' ',' ',' ',' ',' ',
	' ',' ',' ',' ',' ',' ','|','\\',' / ','\\','_','|','"','|',' ',' ','|',' ',' ',' ',' ',' ',
	' ',' ',' ',' ',' ',' ','|','_','\\',' ','|','; ',' - ','|',' ',' ',';',' ',' ',' ',' ',' ',
	' ',' ',' ',' ',' ',' ','|',' ','/',' ','\\','|',' ','|','_','/',' ','\\',' ',' ',' ',' ',
	' ',' ',' ',' ',' ',' ','|',' ',')','/','\\','/',' ',' ',' ',' ',' ',' ','\\',' ',' ',' ',
	' ',' ',' ',' ',' ',' ','|',' ','(',' ','\'','|',' ',' ','\\',' ',' ',' ','|',' ',' ',' ',
	' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ','\\','_',' ','/',' ',' ',' ','\\',' ',' ',' ',
	' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ','/',' ',' ','\\','_','.','-','-','\\',' ',' ',
	' ',' ',' ',' ',' ',' ','\\',' ',' ',' ',' ','|',' ',' ',' ',' ','(','|','\\','`',' ',' ',
	' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ',' ',' ','\\',' ',' ',' ',' ',
	' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ',' ',' ',' ','\'','.',' ',' ',
	' ',' ',' ',' ',' ',' ',' ','|',' ',' ','/',' ',' ',' ',' ',' ',' ',' ',' ',' ','\\',' ',
	' ',' ',' ',' ',' ',' ',' ','\\',' ',' ','\\','.','_','_','.','_','_','.','-','.','_',')'
		};
		for (int i = 0; i < 16; i++)
		{
			for (int g = 0; g < 22; g++)
			{
				cout << death[i][g];
			}
			cout << endl;
		}
	}
}