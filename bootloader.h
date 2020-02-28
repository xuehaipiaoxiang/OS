#pragma once
#include<vector>
#include<fstream>
#include<string>

#define SECTOR_N 512

using std::vector;
using std::ofstream;
using std::string;

typedef   char sector ;
typedef unsigned cylinderNum;
typedef unsigned traceNum;
typedef unsigned sectorNum;
enum cylinder { side1, side2 };

class bootloader
{
private:
	sectorNum curSector;
	traceNum curTrace;
	cylinderNum curcyl;
	sectorNum allSector;
	traceNum allTrace;
	cylinderNum allcyl;
protected:
	// STRUCT trace,cylinder,sectorNum
	vector<vector<vector<sector*>*>*>  *data;
	
	//map<cylinder,>
	void initDisc();
public:
	bootloader(cylinderNum allcyl=2,traceNum allTrace=80,sectorNum allSector =18);
	void instance(string);
	void writerSector(cylinderNum, traceNum, sectorNum, sector*);
	~bootloader();
};

