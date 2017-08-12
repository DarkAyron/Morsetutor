/*** DTB_USER_CODE_START vvv Add file header below vvv ***/
/*** DTB_USER_CODE_END   ^^^ Add file header above ^^^ ***/

/*
 * File: morsetutor.c
 * Contains: main() and cross-module connections
 *
 * This file was generated by dtcodegen, from project morsetutor
 *
 * Any text may be added between the DTB_USER_CODE_START and
 * DTB_USER_CODE_END comments (even non-C code). Descriptive comments
 * are provided only as an aid.
 *
 *  ** EDIT ONLY WITHIN SECTIONS MARKED WITH DTB_USER_CODE COMMENTS.  **
 *  ** ALL OTHER MODIFICATIONS WILL BE OVERWRITTEN. DO NOT MODIFY OR  **
 *  ** DELETE THE GENERATED COMMENTS!                                 **
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <X11/Intrinsic.h>
#include <Xm/Xm.h>
#include <Xm/MwmUtil.h>
#include <Xm/Protocols.h>
#include "main_ui.h"
#include "settings_ui.h"
#include "charset_ui.h"
#include "connect_ui.h"
#include "deviceConfig_ui.h"
#include "morsetutor.h"
#include "dtb_utils.h"


/**************************************************************************
 *** DTB_USER_CODE_START
 ***
 *** All necessary header files have been included.
 ***
 *** Add include files, types, macros, externs, and user functions here.
 ***/
#include <pthread.h>

#include "configuration.h"
#include "network.h"

void doQuit(Widget widget, XtPointer clientData, XtPointer callData);

/*** DTB_USER_CODE_END
 ***
 *** End of user code section
 ***
 **************************************************************************/



/*
 * command line options...
 */
static XrmOptionDescRec optionDescList[] = {
    {"-session", "*session", XrmoptionSepArg, (XPointer)NULL}
    
    /*** DTB_USER_CODE_START vvv Add structure fields below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add structure fields above ^^^ ***/
};

/*
 * Application Resources
 */
static XtResource resources[] = {
    {"session", "Session", XtRString, sizeof(String),
        XtOffsetOf(DtbAppResourceRec, session_file), XtRImmediate, (XtPointer)NULL}
    
    /*** DTB_USER_CODE_START vvv Add structure fields below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add structure fields above ^^^ ***/
};

DtbAppResourceRec	dtb_app_resource_rec;


/*
 * main for application morsetutor
 */
