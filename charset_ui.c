/*
 * File: charset_ui.c
 * Contains: user module object initialize and create functions
 *
 * This file was generated by dtcodegen, from module charset
 *
 *    ** DO NOT MODIFY BY HAND - ALL MODIFICATIONS WILL BE LOST **
 */


#include <stdlib.h>
#include <X11/Intrinsic.h>
#include <Xm/DialogS.h>
#include <Xm/Form.h>
#include <Xm/PanedW.h>
#include <Xm/RowColumn.h>
#include <Xm/Separator.h>
#include <Xm/Label.h>
#include <Xm/ToggleB.h>
#include <Xm/PushB.h>
#include "dtb_utils.h"
#include "morsetutor.h"
#include "charset_ui.h"


DtbCharsetCharsetDialogInfoRec	dtb_charset_charset_dialog = 
{
    False	 /* initialized */
};

/*
 * Widget create procedure decls
 */
static int dtb_charset_charset_dialog_create(
    DtbCharsetCharsetDialogInfo	instance,
    Widget	parent
);
static int dtb_charset_dialog_button_panel_create(
    DtbCharsetCharsetDialogInfo	instance,
    Widget	parent
);
static int dtb_charset_controlpane_create(
    DtbCharsetCharsetDialogInfo	instance,
    Widget	parent
);
static int dtb_charset_char_box_create(
    DtbCharsetCharsetDialogInfo	instance,
    Widget	parent
);
static int dtb_charset_lesson_box_create(
    DtbCharsetCharsetDialogInfo	instance,
    Widget	parent
);
static int dtb_charset_separator_create(
    DtbCharsetCharsetDialogInfo	instance,
    Widget	parent
);
static int dtb_charset_stage_box_create(
    DtbCharsetCharsetDialogInfo	instance,
    Widget	parent
);
static int dtb_charset_separator2_create(
    DtbCharsetCharsetDialogInfo	instance,
    Widget	parent
);
static int dtb_charset_charset_ok_create(
    DtbCharsetCharsetDialogInfo	instance,
    Widget	parent
);
static int dtb_charset_charset_reset_create(
    DtbCharsetCharsetDialogInfo	instance,
    Widget	parent
);
static int dtb_charset_charset_cancel_create(
    DtbCharsetCharsetDialogInfo	instance,
    Widget	parent
);

int 
dtbCharsetCharsetDialogInfo_clear(DtbCharsetCharsetDialogInfo instance)
{
    memset((void *)(instance), 0, sizeof(*instance));
    return 0;
}

