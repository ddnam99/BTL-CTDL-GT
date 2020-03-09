#include "pch.h"
#include <ctime>

int main() {
	SetConsole();

	int Choose, AddressOfItem;
	/**/ int StartCount = clock();

	Dictionary Admin(177147);
	LoadData(Admin);

	/**/ 
	system("cls");
	wcout << ConvertMillisecondsToClock(L"Time load", clock() - StartCount);

	while (1) {
		ItemDictionary ItemDict;

		wcout << L">> Menu\n"
			<< L"1. Tra từ điển\n"
			<< L"2. Thêm mục từ\n"
			<< L"0. Thoát\n";
		Choose = getDataOfChoose(0, 2);

		if (Choose == 0) break;

		system("cls");

		switch (Choose) {
			case 1:
				wcout << L">> Tra từ (kí tự không hợp lệ sẽ bị xóa)\n";
				Choose1:wcout << L"Nhập key: ";
				getline(wcin, ItemDict.English);

				if (!RepairData(ItemDict.English,L"en")) goto Choose1;

				/**/ StartCount = clock();

				if (Admin.getMeanOfVietnamese(ItemDict, AddressOfItem)) {
					wcout << L"\n\t\tNghĩa của từ " << ItemDict.English << " là: \n\n" << ItemDict.Vietnamese << endl;

					/**/ wcout << ConvertMillisecondsToClock(L"Time search", clock() - StartCount);

					if (AddressOfItem != -1) {
						wcout << L">> Menu tra từ\n"
						<< L"1. Sửa mục từ\n"
						<< L"2. Xóa mục từ\n"
						<< L"0. Thoát\n";
						 Choose = getDataOfChoose(0, 2);

						 system("cls");

						 switch (Choose) {
							 case 1:
								 Admin.RepairItem(AddressOfItem);
								 break;
							 case 2:
								 Admin.DeleteItem(AddressOfItem);
								 break;
						 }
					}
				}
				else wcout << L"\n\t\tKhông tìm thấy " << ItemDict.English << L" trong từ điển ! ! !\n"
					<< L"\t  ---------------------Double D---------------------\n\n";
				break;
			case 2:
				wcout << L">> Thêm từ (kí tự không hợp lệ sẽ bị xóa)\n";
				Choose2:wcout << L"Nhập key: ";
				getline(wcin, ItemDict.English);

				if (!RepairData(ItemDict.English,L"en")) goto Choose2;

				if (Admin.getMeanOfVietnamese(ItemDict, AddressOfItem)) {
					wcout << L"\n\t\tĐã có từ " << ItemDict.English << L" trong từ điển ! ! !\n"
						<< L"\t---------------------Double D---------------------\n\n"
						<< L">> Bạn có sửa nghĩa của từ " << ItemDict.English << L"?\n"
						<< L"1. Có\n"
						<< L"2. Không\n";
					Choose = getDataOfChoose(1, 2);

					system("cls");

					if (Choose == 1) Admin.RepairItem(AddressOfItem);
					else wcout << L"\n\t\t\tĐã hủy thao tác ! ! !\n"
						<< L"\t---------------------Double D---------------------\n\n";
				}
				else {
					wcout << L"Nhập nghĩa của từ " << ItemDict.English << L": \n";

					int CountLine = 0;
					wstring line, TempLine;

					while (1) {
						if (CountLine == 0) wcout << L"Line " << ++CountLine << L" (0 để hủy): ";
						else wcout << L"Line " << ++CountLine << L" (0 để dừng): ";
						getline(wcin, line);

						TempLine = line;
						RepairData(TempLine, L"DelSpace");

						if (TempLine == L"0") break;
						ItemDict.Vietnamese += line + L"\n";
					}

					if (RepairData(ItemDict.Vietnamese, L"vi")) {
						/**/ StartCount = clock();

						Admin.insertItem(ItemDict);
						wcout << L"\n\t\tĐã thêm từ " << ItemDict.English << L" thành công ! ! !\n"
							<< L"\t---------------------Double D---------------------\n\n";

						/**/ wcout << ConvertMillisecondsToClock(L"Time insert", clock() - StartCount);
					}
					else {
						system("cls");
						wcout << L"\n\t\t\tĐã hủy thao tác ! ! !\n"
							<< L"\t---------------------Double D---------------------\n\n";
					}
				}
				break;
		}
	}

	return 0;
}