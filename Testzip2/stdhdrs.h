//  Copyright (C) 1999 AT&T Laboratories Cambridge. All Rights Reserved.
//
//  This file is part of the VNC system.
//
//  The VNC system is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 2 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307,
//  USA.
//
// TightVNC distribution homepage on the Web: http://www.tightvnc.com/
//
// If the source code for the VNC system is not available from the place 
// whence you received this file, check http://www.uk.research.att.com/vnc or contact
// the authors on vnc@uk.research.att.com for information on obtaining it.


// #define VC_EXTRALEAN
#define STRICT

#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <process.h>
#include <crtdbg.h>
#include <string>
#include "rfb.h"
#include <queue>
#include <map>

#include "vncJsonParser.h"
#include "vncAuditToolFunc.h"

#include <CDALog.h>
typedef std::string VNCString ;
#define ARRAY_ELEMS(a)    sizeof(a)/sizeof(a[0])



// LOGGING SUPPORT
// #include "Log.h"
// extern Log vnclog;

//extern const UINT g_StaticISAMessageList;



// No logging at all
//#define LL_NONE		0
// Log server startup/shutdown
//#define LL_STATE	0
// Log connect/disconnect
//#define LL_CLIENTS	1
// Log connection errors (wrong pixfmt, etc)
//#define LL_CONNERR	0
// Log socket errors
//#define LL_SOCKERR	4
// Log internal errors
// #define LL_ERROR	0
// 
// //Log for Debug Test
// #define LL_WARN	1
// 
// 
// // Log internal warnings
// #define LL_WARN	1
// 
// // Log internal info
// #define LL_INFO	2
// // Log socket errors
// //#define LL_SOCKINFO	10
// // Log everything, including internal table setup, etc.
// #define LL_ALL		3


#define _MY_DEBUG_	0

#define __VISTA_BEFORE__ 0

// for GetTickCount64 
typedef ULONGLONG  (WINAPI *PGetTickCount64)(void);


#define		KEY_HASH_CODE			"hashkey"            
#define		KEY_AGENT_SCENE			"agentscene"         
#define		KEY_IMAGE_QUALITY		"imagequality"       
#define		KEY_COMPRESS_LEVEL		"compresslevel"      
#define		KEY_QUALITY				"quality"            
#define		KEY_FULL_SCREEN_TIMER	"fullscreentimer"    
#define		KEY_UPDATE_FREQUENCY	"updatefrequency"    
#define		KEY_SCREEN_FREQUENCY	"screenfrequency"    
#define		KEY_RECORD_TIMER		"recordtimeout"      
#define		KEY_START_URL			"starturl"           
#define		KEY_JUMP_URL			"jumpurl"            
#define		KEY_WEB_KEY_FEATURE		"webkeyfeature"      
#define		KEY_APP_NAME			"appnames"           
#define		KEY_CLOUD_TYPE			"cloudtype"   
#define		KEY_CLOUD_PORT			"cloudport"          
#define		KEY_CHECK_PORCESS_TIMER	"checkprocesstime" 
#define		KEY_POLL_NET_TIMER		"pollnettime"      
#define		KEY_TWICE_AUTH			"authflag"        
#define		KEY_REQUEST_DATA		"getrequestdata"     
#define		KEY_RESPONSEDATA		"getresponsedata"    
#define		KEY_EXPECT_USER			"expectuser"         
#define		KEY_APP_MONITOR			"appmonitor"   
#define		KEY_APP_MONITOR_NAME	"name"              
#define		KEY_APP_KEY_WORD		"keys"          
#define		KEY_APP_AUTH_KEYS		"authkeys"   
#define		KEY_BLUR_OPEN			"openblur"
#define		KEY_BLUR_LEVEL			"blurlevel"
#define		KEY_BLUR_RULES			"blurrules"
#define		RULE_MATCH_SRC			"matchsrc"
#define		RULE_MATCH_MODEL		"matchmodel"
#define		RULE_MATCH_CONTENT		"matchcontent"
#define		RULE_MATCH_AREA			"blurarea"
#define		KEY_APPFILTERTYPE		"appfiltertype"
#define		KEY_APPFILTER			"appfilter"
#define		EXT_OPTION_STRING		"ext_option"

#define		KEY_IE_ADDRESS					"ieappaddr"
#define		KEY_IE_START 					"ieapprecordstart"
#define		KEY_IE_MATCH_SRC 				"matchsrc"
#define		KEY_IE_MATCH_MODEL				"matchmodel"
#define		KEY_IE_MATCH_CONTENT 			"matchcontent"
#define		KEY_IE_STOP						"ieapprecordstop"
#define		KEY_VIDEO_TRIGGER				"videotrigger"
#define		KEY_VIDEO_TRIGGER_PROGRAM		"triggerprogram"
#define		KEY_VIDEO_TRIGGER_READNEED		"isneedread"
#define		KEY_VIDEO_TRIGGER_COMPLETE_MODE	"completemode"
#define		KEY_VIDEO_TRIGGER_BINAME		"biname"
#define		KEY_VIDEO_TRIGGER_BICODE		"bicode"
#define		KEY_VIDEO_TRIGGER_RULE			"triggerrule"
#define		KEY_VIDEO_TRIGGER_PARAM_TIGGER 	"paramtrigger"
#define		KEY_VIDEO_TRIGGER_PARAMS		"params"
#define		KEY_VIDEO_TRIGGER_PARAM_NAME	"paramname"
#define		KEY_VIDEO_TRIGGER_PARAM_CODE	"paramcode"
#define		KEY_VIDEO_TRIGGER_PARAM_RULE	"paramrule"