int 
dtb_charset_charset_dialog_initialize(
    DtbCharsetCharsetDialogInfo instance,
    Widget parent
)
{
    WidgetList	children = NULL;
    int		numChildren = 0;
    if (instance->initialized)
    {
        return 0;
    }
    instance->initialized = True;

    dtb_charset_charset_dialog_create(instance,
        parent);
    dtb_charset_dialog_button_panel_create(instance,
        instance->charsetDialog_panedwin);
    dtb_charset_controlpane_create(instance,
        instance->charsetDialog_form);
    dtb_charset_char_box_create(instance,
        instance->controlpane);
    dtb_charset_lesson_box_create(instance,
        instance->controlpane);
    dtb_charset_separator_create(instance,
        instance->controlpane);
    dtb_charset_stage_box_create(instance,
        instance->controlpane);
    dtb_charset_separator2_create(instance,
        instance->controlpane);
    dtb_charset_charset_ok_create(instance,
        instance->dialog_button_panel);
    dtb_charset_charset_reset_create(instance,
        instance->dialog_button_panel);
    dtb_charset_charset_cancel_create(instance,
        instance->dialog_button_panel);
    
    /*
     * Add widget-reference resources.
     */
    
    XtVaSetValues(instance->charsetDialog_shellform,
        XmNdefaultButton, instance->charset_ok,
        NULL);
    
    XtVaSetValues(instance->lessonBox_rowcolumn,
        XmNtopWidget, instance->separator,
        NULL);
    
    XtVaSetValues(instance->separator,
        XmNtopWidget, instance->charBox_rowcolumn,
        NULL);
    
    XtVaSetValues(instance->stageBox_rowcolumn,
        XmNleftWidget, instance->lessonBox_rowcolumn,
        XmNtopWidget, instance->separator,
        NULL);
    
    XtVaSetValues(instance->separator2,
        XmNtopWidget, instance->lessonBox_rowcolumn,
        NULL);
    
    /*
     * Call utility functions to do group layout
     */
    
    /*
     * Make Dialog Button-Panel & Footer a fixed height
     */
    {
        Dimension	pane_height;

        XtVaGetValues(instance->dialog_button_panel,
            XmNheight, &pane_height,
            NULL);
        XtVaSetValues(instance->dialog_button_panel,
            XmNpaneMinimum,   pane_height,
            XmNpaneMaximum,   pane_height,
            NULL);

    }
    
    /*
     * Manage the tree, from the bottom up.
     */
    XtVaGetValues(instance->charBox,
        XmNchildren, &children, XmNnumChildren, &numChildren, NULL);
    XtManageChildren(children, numChildren);
    XtVaGetValues(instance->charBox_rowcolumn,
        XmNchildren, &children, XmNnumChildren, &numChildren, NULL);
    XtManageChildren(children, numChildren);
    XtVaGetValues(instance->lessonBox_menu,
        XmNchildren, &children, XmNnumChildren, &numChildren, NULL);
    XtManageChildren(children, numChildren);
    XtVaGetValues(instance->lessonBox_rowcolumn,
        XmNchildren, &children, XmNnumChildren, &numChildren, NULL);
    XtManageChildren(children, numChildren);
    XtVaGetValues(instance->stageBox_menu,
        XmNchildren, &children, XmNnumChildren, &numChildren, NULL);
    XtManageChildren(children, numChildren);
    XtVaGetValues(instance->stageBox_rowcolumn,
        XmNchildren, &children, XmNnumChildren, &numChildren, NULL);
    XtManageChildren(children, numChildren);
    XtVaGetValues(instance->controlpane,
        XmNchildren, &children, XmNnumChildren, &numChildren, NULL);
    XtManageChildren(children, numChildren);
    XtVaGetValues(instance->charsetDialog_form,
        XmNchildren, &children, XmNnumChildren, &numChildren, NULL);
    XtManageChildren(children, numChildren);
    XtVaGetValues(instance->dialog_button_panel,
        XmNchildren, &children, XmNnumChildren, &numChildren, NULL);
    XtManageChildren(children, numChildren);
    XtManageChild(instance->charsetDialog_form);
    XtManageChild(instance->dialog_button_panel);
    XtVaGetValues(instance->charsetDialog_shellform,
        XmNchildren, &children, XmNnumChildren, &numChildren, NULL);
    XtManageChildren(children, numChildren);
    /*
     * Turn off traversal for invisible sash in dialog's PanedWindow
     */
    dtb_remove_sash_focus(instance->charsetDialog_panedwin);
    
    /*
     * Add User and Connection callbacks
     */
    	XtAddCallback(instance->lessonBox_items.lesson1_item,
		XmNactivateCallback, setLesson,
    		(XtPointer)&(*instance));
	XtAddCallback(instance->lessonBox_items.lesson2_item,
		XmNactivateCallback, setLesson,
		(XtPointer)&(*instance));
	XtAddCallback(instance->lessonBox_items.lesson3_item,
		XmNactivateCallback, setLesson,
		(XtPointer)&(*instance));
	XtAddCallback(instance->lessonBox_items.lesson4_item,
		XmNactivateCallback, setLesson,
		(XtPointer)&(*instance));
	XtAddCallback(instance->lessonBox_items.lesson5_item,
		XmNactivateCallback, setLesson,
		(XtPointer)&(*instance));
	XtAddCallback(instance->lessonBox_items.lesson6_item,
		XmNactivateCallback, setLesson,
		(XtPointer)&(*instance));
	XtAddCallback(instance->lessonBox_items.lesson7_item,
		XmNactivateCallback, setLesson,
		(XtPointer)&(*instance));
	XtAddCallback(instance->lessonBox_items.lesson8_item,
		XmNactivateCallback, setLesson,
		(XtPointer)&(*instance));
	XtAddCallback(instance->lessonBox_items.lesson9_item,
		XmNactivateCallback, setLesson,
		(XtPointer)&(*instance));
	XtAddCallback(instance->lessonBox_items.lesson10_item,
		XmNactivateCallback, setLesson,
		(XtPointer)&(*instance));
	XtAddCallback(instance->lessonBox_items.lesson11_item,
		XmNactivateCallback, setLesson,
		(XtPointer)&(*instance));
	XtAddCallback(instance->lessonBox_items.lesson12_item,
		XmNactivateCallback, setLesson,
		(XtPointer)&(*instance));
	XtAddCallback(instance->lessonBox_items.lesson13_item,
		XmNactivateCallback, setLesson,
		(XtPointer)&(*instance));
	XtAddCallback(instance->lessonBox_items.lesson14_item,
		XmNactivateCallback, setLesson,
		(XtPointer)&(*instance));
	XtAddCallback(instance->lessonBox_items.lesson15_item,
		XmNactivateCallback, setLesson,
		(XtPointer)&(*instance));
	XtAddCallback(instance->lessonBox_items.lesson16_item,
		XmNactivateCallback, setLesson,
		(XtPointer)&(*instance));
	XtAddCallback(instance->lessonBox_items.lesson17_item,
		XmNactivateCallback, setLesson,
		(XtPointer)&(*instance));
	XtAddCallback(instance->lessonBox_items.lesson18_item,
		XmNactivateCallback, setLesson,
		(XtPointer)&(*instance));
	XtAddCallback(instance->lessonBox_items.lesson19_item,
		XmNactivateCallback, setLesson,
		(XtPointer)&(*instance));
	XtAddCallback(instance->lessonBox_items.lesson20_item,
		XmNactivateCallback, setLesson,
		(XtPointer)&(*instance));
	XtAddCallback(instance->lessonBox_items.lesson21_item,
		XmNactivateCallback, setLesson,
		(XtPointer)&(*instance));
	XtAddCallback(instance->lessonBox_items.lesson22_item,
		XmNactivateCallback, setLesson,
		(XtPointer)&(*instance));
	XtAddCallback(instance->lessonBox_items.lesson23_item,
		XmNactivateCallback, setLesson,
		(XtPointer)&(*instance));
	XtAddCallback(instance->lessonBox_items.lesson24_item,
		XmNactivateCallback, setLesson,
		(XtPointer)&(*instance));
	XtAddCallback(instance->lessonBox_items.lesson25_item,
		XmNactivateCallback, setLesson,
		(XtPointer)&(*instance));
	XtAddCallback(instance->stageBox_items.only_new,
		XmNactivateCallback, setLessonStage,
		(XtPointer)&(*instance));
	XtAddCallback(instance->stageBox_items.one,
		XmNactivateCallback, setLessonStage,
		(XtPointer)&(*instance));
	XtAddCallback(instance->stageBox_items.all,
		XmNactivateCallback, setLessonStage,
		(XtPointer)&(*instance));
	XtAddCallback(instance->charset_ok,
		XmNactivateCallback, charset_charset_ok_CB1,
		(XtPointer)&(*instance));
	XtAddCallback(instance->charset_ok,
		XmNactivateCallback, setCharset,
		(XtPointer)&(*instance));
	XtAddCallback(instance->charset_reset,
		XmNactivateCallback, resetCharset,
		(XtPointer)&(*instance));
	XtAddCallback(instance->charset_cancel,
		XmNactivateCallback, charset_charset_cancel_CB1,
		(XtPointer)&(*instance));
return 0;
}



