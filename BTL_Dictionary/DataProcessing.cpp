#include "pch.h"
#include <locale>
#include <codecvt>
#include <fstream>
#include <thread>

int getDataOfChoose(int _Start, int _End) 
{
	int Choose;
	input:wstring DataChoose;
	bool TestResults = true;

	wcout << L"Lựa chọn: ";
	getline(wcin, DataChoose);
	RepairData(DataChoose, L"DelSpace");

	for (int i = 0; i < DataChoose.size(); i++)
		if (DataChoose[i]<L'0' or DataChoose[i]>L'9') {
			TestResults = false;
			break;
		}

	if (!TestResults or DataChoose == L"") {
		if (DataChoose == L"") wcout << L"\n\t\tError: Chưa nhập dữ liệu vào ô ! ! !\n";
		else if (DataChoose.size() > 1) wcout << L"\n\t   Error: Dữ liệu chứa kí tự không hợp lệ ! ! !\n";
		else wcout << L"\n\t\t   Error: Kí tự không hợp lệ !!!\n";
		wcout << L"\t---------------------Double D---------------------\n\n";

		goto input;
	}
	else {
		Choose = stoi(DataChoose);

		if (Choose<_Start || Choose>_End) {
			if (_End - _Start > 1) wcout << L"\n\t\tError: Chỉ được chọn từ " << _Start << " -> " << _End << " ! ! !\n";
			else wcout << L"\n\t\tError: Chỉ được chọn " << _Start << L" hoặc " << _End << " ! ! !\n";
			wcout << L"\t ---------------------Double D---------------------\n\n";

			goto input;
		}
	}

	wcin.sync();
	return Choose;
}

wstring ConvertMillisecondsToClock(wstring _Title, int _Data)
{
	int _Milliseconds = _Data % 1000, _Seconds = ((_Data - _Milliseconds) / 1000) % 60, _Minutes = ((_Data - _Seconds * 1000) / 1000) / 60;

	if (_Minutes == 0) return _Title + L": " + to_wstring(_Seconds) + L"s " + to_wstring(_Milliseconds) + L"ms\n";
	else return _Title + L": " + to_wstring(_Minutes) + L"m " + to_wstring(_Seconds) + L"s " + to_wstring(_Milliseconds) + L"ms\n";
}

