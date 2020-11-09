#include "Player.h"
void Player::init(string pName)
{
	name = pName;
	GoodDeeds = 0;
	attack = 5;
	health = 70;
	armor = 1;
	maxHealth = 100;
	playerLocation.y = 0;
	playerLocation.x = 0;
	inBattle = false;
	toggleEncounter = true;
	isFightingBoss = false;
	bossDefited = false;
	time = 0;
	bossID = 1;
	toggleMap = false;
	isOnBoss = false;
	bossConvinced = false;
	numItemsInInventory = 0;
	hasMoved = 0;
	apple.init();
	 axe.init();
	 crown.init();
	 painting.init();
	 statue.init();
	 candle.init();
	 clock.init();
	 map.init();
	 inventory.push_back(apple);
	 inventory.push_back(axe);
	 inventory.push_back(crown);
	 inventory.push_back(painting);
	 inventory.push_back(statue);
	 inventory.push_back(candle);
	 inventory.push_back(clock);
	 inventory.push_back(map);
}
void Player::update(int maxX, int maxY)
{
	numItemsInInventory = 0;
	hasMoved = false;
	isFightingBoss = false;
	bossConvinced = false;
	if (inBattle == false)
	{
		char choice;
		char cChoice;
		choice = _getch();
		switch (choice)
		{
		case UP:
			if (playerLocation.y > 0)
			{
				playerLocation.y--;
				hasMoved = true;
			}
			break;
		case DOWN:
			if (playerLocation.y < maxY)
			{
				playerLocation.y++;
				hasMoved = true;
			}
			;
			break;
		case LEFT:
			if (playerLocation.x > 0)
			{
				playerLocation.x--;
				hasMoved = true;
			}

			break;
		case RIGHT:
			if (playerLocation.x < maxX)
			{
				playerLocation.x++;
				hasMoved = true;
			}
			break;
		case ITEMS:
			system("CLS");
			for (int i = 0; i < inventory.size(); i++)
			{
				numItemsInInventory += inventory[i].numInInventory;
			}
			if (numItemsInInventory > 0)
			{
				for (int i = 0; i < inventory.size(); i++)
				{
					if (inventory[i].numInInventory > 0)
					{
						cout <<"Number of " <<inventory[i].name << " in inventory: (" << inventory[i].numInInventory << ") Press (" << i << ") to use" << endl;
					}
				}
				cout << "Press any key to exit" << endl;
				choice = _getch();
				if (choice > 47 && choice < 58)
				{
					if (inventory[choice-48].numInInventory > 0)
					{
						useItem(choice - 48);
						if (choice - 48 == 0)
						{
							inventory[choice - 48].numInInventory--;
						}			
					}
					else
					{
						cout << "Item not in the inventory" << endl;
					}
				}
				else
				{
					cout << "invalid choice" << endl;
				}
				system("PAUSE");
			}
			else
			{
				cout << "No items in inventory" << endl;
				system("PAUSE");
			}
			break;
		case TALK:
			system("CLS");
			if (isOnBoss == true)
			{
				cout << "What you want?" << endl;
				cout << "FIGHT \"1\" ASK \"2\" TALK \"3\"" << endl;
				cChoice = _getch();
			
				switch (cChoice-48)
				{
				case FIGHT:
					isFightingBoss = true;
					break;
				case ASK:
					if (bossID == 1)
					{
						system("CLS");
						print(0);
						cout << "Mermaids. This one seems self obsesed, it seems like the type of person that would wear a crown..." << endl;
						maxHealth += 50;
						system("PAUSE");
					}
					else if (bossID == 2)
					{
						system("CLS");
						print(0);
						armor += 2;
						cout << "Ahhh fairies, judging by the brush in her hand I assume she was painting something before her mind was taken away... " << endl;
						system("PAUSE");
					}
					else if (bossID == 3)
					{
						system("CLS");
						print(0);
						attack += 10;
						cout << "Minotaurs, simple yet powerful cretures. Their will power is so strong that one might say it counts for two..." << endl;
					
						system("PAUSE");
					}
					break;
				case OFFERITEMS:
					if (bossID == 1)
					{
						if (inventory[2].numInInventory > 0)
						{
							system("CLS");
							print(2);
							cout << "Wow you saved me. I am so greatfull" << endl;
							cout << "Please you need to rescue the others there's no time" << endl;
							bossConvinced = true;
							system("PAUSE");
						}
					}
					else if (bossID == 2)
					{
						if (inventory[3].numInInventory > 0)
						{
							system("CLS");
							print(3);
							cout << "What are you doing here?" << endl;
							cout << "Please you need to rescue the others there's no time" << endl;
							bossConvinced = true;
							system("PAUSE");
						}
					}
					else if (bossID == 3)
					{
						if (inventory[1].numInInventory > 0 && inventory[4].numInInventory > 0)
						{
							system("CLS");
							print(4);
							cout << "RHAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAARGh" << endl;
							bossConvinced = true;
							system("PAUSE");
						}
					}
					else
					{
						system("CLS");
						cout << "waaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaargh" << endl;
						system("PAUSE");
					}
					break;
				default:
					break;
				}
			}
			else
			{
				system("CLS");
				print(0);
				cout << "Maybe if we just looked around for a bit" << endl;
				system("PAUSE");
			}			
			break;
		case CHEATS:
			toggleMap = !toggleMap;
			time += 1;
			toggleEncounter = !toggleEncounter;
			maxHealth = 1000;
			health = maxHealth;
			break;
		case ADDALLITEMS:
			for (int i = 0; i < inventory.size(); i++)
			{
				inventory[i].numInInventory++;
			}
			break;
		default:
			break;
		}
	}
	if (health > maxHealth)
	{
		health = maxHealth;
	}
}
void Player::addItem(int type)
{
	inventory[type].numInInventory++;
}