static int 
dtb_charset_charset_dialog_create(
    DtbCharsetCharsetDialogInfo instance,
    Widget parent
)
{
    XmString	label_xmstring = NULL;
    Display	*display= (parent == NULL? NULL:XtDisplay(parent));
    Arg	args[8];	/* need 3 args (add 5 to be safe) */
    int	n = 0;
    
    if (instance->charsetDialog == NULL) {
        n = 0;
        XtSetArg(args[n], XmNallowShellResize, True);  ++n;
        XtSetArg(args[n], XmNtitle, "Charset");  ++n;
        XtSetArg(args[n], XmNbackground, dtb_cvt_string_to_pixel(parent, "white"));  ++n;
        instance->charsetDialog =
            XmCreateDialogShell(parent,
                "dtb_charset_charsetDialog", args, n);
    }
    if (instance->charsetDialog == NULL)
        return -1;

    if (instance->charsetDialog_shellform == NULL) {
        instance->charsetDialog_shellform =
            XtVaCreateWidget("dtb_charset_charsetDialog_shellform",
                xmFormWidgetClass,
                instance->charsetDialog,
                XmNnoResize, True,
                XmNdefaultPosition, False,
                XmNmarginHeight, 0,
                XmNmarginWidth, 0,
                XmNbackground, dtb_cvt_string_to_pixel(instance->charsetDialog, "white"),
                NULL);
    }
    if (instance->charsetDialog_shellform == NULL)
        return -1;

    if (instance->charsetDialog_panedwin == NULL) {
        instance->charsetDialog_panedwin =
            XtVaCreateWidget("charsetDialog_panedwin",
                xmPanedWindowWidgetClass,
                instance->charsetDialog_shellform,
                XmNbottomOffset, 0,
                XmNbottomPosition, 100,
                XmNbottomAttachment, XmATTACH_POSITION,
                XmNrightOffset, 0,
                XmNrightPosition, 100,
                XmNrightAttachment, XmATTACH_POSITION,
                XmNleftOffset, 0,
                XmNleftPosition, 0,
                XmNleftAttachment, XmATTACH_POSITION,
                XmNtopOffset, 0,
                XmNtopPosition, 0,
                XmNtopAttachment, XmATTACH_POSITION,
                XmNsashWidth, 1,
                XmNsashHeight, 1,
                XmNspacing, 0,
                XmNmarginHeight, 0,
                XmNmarginWidth, 0,
                XmNbackground, dtb_cvt_string_to_pixel(instance->charsetDialog_shellform, "white"),
                NULL);
    }
    if (instance->charsetDialog_panedwin == NULL)
        return -1;

    if (instance->charsetDialog_form == NULL) {
        instance->charsetDialog_form =
            XtVaCreateWidget("charsetDialog_form",
                xmFormWidgetClass,
                instance->charsetDialog_panedwin,
                XmNallowResize, True,
                XmNmarginHeight, 0,
                XmNmarginWidth, 0,
                XmNresizePolicy, XmRESIZE_GROW,
                XmNheight, 227,
                XmNwidth, 542,
                XmNbackground, dtb_cvt_string_to_pixel(instance->charsetDialog_panedwin, "white"),
                NULL);
    }
    if (instance->charsetDialog_form == NULL)
        return -1;

    return 0;
}



