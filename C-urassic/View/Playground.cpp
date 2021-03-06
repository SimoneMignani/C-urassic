#ifndef PLAYGROUND_H
#define PLAYGROUND_H value
#include "../View/Playground.hpp"
#endif

Playground::Playground() {

}

void Playground::loadMap(Map *map) {
	this->map = map;
}

void Playground::refresh() {
	refresh(NULL);
}

void Playground::refresh(char *messageText) {
	int i, j, numStrings;
	MapCharacter *player = this->map->getPlayer();

	/*First thing to do is generate the strings*/
	/*numStrings contains the number of side strings*/
	if (messageText == NULL) numStrings = 0;
		else {
			if (strcmp(messageText, "") == 0) {
				messageText = NULL;
				numStrings = 0;
			}
		 	else numStrings = 1;
		}
	numStrings += 1 //The player status
				+ this->map->numEnemies; //+ the enemies statuses

	char statusString[numStrings][LEFT_BORDER +1];
	/*Let's start from the player*/
	sprintf(statusString[0], "%c has %d lifepoints", *(player->obj), player->lifePoints);
	addSpaces(statusString[0]);


	//Qui ci va il codice dei nemici!
	if (messageText != NULL) {
		addSpaces(messageText);
		strcpy(statusString[numStrings -1], messageText);
	}
	
	for (i = 0; i < HEIGHT; i++) {
		if (numStrings > 0) {
			cout << statusString[--numStrings];
		} else {
			for (j = 0; j < LEFT_BORDER; j++){
				cout << ' ';
			}
		}
		for (j = 0; j < LENGHT; j++) {
			cout << map->matrix[i][j];
		}
		cout << endl;
	}
}

void Playground::addSpaces(char *c) {
	//Calculate how much spaces to add at left and right
	int i, spacesLR;
	char spc[spacesLR +1], cc[LEFT_BORDER];

	spacesLR  = (LEFT_BORDER - strlen(c)) /2;
	for (i = 0; i < spacesLR; i++) {
		spc[i] = ' ';
	}

	spc[spacesLR] = '\0';
	strcpy(cc, c);
	sprintf(c, "%s%s%s", spc, cc, spc);

}