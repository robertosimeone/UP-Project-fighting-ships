#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;
const int MAX_ROWS = 10;
const int MAX_COLS = 10;
const int SMALL_SHIP_LENGHT = 2;
const int MEDIUM_SHIP_LENGHT = 3;
const int LARGE_SHIP_LENGHT = 4;
const int MEGA_SHIP_LENGHT = 6;
char boardPlayer1[MAX_ROWS][MAX_COLS] = {};
char boardPlayer2[MAX_ROWS][MAX_COLS] = {};
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
void defaultPlacementConfig(char playerBoard[][10], const int size) {
	inputSingleShip(playerBoard, size, 1, 'A', 'r', 'a', SMALL_SHIP_LENGHT);
	inputSingleShip(playerBoard, size, 3, 'J', 'd', 'b', SMALL_SHIP_LENGHT);
	inputSingleShip(playerBoard, size, 8, 'A', 'r', 'c', SMALL_SHIP_LENGHT);
	inputSingleShip(playerBoard, size, 6, 'F', 'd', 'd', SMALL_SHIP_LENGHT);
	inputSingleShip(playerBoard, size, 1, 'A', 'r', 'e', MEDIUM_SHIP_LENGHT);
	inputSingleShip(playerBoard, size, 1, 'A', 'r', 'f', MEDIUM_SHIP_LENGHT);
	inputSingleShip(playerBoard, size, 1, 'A', 'r', 'g', MEDIUM_SHIP_LENGHT);
	inputSingleShip(playerBoard, size, 1, 'A', 'r', 'h', LARGE_SHIP_LENGHT);
	inputSingleShip(playerBoard, size, 1, 'A', 'r', 'i', LARGE_SHIP_LENGHT);
	inputSingleShip(playerBoard, size, 1, 'A', 'r', 'j', MEGA_SHIP_LENGHT);
}
int TransformInt(int z) {
	int x = 0;
	x = z - 1;
	return x;
}
int  TransformChar(char y) {
	if (y == 'A') {
		return 0;
	}
	else if (y == 'B') {
		return 1;
	}
	else if (y == 'C') {
		return 2;
	}
	else if (y == 'D') {
		return 3;
	}
	else if (y == 'E') {
		return 4;
	}
	else if (y == 'F') {
		return 5;
	}
	else if (y == 'G') {
		return 6;
	}
	else if (y == 'H') {
		return 7;
	}
	else if (y == 'I') {
		return 8;
	}
	else if (y == 'J') {
		return 9;
	}
}
void inputSingleShip(char playerBoard[][10],const int size,int coordinate, char z, char c,char name,const int lenght) {
	int y = TransformChar(z);
	int x = TransformInt(coordinate);
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
			if (playerBoard[x][y - i] != '\0' || x<0 || (y - i) < 0 || x > size - 1 || (y - i)>size - 1) {
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
			if (playerBoard[x + i][y] != '\0' || (x + i) < 0 || (y) < 0 || (x + i) > size - 1 || y > size - 1) {
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
void clearBoard(char playerBoard[][10], const int size) {
	for (int i = 0;i < size;i++) {
		for (int j = 0;j < size;j++) {
			playerBoard[i][j] = '\0';
		}
	}
}
int main() {
	const int MAX_ROWS = 10;
	const int MAX_COLS = 10;
	char c   = 0;
	cin >> c;
	if (c == 'c') {
		
		clearConsole();
	}
	return 0;
}