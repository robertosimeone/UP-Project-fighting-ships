#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
void printBoard(char playerBoard[][10], const int SIZE) {
	for (int i = 0;i < SIZE;i++) {
		for (int j = 0;j < SIZE;j++) {
			cout << setw(3) << playerBoard[i][j];
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
	return (int)(y - 64);
}


void inputShips() {

}
bool validateShipPlacement(char playerBoard[][10], const int size, int x, int y, char c, const int lenght) {
	bool flag = true;
	if (c == 'r') {
		for (int i = 0;i < lenght;i++) {
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
			for (int i = 0;i < (lenght + 2);i++) {
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
			if (x <= size - 1 and x >= 0 and y - 1 <= size - 1 and y - 1 >= 0 and y - 1 + lenght <= size - 1) {
				if (playerBoard[x][y - 1] != '\0')
					flag = false;
			}
			if ((y + lenght - 1) >= 0 and (y + lenght - 1 <= size - 1) and x <= size - 1 and x >= 0) {
				if (playerBoard[x][y + lenght - 1] != '\0') {
					flag = false;
				}
			}
		}
		return flag;
	}
	if (c == 'l') {
		for (int i = 0;i < lenght;i++) {
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
			for (int i = 0;i < (lenght + 2);i++) {
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
			if (x <= size - 1 and x >= 0 and y - lenght + 1 <= size - 1 and y - 1 >= 0 and y - lenght + 1 <= size - 1) {
				if (playerBoard[x][y - lenght + 1] != '\0') {
					flag = false;
				}
			}
		}
		return flag;
	}
	if (c == 'd') {
		for (int i = 0;i < lenght;i++) {
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
			for (int i = 0;i < (lenght + 2);i++) {
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
			if (x <= size - 1 and x >= 0 and y - lenght + 1 <= size - 1 and y - lenght + 1 >= 0 ) {
				if (playerBoard[x][y - lenght + 1] != '\0') {
					flag = false;
				}
			}
		}
		return flag;
	}
	if (c == 'u') {
		for (int i = 0;i < lenght;i++) {
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
			for (int i = 0;i < (lenght + 2);i++) {
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
			if (y <= size - 1 and y >= 0 and x + lenght - 1 <= size - 1 and x + lenght - 1 >= 0) {
				if (playerBoard[x+lenght-1][y] != '\0') {
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
	srand(time(NULL));
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
			do {
				cout << "Enter the starting  the starting coordinates of the ship which has lenght " << i << "\n. In format X Y D where X - vertical coordinate,Y horizontal coordinate and D is direction" << endl;
				cout << "Enter valid coordinates!";
				cin >> verticalCooordinate >> horizontalCoordinate >> direction;

			}while (!validateCoordinates(verticalCooordinate, horizontalCoordinate, playerBoardSize));
			transformedX = transformInt(verticalCooordinate);
			transformedY = transformChar(horizontalCoordinate);
			int nameOfShip = randomNameGenerate(nameOfShips, nameOfShipsSize);
			if (validateShipPlacement(playerBoard, playerBoardSize, transformedX, transformedY, nameOfShip, i)) {
				inputSingleShip(playerBoard, playerBoardSize, verticalCooordinate, horizontalCoordinate,direction, nameOfShip,i);
				uniqueShipsWithLenght[i]--;
			}
			clearConsole();
			printBoard(playerBoard, playerBoardSize);
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
bool shipOnSquare(char playerBoard[][10], const int playerBoardSize, int verticalCoordinate, char horizontalCoordinate){
	int x = transformInt(verticalCoordinate);
	int y = transformChar(horizontalCoordinate);
	if (playerBoard[x][y] != '\0') {
		return true;
	}
	return false;
}
void shipRemovement(char playerBoard[][10], const int playerBoardSize, int verticalCoordinate, int horizontalCoordinate,int removedShips[],const  int SIZE_OF_REMOVED_SHIPS) {
	int counter = 0;
	if (playerBoard[verticalCoordinate][horizontalCoordinate] != '\0') {
		counter++;
	}
	else {
		return;
	}
	playerBoard[verticalCoordinate][horizontalCoordinate] == '\0';
	
}
void shipCorrection(char playerBoard[][10], const int playerBoardSize,int removedShips[],const int SIZE_OF_REMOVED_SHIPS) {
	char answer = 0;
	int verticalCoordinate = 0;
	char horizontalCoordinate = 0;
	cout << "Would u like to correct the positions of your ships? Enter y for yes and n for no" << endl;
	do {
		cin >> answer;
		if (answer == 'y' and !isEmpty(playerBoard, playerBoardSize)) {
			cout << "Enter one of the coordinates of the ship that u want to correct." << endl;
			cin >> verticalCoordinate >> horizontalCoordinate;
			if (shipOnSquare(playerBoard, playerBoardSize, verticalCoordinate, horizontalCoordinate)) {

				//
				printBoard(playerBoard, playerBoardSize);

			}
			else {
				cout << "Oops!Looks like u dont have a ship there." << endl;
			}
		}
		else {
			break;
		}
		
	} while (answer == 'y');

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