static int 
dtb_charset_dialog_button_panel_create(
    DtbCharsetCharsetDialogInfo instance,
    Widget parent
)
{
    
    if (instance->dialog_button_panel == NULL) {
        instance->dialog_button_panel =
            XtVaCreateWidget("dialog_button_panel",
                xmFormWidgetClass,
                parent,
                XmNpaneMaximum, 48,
                XmNpaneMinimum, 48,
                XmNresizePolicy, XmRESIZE_GROW,
                XmNmarginHeight, 7,
                XmNmarginWidth, 7,
                XmNpositionIndex, 1,
                XmNheight, 48,
                NULL);
    }
    if (instance->dialog_button_panel == NULL)
        return -1;

    return 0;
}



static int 
dtb_charset_controlpane_create(
    DtbCharsetCharsetDialogInfo instance,
    Widget parent
)
{
    
    if (instance->controlpane == NULL) {
        instance->controlpane =
            XtVaCreateWidget("controlpane",
                xmFormWidgetClass,
                parent,
                XmNbottomOffset, 0,
                XmNbottomAttachment, XmATTACH_FORM,
                XmNrightOffset, 0,
                XmNrightAttachment, XmATTACH_FORM,
                XmNleftOffset, 0,
                XmNleftAttachment, XmATTACH_FORM,
                XmNtopOffset, 0,
                XmNtopAttachment, XmATTACH_FORM,
                XmNresizePolicy, XmRESIZE_GROW,
                XmNmarginHeight, 0,
                XmNmarginWidth, 0,
                XmNheight, 227,
                XmNwidth, 542,
                XmNy, 34,
                XmNx, 36,
                NULL);
    }
    if (instance->controlpane == NULL)
        return -1;

    return 0;
}



