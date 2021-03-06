/*
 * File: settings_ui.h
 * Contains: Declarations of module objects, user create procedures,
 *           and callbacks.
 *
 * This file was generated by dtcodegen, from module settings
 *
 *    ** DO NOT MODIFY BY HAND - ALL MODIFICATIONS WILL BE LOST **
 */
#ifndef _SETTINGS_UI_H_
#define _SETTINGS_UI_H_

#include <stdlib.h>
#include <X11/Intrinsic.h>
#include "dtb_utils.h"

/*
 * User Interface Objects
 */
/*
 * Shared data structures
 */

typedef struct
{
    Boolean	initialized;
    
    Widget	speedDialog;	/* object "speedDialog" */
    Widget	speedDialog_shellform;
    Widget	speedDialog_panedwin;
    Widget	speedDialog_form;
    
    Widget	dialog_button_panel;
    Widget	controlpane;
    
    Widget	Speed_rowcolumn;	/* object "Speed" */
    Widget	Speed_label;
    Widget	Speed;
    
    Widget	farnsworth_rowcolumn;	/* object "farnsworth" */
    Widget	farnsworth_label;
    Widget	farnsworth;
    
    Widget	separator2;
    Widget	speed_ok;
    Widget	speed_cancel;
} DtbSettingsSpeedDialogInfoRec, *DtbSettingsSpeedDialogInfo;

typedef struct {
    Widget	Continental_item;
    Widget	American_item;
} SettingsCodeBoxItemsRec, *SettingsCodeBoxItems;
typedef struct {
    Widget	Continental_item;
    Widget	American_item;
} SettingsCodeBoxChoiceItemsRec, *SettingsCodeBoxChoiceItems;
typedef struct
{
    Boolean	initialized;
    
    Widget	codeDialog;	/* object "codeDialog" */
    Widget	codeDialog_shellform;
    Widget	codeDialog_panedwin;
    Widget	codeDialog_form;
    
    Widget	dialog_button_panel2;
    Widget	controlpane2;
    
    Widget	codeBox_rowcolumn;	/* object "codeBox" */
    Widget	codeBox_label;
    Widget	codeBox;
    SettingsCodeBoxItemsRec	codeBox_items;
    
    Widget	separator;
    Widget	code_ok;
    Widget	code_cancel;
} DtbSettingsCodeDialogInfoRec, *DtbSettingsCodeDialogInfo;


extern DtbSettingsSpeedDialogInfoRec dtb_settings_speed_dialog;
extern DtbSettingsCodeDialogInfoRec dtb_settings_code_dialog;

/*
 * Structure Clear Procedures: These set the fields to NULL
 */
int dtbSettingsSpeedDialogInfo_clear(DtbSettingsSpeedDialogInfo instance);
int dtbSettingsCodeDialogInfo_clear(DtbSettingsCodeDialogInfo instance);

/*
 * Structure Initialization Procedures: These create the widgets
 */
int dtb_settings_speed_dialog_initialize(
    DtbSettingsSpeedDialogInfo	instance,
    Widget	parent
);
int dtb_settings_code_dialog_initialize(
    DtbSettingsCodeDialogInfo	instance,
    Widget	parent
);

/*
 * User Callbacks
 */
void setSpeed(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);
void setCode(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);
void initSpeedDialog(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);
void initCodeDialog(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);

/*
 * Connections
 */
void settings_speed_cancel_CB1(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);
void settings_speed_ok_CB1(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);
void settings_code_ok_CB1(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);
void settings_code_cancel_CB1(
    Widget	widget,
    XtPointer	clientData,
    XtPointer	callData
);
#endif /* _SETTINGS_UI_H_ */
