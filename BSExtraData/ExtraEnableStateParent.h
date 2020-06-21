#pragma once
#include "RE/Skyrim.h"
#include "MoreInformativeConsole/ExtraInfoEntry.h"

void ProcessEnableParentInformation(ExtraInfoEntry* resultArray, RE::ExtraEnableStateParent* enableParentInformation);

const int flag_EnableStateOppositeParent = 1 << 0;
const int flag_PopIn = 1 << 1;