static int 
dtb_charset_char_box_create(
    DtbCharsetCharsetDialogInfo instance,
    Widget parent
)
{
    XmString	label_xmstring = NULL;
    Arg	args[22];	/* need 17 args (add 5 to be safe) */
    int	n = 0;
    Widget	charBox_choice_items[55];
    static String	charBox_choice_names[] =
    {
        "A_item", "B_item", "C_item", "D_item", "E_item", "F_item", "G_item", "H_item", "I_item", "J_item", "K_item", "L_item", "M_item", "N_item", "O_item", "P_item", "Q_item", "R_item", "S_item", "T_item", "U_item", "V_item", "W_item", "X_item", "Y_item", "Z_item", "one_item", "two_item", "three_item", "four_item", "five_item", "six_item", "seven_item", "eight_item", "nine_item", "zero_item", "dot_item", "comma_item", "exclamation_item", "question_item", "equal_item", "dash_item", "underline_item", "colon_item", "semicolon_item", "apostrophe_item", "quotation_item", "slash_item", "open_bracket_item", "close_bracket_item", "dollar_item", "ampersand_item", "at_item", "begin_item", "end_item"
    };
    static String	charBox_choice_strings[] =
    {
        "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", ".", ",", "!", "?", "=", "-", "_", ":", ";", "'", "\"", "/", "(", ")", "$", "&", "@", "~", "+"
    };
    int	i = 0;
    Boolean	charBox_choice_selected[] =
    {
        False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False
    };
    
    if (instance->charBox_rowcolumn == NULL) {
        instance->charBox_rowcolumn =
            XtVaCreateWidget("charBox_rowcolumn",
                xmRowColumnWidgetClass,
                parent,
                XmNbottomAttachment, XmATTACH_NONE,
                XmNrightAttachment, XmATTACH_NONE,
                XmNleftOffset, 10,
                XmNleftAttachment, XmATTACH_FORM,
                XmNtopOffset, 10,
                XmNtopAttachment, XmATTACH_FORM,
                XmNentryVerticalAlignment, XmALIGNMENT_BASELINE_BOTTOM,
                XmNpacking, XmPACK_TIGHT,
                XmNisHomogeneous, False,
                XmNadjustLast, True,
                XmNspacing, 0,
                XmNmarginWidth, 0,
                XmNmarginHeight, 0,
                XmNentryAlignment, XmALIGNMENT_END,
                XmNorientation, XmHORIZONTAL,
                XmNy, 11,
                XmNx, 9,
                NULL);
    }
    if (instance->charBox_rowcolumn == NULL)
        return -1;

    label_xmstring = XmStringCreateLocalized(" ");
    if (instance->charBox_label == NULL) {
        instance->charBox_label =
            XtVaCreateWidget("charBox_label",
                xmLabelWidgetClass,
                instance->charBox_rowcolumn,
                XmNmarginHeight, 8,
                XmNlabelString, label_xmstring,
                NULL);
        XmStringFree(label_xmstring);
        label_xmstring = NULL;
    }
    if (instance->charBox_label == NULL)
        return -1;

    if (instance->charBox == NULL) {
        n = 0;
        XtSetArg(args[n], XmNradioBehavior, False);  ++n;
        XtSetArg(args[n], XmNentryClass, xmToggleButtonWidgetClass);  ++n;
        XtSetArg(args[n], XmNnumColumns, 5);  ++n;
        XtSetArg(args[n], XmNisHomogeneous, True);  ++n;
        XtSetArg(args[n], XmNspacing, 0);  ++n;
        XtSetArg(args[n], XmNrowColumnType, XmWORK_AREA);  ++n;
        XtSetArg(args[n], XmNpacking, XmPACK_COLUMN);  ++n;
        XtSetArg(args[n], XmNorientation, XmHORIZONTAL);  ++n;
        instance->charBox =
            XmCreateRadioBox(instance->charBox_rowcolumn,
                "charBox", args, n);
    }
    if (instance->charBox == NULL)
        return -1;

    for (i = 0; i < XtNumber(charBox_choice_strings); i++)
    {
        label_xmstring = XmStringCreateLocalized(charBox_choice_strings[i]);
        charBox_choice_items[i] = XtVaCreateWidget(charBox_choice_names[i],
            xmToggleButtonWidgetClass,
            instance->charBox,
            XmNset, charBox_choice_selected[i],
            XmNlabelString, label_xmstring,
            NULL);
        XmStringFree(label_xmstring);
        label_xmstring = NULL;
    }
    instance->charBox_items.A_item = charBox_choice_items[0];
    instance->charBox_items.B_item = charBox_choice_items[1];
    instance->charBox_items.C_item = charBox_choice_items[2];
    instance->charBox_items.D_item = charBox_choice_items[3];
    instance->charBox_items.E_item = charBox_choice_items[4];
    instance->charBox_items.F_item = charBox_choice_items[5];
    instance->charBox_items.G_item = charBox_choice_items[6];
    instance->charBox_items.H_item = charBox_choice_items[7];
    instance->charBox_items.I_item = charBox_choice_items[8];
    instance->charBox_items.J_item = charBox_choice_items[9];
    instance->charBox_items.K_item = charBox_choice_items[10];
    instance->charBox_items.L_item = charBox_choice_items[11];
    instance->charBox_items.M_item = charBox_choice_items[12];
    instance->charBox_items.N_item = charBox_choice_items[13];
    instance->charBox_items.O_item = charBox_choice_items[14];
    instance->charBox_items.P_item = charBox_choice_items[15];
    instance->charBox_items.Q_item = charBox_choice_items[16];
    instance->charBox_items.R_item = charBox_choice_items[17];
    instance->charBox_items.S_item = charBox_choice_items[18];
    instance->charBox_items.T_item = charBox_choice_items[19];
    instance->charBox_items.U_item = charBox_choice_items[20];
    instance->charBox_items.V_item = charBox_choice_items[21];
    instance->charBox_items.W_item = charBox_choice_items[22];
    instance->charBox_items.X_item = charBox_choice_items[23];
    instance->charBox_items.Y_item = charBox_choice_items[24];
    instance->charBox_items.Z_item = charBox_choice_items[25];
    instance->charBox_items.one_item = charBox_choice_items[26];
    instance->charBox_items.two_item = charBox_choice_items[27];
    instance->charBox_items.three_item = charBox_choice_items[28];
    instance->charBox_items.four_item = charBox_choice_items[29];
    instance->charBox_items.five_item = charBox_choice_items[30];
    instance->charBox_items.six_item = charBox_choice_items[31];
    instance->charBox_items.seven_item = charBox_choice_items[32];
    instance->charBox_items.eight_item = charBox_choice_items[33];
    instance->charBox_items.nine_item = charBox_choice_items[34];
    instance->charBox_items.zero_item = charBox_choice_items[35];
    instance->charBox_items.dot_item = charBox_choice_items[36];
    instance->charBox_items.comma_item = charBox_choice_items[37];
    instance->charBox_items.exclamation_item = charBox_choice_items[38];
    instance->charBox_items.question_item = charBox_choice_items[39];
    instance->charBox_items.equal_item = charBox_choice_items[40];
    instance->charBox_items.dash_item = charBox_choice_items[41];
    instance->charBox_items.underline_item = charBox_choice_items[42];
    instance->charBox_items.colon_item = charBox_choice_items[43];
    instance->charBox_items.semicolon_item = charBox_choice_items[44];
    instance->charBox_items.apostrophe_item = charBox_choice_items[45];
    instance->charBox_items.quotation_item = charBox_choice_items[46];
    instance->charBox_items.slash_item = charBox_choice_items[47];
    instance->charBox_items.open_bracket_item = charBox_choice_items[48];
    instance->charBox_items.close_bracket_item = charBox_choice_items[49];
    instance->charBox_items.dollar_item = charBox_choice_items[50];
    instance->charBox_items.ampersand_item = charBox_choice_items[51];
    instance->charBox_items.at_item = charBox_choice_items[52];
    instance->charBox_items.begin_item = charBox_choice_items[53];
    instance->charBox_items.end_item = charBox_choice_items[54];
    return 0;
}