void Player::useItem(int type)
{
	if (type == 0)
	{
		print(6);
		cout << "You ate an apple. Heal 10 HP" << endl;
		health += 10;
	}
	if (type == 1)
	{
		print(7);
		cout << "There's something about this axes that draws you into it" << endl;
	}
	if (type == 2)
	{
		print(8);
		cout << "There's something about this crown that draws you into it" << endl;

	}
	if (type == 3)
	{
		print(9);
		cout << "There's something about this painting that draws you into it" << endl;

	}
	if (type == 4)
	{
		print(10);
		cout << "There's something about this statue that draws you into it" << endl;

	}
	else if (type == 5)
	{
		print(11);
		cout << "This candle will keep/draw enemies toward you" << endl;
		toggleEncounter = !toggleEncounter;
	}
	else if (type == 6)
	{
		print(12);
		cout << "You rest an hour. Heal max health" << endl;

		time += 1;
	}
	else if (type == 7)
	{
		cout << "Toggle map" << endl;

		toggleMap = !toggleMap;
	}

	cout << "Item Used " << endl;
}
void Player::evilEnding()
{
	system("CLS");
	print(1);
	cout << "Well then... Mission complete"<< endl;
	system("PAUSE");
	cout << "I can't wait to go back home and tell the boss about our mission" << endl;
	system("PAUSE");
	system("CLS");
	print(0);
	cout << "Maybe she will even forgive Aruba..." << endl;
	system("PAUSE");
	system("CLS");
	cout << "*You hear something sneaking behind you*" << endl;
	system("PAUSE");
	system("CLS");
	print(1);
	cout << name <<" LOOK OUT!!" << endl;
	system("PAUSE");
	system("CLS");
	print(5);
	cout << "You finally killed every last one of them" << name << endl;
	cout << "I could not wait any longer" << endl;
	system("PAUSE");
	system("CLS");
	print(5);
	cout << "Wondering who I am? "<< name<<"?" << endl;
	cout << "I am the one who hired you to kill these filthy beasts" << endl;
	system("PAUSE");
	system("CLS");
	print(5);
	cout << "And now you will share the same fate..." << endl;
	system("PAUSE");
}
void Player::goodEnding()
{
	system("CLS");
	print(0);
	cout << "Wow you actually did it" << endl;
	system("PAUSE");
	cout << "I'll be honest, I tought you were just gonna murder everyone " << name << endl;
	system("PAUSE");
	system("CLS");
	print(2);
	cout << "Thank you so much for rescuing us" << endl;
	system("PAUSE");
	system("CLS");
	print(3);
	cout << "Yes thank you so much, we owe you one" << endl;
	system("PAUSE");
	system("CLS");
	print(4);
	cout << "AAAAAAAAAARGH ARGH" << endl;
	system("PAUSE");
	system("CLS");
	print(0);
	cout << "It's all good and all but I'm still wondering... " << name << endl;
	system("PAUSE");
	print(1);
	cout << "Who would do something like this?" << endl;
	system("PAUSE");
	system("CLS");
	cout << "I can answer that" << endl;
	system("PAUSE");
	print(5);
	cout << "Hello " << name << endl;
	system("PAUSE");
	system("CLS");
	print(5);
	cout << "My name is Bones and I am the one who hired you to kill these beasts" << endl;
	system("PAUSE");
	cout << "You see, I use to live in the Grim Riper Islands all by myself. But these filthy cretures decided to come in and make themselves a nest" << endl;
	system("PAUSE");
	system("CLS");
	print(5);
	cout << "I was hoping you would be able to deal with this filth, now I see I'm wrong..." << endl;
	system("PAUSE");
}

