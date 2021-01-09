#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

void printBoard(char playerBoard[][10], const int size) {
	cout << setw(70);
	for (int i = 0;i < size + 1;i++) {
		cout << char(201) << char(205) << char(205) << char(205) << char(187);
	}
	cout << endl;
	cout << setw(70);
	for (int i = 0;i < size + 1;i++) {
		if (i == 0) {
			cout << char(186) << " " << (char)0 << " " << char(186);
		}
		else {
			cout << char(186) << " " << (char)(64 + i) << " " << char(186);
		}
	}
	cout << endl;
	cout << setw(70);
	for (int i = 0;i < size + 1;i++) {
		cout << char(200) << char(205) << char(205) << char(205) << char(188);
	}
	cout << endl;
	for (int j = 0;j < size;j++) {
		cout << setw(70);
		for (int i = 0;i < size + 1;i++) {
			cout << char(201) << char(205) << char(205) << char(205) << char(187);
		}
		cout << endl;
		cout << setw(70);
		for (int i = 0;i < size + 1;i++) {
			if (i == 0) {
				if (j + 49 == 58) {
					cout << char(186) << setw(1) << "10" << " " << char(186);
				}
				else {
					cout << char(186) << " " << (char)(j + 49) << " " << char(186);
				}
			}
			else {
				cout << char(186) << " " << playerBoard[j][i - 1] << " " << char(186);
			}
		}
		cout << endl;
		cout << setw(70);
		for (int i = 0;i < size + 1;i++) {
			cout << char(200) << char(205) << char(205) << char(205) << char(188);
		}
		cout << endl;

	}
}
void printBlank() {
	for (int i = 0;i < 3;i++) {
		cout << " ";
	}
}

void fillBoard(char playerBoard[][10],const int size) {
	for (int i = 0;i < size;i++) {
		for (int j = 0;j < size;j++) {
			playerBoard[i][j] = '1';
		}
	}
}
void drawBoard(char playerBoard[][10],const int size){
	for (int i = 0;i < size;i++) {
		for (int j = 0;j < size;j++) {
			cout << setw(3) << playerBoard[i][j];
		}
		cout << endl;
	}
	
	
}
//function that clears the console
void clearConsole() {
	system("cls");
}

int transformInt(int z) {
	int x = 0;
	x = z - 1;
	return x;
}
int  transformChar(char y) {
	return (int)(y - 65);
}


