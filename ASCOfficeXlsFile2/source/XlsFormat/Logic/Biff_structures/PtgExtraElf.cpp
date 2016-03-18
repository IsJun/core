
#include "PtgExtraElf.h"
#include "CellRangeRef.h"
#include <Binary/CFRecord.h>

namespace XLS
{


PtgExtraElf::PtgExtraElf()
{
}


PtgExtraElf::PtgExtraElf(CFRecord& record)
{
	load(record);
}


BiffStructurePtr PtgExtraElf::clone()
{
	return BiffStructurePtr(new PtgExtraElf(*this));
}


void PtgExtraElf::store(CFRecord& record)
{
#pragma message("####################### PtgExtraElf record has no BiffStructure::store() implemented")
	Log::error(" Error!!! PtgExtraElf record has no BiffStructure::store() implemented.");
	//record << something;
}


void PtgExtraElf::load(CFRecord& record)
{
	_UINT32 flags;
	record >> flags;
	
	_UINT32 count = flags & 0x3fffffff;
	
	fRel = GETBIT(flags, 31);
	for(_UINT32 i = 0; i < count; ++i)
	{
		RgceElfLocExtra cell_ref;
		record >> cell_ref;
		array_.push_back(cell_ref);
	}
}


const std::wstring PtgExtraElf::toString() const
{
	std::wstring range;
	for(std::vector<RgceElfLocExtra>::const_iterator it = array_.begin(), itEnd = --array_.end(); it != itEnd; ++it)
	{
		range += it->toString() + L';';
	}
	return range + array_.back().toString();
}


const std::wstring PtgExtraElf::toColumnsSet() const
{
	std::wstring range;
	for(std::vector<RgceElfLocExtra>::const_iterator it = array_.begin(), itEnd = --array_.end(); it != itEnd; ++it)
	{
		range += CellRangeRef(*it, CellRangeRef::stColumnBelow).toString() + L';';
	}
	return range + CellRangeRef(array_.back(), CellRangeRef::stColumnBelow).toString();
}


} // namespace XLS

