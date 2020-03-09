#include "pch.h"

Dictionary::Dictionary(int _size) {
	TableSize = _size;
	Table = new ItemDictionary[TableSize]();
	ArrChecksNullTable = new bool[TableSize];
	AmountOfItem = 0;
}

Dictionary::~Dictionary() {
	delete[] Table;
	delete[] ArrChecksNullTable;
}

void Dictionary::insertItem(ItemDictionary &_ItemDict) {
	int indexHash = hash(_ItemDict.English), k = 0;

	while (1) {
		int TempOfIndexHash = (indexHash + k * k) % TableSize;

		if (ArrChecksNullTable[TempOfIndexHash]) {
			Table[TempOfIndexHash] = _ItemDict;
			ArrChecksNullTable[TempOfIndexHash] = false;
			AmountOfItem += 1;
			break;
		}

		k += 1;
	}

	if (AmountOfItem / (double)TableSize >= 0.5) CreateNewDict();
}

bool Dictionary::getMeanOfVietnamese(ItemDictionary &_ItemDict, int &_AddressOfItem) {
	int indexHash = hash(_ItemDict.English), k = 0;

	while (1) {
		int TempOfIndexHash = (indexHash + k * k) % TableSize;

		if (!ArrChecksNullTable[TempOfIndexHash]) {
			if (Table[TempOfIndexHash].English == _ItemDict.English) {
				_ItemDict.Vietnamese = Table[TempOfIndexHash].Vietnamese;
				_AddressOfItem = TempOfIndexHash;
				return true;
			}

			k += 1;
		}

		else return false;
	}
}

void Dictionary::CreateNewDict() {
	Dictionary TempTuDien = *this;

	this->TableSize = TempTuDien.TableSize * 3;
	this->Table = new ItemDictionary[this->TableSize];
	this->ArrChecksNullTable = new bool[this->TableSize];
	this->AmountOfItem = 0;

	for (int i = 0; i < TempTuDien.TableSize; i++)
		if (!TempTuDien.ArrChecksNullTable[i])
			this->insertItem(TempTuDien.Table[i]);
}

int Dictionary::getAmountOfItem() {
	return AmountOfItem;
}

void Dictionary::RepairItem(const int &_AddressOfItem) {
	wcout << L"Nhập nghĩa mới của từ " << Table[_AddressOfItem].English << L": \n";

	wstring Result = L"";
	int CountLine = 0;
	wstring line, TempLine;

	while (1) {
		if (CountLine == 0) wcout << L"Line " << ++CountLine << L" (0 để hủy): ";
		else wcout << L"Line " << ++CountLine << L" (0 để dừng): ";
		getline(wcin, line);

		TempLine = line;
		RepairData(TempLine, L"DelSpace");

		if (TempLine == L"0") break;
		Result += line + L"\n";
	}

	if (RepairData(Result, L"vi")) {
		Table[_AddressOfItem].Vietnamese = Result;
		wcout << L"\n\t\tĐã sửa từ " << Table[_AddressOfItem].English << " thành công ! ! !\n";
	}
	else {
		system("cls");
		wcout << L"\n\t\t\tĐã hủy thao tác ! ! !\n";
	}
	wcout << L"\t---------------------Double D---------------------\n\n";
}

void Dictionary::DeleteItem(const int &_AddressOfItem) {
	ArrChecksNullTable[_AddressOfItem] = true;

	wcout << L"\n\t\tĐã xóa từ " << Table[_AddressOfItem].English << " thành công ! ! !\n"
		<< L"\t---------------------Double D---------------------\n\n";
}

int Dictionary::hash(const wstring &_English) {
	int SumOfValueAscii = 0, k = 41;

	for (int i = 0; i < _English.size(); i++)
		SumOfValueAscii += _English[i] * k--;

	return SumOfValueAscii % TableSize;
}