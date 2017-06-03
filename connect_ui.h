/*
 * File: connect_ui.h
 * Contains: Declarations of module objects, user create procedures,
 *           and callbacks.
 *
 * This file was generated by dtcodegen, from module connect
 *
 *    ** DO NOT MODIFY BY HAND - ALL MODIFICATIONS WILL BE LOST **
 */
#ifndef _CONNECT_UI_H_
#define _CONNECT_UI_H_

#include <stdlib.h>
#include <X11/Intrinsic.h>
#include "dtb_utils.h"

/*
 * User Interface Objects
 */
/*
 * Shared data structures
 */

typedef struct {
    Widget	items_item;
} ConnectNetworkBoxItemsRec, *ConnectNetworkBoxItems;
typedef struct {
    Widget	items_item;
} ConnectNetworkBoxMenuItemsRec, *ConnectNetworkBoxMenuItems;
typedef struct
{
    Boolean	initialized;
    
    Widget	connect;	/* object "connect" */
    Widget	connect_shellform;
    Widget	connect_panedwin;
    Widget	connect_form;
    
    Widget	dialog_button_panel;
    Widget	controlpane;
    
    Widget	networkBox_rowcolumn;	/* object "networkBox" */
    Widget	networkBox_menu;
    Widget	networkBox_label;
    Widget	networkBox;
    ConnectNetworkBoxItemsRec	networkBox_items;
    
    Widget	nodeBox_rowcolumn;	/* object "nodeBox" */
    Widget	nodeBox_label;
    Widget	nodeBox;
    
    Widget	connect_ok;
    Widget	connect_rescan;
    Widget	connect_cancel;
} DtbConnectConnectInfoRec, *DtbConnectConnectInfo;


extern DtbConnectConnectInfoRec dtb_connect_connect;

/*
 * Structure Clear Procedures: These set the fields to NULL
 */
int dtbConnectConnectInfo_clear(DtbConnectConnectInfo instance);

/*
 * Structure Initialization Procedures: These create the widgets
 */
int dtb_connect_connect_initialize(
    DtbConnectConnectInfo	instance,
    Widget	parent
);

/*
 * User Callbacks
 */
void connectOk(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);
void doRescan(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);

/*
 * Connections
 */
void connect_connect_cancel_CB1(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);
#endif /* _CONNECT_UI_H_ */
