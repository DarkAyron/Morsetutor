/*
 * File: main_ui.h
 * Contains: Declarations of module objects, user create procedures,
 *           and callbacks.
 *
 * This file was generated by dtcodegen, from module main
 *
 *    ** DO NOT MODIFY BY HAND - ALL MODIFICATIONS WILL BE LOST **
 */
#ifndef _MAIN_UI_H_
#define _MAIN_UI_H_

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
    Widget	separator1_item;
    Widget	Quit_item;
} MainFileMenuItemsRec, *MainFileMenuItems;
typedef struct {
    Widget	items_item;
    Widget	items_item2;
    Widget	items_item3;
} MainEditMenuItemsRec, *MainEditMenuItems;
typedef struct {
    Widget	Start_item;
} MainTrainingMenuItemsRec, *MainTrainingMenuItems;
typedef struct {
    Widget	items_item;
} MainHelpMenuItemsRec, *MainHelpMenuItems;


typedef struct {
    Widget	File_item;
    Widget	Edit_item;
    Widget	Training_item;
    Widget	Help_item;
} MainMenubarItemsRec, *MainMenubarItems;
typedef struct
{
    Boolean	initialized;
    
    Widget	mainwindow;	/* object "mainwindow" */
    Widget	mainwindow_mainwin;
    Widget	mainwindow_form;
    
    Widget	menubar;	/* object "menubar" */
    MainMenubarItemsRec	menubar_items;
    
    Widget	mainwindow_toolbar;
    
    Widget	menubar_File_item_File_menu;	/* object "File_menu" */
    MainFileMenuItemsRec	menubar_File_item_File_menu_items;
    
    Widget	menubar_Edit_item_Edit_menu;	/* object "Edit_menu" */
    MainEditMenuItemsRec	menubar_Edit_item_Edit_menu_items;
    
    Widget	menubar_Training_item_Training_menu;	/* object "Training_menu" */
    MainTrainingMenuItemsRec	menubar_Training_item_Training_menu_items;
    
    Widget	menubar_Help_item_Help_menu;	/* object "Help_menu" */
    MainHelpMenuItemsRec	menubar_Help_item_Help_menu_items;
    
    Widget	connectButton;
    Widget	startButton;
    Widget	pauseButton;
    Widget	stopButton;
    Widget	sounderButton;
    Widget	sendButton;
    Widget	rxBox;
    
    Widget	outputBox_scrolledwin;	/* object "outputBox" */
    Widget	outputBox;
} DtbMainMainwindowInfoRec, *DtbMainMainwindowInfo;

typedef struct
{
    Boolean	initialized;
    
    Widget	about;	/* object "about" */
    Widget	about_shellform;
    Widget	about_panedwin;
    Widget	about_form;
    
    Widget	dialog_button_panel;
    Widget	controlpane;
    Widget	label;
    Widget	about_ok;
} DtbMainAboutInfoRec, *DtbMainAboutInfo;


extern DtbMainMainwindowInfoRec dtb_main_mainwindow;
extern DtbMainAboutInfoRec dtb_main_about;

/*
 * Structure Clear Procedures: These set the fields to NULL
 */
int dtbMainMainwindowInfo_clear(DtbMainMainwindowInfo instance);
int dtbMainAboutInfo_clear(DtbMainAboutInfo instance);

/*
 * Structure Initialization Procedures: These create the widgets
 */
int dtb_main_mainwindow_initialize(
    DtbMainMainwindowInfo	instance,
    Widget	parent
);
int dtb_main_about_initialize(
    DtbMainAboutInfo	instance,
    Widget	parent
);

/*
 * User Callbacks
 */
void doConnect(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);
void startTraining(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);
void pauseTraining(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);
void stopTraining(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);
void doQuit(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);
void showSpeed(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);
void showCharset(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);
void showCode(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);
void sendToSounder(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);
void sendToRadio(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);

/*
 * Connections
 */
void main_about_ok_CB1(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);
void main_Help_menu_items_item_CB1(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);
#endif /* _MAIN_UI_H_ */