int 
main(
    int argc,
    char **argv
)
{
    Widget		toplevel = (Widget)NULL;
    XtAppContext	app = (XtAppContext)NULL;
    String		*fallback_resources = (String*)NULL;
    ArgList		init_args = (ArgList)NULL;
    Cardinal		num_init_args = (Cardinal)0;
    ArgList		get_resources_args = (ArgList)NULL;
    Cardinal		num_get_resources_args = (Cardinal)0;
    
    
    /**************************************************************************
     *** DTB_USER_CODE_START
     ***
     ***  No initialization has been done.
     ***
     *** Add local variables and code.
     ***/
    Atom       WM_DELETE_WINDOW;
    
    XtToolkitThreadInitialize();
    XtSetLanguageProc(NULL, (XtLanguageProc)NULL, NULL);

    /*** DTB_USER_CODE_END
     ***
     *** End of user code section
     ***
     **************************************************************************/
    

    toplevel = XtAppInitialize(&app, "Morsetutor",
        optionDescList, XtNumber(optionDescList),
        &argc, argv, fallback_resources,
        init_args, num_init_args);

    /*
     * Get display and verify initialization was successful.
     */
    if (toplevel == NULL)
    {
        fprintf(stderr, "Could not open display.\n");
        exit(1);
    }
    
    /*
     * Save the toplevel widget so it can be fetched later as needed.
     */
    dtb_save_toplevel_widget(toplevel);
    
    /*
     * Save the command used to invoke the application.
     */
    dtb_save_command(argv[0]);
    
    XtGetApplicationResources(toplevel, (XtPointer)&dtb_app_resource_rec,
        resources, XtNumber(resources),
        get_resources_args, num_get_resources_args);
    
    /**************************************************************************
     *** DTB_USER_CODE_START
     ***
     ***      A connection to the X server has been established, and all
     *** initialization has been done.
     ***
     ***  Add extra initialization code after this comment.
     ***/
    
    readConfig();
    /*** DTB_USER_CODE_END
     ***
     *** End of user code section
     ***
     **************************************************************************/
    

    /*
     * Initialize all global variables.
     */
    dtbMainMainwindowInfo_clear(&dtb_main_mainwindow);
    dtbMainAboutInfo_clear(&dtb_main_about);
    dtbMainFileSelnInfo_clear(&dtb_main_file_seln);
    dtbSettingsSpeedDialogInfo_clear(&dtb_settings_speed_dialog);
    dtbSettingsCodeDialogInfo_clear(&dtb_settings_code_dialog);
    dtbCharsetCharsetDialogInfo_clear(&dtb_charset_charset_dialog);
    dtb_charset_dont_deselect_initialize(&dtb_charset_dont_deselect);
    dtbConnectConnectManualInfo_clear(&dtb_connect_connect_manual);
    dtbConnectAuthDialogInfo_clear(&dtb_connect_auth_dialog);
    dtb_connect_netunreach_initialize(&dtb_connect_netunreach);
    dtb_connect_noderesponse_initialize(&dtb_connect_noderesponse);
    dtbConnectConnectInfo_clear(&dtb_connect_connect);
    dtbDeviceConfigDevConfigInfo_clear(&dtb_device_config_dev_config);
    
    /*
     * Set up the application's root (primary) window.
     */
    dtb_main_mainwindow.mainwindow = toplevel;
    XtVaSetValues(dtb_main_mainwindow.mainwindow,
        XmNallowShellResize, True,
        XmNtitle, "Morsetutor",
        XmNinitialState, NormalState,
        XmNbackground, dtb_cvt_string_to_pixel(dtb_main_mainwindow.mainwindow, "white"),
        NULL);
    
    dtb_main_mainwindow_initialize(&(dtb_main_mainwindow), dtb_get_toplevel_widget());
    
    
    
    /**************************************************************************
     *** DTB_USER_CODE_START
     ***
     ***      All initially-mapped widgets have been created, but not
     *** realized. Set resources on widgets, or perform other operations
     *** that must be completed before the toplevel widget is
     *** realized.
     ***/
    WM_DELETE_WINDOW = XInternAtom (XtDisplay (toplevel), "WM_DELETE_WINDOW", False);
    XmAddWMProtocolCallback (toplevel, WM_DELETE_WINDOW, doQuit,
                                (XtPointer) toplevel);

    if (vConfiguration.sounderSelected) {
	dtb_set_label_from_image_file(dtb_main_mainwindow.sounderButton, "sounder_r.m");
    } else {
	dtb_set_label_from_image_file(dtb_main_mainwindow.sounderButton, "sounder.m");
    }

    if (vConfiguration.radioSelected) {
	dtb_set_label_from_image_file(dtb_main_mainwindow.sendButton, "send_r.m");
    } else {
	dtb_set_label_from_image_file(dtb_main_mainwindow.sendButton, "send.m");
    }

    /*** DTB_USER_CODE_END
     ***
     *** End of user code section
     ***
     **************************************************************************/
    

    XtRealizeWidget(toplevel);

    
    /**************************************************************************
     *** DTB_USER_CODE_START
     ***
     ***      All automatic initialization is complete. Add any additional
     *** code that should be executed before the Xt main loop is entered.
     ***/
    if (!networkInit()) {
	    dtb_connect_netunreach_initialize(&dtb_connect_netunreach);
	    dtb_show_modal_message(toplevel, &dtb_connect_netunreach, NULL, NULL, NULL);
    }
    /*** DTB_USER_CODE_END
     ***
     *** End of user code section
     ***
     **************************************************************************/
    

    /*
     * Enter event loop
     */
    XtAppMainLoop(app);
    return 0;
}


/**************************************************************************
 *** DTB_USER_CODE_START
 ***
 *** All automatically-generated data and functions have been defined.
 ***
 *** Add new functions here, or at the top of the file.
 ***/

/*** DTB_USER_CODE_END
 ***
 *** End of user code section
 ***
 **************************************************************************/