void Player::end()
{
	system("CLS");
	print(1);
	cout << "OH NO!!! " << name<<endl;
	cout << "WE JUST KILLED THE CLIENT!!!!" << endl;
	system("PAUSE");
	system("CLS");
	print(0);
	cout << "I guess we will have to head home and tell the boss the client won't be able to pay for the contract" << endl;
	cout << "Welp, still better than Aruba... Am I right " << name <<"?" <<endl;
	system("PAUSE");
	system("CLS");
}
void Player::story1()
{
	system("CLS");
	cout << "HEEEEEYYYYY!!!!  " << name << " OVER HEEEEEEREEE!!!!!" << endl;
	system("PAUSE");
	cout << "Finally, do you know how long I've been waiting for you?" << endl;
	system("PAUSE");
	system("CLS");
	print(0);
	sleep_for(milliseconds(800));
	system("CLS");
	print(1);
	sleep_for(milliseconds(500));
	system("CLS");
	print(0);
	cout << "And you came in one piece this time... " << endl;;
	system("PAUSE");
	cout<< "Perfect" << endl;
	system("PAUSE");
	system("CLS");
	print(1);
	cout << "I hope you rested well on your way here" << endl;
	system("PAUSE");
	cout << "We have work to do..." << endl;
	system("PAUSE");
	system("CLS");
	print(0);
	cout << "Don't tell me you already forgot?" << endl;
	system("PAUSE");
	system("CLS");
	print(1);
	cout << "Listen, about last time..." << endl;
	system("PAUSE");
	cout << "The boss wasn't happy with our little incident in Aruba" << endl;
	system("PAUSE");
	cout << "Remember what she told us?" << endl;
	system("PAUSE");
	cout << "Yeah, I don't wanna spend the rest of my days cleaning Ork Gunk at the academy..." << endl;
	system("PAUSE");
	system("CLS");
	print(0);
	cout << "Soooo, let's not fail in our litle assingment this time... shall we?" << endl;
	system("PAUSE");
	cout << "Lucky for you I already did a litle bit of reconnaissance" << endl;
	system("PAUSE");
	system("CLS");
	print(1);
	cout << "According to the client, there are 3 powerful beasts living in each island" << endl;
	system("PAUSE");
	cout << "And our job is to get rid of them " << endl;
	system("PAUSE");
	cout << "Buuut there seem to be something peculiar about these beasts" << endl;
	system("PAUSE");
	cout << "I saw them alright..." << endl;
	system("PAUSE");
	cout << "They don't seem like your ordinary beast" << endl;
	system("PAUSE");
	system("CLS");
	print(1);
	cout << "It seems as if their minds have been taken from them" << endl;
	system("PAUSE");
	cout << "If that's the case, then they might be somewhere in the islands" << endl;
	system("PAUSE");
	cout << "Maybe if we look closesly through each island we might find our answer" << endl;
	system("PAUSE");
	system("CLS");
	print(0);
	cout << "But alas, you are the shot caller this time " << name << endl;
	system("PAUSE");
	cout << "If you wish to slay your way through the islands that's fine by me too" << endl;
	system("PAUSE");
	system("CLS");
	print(1);
	cout << "let's go now, we are a week late already" << endl;
	system("PAUSE");
	system("CLS");
}

