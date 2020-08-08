#include "MagicItem.h"
#include "TESForm.h"

//
void GetMagicItemData(ExtraInfoEntry* resultArray, RE::TESForm* baseForm)
{
	_DMESSAGE("GetMagicItemData: Start");

	RE::MagicItem* magicItem = static_cast<RE::MagicItem*>(baseForm);

	if( magicItem )
	{
		ExtraInfoEntry* magicEffectsEntry;

		CreateExtraInfoEntry(magicEffectsEntry, "Magic Effects", "", priority_MagicItem_MagicEffects);

		int numEffects = magicItem->effects.size();

		for (int i = 0; i < numEffects; i++)
		{
			RE::Effect* effect = magicItem->effects[i];

			if (effect && effect->baseEffect )
			{
				GetEffectData(magicEffectsEntry, effect, "");
			}

			else
			{
				ExtraInfoEntry* effectEntry;
				CreateExtraInfoEntry(effectEntry, "Unknown Effect Type", "", priority_MagicItem_Effect);
				magicEffectsEntry->PushBack(effectEntry);
			}

			_DMESSAGE("GetSpellData: Ending Active Effect");


		}

		resultArray->PushBack(magicEffectsEntry);

		_DMESSAGE("GetMagicItemData: End");
	}
}

void GetEffectData(ExtraInfoEntry* resultArray, RE::Effect* effect, std::string effectActiveString)
{
	_DMESSAGE("GetEffectData Start");

	ExtraInfoEntry* effectEntry;

	RE::EffectSetting* effectSetting = effect->baseEffect;
	std::string effectName = effectSetting->fullName.c_str();

	CreateExtraInfoEntry(effectEntry, effectName, effectActiveString, priority_MagicItem_Effect);

	//Get data for the actual effect
	GetFormData(effectEntry, effectSetting, nullptr);

	//Magnitude
	ExtraInfoEntry* magnitudeEntry;

	float magnitude = effect->effectItem.magnitude;
	CreateExtraInfoEntry(magnitudeEntry, "Magnitude", FloatToString(magnitude), priority_Effect_Magnitude);
	effectEntry->PushBack(magnitudeEntry);

	//Duration
	ExtraInfoEntry* durationEntry;

	float duration = effect->effectItem.duration;
	CreateExtraInfoEntry(durationEntry, "Duration", FloatToString(duration), priority_Effect_Duration);
	effectEntry->PushBack(durationEntry);


	//Magnitude
	ExtraInfoEntry* areaEntry;

	float area = effect->effectItem.area;
	CreateExtraInfoEntry(areaEntry, "Area", FloatToString(area), priority_Effect_Area);
	effectEntry->PushBack(areaEntry);

	resultArray->PushBack(effectEntry);
}