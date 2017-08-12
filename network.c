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
 interface.c
 
 Created on: 4 Jun 2017
 
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

#include "network.h"

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <stdio.h>
#include <netipx/ipx.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/select.h>
#include "network.h"
#include <X11/Intrinsic.h>

static struct sockaddr_ipx si_remote;
static struct sockaddr_ipx si_local;
static int ipxSocket;

volatile struct networkStatus vNetworkStatus;

const IPXNode broadcastNode = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

static void networkSendCommand(int major, int minor)
{

}
/****************************************************************************
 * X11 Context
 ****************************************************************************/

int getAvailableNetworks(IPXNet *networks, size_t buffersize, IPXNet *defaultNet)
{
	FILE *routes;
	char unused[25];
	char routerNet[25];
	int n;
	int result;

	routes = fopen("/proc/net/ipx/route", "r");

	if (routes == NULL) {
		return ENETUNREACH;
	}

	*defaultNet = -1;
	fscanf(routes, "%s %s %s", unused, unused, unused);
	for (n = 0; n < buffersize; n++) {
		result = fscanf(routes, "%X %s %s", &(networks[n]), routerNet, unused);
		if (result != 3)
			break;
		if (!strcmp(routerNet, "Directly")) {
			*defaultNet = n;
		}
	}

	return n;
}

int networkInit()
{
	int one = 1;

	ipxSocket = socket(AF_IPX, SOCK_DGRAM, 0);
	if (ipxSocket < 0) {
		return 0;
	}

	memset((char *) &si_local, 0, sizeof(si_local));
	si_local.sipx_family = AF_IPX;
	if (bind(ipxSocket, (struct sockaddr*)&si_local, sizeof(si_local)) < 0) {
		return 0;
	}

	vNetworkStatus.stop = 0;
	return 1;
}

int networkConnect(const IPXNode *node, IPXNet network, IPXPort port)
{
	memset(&si_remote, 0, sizeof(si_remote));
	si_remote.sipx_family = AF_IPX;
	si_remote.sipx_type = IPXTYPE_ALCHEMY;
	memcpy(si_remote.sipx_node, node, 6);
	si_remote.sipx_network = network;
	si_remote.sipx_port = port;

	return connect(ipxSocket, (struct sockaddr*)&si_remote, sizeof(si_remote));
}

int networkInterrogate()
{

}

void networkShutdown()
{
	close(ipxSocket);
}

struct sap_entry *requestSAP(Cardinal *n_entries)
{
	struct sockaddr_ipx addr;
	struct sap_request req;
	struct sap_packet packet;
	int sock;
	size_t sendlen;
	size_t sapLength;
	size_t compareLength;
	static int one = 1;
	struct sap_entry *entries = NULL;
	struct sap_entry *old_entries;
	size_t len;
	fd_set rfds;
	struct timeval tv;
	int retval;
	int found = 0;
	int n, m;

	sapLength = sizeof(struct sap_entry);
	compareLength = sizeof(struct sap_entry) - 2;
	*n_entries = 0;

	if ((sock = socket(AF_IPX, SOCK_DGRAM, 0)) < 0) {
		return NULL;
	}

	if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &one, sizeof(one)) == -1) {
		close(sock);
		return NULL;
	}

	memset(&addr, 0, sizeof(addr));
	addr.sipx_family = AF_IPX;
	addr.sipx_type = IPX_SAP_PTYPE;

	if (bind(sock, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
		close(sock);
		return NULL;
	}

	memset(&addr, 0, sizeof(addr));
	addr.sipx_family = AF_IPX;
	addr.sipx_port = htons(IPX_SAP_PORT);
	addr.sipx_type = IPX_SAP_PTYPE;
	addr.sipx_network = htonl(0x0);
	memcpy(addr.sipx_node, broadcastNode, sizeof(IPXNode));

	req.operation = htons(IPX_SAP_OP_REQUEST);
	req.ser_type = htons(IPX_SAP_GENERAL_RQ);

	sendlen = sizeof(struct sap_request);
	if ((size_t)sendto(sock, &req, sendlen, 0,
		   (struct sockaddr *) &addr, sizeof(addr)) != sendlen) {
		close(sock);
		return NULL;
	}

	while(1) {
		FD_ZERO(&rfds);
		FD_SET(sock, &rfds);

		tv.tv_sec = 2;
		tv.tv_usec = 0;

		retval = select(sock + 1, &rfds, NULL, NULL, &tv);
		if (retval > 0) {
			len = recv(sock, &packet, sizeof(struct sap_packet), 0);
			if (len < (2 + sapLength))
				continue;
			len -= 2;
			if (ntohs(packet.operation) != IPX_SAP_OP_RESPONSE)
				continue;

			old_entries = entries;
			entries = (struct sap_entry*)XtCalloc((*n_entries + 1) + (len / sapLength), sapLength);

			if (old_entries) {
				memcpy(entries, old_entries, *n_entries * sapLength);
				XtFree((char*)old_entries);
			}
			for (n = 0; n < len / sapLength; n++) {
				found = 0;
				puts(packet.sap_entries[n].ser_name);
				printf("%d\n", packet.sap_entries[n].hops);
				for (m = 0; m < *n_entries; m++) {
					if (!memcmp(&entries[m], &packet.sap_entries[n], compareLength)) {
						if (entries[m].hops > packet.sap_entries[n].hops)
							entries[m].hops = packet.sap_entries[n].hops;
						found = 1;
						break;
					}
				}
				if (!found) {
					memcpy(&(entries[(*n_entries)++]), &(packet.sap_entries[n]), sapLength);
				}
			}
		} else {
			break;
		}
	}
	close(sock);
	return entries;
}

/****************************************************************************
 * Network Context
 ****************************************************************************/

void networkReceiveLoop()
{
	struct timeval timeout;
	fd_set rfds;
	int sockfd;
	int result;

	sockfd = ipxSocket;



	while(!vNetworkStatus.stop) {
		timeout.tv_sec = 1;
		timeout.tv_usec = 0;

		FD_ZERO(&rfds);
		FD_SET(sockfd, &rfds);
		result = select(sockfd + 1, &rfds, NULL, NULL, &timeout);
	}
}
