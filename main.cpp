#include"pch.h"
#include"bootloader.h"

int main()
{
	bootloader bl;
	char* arr = new char[512]{ 1 };
	bl.writerSector(0, 0, 1, arr);
	bl.instance("t2.img");
	return 0;
}