// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"

/**
* This is a unit test to verify that the JNI_OnLoad callback is properly
* invoked on Android.
* A successful test will display a message in the Android logcat.
*/
#if PLATFORM_ANDROID

/*
 * Class container for the unit test
 * In this case `Unit Test` is meant as a
 * test created by the developer to make sure
 * a particular feature works.
 */
class AndroidPluginTest001
{
public:
	/* This test uses the class constructor
	 * to register the callback by
	 * constructing a global variable
	 * which happens long before the
	 * JNI_OnLoad event.
	 */
	class SetupCallbackJNIOnLoad
	{
	public:
		// The constructor will register the JNI_OnLoad callback
		SetupCallbackJNIOnLoad();
	};
};

#endif