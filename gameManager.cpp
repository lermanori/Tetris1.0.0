#include "gameManager.h"


GameManager::GameManager()
{
	std::srand((unsigned int)time(NULL)); //casting to unsigned int because we had warning: possible loss of data

}

void GameManager::resetGame()
{
	board.cleanFallenItems();
	board.cleanScore();
	board.showFailureMessage();
}

void GameManager::setSpeed(double newSpeed)
{
	gameSpeed = newSpeed;

	gotoxy(SCORE_X - 8, SCORE_Y - 3);
	if (gameSpeed == 1.25)
		 std::cout << very_slow;
	else if (gameSpeed == 1)
		std::cout << slow;
	else if (gameSpeed == 0.75)
		std::cout <<  normal;
	else if (gameSpeed == 0.5)
		std::cout <<  fast;
	else if (gameSpeed == 0.25)
		std::cout <<  very_fast;
}

void GameManager::runGame()
{
	saveTime = time(NULL);
	while (!quitGame)
	{
		Sleep(100);
		if (gameOn)
		{

			if (existingShape == false)//Generating Parts
			{
				shape = ShapeFactory::createShape(ShapeFactory::shapeProbabilities());
				existingShape = true;
				board.setFallenItems(board.getFallenItems() + 1);
			}

			currTime = time(NULL);
			if (std::difftime(currTime, saveTime) > gameSpeed)
			{
				if (shape->canMove(board, DOWN))
				{
					shape->move(DOWN);
				}
				saveTime = currTime;
			}
			dir = menu(keyPressed);

			if (dir == HARDDROP)
			{
				while (shape->canMove(board, DOWN))
				{
					shape->move(DOWN);
					board.setScore(board.getScore() + 2);
				}
				erasedLines = shape->markShape(board);
				board.updateScore(erasedLines, *shape);
				delete shape;
				existingShape = false;

			}

			else if ((dir == DOWN) && (shape->getShapeType() == JOKER))
			{
				erasedLines = shape->markShape(board);
				board.updateScore(erasedLines, *shape);
				delete shape;
				existingShape = false;

			}
			else if (shape->canMove(board, dir))
			{
				shape->move(dir);
				if (dir == DOWN)//update score for soft-Drop
					board.setScore(board.getScore() + 1);

			}
			else
			{ //not hardDrop , not save joker, shape cant move anymore
				//killing switch
				if (!shape->canMove(board, DOWN))
				{
					Sleep(400);
					if (_kbhit())
					{
						keyPressed = _getch();
						dir = menu(keyPressed);
					}

					while (shape->canMove(board, dir) && dir != STAY)
					{
						shape->move(dir);
						if (_kbhit())
						{
							keyPressed = _getch();
							dir = menu(keyPressed);
						}
						else
						{
							dir = STAY;
						}

					}
					Sleep(100);
					if (!shape->canMove(board, DOWN))
					{
						erasedLines = shape->markShape(board);
						board.updateScore(erasedLines, *shape);
						delete shape;
						existingShape = false;
					}



				}
			}

			//check game status 
			gameFailure = board.checkGameFailure();
			if (gameFailure)
			{
				gameOn = false;
				resetGame();
			}

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

	case HARD_DROP:
		return HARDDROP;

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
