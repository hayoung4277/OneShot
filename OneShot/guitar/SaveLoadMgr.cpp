#include "stdafx.h"
#include "SaveLoadMgr.h"

void SaveLoadMgr::Save(const SaveDataVC& saveData)
{
	json j = saveData;
	std::ofstream f(tempSavePath);
	f << j.dump(4) << std::endl;
	f.close();
}

SaveDataVC SaveLoadMgr::Load()
{
	std::ifstream f(tempSavePath);
	json j = json::parse(f);
	f.close();
	return j.get<SaveDataVC>();
}
