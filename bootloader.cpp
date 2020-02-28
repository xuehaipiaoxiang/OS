#include"pch.h"
#include "bootloader.h"
void bootloader::initDisc()
{
	
	data= new vector<vector<vector<sector*>*>* >(allTrace);
	for (unsigned i = 0; i < allTrace; i++)
	{
		vector<vector<sector*>*>* curS = new vector<vector<sector*>*>(allcyl);
		for (unsigned j = 0; j < allcyl; j++)
		{
			vector<sector*>* cur = new vector<sector*>(allSector);
			for (unsigned k = 0; k < allSector; k++)
				cur->at(k) = new sector[SECTOR_N]{ 0 };
			curS->at(j) = cur;
		}
		data->at(i) = curS;
	}
}

bootloader::bootloader(cylinderNum allcyl, traceNum allTrace, sectorNum allSector) :
	allcyl(allcyl), allTrace(allTrace), allSector(allSector) 
{
	initDisc();
}

void bootloader::instance(string name)
{
	ofstream out(name, std::ios::out);
	for (vector<vector<vector<sector*>*>*>::iterator iter_i = data->begin(); iter_i != data->end(); iter_i++)
		for (vector<vector<sector*>*>::iterator iter_j = (*iter_i)->begin(); iter_j != (*iter_i)->end(); iter_j++)
			for (vector<sector*>::iterator iter_k = (*iter_j)->begin(); iter_k != (*iter_j)->end(); iter_k++)
				out.write(*iter_k, SECTOR_N);
}

// writer sector by sector 
void bootloader::writerSector(cylinderNum curcyl, traceNum curTrace, sectorNum curSector, sector * sp) 
{
	this->curcyl = curcyl;
	this->curTrace = curTrace;
	this->curSector = curSector;
	//data[curTrace].
	(*data).at(curTrace)->at(curcyl)->at(curSector) = sp;
}




bootloader::~bootloader()
{
	for (vector<vector<vector<sector*>*>*>::iterator iter_i = data->begin(); iter_i != data->end(); iter_i++)
		for (vector<vector<sector*>*>::iterator iter_j = (*iter_i)->begin(); iter_j != (*iter_i)->end(); iter_j++)
			for (vector<sector*>::iterator iter_k = (*iter_j)->begin(); iter_k != (*iter_j)->end(); iter_k++)
				delete [] (*iter_k) ;
	data->~vector();
}