static int 
dtb_charset_lesson_box_create(
    DtbCharsetCharsetDialogInfo instance,
    Widget parent
)
{
    XmString	label_xmstring = NULL;
    Arg	args[22];	/* need 17 args (add 5 to be safe) */
    int	n = 0;
    Widget	lessonBox_menu_items[26];
    static String	lessonBox_menu_names[] =
    {
        "lesson1_item", "lesson2_item", "lesson3_item", "lesson4_item", "lesson5_item", "lesson6_item", "lesson7_item", "lesson8_item", "lesson9_item", "lesson10_item", "lesson11_item", "lesson12_item", "lesson13_item", "lesson14_item", "lesson15_item", "lesson16_item", "lesson17_item", "lesson18_item", "lesson19_item", "lesson20_item", "lesson21_item", "lesson22_item", "lesson23_item", "lesson24_item", "lesson25_item", "user_item"
    };
    static String	lessonBox_menu_strings[] =
    {
        "1 - elv", "2 - 0a", "3 - sq", "4 - t2", "5 - oc", "6 - =d", "7 - 5r", "8 - /?", "9 - i9", "10 - gx", "11 - f4", "12 - nj", "13 - u7", "14 - h,", "15 - kb", "16 - 3p", "17 - my", "18 - zw", "19 - 61", "20 - 8.", "21 - !@", "22 - :;", "23 - ()", "24 - \"$", "25 - '&", "user defined"
    };
    int	i = 0;
    Boolean	lessonBox_menu_selected[] =
    {
        True, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False
    };
    
    if (instance->lessonBox_rowcolumn == NULL) {
        instance->lessonBox_rowcolumn =
            XtVaCreateWidget("lessonBox_rowcolumn",
                xmRowColumnWidgetClass,
                parent,
                XmNbottomAttachment, XmATTACH_NONE,
                XmNrightAttachment, XmATTACH_NONE,
                XmNleftOffset, 10,
                XmNleftAttachment, XmATTACH_FORM,
                XmNtopOffset, 5,
                XmNtopAttachment, XmATTACH_WIDGET,
                XmNpacking, XmPACK_TIGHT,
                XmNisHomogeneous, False,
                XmNadjustLast, True,
                XmNspacing, 0,
                XmNmarginWidth, 0,
                XmNmarginHeight, 0,
                XmNentryAlignment, XmALIGNMENT_END,
                XmNorientation, XmHORIZONTAL,
                XmNy, 171,
                XmNx, 38,
                NULL);
    }
    if (instance->lessonBox_rowcolumn == NULL)
        return -1;

    if (instance->lessonBox_menu == NULL) {
        n = 0;
        XtSetArg(args[n], XmNrowColumnType, XmMENU_PULLDOWN);  ++n;
        instance->lessonBox_menu =
            XmCreatePulldownMenu(instance->lessonBox_rowcolumn,
                "lessonBox_menu", args, n);
    }
    if (instance->lessonBox_menu == NULL)
        return -1;

    label_xmstring = XmStringCreateLocalized("Lesson:");
    if (instance->lessonBox_label == NULL) {
        instance->lessonBox_label =
            XtVaCreateWidget("lessonBox_label",
                xmLabelWidgetClass,
                instance->lessonBox_rowcolumn,
                XmNlabelString, label_xmstring,
                NULL);
        XmStringFree(label_xmstring);
        label_xmstring = NULL;
    }
    if (instance->lessonBox_label == NULL)
        return -1;

    if (instance->lessonBox == NULL) {
        n = 0;
        XtSetArg(args[n], XmNrowColumnType, XmMENU_OPTION);  ++n;
        XtSetArg(args[n], XmNspacing, 0);  ++n;
        XtSetArg(args[n], XmNsubMenuId, instance->lessonBox_menu);  ++n;
        instance->lessonBox =
            XmCreateOptionMenu(instance->lessonBox_rowcolumn,
                "lessonBox", args, n);
    }
    if (instance->lessonBox == NULL)
        return -1;

    for (i = 0; i < XtNumber(lessonBox_menu_strings); i++)
    {
        label_xmstring = XmStringCreateLocalized(lessonBox_menu_strings[i]);
        lessonBox_menu_items[i] = XtVaCreateWidget(lessonBox_menu_names[i],
            xmPushButtonWidgetClass,
            instance->lessonBox_menu,
            XmNlabelString, label_xmstring,
            NULL);
        XmStringFree(label_xmstring);
        label_xmstring = NULL;
    }
    instance->lessonBox_items.lesson1_item = lessonBox_menu_items[0];
    instance->lessonBox_items.lesson2_item = lessonBox_menu_items[1];
    instance->lessonBox_items.lesson3_item = lessonBox_menu_items[2];
    instance->lessonBox_items.lesson4_item = lessonBox_menu_items[3];
    instance->lessonBox_items.lesson5_item = lessonBox_menu_items[4];
    instance->lessonBox_items.lesson6_item = lessonBox_menu_items[5];
    instance->lessonBox_items.lesson7_item = lessonBox_menu_items[6];
    instance->lessonBox_items.lesson8_item = lessonBox_menu_items[7];
    instance->lessonBox_items.lesson9_item = lessonBox_menu_items[8];
    instance->lessonBox_items.lesson10_item = lessonBox_menu_items[9];
    instance->lessonBox_items.lesson11_item = lessonBox_menu_items[10];
    instance->lessonBox_items.lesson12_item = lessonBox_menu_items[11];
    instance->lessonBox_items.lesson13_item = lessonBox_menu_items[12];
    instance->lessonBox_items.lesson14_item = lessonBox_menu_items[13];
    instance->lessonBox_items.lesson15_item = lessonBox_menu_items[14];
    instance->lessonBox_items.lesson16_item = lessonBox_menu_items[15];
    instance->lessonBox_items.lesson17_item = lessonBox_menu_items[16];
    instance->lessonBox_items.lesson18_item = lessonBox_menu_items[17];
    instance->lessonBox_items.lesson19_item = lessonBox_menu_items[18];
    instance->lessonBox_items.lesson20_item = lessonBox_menu_items[19];
    instance->lessonBox_items.lesson21_item = lessonBox_menu_items[20];
    instance->lessonBox_items.lesson22_item = lessonBox_menu_items[21];
    instance->lessonBox_items.lesson23_item = lessonBox_menu_items[22];
    instance->lessonBox_items.lesson24_item = lessonBox_menu_items[23];
    instance->lessonBox_items.lesson25_item = lessonBox_menu_items[24];
    instance->lessonBox_items.user_item = lessonBox_menu_items[25];
    return 0;
}



