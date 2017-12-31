TETRIS 
Part 1
Made By:
Ori Lerman 205665508
Amir Nadv 305707044


Special Notes:
Game Keys-                       
		RIGHT = d
    LEFT = a
    ROTATE RIGHT = w
    SOFT DROP / STOP(JOKER) = s
    HARD DROP = space
Speeds-
    User can choose between 5 different speed levels:
          ULTRA FAST = 100m/s
          FAST = 125m/s
          NORMAL(DEFAULT) = 150m/s
          SLOW = 175m/s
          ULTRA SLOW= 200m/s
	  

     -as u can see we made a file for each object and there is seperation between every object of the game
     the master classes are:
     Point-who handles all of the movement/drawing/checkings of the smallest building block of the game.
     shape factory-who is incharge of controlling the diffrent objects create ,destroy etc.
     board-who is in chrage of the data structure matrix that we built and represent data structure of the actual 10*15 board.
     
     -the method that this project is built about is that we tell a general object to do a certion thing and the mechanism is activating 	the relevent piece in the screen(example:we tell an shape to move and the shape know that it is a line and because of that call the	 relavent move function of line who calls the move function of point for every point in the line.)  
     
     -there is whole file dedecated to the constants of the project called constants.h
     

