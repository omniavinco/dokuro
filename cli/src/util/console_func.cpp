﻿// Ŭnicode please 
#include "stdafx.h"
#include "console_func.h"
#include "base/lib.h"
#include "base/string_util.h"
#include "util/audio_manager.h"

namespace console {;
bool driverInfo(const std::vector<std::string> &args)
{
	if(Lib::device) {
		std::string msg = " Irrlicht Version : ";
		msg += Lib::device->getVersion();
		Lib::printf(msg);

		msg = " OS Version : ";
		auto osInfo = Lib::device->getOSOperator()->getOperatingSystemVersion();
		msg += osInfo.c_str();
		Lib::printf(msg);

		msg = " Display Driver : ";
		msg += StringUtil::wstring2string(Lib::driver->getName());
		Lib::printf(msg);

		return true;
	} else {
		Lib::warning("No valid irrlicht device detected!");
		return false;
	}
}

bool playBGM(const std::vector<std::string> &args)
{
	//제대로 만드려면 중복재생같은거 예외처리 해야됨
	if(Lib::audio->isSupport()) {
		const std::string bg("res/sound/bg.wav");
		BGM bgm;
		bgm.startUp(bg);
		bgm.open();
		bgm.play();
		Lib::audio->addBGM(bg, bgm);
		return true;
	} else {
		return false;
	}
}

bool save(const std::vector<std::string> &args)
{
	std::string sFile = "cvars.xml";
	const std::vector<std::string> &vAcceptedSubstrings = args;

	printf( "Saving cvars to \"%s\".", sFile.c_str() );
	if( !CVarUtils::Save( sFile, vAcceptedSubstrings ) ) {
		printf( "Error saving file.\n" );
		return false;
	}

	return true;
}

bool load(const std::vector<std::string> &args)
{
	std::string sFile = "cvars.xml";
	const std::vector<std::string> &vAcceptedSubstrings = args;

	printf( "Loading file \"%s\".\n", sFile.c_str() );
	if( !CVarUtils::Load( sFile, vAcceptedSubstrings ) ) {
		printf( "Error: Could not load \"%s\".", sFile.c_str() );
	}
	return true;
}

bool restartGame(const std::vector<std::string> &args)
{
	
	return true;
}

}	// namespace console