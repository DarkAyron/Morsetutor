/*____________________________________________________,8_________________
 ___________________________________________________,d8*_________________
 _________________________________________________,d88**_________________
 _______________________________________________,d888`**_________________
 ____________________________________________,d888`****__________________
 ___________________________________________,d88`******__________________
 _________________________________________,d88`*********_________________
 ________________________________________,d8`************________________
 ______________________________________,d8****************_______________
 ____________________________________,d88**************..d**`____________
 __________________________________,d88`*********..d8*`****______________
 ________________________________,d888`****..d8P*`********_______________
 ________________________._____,d8888*8888*`*************________________
 ______________________,*_____,88888*8P*****************_________________
 ____________________,*______d888888*8b.****************_________________
 __________________,P_______dP__*888.*888b.**************________________
 ________________,8*________8____*888*8`**88888b.*********_______________
 ______________,dP________________*88_8b.*******88b.******_______________
 _____________d8`__________________*8b_8b.***********8b.***______________
 ___________,d8`____________________*8._8b.**************88b.____________
 __________d8P_______________________88.*8b.***************______________
 ________,88P________________________*88**8b.************________________
 _______d888*_______.d88P____________888***8b.*********__________________
 ______d8888b..d888888*______________888****8b.*******________*__________
 ____,888888888888888b.______________888*****8b.*****_________8__________
 ___,8*;88888P*****788888888ba.______888******8b.****______*_8'_*________
 __,8;,8888*_________`88888*_________d88*******8b.***_______*8*'_________
 __)8e888*__________,88888be._______888*********8b.**_______8'___________
 _,d888`___________,8888888***_____d888**********88b.*____d8'____________
 ,d88P`___________,8888888Pb._____d888`***********888b.__d8'_____________
 888*____________,88888888**___.d8888*************______d8'______________
 `88____________,888888888____.d88888b*********________d88'______________
 ______________,8888888888bd888888********_____________d88'______________
 ______________d888888888888d888********________________d88'_____________
 ______________8888888888888888b.****____________________d88'____________
 ______________88*._*88888888888b.*______.oo._____________d888'__________
 ______________`888b.`8888888888888b._.d8888P_______________d888'________
 _______________**88b.`*8888888888888888888888b...____________d888'______
 ________________*888b.`*8888888888P***7888888888888e.__________d888'____
 _________________88888b.`********.d8888b**__`88888P*____________d888'___
 _________________`888888b_____.d88888888888**__`8888.____________d888'__
 __________________)888888.___d888888888888P______`8888888b.______d88888'
 _________________,88888*____d88888888888**`________`8888b__________d888'
 ________________,8888*____.8888888888P`______________`888b.________d888'
 _______________,888*______888888888b...________________`88P88b.__d8888'_
 ______.db.___,d88*________88888888888888b________________`88888888888___
 __,d888888b.8888`_________`*888888888888888888P`______________******____
 _/*****8888b**`______________`***8888P*``8888`__________________________
 __/**88`_______________________________/**88`___________________________
 __`|'_____________________________`|*8888888'___________________________

 ************************************************************************
 configuration.c
 
 Created on: 10 Jun 2017
 
 Copyright 2017 ayron
 
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along
 with this program; if not, write to the Free Software Foundation, Inc.,
 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

 ***********************************************************************/

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

#include "configuration.h"

struct configuration vConfiguration;
static char AVAILABLE[] = "abcdefghijklmnopqrstuvwxyz1234567890.,!?=-_:;'\"/()$&@~+";

void loadDefaultConfig()
{
	memset(&vConfiguration, 0, sizeof(vConfiguration));
	vConfiguration.charset[4] = 1; /* e */
	vConfiguration.charset[11] = 1; /* l */
	vConfiguration.charset[21] = 1; /* v */
	vConfiguration.charset[53] = 1;
	vConfiguration.charset[54] = 1;
	vConfiguration.sounderSelected = 1;
}

int readConfig()
{
	int fd;
	struct stat vStat;
	char filename[256];

	strcpy(filename, getenv("HOME"));
	strcat(filename, CONFIG_FILE_NAME);
	if (stat(filename, &vStat) < 0) {
		loadDefaultConfig();
		return 0;
	}

	if (vStat.st_size != sizeof(struct configuration)) {
		loadDefaultConfig();
		return 0;
	}

	fd = open(filename, O_RDONLY);
	if (read(fd, &vConfiguration, sizeof(struct configuration)) != sizeof(struct configuration)) {
		close(fd);
		loadDefaultConfig();
		return 0;
	} else {
		close(fd);
		return 1;
	}
}

int writeConfig()
{
	int fd;
	char filename[256];

	strcpy(filename, getenv("HOME"));
	strcat(filename, CONFIG_FILE_NAME);

	fd = creat(filename, 0644);
	if (fd < 0) {
		return 0;
	}

	if (write(fd, &vConfiguration, sizeof(struct configuration)) != sizeof(struct configuration)) {
		close(fd);
		return 0;
	} else {
		close(fd);
		return 1;
	}
}

int getCharIndex(char c)
{
	char *p;
	p = strchr(AVAILABLE, c);
	return p - AVAILABLE;
}

char getIndexedChar(int i)
{
	return AVAILABLE[i];
}

void charsetSet(char c, int b)
{
	vConfiguration.charset[getCharIndex(c)] = b;
}

