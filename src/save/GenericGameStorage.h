#pragma once

#include "PCSave.h"

class CDate
{
public:
	int m_nSecond;
	int m_nMinute;
	int m_nHour;
	int m_nDay;
	int m_nMonth;
	int m_nYear;
	
	CDate();
	bool operator>(const CDate &right);
	bool operator<(const CDate &right);
	bool operator==(const CDate &right);
	void PopulateDateFields(int8 &second, int8 &minute, int8 &hour, int8 &day, int8 &month, int16 year);
};

#define SLOT_COUNT (8)

bool GenericSave(int file);
bool GenericLoad();
bool ReadInSizeofSaveFileBuffer(int32 &file, uint32 &size);
bool ReadDataFromFile(int32 file, uint8 *buf, uint32 size);
bool CloseFile(int32 file);
void DoGameSpecificStuffAfterSucessLoad();
bool CheckSlotDataValid(int32 slot);
void MakeSpaceForSizeInBufferPointer(uint8 *&presize, uint8 *&buf, uint8 *&postsize);
void CopySizeAndPreparePointer(uint8 *&buf, uint8 *&postbuf, uint8 *&postbuf2, uint32 &unused, uint32 &size);
void DoGameSpecificStuffBeforeSave();
void MakeValidSaveName(int32 slot);
wchar *GetSavedGameDateAndTime(int32 slot);
wchar *GetNameOfSavedGame(int32 slot);
bool CheckDataNotCorrupt(int32 slot, char *name);
bool RestoreForStartLoad();
int align4bytes(int32 size);

extern CDate& CompileDateAndTime;

extern char (&DefaultPCSaveFileName)[260];
extern char (&ValidSaveName)[260];
extern char (&LoadFileName)[256];
extern wchar (&SlotFileName)[SLOT_COUNT][260];
extern wchar (&SlotSaveDate)[SLOT_COUNT][70];
extern int &CheckSum;
extern enum eLevelName &m_LevelToLoad;
extern int (&Slots)[SLOT_COUNT+1];

extern char SaveFileNameJustSaved[260]; // 8F2570

const char TopLineEmptyFile[] = "THIS FILE IS NOT VALID YET";
extern C_PcSave &PcSaveHelper;