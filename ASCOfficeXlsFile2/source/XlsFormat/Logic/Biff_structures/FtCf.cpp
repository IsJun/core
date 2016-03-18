
#include "FtCf.h"
#include <Binary/CFRecord.h>

namespace XLS
{


BiffStructurePtr FtCf::clone()
{
	return BiffStructurePtr(new FtCf(*this));
}



void FtCf::store(CFRecord& record)
{
	unsigned short ft = 0x07; // reserved
	unsigned short cb = 0x02; // reserved
	record << ft << cb;

	record << cf;
}


void FtCf::load(CFRecord& record)
{
	//record.skipNunBytes(4); // reserved
	unsigned short ft, cb;
	record >> ft;
	
	// OpenOffice fuck!!!
	if (ft == 0)
		record.RollRdPtrBack(2);		
	else
	{
		record >> cb;
		record >> cf;
	}
}


} // namespace XLS

