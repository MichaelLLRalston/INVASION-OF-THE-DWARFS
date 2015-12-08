#pragma once


//#include "GameState.h"

enum STATE{MENU, GAME};



class Menu
{
public:
	Menu();
	STATE current;
	void update()
	{			
			if (sfw::getKey(KEY_ENTER))
			{
				current = GAME;
				//return current;
			}
	}

};

Menu::Menu()
{
	current = MENU;
}