static int 
dtb_charset_separator_create(
    DtbCharsetCharsetDialogInfo instance,
    Widget parent
)
{
    
    if (instance->separator == NULL) {
        instance->separator =
            XtVaCreateWidget("separator",
                xmSeparatorWidgetClass,
                parent,
                XmNbottomAttachment, XmATTACH_NONE,
                XmNrightOffset, 0,
                XmNrightAttachment, XmATTACH_FORM,
                XmNleftOffset, 0,
                XmNleftAttachment, XmATTACH_FORM,
                XmNtopOffset, 5,
                XmNtopAttachment, XmATTACH_WIDGET,
                XmNseparatorType, XmSHADOW_ETCHED_IN,
                XmNorientation, XmHORIZONTAL,
                XmNheight, 10,
                XmNy, 156,
                XmNx, 102,
                NULL);
    }
    if (instance->separator == NULL)
        return -1;

    return 0;
}



static int 
dtb_charset_stage_box_create(
    DtbCharsetCharsetDialogInfo instance,
    Widget parent
)
{
    XmString	label_xmstring = NULL;
    Arg	args[23];	/* need 18 args (add 5 to be safe) */
    int	n = 0;
    Widget	stageBox_menu_items[3];
    static String	stageBox_menu_names[] =
    {
        "only_new", "one", "all"
    };
    static String	stageBox_menu_strings[] =
    {
        "only new characters", "previous +1 new", "all characters"
    };
    int	i = 0;
    Boolean	stageBox_menu_selected[] =
    {
        True, False, False
    };
    
    if (instance->stageBox_rowcolumn == NULL) {
        instance->stageBox_rowcolumn =
            XtVaCreateWidget("stageBox_rowcolumn",
                xmRowColumnWidgetClass,
                parent,
                XmNbottomAttachment, XmATTACH_NONE,
                XmNrightAttachment, XmATTACH_NONE,
                XmNleftOffset, 10,
                XmNleftAttachment, XmATTACH_WIDGET,
                XmNtopOffset, 5,
                XmNtopAttachment, XmATTACH_WIDGET,
                XmNpacking, XmPACK_TIGHT,
                XmNisHomogeneous, False,
                XmNadjustLast, True,
                XmNspacing, 0,
                XmNmarginWidth, 0,
                XmNmarginHeight, 0,
                XmNentryAlignment, XmALIGNMENT_END,
                XmNorientation, XmHORIZONTAL,
                XmNy, 183,
                XmNx, 273,
                NULL);
    }
    if (instance->stageBox_rowcolumn == NULL)
        return -1;

    if (instance->stageBox_menu == NULL) {
        n = 0;
        XtSetArg(args[n], XmNrowColumnType, XmMENU_PULLDOWN);  ++n;
        instance->stageBox_menu =
            XmCreatePulldownMenu(instance->stageBox_rowcolumn,
                "stageBox_menu", args, n);
    }
    if (instance->stageBox_menu == NULL)
        return -1;

    label_xmstring = XmStringCreateLocalized("Stage:");
    if (instance->stageBox_label == NULL) {
        instance->stageBox_label =
            XtVaCreateWidget("stageBox_label",
                xmLabelWidgetClass,
                instance->stageBox_rowcolumn,
                XmNlabelString, label_xmstring,
                NULL);
        XmStringFree(label_xmstring);
        label_xmstring = NULL;
    }
    if (instance->stageBox_label == NULL)
        return -1;

    if (instance->stageBox == NULL) {
        n = 0;
        XtSetArg(args[n], XmNrowColumnType, XmMENU_OPTION);  ++n;
        XtSetArg(args[n], XmNspacing, 0);  ++n;
        XtSetArg(args[n], XmNsubMenuId, instance->stageBox_menu);  ++n;
        instance->stageBox =
            XmCreateOptionMenu(instance->stageBox_rowcolumn,
                "stageBox", args, n);
    }
    if (instance->stageBox == NULL)
        return -1;

    for (i = 0; i < XtNumber(stageBox_menu_strings); i++)
    {
        label_xmstring = XmStringCreateLocalized(stageBox_menu_strings[i]);
        stageBox_menu_items[i] = XtVaCreateWidget(stageBox_menu_names[i],
            xmPushButtonWidgetClass,
            instance->stageBox_menu,
            XmNlabelString, label_xmstring,
            NULL);
        XmStringFree(label_xmstring);
        label_xmstring = NULL;
    }
    instance->stageBox_items.only_new = stageBox_menu_items[0];
    instance->stageBox_items.one = stageBox_menu_items[1];
    instance->stageBox_items.all = stageBox_menu_items[2];
    return 0;
}



