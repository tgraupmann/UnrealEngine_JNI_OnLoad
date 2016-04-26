package com.tagenigma.androidplugintest001;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.KeyEvent;
import android.view.MotionEvent;
import com.epicgames.ue4.GameActivity;

public class TestOnGameActivityListener implements GameActivity.OnGameActivityListener {

	private static final String TAG = TestOnGameActivityListener.class.getSimpleName();

	public boolean dispatchGenericMotionEvent(MotionEvent motionEvent) {
		Log.i(TAG, "*** dispatchGenericMotionEvent ***");
		return false;
	}

	public boolean dispatchKeyEvent(KeyEvent keyEvent) {
		Log.i(TAG, "*** dispatchKeyEvent ***");
		return false;
	}
		
	public boolean onActivityResult(int requestCode, int resultCode, Intent data) {
		Log.i(TAG, "*** onActivityResult ***");
		return false;
	}

	public void onCreate(Bundle savedInstanceState) {
		Log.i(TAG, "*** onCreate ***");
	}

	public void onDestroy() {
		Log.i(TAG, "*** onDestroy ***");
	}

	public void onPause() {
		Log.i(TAG, "*** onPause ***");
	}

	public void onResume() {
		Log.i(TAG, "*** onResume ***");
	}

	public void onStart() {
		Log.i(TAG, "*** onStart ***");
	}

	public void onStop() {
		Log.i(TAG, "*** onStop ***");
	}
}
