#include "gameManager.h"

void GameManager::resetGame()
{
	board.cleanFallenItems(SPACE);
	board.setFallenItems(0);
	board.cleanScore(SPACE);
	board.setScore(0);
	board.showFailureMessage();
}

GameManager::GameManager()
{
	std::srand((unsigned int)time(NULL)); //casting to unsigned int because we had warning: possible loss of data
}

void GameManager::runGame()
{
	while (!quitGame)
	{
		if (gameOn)
		{
				if (existingShape == false)//generating parts
			{
				shape = new ShapeFactory;
				existingShape = true;
				board.setFallenItems(board.getFallenItems() + 1);
			}

			if (shape->canMove(board, DOWN))//i want to change the killing switch into cant move down and that the direction that is getted from the user is stay ("nothing") in order to prolong the delay before killing the shape 
											//new defintion: "the shape cant move down and the user stopped controling it"
				shape->move(DOWN);
			
			dir = menu(keyPressed);
			
		
			if ((dir == DOWN) && (shape->getShapeType() == JOKER))
			{
				board.markShape(*shape);
				delete shape;
				existingShape = false;
			}
			else if (shape->canMove(board, dir))
				shape->move(dir);
			else
			{
				if (shape->canMove(board, DOWN))
					shape->move(DOWN);
				//killing switch
				
				else //if(dir==STAY||dir==DOWN) //changed from else to else if
				{

					if (shape->getShapeType() == BOMB)
						board.explodeBomb(shape->getPoint());
					shape->draw(' ');
					if (shape->getShapeType() != BOMB)
						board.markShape(*shape);
 					delete shape;
					existingShape = false;
				}
			}
			//check game status 
				gameFailure = board.checkGameFailure();
			if (!gameFailure)
			{
				gameOn = false;
				resetGame();
			}

			Sleep(gameSpeed);

			keyPressed = 0;

			if (_kbhit())
				keyPressed = _getch();
		
		}

		else//menu mode
		{

			keyPressed = 0;

			if (_kbhit())
				keyPressed = _getch();
			dummy = menu(keyPressed);
			

		}
	}

}



//gets an input from keyboard and returns the relevant direction accordingly. Default returnd value
//will be STAY.
Direction GameManager::menu(char &keyPressed)
{
	switch (keyPressed)
	{
	case 'w':
		return ROTATE;
		break;
	case 'd':
		return RIGHT;
		break;
	case 's':
		return DOWN;
		break;
	case 'a':
		return LEFT;
		break;

	case START_GAME:
		board.printMatrix();
		setGameOn();
		
		return STAY;
		break;

	case PLAY_PAUSE:
		if (gameOn)
			pauseGame();
		else
		{
			board.printMatrix();
			setGameOn();
			keyPressed = 0;
		}
		break;
	case SPEED_UP:
		if ((gameSpeed - SPEED_CHANGE) >= MAX_SPEED && gameSpeed <= MIN_SPEED)
			setSpeed(getSpeed() - SPEED_CHANGE);
		return STAY;
		break;
	case SPEED_DOWN:
		if (gameSpeed >= MAX_SPEED && (gameSpeed + SPEED_CHANGE) <= MIN_SPEED)
			setSpeed(getSpeed() + SPEED_CHANGE);
		return STAY;
		break;
	case EXIT:
		leaveGame();
		break;



	default:
		return STAY;
		break;

	}
}
