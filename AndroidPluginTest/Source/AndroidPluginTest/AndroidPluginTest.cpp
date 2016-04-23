// Fill out your copyright notice in the Description page of Project Settings.

#include "AndroidPluginTest.h"

// this test is Android specific
#if PLATFORM_ANDROID

// Get access to Android logging
#include <android/log.h>

// The JNI_OnLoad callback is defined in the JNI code
#include "../../../Launch/Public/Android/AndroidJNI.h"

// Find a class within the JAR
#include "OuyaSDK_OuyaController.h"

using namespace tv_ouya_console_api_OuyaController;

// Redefine a tag for logging
#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "AndroidPluginTest"

#endif

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, AndroidPluginTest, "AndroidPluginTest" );

// Android specific code
#if PLATFORM_ANDROID

// AndroidJNI global variable
extern JavaVM* GJavaVM;

// Use a global variable to cause the constructor to invoke
AndroidPluginTestSetupCallbackJNIOnload GSetupCallbackJNIOnload;

// define the callback function that will be invoked in the JNI_OnLoad event
int AndroidPluginTestHandleRegisterCallbackJNIOnLoad(JNIEnv* env)
{
	// check the adb logcat
	__android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, "*** This indicates a successful test. The callback was invoked! ***");

	__android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, "*** Initialize the OuyaController classes... ***");
	if (OuyaController::InitJNI(env) == JNI_ERR)
	{
		__android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, "*** Failed to initialize the OuyaController! ***");
		return JNI_ERR;
	}

	__android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, "*** OuyaController initialized successfully. ***");
	return JNI_OK;
}

// Use the constructor to register the callback using the global var: `GSetupCallbackJNIOnload`
AndroidPluginTestSetupCallbackJNIOnload::AndroidPluginTestSetupCallbackJNIOnload()
{
	RegisterCallbackJNIOnLoad(AndroidPluginTestHandleRegisterCallbackJNIOnLoad);
}

#endif