void inputShips() {

}
bool validateShipPlacement(char playerBoard[][10], const int size, int x, int y, char direction, const int lenghtOfShip) {
	bool flag = true;
	if (direction == 'r') {
		for (int i = 0;i < lenghtOfShip;i++) {
			//checking wheter that space is avaible
			if ( x<0 || (y + i) < 0 || x > size - 1 || (y + i)>size - 1){
				flag = false;
				break;
			}
			else {
				if (playerBoard[x][y + 1] != '\0') {
					flag = false;
					break;
				}
			}
		}
		if (flag == true) {
			for (int i = 0;i < (lenghtOfShip + 2);i++) {
				if (x - 1 <= size - 1 and (y - 1 + i) <= size - 1 and x - 1 >= 0 and (y - 1 + i) >= 0) {
					if (playerBoard[x - 1][y - 1 + i] != '\0')
						flag = false;
					break;
				}
				if (x + 1 <= size - 1 and (y - 1 + i) <= size - 1 and x + 1 >= 0 and (y - 1 + i) >= 0) {
					if (playerBoard[x + 1][y - 1 + i] != '\0') {
						flag = false;
						break;
					}
				}
			}
		}
		if (flag == true) {
			if (x <= size - 1 and x >= 0 and y - 1 <= size - 1 and y - 1 >= 0 and y - 1 + lenghtOfShip <= size - 1) {
				if (playerBoard[x][y - 1] != '\0')
					flag = false;
			}
			if ((y + lenghtOfShip - 1) >= 0 and (y + lenghtOfShip - 1 <= size - 1) and x <= size - 1 and x >= 0) {
				if (playerBoard[x][y + lenghtOfShip - 1] != '\0') {
					flag = false;
				}
			}
		}
		return flag;
	}
	if (direction == 'l') {
		for (int i = 0;i < lenghtOfShip;i++) {
			//checking wheter that space is avaible
			if (x<0 || (y - i) < 0 || x > size - 1 || (y - i)>size - 1) {
				flag = false;
				break;
			}
			else {
				if (playerBoard[x][y - i] != '\0') {
					flag = false;
					break;
				}
			}
		}
		if (flag == true) {
			for (int i = 0;i < (lenghtOfShip + 2);i++) {
				if (x - 1 <= size - 1 and (y + 1 - i) <= size - 1 and x - 1 >= 0 and (y + 1 - i) >= 0) {
					if (playerBoard[x - 1][y + 1 - i] != '\0')
						flag = false;
					break;
				}
				if (x + 1 <= size - 1 and (y + 1 - i) <= size - 1 and x + 1 >= 0 and (y + 1 - i) >= 0) {
					if (playerBoard[x + 1][y + 1 - i] != '\0') {
						flag = false;
						break;
					}
				}
			}
		}
		if (flag == true) {
			if (x <= size - 1 and x >= 0 and y - 1 <= size - 1 and y - 1 >= 0) {
				if (playerBoard[x][y + 1] != '\0') {
					flag = false;
				}
			}
			if (x <= size - 1 and x >= 0 and y - lenghtOfShip + 1 <= size - 1 and y - 1 >= 0 and y - lenghtOfShip + 1 <= size - 1) {
				if (playerBoard[x][y - lenghtOfShip + 1] != '\0') {
					flag = false;
				}
			}
		}
		return flag;
	}
	if (direction == 'd') {
		for (int i = 0;i < lenghtOfShip;i++) {
			//checking wheter that space is avaible
			if ( (x + i) < 0 || (y) < 0 || (x + i) > size - 1 || y > size - 1) {
				flag = false;
				break;
			}
			else {
				if (playerBoard[x + i][y] != '\0') {
					flag = false;
					break;
				}
			}
		}
		if (flag == true) {
			for (int i = 0;i < (lenghtOfShip + 2);i++) {
				if ((x + i) <= size - 1 and (y + 1) <= size - 1 and (x + i) >= 0 and (y + 1) >= 0) {
					if (playerBoard[x + i][y + 1] != '\0')
						flag = false;
						break;
				}
				if ((x + i) <= size - 1 and (y - 1) <= size - 1 and (x + i) >= 0 and (y - 1) >= 0) {
					if (playerBoard[x + i][y - 1] != '\0') {
						flag = false;
						break;
					}
				}
			}
		}
		if (flag == true) {
			if (x <= size -1 and x >= 0 and y - 1 <= size - 1 and y - 1 >= 0 ) {
				if (playerBoard[x][y + 1] != '\0')
					flag = false;
			}
			if (x <= size - 1 and x >= 0 and y - lenghtOfShip + 1 <= size - 1 and y - lenghtOfShip + 1 >= 0 ) {
				if (playerBoard[x][y - lenghtOfShip + 1] != '\0') {
					flag = false;
				}
			}
		}
		return flag;
	}
	if (direction == 'u') {
		for (int i = 0;i < lenghtOfShip;i++) {
			//checking wheter that space is avaible
			if ((x - i) < 0 || (y) < 0 || (x - i) > size - 1 || y > size - 1) {
				flag = false;
				break;
			}
			else{
				if (playerBoard[x - i][y] != '\0') {
					flag = false;
					break;
				}
			}
				
		}
		if (flag == true) {
			for (int i = 0;i < (lenghtOfShip + 2);i++) {
				if ((x - i) <= size - 1 and (y + 1) <= size - 1 and (x - i) >= 0 and (y + 1) >= 0) {
					if (playerBoard[x - i][y + 1] != '\0')
						flag = false;
					break;
				}
				if ((x - i) <= size - 1 and (y - 1) <= size - 1 and (x - i) >= 0 and (y - 1) >= 0) {
					if (playerBoard[x + i][y - 1] != '\0') {
						flag = false;
						break;
					}
				}
			}
		}
		if (flag == true) {
			if (y <= size - 1 and y >= 0 and x + 1 <= size - 1 and x + 1 >= 0) {
				if (playerBoard[x+1][y] != '\0')
					flag = false;
			}
			if (y <= size - 1 and y >= 0 and x + lenghtOfShip - 1 <= size - 1 and x + lenghtOfShip - 1 >= 0) {
				if (playerBoard[x+lenghtOfShip-1][y] != '\0') {
					flag = false;
				}
			}
		}
		return flag;
	}
	
}
void inputSingleShip(char playerBoard[][10], const int size, int coordinate, char z, char c, char name,int lenght) {
	int y = transformChar(z);
	int x = transformInt(coordinate);
	if (validateShipPlacement(playerBoard, size, x, y, c, lenght)) {
		if (c == 'r') {
			for (int i = 0;i < lenght;i++) {
				playerBoard[x][y + i] = name;
			}
		}
		if (c == 'l') {
			for (int i = 0;i < lenght;i++) {
				playerBoard[x][y - i] = name;
			}
		}
		if (c == 'u') {
			for (int i = 0;i < lenght;i++) {
				playerBoard[x - i][y] = name;
			}
		}
		if (c == 'd') {
			for (int i = 0;i < lenght;i++) {
				playerBoard[x + i][y] = name;
			}
		}
	}
}
//cannot use '\0',h,m,s for ship names
void defaultPlacementConfig(char playerBoard[][10], const int size,const int SMALL_SHIP_LENGHT,const int MEDIUM_SHIP_LENGHT,const int LARGE_SHIP_LENGHT,const int MEGA_SHIP_LENGHT) {
	inputSingleShip(playerBoard, size, 1, 'A', 'r', 'a', SMALL_SHIP_LENGHT);
	inputSingleShip(playerBoard, size, 3, 'J', 'd', 'b', SMALL_SHIP_LENGHT);
	inputSingleShip(playerBoard, size, 8, 'A', 'r', 'c', SMALL_SHIP_LENGHT);
	inputSingleShip(playerBoard, size, 6, 'F', 'd', 'd', SMALL_SHIP_LENGHT);
	inputSingleShip(playerBoard, size, 1, 'D', 'd', 'e', MEDIUM_SHIP_LENGHT);
	inputSingleShip(playerBoard, size, 3, 'F', 'l', 'f', MEDIUM_SHIP_LENGHT);
	inputSingleShip(playerBoard, size, 1, 'J', '6', 'g', MEDIUM_SHIP_LENGHT);
	inputSingleShip(playerBoard, size, 3, 'A', 'd', 'i', LARGE_SHIP_LENGHT);
	inputSingleShip(playerBoard, size, 1, 'G', 'r', 'j', LARGE_SHIP_LENGHT);
	inputSingleShip(playerBoard, size, 10, 'E', 'r', 'k', MEGA_SHIP_LENGHT);
}
bool validateCoordinates(int x, char y,const int size) {
	if (x > size - 1 || x < 0 || y < 'A' || y > 'J')
		return false;
	else {
		return true;
	}
}
char randomNameGenerate(char namesOfShips[],const int size) {
	srand(time(nullptr));
	char nameOfShip = 0;
	int randomIndex = 0;
	do {
		 randomIndex = rand() % (size - 1) + 0;
	} while (namesOfShips[randomIndex]!='\0');
	nameOfShip = namesOfShips[randomIndex];
	namesOfShips[randomIndex] = '\0';

	return nameOfShip;

}
void manualPlacementConfig(char playerBoard[][10],const int playerBoardSize,int uniqueShipsWithLenght[],const int uniqueShipSize,char nameOfShips[],const int nameOfShipsSize ){
	int verticalCooordinate = 0;
	char horizontalCoordinate = 0;
	char direction = 0;
	int transformedX = 0;
	int transformedY = 0;
	for (int i = 2;i < uniqueShipSize;) {
		if (uniqueShipsWithLenght[i] != 0) {

			cout << "Enter the starting  the starting coordinates of the ship which has lenght " << i << "\n. In format X Y D where X - vertical coordinate,Y horizontal coordinate and D is direction" << endl;
			cin >> verticalCooordinate >> horizontalCoordinate >> direction;
			if (validateCoordinates(verticalCooordinate, horizontalCoordinate, playerBoardSize)) {
				transformedX = transformInt(verticalCooordinate);
				transformedY = transformChar(horizontalCoordinate);
				char nameOfShip = randomNameGenerate(nameOfShips, nameOfShipsSize);
				if (validateShipPlacement(playerBoard, playerBoardSize, transformedX, transformedY, direction, i)) {
					inputSingleShip(playerBoard, playerBoardSize, verticalCooordinate, horizontalCoordinate, direction, nameOfShip, i);
					uniqueShipsWithLenght[i]--;
					break;
				}
				else {
					cout << "There's either no enough space or the ship goes out of bounds.Please check and try again\n";
					break;
				}
				//clearConsole();
				//printBoard(playerBoard, playerBoardSize);
			}
			else {
				cout << "The coordinates that you've put in are incorrect.Please check and try again.\n";
				break;
			}
		}
	}
}
bool isEmpty(char playerBoard[][10], const int playerBoardSize) {
	for (int i = 0;i < playerBoardSize;i++) {
		for (int j = 0;j < playerBoardSize;j++) {
			if (playerBoard[i][j] != '\0')
				return false;
		}
	}
	return true;
}
bool shipExists(char playerBoard[][10], const int playerBoardSize,char correctShip){
	for (int i = 0;i < playerBoardSize; i++) {
		for (int j = 0;j < playerBoardSize;j++) {
			if (playerBoard[i][j] == correctShip) {
				return true;
			}
		}
	}
	return false;
}
int shipRemovement(char playerBoard[][10], const int playerBoardSize, char shipsName) {//fix this function
	int shipsLenght = 0;
	for (int i = 0;i < playerBoardSize;i++) {
		for (int j = 0;j < playerBoardSize;j++) {
			if (playerBoard[i][j] == shipsName) {
				playerBoard[i][j] = '\0';
				shipsLenght++;
			}
		}
	}
	return shipsLenght;
}
void addNameOfRemovedShip(char namesOfRemovedShips[], const int SIZE_OF_NAMES, char nameOfShip) {
		for (int i = 0;i < SIZE_OF_NAMES;i++) {
			if (namesOfRemovedShips[i] == '\0') {
				namesOfRemovedShips[i] = nameOfShip;
			}
		}
	

}
void shipCorrection(char playerBoard[][10], const int playerBoardSize,int removedShips[],const int SIZE_OF_REMOVED_SHIPS,char namesOfRemovedShips[],const int sizeOfNamesOfRemovedShips) {
	int shipsLenght = 0;
	char correctShip = 0;
	char answer = 0;
	cout << "Would u like to correct the positions of your ships? Enter y for yes and n for no" << endl;
		cin >> answer;
		if (answer == 'y' and !isEmpty(playerBoard, playerBoardSize)) {
			cout << "Enter the ships name in order to correct it." << endl;//name of the ship
			cin >> correctShip;
			if (shipExists(playerBoard, playerBoardSize, correctShip)) {
				shipsLenght = shipRemovement(playerBoard,playerBoardSize,correctShip);
				addNameOfRemovedShip(namesOfRemovedShips, sizeOfNamesOfRemovedShips, correctShip);
				removedShips[shipsLenght]++; 
				//
				//clearConsole();
				//printBoard(playerBoard, playerBoardSize);

			}
			else {

				cout << "Oops!Looks like u dont have a ship with such name" << endl;
			}
		}
}
void ChangeToSunkShip(char playerBoard[][10], const int playerBoardSize, int realVerticalCoordinate, int realHorizontalCoordinate,char hit,char sunk) {
	if (playerBoard[realVerticalCoordinate][realHorizontalCoordinate] == '\0' || playerBoard[realVerticalCoordinate][realHorizontalCoordinate] == sunk) {
		return;
	}
	if (playerBoard[realVerticalCoordinate][realHorizontalCoordinate] == hit) {
		playerBoard[realVerticalCoordinate][realHorizontalCoordinate] = sunk;
	}
	ChangeToSunkShip(playerBoard, playerBoardSize, realHorizontalCoordinate+1, realHorizontalCoordinate, hit, sunk);
	ChangeToSunkShip(playerBoard, playerBoardSize, realHorizontalCoordinate-1, realHorizontalCoordinate, hit, sunk);
	ChangeToSunkShip(playerBoard, playerBoardSize, realHorizontalCoordinate, realHorizontalCoordinate+1, hit, sunk);
	ChangeToSunkShip(playerBoard, playerBoardSize, realHorizontalCoordinate, realHorizontalCoordinate-1, hit, sunk);
}
bool isShipSunken(char playerBoard[][10], const int playerBoardSize, char shipName){
	for (int i = 0;i < playerBoardSize; i++) {
		for (int j = 0;j < playerBoardSize;j++) {
			if (playerBoard[i][j] == shipName) {
				return false;
			}
		}
	}
	return true;
}
char fromIntToChar(int x) {
	char a = 0;
	a = x + 65;
	return a;
}
int transformToReal(int x) {
	int realX = 0;
	realX = x + 1;
	return realX;
}

