#pragma once

#include "GeneralUtil.h"
#include "TranslationCache.h"
#include "SKSE/Logger.h"
#include <memory>
#include <sstream>
#include <vector>

//4-29-2022: Checked for translations needed

//MIC options

//const char deliminator = '\\';

std::vector<std::string> ScriptsToSkip =
{
"activemagiceffect",
"actor",
"actorbase",
"actorvalueinfo",
"alias",
"ammo",
"apparatus",
"armor",
"armoraddon",
"art",
"book",
"camera",
"cell",
"colorcomponent",
"colorform",
"combatstyle",
"constructibleobject",
"defaultobjectmanager",
"enchantment",
"equipslot",
"faction",
"flora",
"form",
"formlist",
"formtype",
"game",
"gamedata",
"headpart",
"ingredient",
"input",
"keyword",
"leveledactor",
"leveleditem",
"leveledspell",
"Location",
"magiceffect",
"math",
"modevent",
"netimmerse",
"objectreference",
"outfit",
"perk",
"potion",
"quest",
"race",
"scroll",
"shout",
"skse",
"soulgem",
"sound",
"sounddescriptor",
"spawnertask",
"spell",
"stringutil",
"textureset",
"treeobject",
"ui",
"uicallback",
"utility",
"weapon",
"weather",
"wornobject",
};

std::string IntToString(int number)
{
	std::ostringstream ss;
	ss << number;
	return ss.str();
}

std::string IntAsDoubleToString(double number)
{
	int numberInt = (int)number;

	return IntToString(numberInt);
}

std::string FloatToString(float number)
{
	std::ostringstream ss;
	ss << number;
	return ss.str();
}

std::string DoubleToString(double number)
{
	std::ostringstream ss;
	ss << number;
	return ss.str();
}

std::string FormIDToString(int formID)
{
	std::ostringstream ss;
	std::unique_ptr<char[]> sResult(new char[RE::WinAPI::MAX_PATH]);
	sprintf_s(sResult.get(), RE::WinAPI::MAX_PATH, "%08X", formID);
	return sResult.get();
}

std::string BooleanToYesNoString(bool boolean)
{
	std::string output = "";

	if (boolean) {
		output = GetTranslation("$Yes");
	}

	else {
		output = GetTranslation("$No");
	}

	return output;
}

bool HasFlag(int Flags, int flag)
{
	return (Flags & flag) == flag;
}

bool GetShouldDisplayScript( std::string scriptName )
{
	std::for_each(scriptName.begin(), scriptName.end(), [](char& c) {
		c = (char)::tolower(c);
	});

	return std::find(ScriptsToSkip.begin(), ScriptsToSkip.end(), scriptName) == ScriptsToSkip.end();
}
