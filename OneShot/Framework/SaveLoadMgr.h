#pragma once
#include "SaveData.h"

class SaveLoadMgr : public Singleton<SaveLoadMgr>
{
public:
	friend Singleton<SaveLoadMgr>;

private:
	std::string tempSavePath = "save.json";

	SaveLoadMgr() = default;
	~SaveLoadMgr() = default;

public:
	void Save(const SaveDataVC& saveData);
	SaveDataVC Load();
};