void Player::print(int number)
{
	if (number == 0)
	{
		char devil[6][18]
		{
	' ',' ',' ',' ',' ',' ',' ',',',' ',' ',',',' ',' ',',',' ',',',' ',',',
	' ',' ',' ',' ',' ',' ','<','(','_','_',')','>',' ','|',' ','|',' ','|',
	' ',' ',' ',' ',' ',' ','|',' ','\\','/',' ','|',' ','\\','_','|','_','/',
	' ',' ',' ',' ',' ',' ','\\','^',' ',' ','^','/',' ',' ',' ','|',' ',' ',
	' ',' ',' ',' ',' ',' ','/','\\','-','-','/','\\',' ',' ','/','|',' ',' ',
	' ',' ',' ',' ',' ','/',' ',' ','\\','/',' ',' ','\\','/',' ','|',' ',' '
		};
		for (int i = 0; i < 6; i++)
		{
			for (int g = 0; g < 18; g++)
			{
				cout << devil[i][g];
			}
			cout << endl;
		}
	}
	if (number == 1)
	{
		char devil[6][18]
		{
	' ',' ',' ',' ',' ',' ',' ',',',' ',' ',',',' ',' ',',',' ',',',' ',',',
	' ',' ',' ',' ',' ',' ','<','(','_','_',')','>',' ','|',' ','|',' ','|',
	' ',' ',' ',' ',' ',' ','|',' ','\\','/',' ','|',' ','\\','_','|','_','/',
	' ',' ',' ',' ',' ',' ','\\','0',' ',' ','0','/',' ',' ',' ','|',' ',' ',
	' ',' ',' ',' ',' ',' ','/','\\','-','-','/','\\',' ',' ','/','|',' ',' ',
	' ',' ',' ',' ',' ','/',' ',' ','\\','/',' ',' ','\\','/',' ','|',' ',' '
		};
		for (int i = 0; i < 6; i++)
		{
			for (int g = 0; g < 18; g++)
			{
				cout << devil[i][g];
			}
			cout << endl;
		}
	}
	if (number == 2)
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
	if (number == 3)
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
	if (number == 4)
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
	}
	if (number == 5)
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
	if (number == 6)
	{
		char apple[5][13]
		{
			' ',' ',' ',',','-','-','.','/',',','-','.',' ',' ',
	' ',' ','/',' ','#',' ',' ',' ',' ',' ',' ','\\',' ',
	' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
	' ',' ','\\',' ',' ',' ',' ',' ',' ',' ',' ','/',' ',
	' ',' ',' ','`','.','_',',','.','_',',','\'',' ',' '
		};
		for (int i = 0; i < 5; i++)
		{
			for (int g = 0; g < 13; g++)
			{
				cout << apple[i][g];
			}
			cout << endl;
		}
	}
	if (number == 7)
	{
		char axe[6][6]
		{
			' ',' ','_',',','-',',',
		' ','T','_',' ',' ','|',
		' ','|','|','`','-','\'',
		' ','|','|',' ',' ',' ',
		' ','|','|',' ',' ',' ',
		' ','~','~',' ',' ',' '
		};
		for (int i = 0; i < 6; i++)
		{
			for (int g = 0; g < 6; g++)
			{
				cout << axe[i][g];
			}
			cout << endl;
		}
	}
	if (number == 8)
	{
		char crown[5][15]
		{
	' ',' ',' ',' ',' ',' ',' ','<','>',' ',' ',' ',' ',' ',' ',
	' ',' ',' ',' ',' ','.',':',':',':',':','.',' ',' ',' ',' ',
	' ','@','\\','\\','/','W','\\','/','\\','/','W','\\','/','/','@',
	' ',' ','\\','\\','/','^','\\','/','\\','/','^','\\','/','/',' ',
	' ',' ',' ','\\','_','O','_','<','>','_','O','_','/',' ',' '
		};
		for (int i = 0; i < 5; i++)
		{
			for (int g = 0; g < 15; g++)
			{
				cout << crown[i][g];
			}
			cout << endl;
		}
	}
	if (number == 9)
	{
		char monalisa[21][26]{
' ','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',' ',
'|','.','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','.','|',
'|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','|',
'|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','|',
'|','|',' ',' ',' ',' ',' ','.','-','"','`','`','`','`','"','-','.',' ',' ',' ',' ',' ',' ',' ','|','|',
'|','|',' ',' ',' ',' ','/',' ',' ','_','.','.','_',' ',' ',' ',' ','`','\\',' ',' ',' ',' ',' ','|','|',
'|','|',' ',' ',' ','/',' ','/','`',' ',' ',' ',' ','`','-','.',' ',' ',' ',';',' ','.',' ','.','|','|',
'|','|',' ',' ',' ','|',' ','|','_','_',' ',' ','_','_',' ',' ','\\',' ',' ',' ','|',' ',' ',' ','|','|',
'|','|','.','-','.','|',' ','|',' ','e','`','/','e','`',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|','|',
'|','|',' ',' ',' ','|',' ','|',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ','|','\'',' - ',' - ','|','|',
'|','|',' ',' ',' ','|',' ','|',' ',' ','\'',' - ',' ',' ',' ',' ',' | ',' ',' ',' ','|',' ',' ',' ','|','|',
'|','|',' ',' ',' ','|',' ',' ','\\',' ',' - ',' - ','\'',' ',' ','/','|',' ',' ',' ','|',' ',' ',' ','|','|',
'|','|',' ',' ',' ','|',' ',' ',' ','`',';','-','-','-','\'','\\',' | ',' ',' ',' ','|',' ',' ',' ','|','|',
'|','|',' ',' ',' ','|',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|','|',
'|','|',' ',' ',' ','|',' ',' ','.','-','\'',' ',' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|','|',
'|','|','\'',' - ',' - ','|',' / ','`',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ','|','-','-','.','|','|',
'|','|',' ',' ',' ',';',' ',' ',' ',' ','.',' ',' ',' ',' ',' ',';',' ',' ','_','.','\\',' ',' ','|','|',
'|','|',' ',' ',' ',' ','`','-','.',';','_',' ',' ',' ',' ','/','.','-','\'',' ',' ',' ',' ',' ','|','|',
'|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ','`','`','`','`',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','|',
'|','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|','|',
'\'','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','\'' };
		for (int i = 0; i < 21; i++)
		{
			for (int g = 0; g < 26; g++)
			{
				cout << monalisa[i][g];
			}
			cout << endl;
		}
	}
	if (number == 10)
	{
		char venus[24][16]{
' ',' ',' ',' ','%','%','%',' ',' ',' ',' ',' ',' ',' ',' ',' ',
' ',' ',' ','=','=','=','=','=',' ',' ',' ',' ',' ',' ',' ',' ',
' ',' ','&','%','&','%','%','%','&',' ',' ',' ',' ',' ',' ',' ',
' ',' ','%','&',' ','<',' ','<','%',' ',' ',' ',' ',' ',' ',' ',
' ',' ',' ','&','\\','_','_','/',' ',' ',' ',' ',' ',' ',' ',' ',
' ',' ',' ',' ','\\',' ','|','_','_','_','_',' ',' ',' ',' ',' ',
' ',' ',' ','.','\'',',',' ',',',' ',' ','(',')',' ',' ',' ',' ',
' ',' ','/',' ','-','.',' ',' ','_',')','|',' ',' ',' ',' ',' ',
' ','|','_','(','_','.',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',
' ','\'',' - ','\'','\\',' ',' ',')',' ',' ','|',' ',' ',' ',' ',' ',
' ',' ',' ',' ',' ',')',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',
' ',' ',' ',' ','/',' ',' ','.',' ',' ',')','.',' ',' ',' ',' ',
' ',' ',' ','/',' ',' ',' ',' ','_','.',' ','|',' ',' ',' ',' ',
' ','/','\'',' - ',' - ',' - ','\'',':','.','-','\'','|',' ',' ',' ',' ',
'(','_','_','.','\'',' ',' / ',' ',' ',' ',' ','/',' ',' ',' ',' ',
' ','\\',' ',' ',' ','(',' ',' / ',' ',' ','/',' ',' ',' ',' ',' ',
' ',' ','\\',' ',' / ',' ',' ','_',' ',' ','|',' ',' ',' ',' ',' ',
' ',' ',' ','\\',' ',' ',' | ',' ',' ','\'','|',' ',' ',' ',' ',' ',
' ',' ',' ','|',' ','.',' ','\\',' ',' ','|',' ',' ',' ',' ',' ',
' ',' ',' ','|','(',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',
' ',' ',' ','|',' ',' ','\\',' ','\\',' ','|',' ',' ',' ',' ',' ',
' ',' ',' ',' ','\\',' ',' ',')','\\',' ','|',' ',' ',' ',' ',' ',
' ',' ',' ','_','_',')','/',' ','/',' ','\\',' ',' ',' ',' ',' ',
'-','-','"','-','-','(','_','.','O','o','o','\'','-','-','-','-' };
		for (int i = 0; i < 24; i++)
		{
			for (int g = 0; g < 16; g++)
			{
				cout << venus[i][g];
			}
			cout << endl;
		}
	}
	if (number == 11)
	{
		char candle[10][12]
		{ ' ',' ',' ',' ',' ',' ',' ','(',' ',' ',' ',' ',
	' ',' ',' ',' ',' ',' ',' ',')','\\',' ',' ',' ',
	' ',' ',' ',' ',' ',' ',' ','{','_','}',' ',' ',
	' ',' ',' ',' ',' ',' ','.','-',';','-','.',' ',
	' ',' ',' ',' ',' ','|','\'',' - ',' = ',' - ','\'','|',
	' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',
	' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',
	' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',
	' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',
	' ',' ',' ',' ',' ','\'','.','_','_','_','.','\''
		};
		for (int i = 0; i < 10; i++)
		{
			for (int g = 0; g < 12; g++)
			{
				cout << candle[i][g];
			}
			cout << endl;
		}
	}
	if (number == 12)
	{
		char clock[5][7]
		{ ' ','+','=','=','=','=','+',
	' ','|','(',':',':',')','|',
	' ','|',' ',')','(',' ','|',
	' ','|','(','.','.',')','|',
	' ','+','=','=','=','=','+'
		};
		for (int i = 0; i < 5; i++)
		{
			for (int g = 0; g < 7; g++)
			{
				cout << clock[i][g];
			}
			cout << endl;
		}
	}
}
