#include"pch.h"
#include"bootloader.h"

using std::ifstream;

int main()
{
	bootloader bl;
	
	 char *arr = new  char[512]{ 0 };
	
	ifstream in("D:\\c++ code\\t3\\BOOT.BAT", std::ios::in);
	in.seekg(0, std::ios::end);
	int length = in.tellg();
	in.seekg(0, std::ios::beg);
	in.read(arr, length);
	arr[510] = 0x55;
	arr[511] = 0xaa;
	bl.writerSector(0, 0,0, arr);
	bl.instance("t2.img");
	//delete[] arr;
	return 0;
}