void shipSunk(char playerBoard[][10], const int playerBoardSize, char shipName) {
	for (int i = 0;i < playerBoardSize;i++) {
		for (int j = 0;j < playerBoardSize;j++) {
			if (playerBoard[i][j] == shipName) {
				return;
			}
		}

	}
	cout << "Congratulations.You've sunk one of your oponent's ships\n";
}

void Attack(char playerBoard[][10], const int playerBoardSize, char hit,char missed,char sunk,bool &flag,int &lastX,char &lastY) {
	int realVerticalCoordinate = 0;
	int realHorizontalCoordinate = 0;
	int verticalCoordinate = 0;
	int horizontalCoordinate = 0;
	int shipName = 0;
	do {
		cin >> verticalCoordinate >> horizontalCoordinate;
		int realVerticalCoordinate = transformInt(verticalCoordinate);
		int realHorizontalCoordinate = transformChar(horizontalCoordinate);
		if (playerBoard[realVerticalCoordinate][realHorizontalCoordinate] == hit || playerBoard[realVerticalCoordinate][realHorizontalCoordinate] == sunk) {
			cout << "You cannot attack a square that's already been  attacked.Please check and try again.\n";
		}
	} while (playerBoard[realVerticalCoordinate][realHorizontalCoordinate] == hit || playerBoard[realVerticalCoordinate][realHorizontalCoordinate] == sunk || playerBoard[realVerticalCoordinate][realHorizontalCoordinate] == missed);
	if (playerBoard[realVerticalCoordinate][realHorizontalCoordinate] == '\0') {
		lastY = fromIntToChar(realHorizontalCoordinate);
		lastX = transformToReal(realHorizontalCoordinate);
		flag = false;
		playerBoard[realVerticalCoordinate][realHorizontalCoordinate] = missed;
		cout << "You've missed.Better luck next time\n";
		return;
	}
	if (playerBoard[realVerticalCoordinate][realHorizontalCoordinate] != missed) {//check if you implement sunk
		flag = true;
		lastY = fromIntToChar(realHorizontalCoordinate);
		lastX = transformToReal(realHorizontalCoordinate);
		shipName = playerBoard[realVerticalCoordinate][realHorizontalCoordinate];
		playerBoard[realVerticalCoordinate][realHorizontalCoordinate] = hit;
		cout << "Congratulations!.You've hit a ship.\n";
		if (isShipSunken(playerBoard, playerBoardSize, shipName)) {
			shipSunk(playerBoard, playerBoardSize, shipName);
			ChangeToSunkShip(playerBoard, playerBoardSize, realVerticalCoordinate, realHorizontalCoordinate, hit, sunk);
		}
	}
}

