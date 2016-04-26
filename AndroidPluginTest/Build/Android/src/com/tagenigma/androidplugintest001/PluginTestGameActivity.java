package com.tagenigma.androidplugintest001;

import android.util.Log;
import com.epicgames.ue4.GameActivity;

public class PluginTestGameActivity {	

	private static final String TAG = PluginTestGameActivity.class.getSimpleName();

	private static TestOnGameActivityListener sTestOnGameActivityListener = new TestOnGameActivityListener();

	static {
		Log.i(TAG, "*** registerOnGameActivityListener ***");
		GameActivity.registerOnGameActivityListener(sTestOnGameActivityListener);
	}
	
	// Need to invoke a static method to trigger the static constructor
	public static void initialize() {		
		Log.i(TAG, "*** initialize ***");
	}
}
