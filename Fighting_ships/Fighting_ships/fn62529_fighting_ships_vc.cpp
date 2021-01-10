#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
void centerFromSide(int x) {
	cout << "\n";
	for (int i = 0;i < x;i++) {
		cout << " ";
	}
}
void centerFromTop() {
	for (int i = 0;i < 20;i++) {
		cout << "\n";
	}
}
void printBoard(char playerBoard[][10], const int size) {
	system("cls");//
	for (int i = 0;i < 8;i++) {
		cout << endl;
	}
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
void printAttackingPhaseMatrix(char playerBoard[][10], const int playerBoardSize, const char hit, const char miss, const char blank) {
	system("cls");//
	char symbol = '\0';
	for (int i = 0;i < 8;i++) {
		cout << endl;
	}
	cout << setw(70);
	for (int i = 0;i < playerBoardSize + 1;i++) {
		cout << char(201) << char(205) << char(205) << char(205) << char(187);
	}
	cout << endl;
	cout << setw(70);
	for (int i = 0;i < playerBoardSize + 1;i++) {
		if (i == 0) {
			cout << char(186) << " " << (char)0 << " " << char(186);
		}
		else {
			cout << char(186) << " " << (char)(64 + i) << " " << char(186);
		}
	}
	cout << endl;
	cout << setw(70);
	for (int i = 0;i < playerBoardSize + 1;i++) {
		cout << char(200) << char(205) << char(205) << char(205) << char(188);
	}
	cout << endl;
	for (int j = 0;j < playerBoardSize;j++) {
		cout << setw(70);
		for (int i = 0;i < playerBoardSize + 1;i++) {
			cout << char(201) << char(205) << char(205) << char(205) << char(187);
		}
		cout << endl;
		cout << setw(70);
		for (int i = 0;i < playerBoardSize + 1;i++) {
			if (i == 0) {
				if (j + 49 == 58) {
					cout << char(186) << setw(1) << "10" << " " << char(186);
				}
				else {
					cout << char(186) << " " << (char)(j + 49) << " " << char(186);
				}
			}
			else {
				if (playerBoard[j][i - 1] == hit) {
					symbol = hit;
				}
				else if (playerBoard[j][i - 1] == miss) {
					symbol = miss;
				}
				else {
					symbol = '-';
				}

				cout << char(186) << " " << symbol << " " << char(186);
			}
		}
		cout << endl;
		cout << setw(70);
		for (int i = 0;i < playerBoardSize + 1;i++) {
			cout << char(200) << char(205) << char(205) << char(205) << char(188);
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
					if (playerBoard[x - 1][y - 1 + i] != '\0') {
						flag = false;
						break;
					}
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
			if (x <= size - 1 and x >= 0 and y - 1 <= size - 1 and y - 1 >= 0 ) {
				if (playerBoard[x][y - 1] != '\0') {
					flag = false;
				}
			}
			if (y + lenghtOfShip  >= 0 and y + lenghtOfShip  <= size - 1 and x <= size - 1 and x >= 0) {
				if (playerBoard[x][y + lenghtOfShip ] != '\0') {
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
					if (playerBoard[x - 1][y + 1 - i] != '\0') {
						flag = false;
						break;
					}
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
			if (x <= size - 1 and x >= 0 and y + 1 <= size - 1 and y + 1 >= 0) {
				if (playerBoard[x][y + 1] != '\0') {
					flag = false;
				}
			}
			if (x <= size - 1 and x >= 0 and y - lenghtOfShip  <= size - 1  and y - lenghtOfShip  >= 0) {
				if (playerBoard[x][y - lenghtOfShip] != '\0') {
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
				if ((x + i-1) <= size - 1 and (y + 1) <= size - 1 and (x + i- 1) >= 0 and (y + 1) >= 0) {
					if (playerBoard[x + i - 1][y + 1] != '\0') {
						flag = false;
						break;
					}
				}
				if ((x + i - 1) <= size - 1 and (y - 1) <= size - 1 and (x + i - 1) >= 0 and (y - 1) >= 0) {
					if (playerBoard[x + i - 1][y - 1] != '\0') {
						flag = false;
						break;
					}
				}
			}
		}
		if (flag == true) {
			if (x - 1 <= size - 1 and x - 1 >= 0 and y <= size - 1 and y >= 0) {
				if (playerBoard[x - 1][y] != '\0') {
					flag = false;
				}
			}
			if (y <= size - 1 and y >= 0 and x + lenghtOfShip <= size - 1 and x + lenghtOfShip >= 0 ) {
				if (playerBoard[x + lenghtOfShip][y] != '\0') {
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
				if ((x - i+1) <= size - 1 and (y + 1) <= size - 1 and (x - i+1) >= 0 and (y + 1) >= 0) {
					if (playerBoard[x - i + 1][y + 1] != '\0') {
						flag = false;
						break;
					}
				}
				if ((x - i+1) <= size - 1 and (y - 1) <= size - 1 and (x - i+1) >= 0 and (y - 1) >= 0) {
					if (playerBoard[x - i + 1][y - 1] != '\0') {
						flag = false;
						break;
					}
				}
			}
		}
		if (flag == true) {
			if (y <= size - 1 and y >= 0 and x + 1 <= size - 1 and x + 1 >= 0) {
				if (playerBoard[x + 1][y] != '\0') {
					flag = false;
				}
			}
			if (y <= size - 1 and y >= 0 and x - lenghtOfShip <= size - 1 and x - lenghtOfShip >= 0) {
				if (playerBoard[x-lenghtOfShip][y] != '\0') {
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
	inputSingleShip(playerBoard, size, 3, 'D', 'u', 'e', MEDIUM_SHIP_LENGHT);
	inputSingleShip(playerBoard, size, 3, 'F', 'r', 'f', MEDIUM_SHIP_LENGHT);
	inputSingleShip(playerBoard, size, 6, 'J', 'd', 'g', MEDIUM_SHIP_LENGHT);
	inputSingleShip(playerBoard, size, 3, 'A', 'd', 'i', LARGE_SHIP_LENGHT);
	inputSingleShip(playerBoard, size, 1, 'G', 'r', 'j', LARGE_SHIP_LENGHT);
	inputSingleShip(playerBoard, size, 10, 'E', 'r', 'k', MEGA_SHIP_LENGHT);
}
bool validateCoordinates(int x, char y,const int size) {
	if (x > size || x < 0 || y < 'A' || y > 'J') {
		return false;
	}
	
		return true;

}
char shipNameGenerator(char namesOfShips[],const int size) {
	char nameOfShip = 0;
	for (int i = 0;i < size;i++) {
		if (namesOfShips[i] != '\0') {
			nameOfShip = namesOfShips[i];
			namesOfShips[i] = '\0';
			break;
		}
	}

	return nameOfShip;

}
void manualPlacementConfig(char playerBoard[][10],const int playerBoardSize,int uniqueShipsWithLenght[],const int uniqueShipSize,char nameOfShips[],const int nameOfShipsSize,const int center){
	int verticalCooordinate = 0;
	char horizontalCoordinate = 0;
	char direction = 0;
	int transformedX = 0;
	int transformedY = 0;
	for (int i = 2;i < uniqueShipSize;) {
		if (uniqueShipsWithLenght[i] != 0) {
			centerFromSide(center);
			cout << "Enter the starting coordinates of the ship which has lenght " << i;
			centerFromSide(center);
		    cout<< ". In format X Y d where X - vertical coordinate,Y horizontal coordinate and D is direction\n";
			cin >> verticalCooordinate >> horizontalCoordinate >> direction;
			if (validateCoordinates(verticalCooordinate, horizontalCoordinate, playerBoardSize)) {
				transformedX = transformInt(verticalCooordinate);
				transformedY = transformChar(horizontalCoordinate);
				if (validateShipPlacement(playerBoard, playerBoardSize, transformedX, transformedY, direction, i)) {
					char nameOfShip = shipNameGenerator(nameOfShips, nameOfShipsSize);
					inputSingleShip(playerBoard, playerBoardSize, verticalCooordinate, horizontalCoordinate, direction, nameOfShip, i);
					centerFromSide(center);
					cout << "Congratulations!You've placed a ship!\n";
					centerFromSide(center);
					system("pause");
					uniqueShipsWithLenght[i]--;
					break;
				}
				else {
					centerFromSide(center);
					cout << "There's either no enough space or the ship goes out of bounds.Please check and try again\n";
					centerFromSide(center);
					system("pause");
					break;

				}
				//clearConsole();
				//printBoard(playerBoard, playerBoardSize);
			}
			else {
				centerFromSide(center);
				cout << "The coordinates that you've put in are incorrect.Please check and try again.\n";
				centerFromSide(center);
				system("pause");
		
			}
		}
		else {
			i++;
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
void shipCorrection(char playerBoard[][10], const int playerBoardSize,int removedShips[],const int SIZE_OF_REMOVED_SHIPS,char namesOfRemovedShips[],const int sizeOfNamesOfRemovedShips,const int center) {
	int shipsLenght = 0;
	char correctShip = 0;
	char answer = 0;
	centerFromSide(center);
	cout << "Would u like to correct the positions of your ships? Enter y for yes and n for no\n" << endl;
		cin >> answer;
		if (answer == 'y' and !isEmpty(playerBoard, playerBoardSize)) {
			centerFromSide(center);
			cout << "Enter the ships name in order to correct it." << endl;//name of the ship
			cin >> correctShip;
			if (shipExists(playerBoard, playerBoardSize, correctShip)) {
				shipsLenght = shipRemovement(playerBoard,playerBoardSize,correctShip);
				addNameOfRemovedShip(namesOfRemovedShips, sizeOfNamesOfRemovedShips, correctShip);
				removedShips[shipsLenght]++; 
				centerFromSide(center);
				cout << "You have successfully removed the ship witht name" << correctShip << endl;
				centerFromSide(center);
				system("pause");
				//
				//clearConsole();
				//printBoard(playerBoard, playerBoardSize);

			}
			else {
				centerFromSide(center);
				cout << "Oops!Looks like u dont have a ship with such name" << endl;
			}
		}
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


void Attack(char playerBoard[][10], const int playerBoardSize, char hit,char missed,const char blank,bool &flag,int &lastX,char &lastY,const int center) {
	int realVerticalCoordinate = 0;
	int realHorizontalCoordinate = 0;
	int verticalCoordinate = 0;
	char horizontalCoordinate = 0;
	char shipName = 0;
	printAttackingPhaseMatrix(playerBoard, playerBoardSize, hit, missed, blank);
	centerFromSide(center);
	cout << "Enter coordinates on the board in order to make your attack\n";
	cin >> verticalCoordinate >> horizontalCoordinate;
	if (validateCoordinates(verticalCoordinate, horizontalCoordinate,playerBoardSize)) {

		realVerticalCoordinate = transformInt(verticalCoordinate);
		realHorizontalCoordinate = transformChar(horizontalCoordinate);
		if (playerBoard[realVerticalCoordinate][realHorizontalCoordinate] == hit) {
			centerFromSide(center);
			cout << "You cannot attack a square that's already been  attacked.Please check and try again.\n";
			centerFromSide(center);
			system("pause");
			clearConsole();
		}
		else if (playerBoard[realVerticalCoordinate][realHorizontalCoordinate] == missed) {
			centerFromSide(center);
			cout << "You cannot attack a square that's already been  attacked.Please check and try again.\n";
			centerFromSide(center);
			system("pause");
			clearConsole();
		}
		else if (playerBoard[realVerticalCoordinate][realHorizontalCoordinate] == '\0') {
			lastY = fromIntToChar(realHorizontalCoordinate);
			lastX = transformToReal(realVerticalCoordinate);
			flag = false;
			playerBoard[realVerticalCoordinate][realHorizontalCoordinate] = missed;
			clearConsole();
			printAttackingPhaseMatrix(playerBoard, playerBoardSize, hit, missed, blank);
			centerFromSide(center);
			cout << "You've missed.Better luck next time\n";
			centerFromSide(center);
			system("pause");
			clearConsole();
		}
		else {//check if you implement sunk
			flag = true;
			lastY = fromIntToChar(realHorizontalCoordinate);
			lastX = transformToReal(realVerticalCoordinate);
			shipName = playerBoard[realVerticalCoordinate][realHorizontalCoordinate];
			playerBoard[realVerticalCoordinate][realHorizontalCoordinate] = hit;
			clearConsole();
			printAttackingPhaseMatrix(playerBoard, playerBoardSize, hit, missed, blank);
			centerFromSide(center);
			cout << "Congratulations!.You've hit a ship.\n";
			if (isShipSunken(playerBoard, playerBoardSize, shipName)) {
				cout << "\n\t\t\tCongratulations!You have sunk one of your oponents ships.\n";
			}
			centerFromSide(center);///////////////////////////////////////////////////
			system("pause");
			clearConsole();
		}
	}
	else {
		cout << "\n\t\t\tLooks like you've entered invalid coordinates.Please check and try again\n";
		centerFromSide(center);
		system("pause");
		clearConsole();
	}
}

void AttackFromLastCoordinate(char playerBoard[][10], const int playerBoardSize, int &lastX, char &lastY,const char missed,const char hit,const char blank,bool &flag,const int center) {
	printAttackingPhaseMatrix(playerBoard, playerBoardSize, hit, missed, blank);
	int realLastX = transformInt(lastX);
	int realLastY = transformChar(lastY);
	char direction = 0;
	char shipName = 0;
	centerFromSide(center);
	cout << "Enter a direction coresponding to your last hit square\n";
	cin >> direction;
	if (direction != 'd' and direction != 'u' and direction != 'l' and direction != 'r') {
		centerFromSide(center);
		cout << "Looks like you've entered an invalid direction\n";
		centerFromSide(center);
		system("pause");
		clearConsole();
		return;
	}
	else if (direction == 'd') {
		realLastX += 1;
	}
	else if (direction == 'u') {
		realLastX -= 1;
	}
	else if (direction == 'l') {//check for reallastx and reallasty u have to save them somewhere
		realLastY -= 1;
	}
	else if (direction == 'r') {
		realLastY += 1;
	}
	if (realLastX < 0 || realLastX >= playerBoardSize || realLastY < 0 || realLastY >= playerBoardSize) {
		centerFromSide(center);
		cout << "That square is out of the board.Please check and try again\n";
		centerFromSide(center);
		system("pause");
		clearConsole();
		return;
	}
	else if (playerBoard[realLastX][realLastY] == missed) {
		centerFromSide(center);
		cout << "You cannot attack a square that's already been  attacked.Please check and try again.\n";
		centerFromSide(center);
		system("pause");
		clearConsole();

	}
	else if (playerBoard[realLastX][realLastY] == hit) {
		centerFromSide(center);
		cout << "You cannot attack a square that's already been  attacked.Please check and try again.\n";
		centerFromSide(center);
		system("pause");
		clearConsole();
	}
	else if (playerBoard[realLastX][realLastY] == '\0') {
		lastY = fromIntToChar(realLastY);
		lastX = transformToReal(realLastX);
		flag = false;
		playerBoard[realLastX][realLastY] = missed;
		clearConsole();
		printAttackingPhaseMatrix(playerBoard, playerBoardSize, hit, missed, blank);
		centerFromSide(center);
		cout << "You've missed.Better luck next time\n";
		centerFromSide(center);
		system("pause");
		clearConsole();
		return;
	}
	else {//check if you implement sunk
		lastY = fromIntToChar(realLastY);
		lastX = transformToReal(realLastX);
		flag = true;
		shipName = playerBoard[realLastX][realLastY];
		playerBoard[realLastX][realLastY] = hit;
		clearConsole();
		printAttackingPhaseMatrix(playerBoard, playerBoardSize, hit, missed, blank);
		centerFromSide(center);
		cout << "Congratulations!.You've hit a ship.\n";
		if (isShipSunken(playerBoard, playerBoardSize, shipName)) {
			centerFromSide(center);
			cout << "Congratulations!You have sunk one of your oponents ships.\n";
		}
		centerFromSide(center);
		system("pause");
	}

}
void clearBoard(char playerBoard[][10], const int size) {
	for (int i = 0;i < size;i++) {
		for (int j = 0;j < size;j++) {
			playerBoard[i][j] = '\0';
		}
	}
}
bool gameWon(char playerBoard[][10], const int playerBoardSize) {
	for (int i = 0;i < playerBoardSize;i++) {
		for (int j = 0;j < playerBoardSize;j++) {
			if (playerBoard[i][j] >= 'a' and playerBoard[i][j] <= 'k') {
				return false;
			}
		}
	}
	return true;
}
bool allShipsPlaced(int playerRemovedShips[], const int sizeOfRemovedShips) {
	for (int i = 0;i < sizeOfRemovedShips;i++) {
		if (playerRemovedShips[i] != 0) {
			return false;
			}
	}
	return true;
}

int main() {
	const int MAX_ROWS = 10;
	const int MAX_COLS = 10;
	char player1Board[MAX_ROWS][MAX_COLS] = {};
	char player2Board[MAX_ROWS][MAX_COLS] = {};
	const int SHIP_NAMES_SIZE = 10;
	char player1ShipNames[SHIP_NAMES_SIZE] = { 'a', 'b' ,'c' ,'d' ,'e' ,'f' ,'g' ,'i' ,'j','k' };
	char player2ShipNames[SHIP_NAMES_SIZE] = { 'a', 'b' ,'c' ,'d' ,'e' ,'f' ,'g' ,'i' ,'j','k' };
	const int UNIQUE_SHIPS = 7;
	int player1RemovedShips[UNIQUE_SHIPS] = { 0,0,4,3,2,0,1};
	int player2RemovedShips[UNIQUE_SHIPS] = { 0,0,4,3,2,0,1};
	bool player1Turn = true;
	bool player2Turn = true;
	int player1LastX = -1;
	char player1LastY = '\0';
	int player2LastX = -1;
	char player2LastY = '\0';
	const char water = '\0';
	const char hit = 'H';
	const char miss = 'M';
	const char blank = '-';
	const int SMALL_SHIP_LENGHT = 2;
	const int MEDIUM_SHIP_LENGHT = 3;
	const int LARGE_SHIP_LENGHT = 4;
	const int MEGA_SHIP_LENGHT = 6;
	int numberOfShipsPlaced = 0;
	char option = 0;
	int verticalCoordinate = 0;
	char horizontalCoordinate = 0;
	char direction = 0;
	bool GameWon = 0;
	const int center = 50;
	//PLAYER1 entering ships
	centerFromTop();
	centerFromSide(center);
	cout << "Welcome to the battleship game,Player 1!Lets get you started\n";
	centerFromSide(center);
	system("pause");
	clearConsole();
	centerFromTop();
	centerFromSide(center);
	cout << "How would you like to place your ships\n";
	centerFromSide(center);
	cout << "1.By our auto config.\n";
	centerFromSide(center);
	cout<<"2.Manually\n";
	centerFromSide(center);
	cout << "Enter 1  or 2\n";
	cin >> option;
	if (option == '1') {
		defaultPlacementConfig(player1Board, MAX_ROWS, SMALL_SHIP_LENGHT, MEDIUM_SHIP_LENGHT, LARGE_SHIP_LENGHT, MEGA_SHIP_LENGHT);
		centerFromSide(center);
		cout << "You have successfully looaded our auto configuration!Have fun!\n";
		centerFromSide(center);
		system("pause");
		clearConsole();
		printBoard(player1Board, MAX_ROWS);
		centerFromSide(center);
		cout << "This is how your board looks like!\n";
		centerFromSide(center);
		system("pause");
		clearConsole();
	}
	else {
		do {
			clearConsole();
			if (allShipsPlaced(player1RemovedShips, UNIQUE_SHIPS)) {
				centerFromSide(center);
				cout << "Congratulations!You've successfully placed all your ships!.Would you like to continue to the battle phase?Enter y for yes and n for no\n";
				cin >> option;
				if (option == 'y') {
					break;
				}

			}
			centerFromSide(center);
			cout << "What do you want to do? :\n";
			centerFromSide(center);
			cout << "1.Place another ship.\n";
			centerFromSide(center);
			cout << "2.Remove a ship.\n";
			centerFromSide(center);
			cout<<"3.View the current state of your board.\n";
			centerFromSide(center);
			cout << "Enter 1 for first option,2 for second option and 3 for 3rd option\n";
			cin >> option;
			if (option == '1') {
				clearConsole();
				if (allShipsPlaced(player1RemovedShips,UNIQUE_SHIPS) == false) {
					manualPlacementConfig(player1Board, MAX_ROWS, player1RemovedShips, UNIQUE_SHIPS, player1ShipNames, SHIP_NAMES_SIZE,center);
				}

				else {
					centerFromSide(center);
					cout << "Sorry, looks like you've placed all the ships already.Try removing one.\n";
					centerFromSide(center);
					system("pause");
				}
			}
			if (option == '2'){
				clearConsole();
				if (isEmpty(player1Board, MAX_ROWS)) {
					centerFromSide(center);
					cout << "That option is currently not avaible since you dont have any ships\n";
					centerFromSide(center);
					system("pause");
				}
				else {
					shipCorrection(player1Board, MAX_ROWS, player1RemovedShips, UNIQUE_SHIPS, player1ShipNames, SHIP_NAMES_SIZE,center);
				}

			}
			if (option == '3') {
				clearConsole();
				printBoard(player1Board, MAX_ROWS);
				centerFromSide(center);
				cout << "This is how your board looks like to this moment!\n";
				centerFromSide(center);
				system("pause");
			}

		} while (true);
	}
	centerFromTop();
	centerFromSide(center);
	cout << "Welcome to the battleship game,Player 2!";
	centerFromSide(center);
	cout<<"Lets get you started\n";
	centerFromSide(center);
	system("pause");
	clearConsole();
	centerFromTop();
	centerFromSide(center);
	cout << "How would you like to place your ships";
	centerFromSide(center);
	cout << "1.By our auto config.";
	centerFromSide(center);
	cout<<"2.Manually\n";
	centerFromSide(center);
	cout << "Enter 1  or 2\n";
	cin >> option;
	//PLAYER2 enterting ships//////////////////////////////////////////////////////////////////////////////////////////////
	if (option == '1') {
		defaultPlacementConfig(player2Board, MAX_ROWS, SMALL_SHIP_LENGHT, MEDIUM_SHIP_LENGHT, LARGE_SHIP_LENGHT, MEGA_SHIP_LENGHT);
		centerFromSide(center);
		cout << "You have successfully looaded our auto configuration!Have fun!\n";
		centerFromSide(center);
		system("pause");
		clearConsole();
		printBoard(player1Board, MAX_ROWS);
		centerFromSide(center);
		cout << "This is how your board looks like!\n";
		centerFromSide(center);
		system("pause");
		clearConsole();
	}
	else {
		do {
			clearConsole();
			if (allShipsPlaced(player2RemovedShips, UNIQUE_SHIPS)) {
				centerFromSide(center);
				cout << "Congratulations!You've successfully placed all your ships!.Would you like to continue to the battle phase?Enter y for yes and n for no\n";
				cin >> option;
				if (option == 'y') {
					break;
				}

			}
			centerFromSide(center);
			cout << "What do you want to do?:\n\t1.Place another ship.\n\t2.Remove a ship.\n\t3.View the current state of your board.\n";
			centerFromSide(center);
			cout << "Enter 1 for first option,2 for second option and 3 for 3rd option\n";
			cin >> option;
			if (option == '1') {
				clearConsole();
				if (allShipsPlaced(player2RemovedShips, UNIQUE_SHIPS == false)) {
					manualPlacementConfig(player2Board, MAX_ROWS, player2RemovedShips, UNIQUE_SHIPS, player2ShipNames, SHIP_NAMES_SIZE,center);
				}

				else {
					centerFromSide(center);
					cout << "Sorry, looks like you've placed all the ships already.Try removing one.\n";
					centerFromSide(center);
					system("pause");
				}
			}
			if (option == '2') {
				clearConsole();
				if (isEmpty(player2Board, MAX_ROWS)) {
					centerFromSide(center);
					cout << "That option is currently not avaible since you dont have any ships\n";
					centerFromSide(center);
					system("pause");
				}
				else {
					shipCorrection(player2Board, MAX_ROWS, player2RemovedShips, UNIQUE_SHIPS, player2ShipNames, SHIP_NAMES_SIZE,center);
				}

			}
			if (option == '3') {
				clearConsole();
				printBoard(player2Board, MAX_ROWS);
				centerFromSide(center);
				cout << "This is how your board looks like to this moment!\n";
				centerFromSide(center);
				system("pause");
			}

		} while (true);
	}
	//attacking phase///////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	centerFromTop();
	centerFromSide(center);
	cout << "Congratulations!You've reached the attacking phase.Try to  take down all oponent's ships\n";
	centerFromTop();
	centerFromSide(center);
	system("pause");
	do {
		player1Turn = true;
		player2Turn = true;
		if (GameWon) {
			break;
		}
		do {
			clearConsole();
			centerFromTop();
			centerFromSide(center);
			cout << "Hello Player 1.You have two attacking options:\n\t1.Attack with new coordinates.\n\t2.Attack according to last coordinates - in this case you have to input direction\n";
			cin >> option;
			clearConsole();
			if (option == '1') {
				Attack(player2Board, MAX_ROWS, hit, miss,blank, player1Turn, player1LastX, player1LastY,center);
			}
			if (option == '2') {
				if (player1LastX != -1 and player1LastY != '\0') {
					centerFromSide(center);
					cout << "tEnter direction according to your last hit square\n";
					centerFromSide(center);
					cout << "Your last hit square was : " << player1LastX << " " << player1LastY << endl;
					AttackFromLastCoordinate(player2Board, MAX_ROWS, player1LastX, player1LastY, miss, hit,blank, player1Turn,center);
				}
				else {
					centerFromSide(center);
					cout << "Oops.Looks like there are no previous coordinates.\n";
					centerFromSide(center);
					system("pause");
				}
			}
			if (gameWon(player2Board, MAX_ROWS)) {
				centerFromSide(center);
				cout << "Congratulations Player 1.You have won the game\n";
				centerFromSide(center);
				system("pause");
				bool GameWon = 1;
				break;
			}
			
			
		} while(player1Turn);
		if (GameWon) {
			break;
		}
		do {
			centerFromSide(center);
			cout << "Hello Player 2.You have two attacking options:\n\t1.Attack with new coordinates.\n\t2.Attack according to last coordinates - in this case you have to input direction\n";
			cin >> option;
			clearConsole();
			if (option == '1') {
				Attack(player1Board, MAX_ROWS, hit, miss,blank, player2Turn, player2LastX, player2LastY,center);
			}
			if (option == '2') {
				if (player2LastX != -1 and player2LastY != '\0') {
					centerFromSide(center);
					cout << "Enter direction according to your last hit square\n";
					centerFromSide(center);
					cout << "Your last hit square was" << player2LastX << " " << player2LastY << endl;
					AttackFromLastCoordinate(player1Board, MAX_ROWS, player2LastX, player2LastY, miss, hit,blank, player2Turn,center);
				}
				else {
					centerFromSide(center);
					cout << "Oops.Looks like there are no previous coordinates.\n";
					centerFromSide(center);
					system("pause");
				}
			}
			if (gameWon(player1Board, MAX_ROWS)) {
				centerFromSide(center);
				cout << "Congratulations Player 2.You have won the game\n";
				system("pause");
				bool GameWon = 1;
				break;
			}
		} while (player2Turn);
	}while(true);
	clearConsole();
	centerFromTop();
	centerFromSide(center);
	cout << "That was the end of the game.Thanks for playing\n";
	return 0;

	//validate input for coordinates
}  