void AttackFromLastCoordinate(char playerBoard[][10], const int playerBoardSize, int &lastX, char &lastY,char direction,char missed,char hit,char sunk,bool &flag) {
	int realLastX = transformInt(lastX);
	int realLastY = transformChar(lastY);
	char shipName = 0;
	if (direction == 'd') {
		realLastX += 1;
	}
	if (direction == 'u') {
		realLastX -= 1;
	}
	if (direction == 'l') {//check for reallastx and reallasty u have to save them somewhere
		realLastY -= 1;
	}
	if (direction == 'r') {
		realLastY += 1;
	}
	if (realLastX < 0 || realLastX >= playerBoardSize || realLastY < 0 || realLastY >= playerBoardSize) {
		cout << "That square is out of the board.Please check and try again\n";
		return;
	}
	if (playerBoard[realLastX][realLastY] == '\0') {
		lastY = fromIntToChar(realLastY);
		lastX = transformToReal(realLastX);
		flag = false;
		playerBoard[realLastX][realLastY] = missed;

		cout << "You've missed.Better luck next time\n";
		return;
	}
	if (playerBoard[realLastX][realLastY] != missed) {//check if you implement sunk
		lastY = fromIntToChar(realLastY);
		lastX = transformToReal(realLastX);
		flag = true;
		shipName = playerBoard[realLastX][realLastY];
		playerBoard[realLastX][realLastY] = hit;
		cout << "Congratulations!.You've hit a ship.\n";
		if (isShipSunken(playerBoard, playerBoardSize, shipName)) {
			shipSunk(playerBoard, playerBoardSize, shipName);
			ChangeToSunkShip(playerBoard, playerBoardSize, realLastX, realLastY, hit, sunk);
		}
	}

}
void clearBoard(char playerBoard[][10], const int size) {
	for (int i = 0;i < size;i++) {
		for (int j = 0;j < size;j++) {
			playerBoard[i][j] = '\0';
		}
	}
}

int main() {
	const int SHIP_NAMES_SIZE = 10;
	char shipNames[SHIP_NAMES_SIZE] = { 'a', 'b' ,'c' ,'d' ,'e' ,'f' ,'g' ,'i' ,'j','k' };
	const char water = '\0';
	const char hit = 'h';
	const char miss = 'm';
	const char sunk = 's';
	const int MAX_ROWS = 10;
	const int MAX_COLS = 10;
	const int SMALL_SHIP_LENGHT = 2;
	const int MEDIUM_SHIP_LENGHT = 3;
	const int LARGE_SHIP_LENGHT = 4;
	const int MEGA_SHIP_LENGHT = 6;
	const int UNIQUE_SHIPS = 7;
	int uniqueShipsWithLenght[UNIQUE_SHIPS] = { 0,0,4,3,2,0,6 };
	char boardPlayer1[MAX_ROWS][MAX_COLS] = {};
	char boardPlayer2[MAX_ROWS][MAX_COLS] = {};
	return 0;
}