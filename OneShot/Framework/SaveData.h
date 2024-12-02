#pragma once

struct SaveData
{
public:
	int version = 0;
	virtual SaveData* VersionUp() = 0;
};

struct SaveDataV1 : public SaveData
{
public:
	SaveDataV1() { version = 1; }

	int highscore = 0;
	SaveData* VersionUp() override;

	NLOHMANN_DEFINE_TYPE_INTRUSIVE(SaveDataV1, highscore)
};

struct SaveDataV2 : public SaveData
{
	SaveDataV2() { version = 2; }

	int highscore = 0;
	int gold = 100;

	SaveData* VersionUp() override { return nullptr; }

	NLOHMANN_DEFINE_TYPE_INTRUSIVE(SaveDataV2, highscore, gold)
};

typedef SaveDataV2 SaveDataVC;
