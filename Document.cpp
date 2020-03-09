void Task(wstring _AddressOfFile, bool _output); 
/* 
	Load file từ đường dẫn _AddressOfFile và tùy chọn 
	hiển thị phần trăm đã load được qua biến _output 
														*/
void LoadData(Dictionary &_Dict, bool _LoadAll = true); 
/* 
	Sử dụng các thread để load file vào từ điển _Dict với tùy chọn load
	toàn bộ file hoặc load một file với mục đích kiểm thử chương trình
																		*/

int getDataOfChoose(int _Start, int _End); 
/* 
	Nhận dữ liệu lựa chọn của người dùng và xử lý lỗi khi người dùng 
	nhập sai hoặc vượt quá khoảng có thể chọn bắt dầu từ _Start đến 
	_End và trả về kết quả lựa chọn của người dùng kiểu int 
																		*/
bool RepairData(wstring &_Text, wstring _mode); 
/* 
	Xử lý dữ liệu _Text với 3 tùy chọn _mode:
	  - 'en' xử lí _Text về chuẩn tiếng Anh
	  - 'vi' xử lí _Text về chuẩn tiếng Việt
	  - 'DelSpace' xóa toàn bộ khoảng trắng trong _Text 
  															*/
bool getMeanOfVietnamese(ItemDictionary &_ItemDict, int &_AddressOfItem); 
/* 
	Tìm nghĩa tiếng Việt của mục từ _ItemDict, lấy ra vị trí của mục
	từ trong bảng băm để khi sửa hoặc xóa mục từ sẽ không mất thời 
	gian tìm kiếm mục từ trong bảng và trả về true nếu tìm thấy nghĩa
	tiếng Việt của mục từ trong bảng, trả về false nếu không tìm thấy
																		*/
void RepairItem(const int &_AddressOfItem); 
/*
	Sửa mục từ trong bảng băm với vị trí vừa 
	tìm được trong hàm 'getMeanOfVietnamese'
												*/

void DeleteItem(const int &_AddressOfItem); 
/* 
	Xóa mục từ trong bảng băm với vị trí vừa 
	tìm được trong hàm 'getMeanOfVietnamese'
												*/

wstring ConvertMillisecondsToClock(wstring Title, int _Data); 
/* 
	Chuyển dữ liệu đo thời gian chạy_Data ở dạng miliseconds về 
	dạng minutes - seconds - miliseconds với tiêu đề hiển thị Title
																	*/