static int 
dtb_charset_separator2_create(
    DtbCharsetCharsetDialogInfo instance,
    Widget parent
)
{
    
    if (instance->separator2 == NULL) {
        instance->separator2 =
            XtVaCreateWidget("separator2",
                xmSeparatorWidgetClass,
                parent,
                XmNbottomAttachment, XmATTACH_NONE,
                XmNrightOffset, 0,
                XmNrightAttachment, XmATTACH_FORM,
                XmNleftOffset, 0,
                XmNleftAttachment, XmATTACH_FORM,
                XmNtopOffset, 5,
                XmNtopAttachment, XmATTACH_WIDGET,
                XmNseparatorType, XmSHADOW_ETCHED_IN,
                XmNorientation, XmHORIZONTAL,
                XmNheight, 10,
                XmNy, 215,
                XmNx, 172,
                NULL);
    }
    if (instance->separator2 == NULL)
        return -1;

    return 0;
}



static int 
dtb_charset_charset_ok_create(
    DtbCharsetCharsetDialogInfo instance,
    Widget parent
)
{
    XmString	label_xmstring = NULL;
    
    label_xmstring = XmStringCreateLocalized("OK");
    if (instance->charset_ok == NULL) {
        instance->charset_ok =
            XtVaCreateWidget("charset_ok",
                xmPushButtonWidgetClass,
                parent,
                XmNbottomAttachment, XmATTACH_NONE,
                XmNrightOffset, 0,
                XmNrightPosition, 30,
                XmNrightAttachment, XmATTACH_POSITION,
                XmNleftOffset, 0,
                XmNleftPosition, 10,
                XmNleftAttachment, XmATTACH_POSITION,
                XmNtopOffset, 5,
                XmNtopAttachment, XmATTACH_FORM,
                XmNrecomputeSize, True,
                XmNalignment, XmALIGNMENT_CENTER,
                XmNdefaultButtonShadowThickness, 1,
                XmNlabelString, label_xmstring,
                NULL);
        XmStringFree(label_xmstring);
        label_xmstring = NULL;
    }
    if (instance->charset_ok == NULL)
        return -1;

    return 0;
}



static int 
dtb_charset_charset_reset_create(
    DtbCharsetCharsetDialogInfo instance,
    Widget parent
)
{
    XmString	label_xmstring = NULL;
    
    label_xmstring = XmStringCreateLocalized("Reset");
    if (instance->charset_reset == NULL) {
        instance->charset_reset =
            XtVaCreateWidget("charset_reset",
                xmPushButtonWidgetClass,
                parent,
                XmNbottomAttachment, XmATTACH_NONE,
                XmNrightOffset, 0,
                XmNrightPosition, 60,
                XmNrightAttachment, XmATTACH_POSITION,
                XmNleftOffset, 0,
                XmNleftPosition, 40,
                XmNleftAttachment, XmATTACH_POSITION,
                XmNtopOffset, 5,
                XmNtopAttachment, XmATTACH_FORM,
                XmNrecomputeSize, True,
                XmNalignment, XmALIGNMENT_CENTER,
                XmNdefaultButtonShadowThickness, 1,
                XmNlabelString, label_xmstring,
                NULL);
        XmStringFree(label_xmstring);
        label_xmstring = NULL;
    }
    if (instance->charset_reset == NULL)
        return -1;

    return 0;
}



static int 
dtb_charset_charset_cancel_create(
    DtbCharsetCharsetDialogInfo instance,
    Widget parent
)
{
    XmString	label_xmstring = NULL;
    
    label_xmstring = XmStringCreateLocalized("Cancel");
    if (instance->charset_cancel == NULL) {
        instance->charset_cancel =
            XtVaCreateWidget("charset_cancel",
                xmPushButtonWidgetClass,
                parent,
                XmNbottomAttachment, XmATTACH_NONE,
                XmNrightOffset, 0,
                XmNrightPosition, 90,
                XmNrightAttachment, XmATTACH_POSITION,
                XmNleftOffset, 0,
                XmNleftPosition, 70,
                XmNleftAttachment, XmATTACH_POSITION,
                XmNtopOffset, 5,
                XmNtopAttachment, XmATTACH_FORM,
                XmNrecomputeSize, True,
                XmNalignment, XmALIGNMENT_CENTER,
                XmNdefaultButtonShadowThickness, 1,
                XmNlabelString, label_xmstring,
                NULL);
        XmStringFree(label_xmstring);
        label_xmstring = NULL;
    }
    if (instance->charset_cancel == NULL)
        return -1;

    return 0;
}