void Nocursortype(bool Hide)
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = !Hide;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void LoadData(Dictionary &_Table, bool _LoadAll) {
	if (!_LoadAll) {
		thread l1(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV1.txt", true);
		l1.join();
	}
	else {
		Nocursortype(TRUE);

		thread l1(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV1.txt", false);
		thread l2(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV2.txt", false);
		thread l3(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV3.txt", false);
		thread l4(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV4.txt", false);
		thread l5(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV5.txt", false);
		thread l6(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV6.txt", false);
		thread l7(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV7.txt", false);
		thread l8(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV8.txt", false);
		thread l9(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV9.txt", false);
		thread l10(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV10.txt", false);
		thread l11(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV11.txt", false);
		thread l12(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV12.txt", false);
		thread l13(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV13.txt", false);
		thread l14(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV14.txt", false);
		thread l15(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV15.txt", false);
		thread l16(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV16.txt", false);
		thread l17(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV17.txt", false);
		thread l18(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV18.txt", false);
		thread l19(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV19.txt", false);
		thread l20(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV20.txt", false);
		thread l21(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV21.txt", false);
		thread l22(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV22.txt", false);
		thread l23(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV23.txt", false);
		thread l24(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV24.txt", false);
		thread l25(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV25.txt", false);
		thread l26(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV26.txt", false);
		thread l27(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV27.txt", false);
		thread l28(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV28.txt", false);
		thread l29(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV29.txt", false);
		thread l30(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV30.txt", false);
		thread l31(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV31.txt", false);
		thread l32(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV32.txt", false);
		thread l33(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV33.txt", false);
		thread l34(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV34.txt", false);
		thread l35(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV35.txt", false);
		thread l36(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV36.txt", false);
		thread l37(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV37.txt", false);
		thread l38(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV38.txt", false);
		thread l39(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV39.txt", false);
		thread l40(&Dictionary::Task, &_Table, L"SourceData\\FileData\\FileSub\\DictEV40.txt", true);

		l1.join(); l2.join(); l3.join(); l4.join(); l5.join(); l6.join(); l7.join(); l8.join(); l9.join(); l10.join();
		l11.join(); l12.join(); l13.join(); l14.join(); l15.join(); l16.join(); l17.join(); l18.join(); l19.join(); l20.join();
		l21.join(); l22.join(); l23.join(); l24.join(); l25.join(); l26.join(); l27.join(); l28.join(); l29.join(); l30.join();
		l31.join(); l32.join(); l33.join(); l34.join(); l35.join(); l36.join(); l37.join(); l38.join(); l39.join(); l40.join();

		Nocursortype(FALSE);
	}
}

void Dictionary::Task(wstring _AddressOfFile, bool _output) {
	wifstream read(_AddressOfFile);

	locale loc(locale(), new codecvt_utf8<wchar_t>);
	read.imbue(loc);

	wstring TempSizeTypeWstr;
	getline(read, TempSizeTypeWstr);
	string TempSizeTypeStr(TempSizeTypeWstr.begin(), TempSizeTypeWstr.end());
	int Size = atoi(TempSizeTypeStr.c_str());

	ItemDictionary _ItemDict;
	bool newWord = false;
	int CountWord = 0;
	wstring line;

	while (!read.eof()) {
		getline(read, line);

		if (line == L"----") {
			if (_ItemDict.English != L"") {
				insertItem(_ItemDict);
				_ItemDict.Vietnamese = L"";
				if (_output) wcout << L"Loading data from file......" + to_wstring((CountWord++ / (double)Size) * 100) + L"%\r";
			}
			newWord = true;
		}

		if (newWord) {
			getline(read, _ItemDict.English);
			newWord = false;
		}
		else _ItemDict.Vietnamese += line + L"\n";
	}

	read.close();
}

bool RepairData(wstring &_Text, wstring _mode)
{
	if (_mode == L"en") {
		if (_Text != L"") {
			wstring TempText = L"";

			for (int i = 0; i < _Text.size(); i++)
				if (_Text[i] == L' ' or _Text[i] >= 65 and _Text[i] <= 90 or _Text[i] >= 97 and _Text[i] <= 122) {
					if (_Text[i] >= 65 and _Text[i] <= 90) TempText += _Text[i] + 32;
					else if (_Text[i] == L' ') 
						if (TempText == L"");
						else if (TempText[TempText.size() - 1] == L' ');
						else TempText += _Text[i];
					else TempText += _Text[i];

					if (TempText == L"");
					else if (TempText.size() == 1) TempText[0] -= 32;
					else if (TempText[TempText.size() - 2] == L' ') TempText[TempText.size() - 1] -= 32;
				}

			if (TempText != L"")
				if (TempText[TempText.size() - 1] == L' ') TempText.erase(TempText.size() - 1, 1);

			if (TempText.size() <= 1) {
				wcout << L"\n\t\t     Error: Từ quá ngắn ! ! !\n"
					<< L"\t---------------------Double D---------------------\n\n";
				return false;
			}

			_Text = TempText;
			return true;
		}

		wcout << L"\n\t\t  Error: Không được để trống ! ! !\n"
			<< L"\t---------------------Double D---------------------\n\n";
		return false;
	}

	if (_mode == L"vi") {
		if (_Text != L"") {
			bool newline = true;
			wstring lower = L"áàạảãăắằặẵẳâấầậẫẩđéèẹẽẻêếềệễểíìịĩỉóòọõỏôốồộỗổơớờợỡởúùụũủưứừựữửýỳỵỹỷ";
			wstring upper = L"ÁÀẠẢÃĂẮẰẶẴẲÂẤẦẬẪẨĐÉÈẸẼẺÊẾỀỆỄỂÍÌỊĨỈÓÒỌÕỎÔỐỒỘỖỔƠỚỜỢỠỞÚÙỤŨỦƯỨỪỰỮỬÝỲỴỸỶ";

			for (int i = 0; i < _Text.size(); i++)
				if (newline) {
					if (_Text[i] >= 97 and _Text[i] <= 122) {
						_Text[i] -= 32;
						newline = false;
					}
					else if (_Text[i] > 126) {
						for (int j = 0; j < lower.size(); j++)
							if (_Text[i] == lower[j]) {
								_Text[i] = upper[j];
								newline = false;
								break;
							}
					}
					else if (_Text[i] >= 65 and _Text[i] <= 90) newline = false;
				}
				else if (_Text[i] == L'\n') newline = true;
				else if (_Text[i] >= 65 and _Text[i] <= 90) _Text[i] += 32;
				else if (_Text[i] > 126)
					for (int j = 0; j < upper.size(); j++)
						if (_Text[i] == upper[j]) {
							_Text[i] = lower[j];
							break;
						}

			return true;
		}

		return false;
	}

	if (_mode == L"DelSpace") {
		wstring Result = L"";

		for (int i = 0; i < _Text.size(); i++)
			if (_Text[i] != L' ') Result += _Text[i];

		_Text = Result;
	}

	return true;
}