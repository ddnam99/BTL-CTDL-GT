#ifndef PCH_H
#define PCH_H

#include "DoubleD.h"

struct ItemDictionary
{
	wstring English;
	wstring Vietnamese;
	ItemDictionary(wstring _English = L"", wstring _Vietnamese = L"") :English(_English), Vietnamese(_Vietnamese) {}
};

class Dictionary
{
public:
	Dictionary(int _size = 101);
	~Dictionary();

	void CreateNewDict();

	void insertItem(ItemDictionary &_ItemDict);
	int getAmountOfItem();
	bool getMeanOfVietnamese(ItemDictionary &_ItemDict, int &_AddressOfItem);

	void RepairItem(const int &_AddressOfItem);
	void DeleteItem(const int &_AddressOfItem);

	void Task(wstring _AddressOfFile, bool _output);
private:
	ItemDictionary * Table;
	int TableSize;
	int AmountOfItem;
	bool * ArrChecksNullTable;

	int hash(const wstring &_English);
};

int getDataOfChoose(int _Start, int _End);
void LoadData(Dictionary &_Dict, bool _LoadAll = true);
bool RepairData(wstring &_Text, wstring _mode);
wstring ConvertMillisecondsToClock(wstring _Title, int _Data);

#endif