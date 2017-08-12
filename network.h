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
 interface.h
 
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

#ifndef NETWORK_H_
#define NETWORK_H_

#include <stdint.h>
#include <netipx/ipx.h>
#include <X11/Intrinsic.h>

typedef uint8_t IPXNode[6];
typedef uint32_t IPXNet;
typedef uint16_t IPXPort;
typedef uint16_t hop_t;
typedef uint16_t tick_t;

#pragma pack(push, 1)
struct alchemyHeader {
	uint8_t flags;
	uint32_t seqnum;
};

struct commandHeader {
	uint8_t major;
	uint8_t minor;
};
#pragma pack(pop)

/******* SAP *******/
#define IPX_SAP_PORT		(0x452U)
#define IPX_SAP_PTYPE		(4U)
#define IPX_SAP_OP_REQUEST	(1U)
#define IPX_SAP_GENERAL_RQ	(0xFFFFU)
#define IPX_SAP_OP_RESPONSE	(2U)
#define IPX_SAP_OP_GNS_REQUEST	(3U)
#define IPX_SAP_OP_GNS_RESPONSE	(4U)
#define IPX_SAP_MAX_ENTRIES	(7U)
#define IPX_SAP_SERVER_DOWN	(16U)
#define IPX_SAP_SERVER_NAME_LEN	(48U)
#define IPX_SAP_REQUEST_LEN	(4U)

#define IPX_SAP_TYPE_HAMRADIO	(0x4357U)

typedef uint16_t ser_type_t;
typedef char ser_name_t[IPX_SAP_SERVER_NAME_LEN];

#pragma pack(push, 1)
struct sap_entry
{
	ser_type_t ser_type;
	ser_name_t ser_name;
	IPXNet network;
	IPXNode node;
	IPXPort port;
	hop_t hops;
};

struct sap_packet
{
	uint16_t operation;
	struct sap_entry   sap_entries[IPX_SAP_MAX_ENTRIES];
};

struct sap_request
{
	uint16_t operation;
	ser_type_t ser_type;
};
#pragma pack(pop)

struct networkStatus {
	int stop;

};

extern volatile struct networkStatus vNetworkStatus;

#define ALC_FLAG_CON 1
#define ALC_FLAG_REJ 2
#define ALC_FLAG_ACK 4
#define ALC_FLAG_FIN 8
#define ALC_FLAG_CONLESS 16
#define ALC_FLAG_COMMAND 32

#define IPXTYPE_ALCHEMY	0x66

int getAvailableNetworks(IPXNet *networks, size_t buffersize, IPXNet *defaultnet);
int networkInit();
int networkConnect(const IPXNode *node, IPXNet network, IPXPort port);
void networkShutdown();
struct sap_entry *requestSAP(Cardinal *n_entries);


#endif /* NETWORK_H_ */
