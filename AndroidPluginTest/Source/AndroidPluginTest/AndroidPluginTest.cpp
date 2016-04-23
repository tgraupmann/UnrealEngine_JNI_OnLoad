// Fill out your copyright notice in the Description page of Project Settings.

#include "AndroidPluginTest.h"

// this test is Android specific
#if PLATFORM_ANDROID

// The JNI_OnLoad callback is defined in the JNI code
#include "../../../Launch/Public/Android/AndroidJNI.h"

// Get access to Android logging
#include <android/log.h>

// Redefine a tag for logging
#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "AndroidPluginTest"

#endif

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, AndroidPluginTest, "AndroidPluginTest" );

// Android specific code
#if PLATFORM_ANDROID

// Use a global variable to cause the constructor to invoke
AndroidPluginTestSetupCallbackJNIOnload GSetupCallbackJNIOnload;

// define the callback function that will be invoked in the JNI_OnLoad event
void OuyaSDKHandleRegisterCallbackJNIOnLoad(Callback_JNI_OnLoad callback)
{
	// check the adb logcat
	__android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, "*** This indicates a successful test. The callback was invoked! ***");
}

// Use the constructor to register the callback using the global var: `GSetupCallbackJNIOnload`
AndroidPluginTestSetupCallbackJNIOnload::AndroidPluginTestSetupCallbackJNIOnload()
{
	RegisterCallbackJNIOnLoad((Callback_JNI_OnLoad)OuyaSDKHandleRegisterCallbackJNIOnLoad);
}

#endif
