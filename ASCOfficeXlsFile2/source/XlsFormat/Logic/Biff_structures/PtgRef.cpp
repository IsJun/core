
#include "PtgRef.h"
#include "CellRef.h"
#include <Binary/CFRecord.h>

namespace XLS
{


PtgRef::PtgRef()
{
}


PtgRef::PtgRef(const std::wstring& word, const PtgDataType data_type)
:	OperandPtg(fixed_id | (static_cast<unsigned char>(data_type) << 5)),
	loc(word)
{
}


BiffStructurePtr PtgRef::clone()
{
	return BiffStructurePtr(new PtgRef(*this));
}


void PtgRef::storeFields(CFRecord& record)
{
	record << loc;
}


void PtgRef::loadFields(CFRecord& record)
{
	record >> loc;
}

void PtgRef::assemble(AssemblerStack& ptg_stack, PtgQueue& extra_data, bool full_ref)
{
	ptg_stack.push(loc.toString());
}



} // namespace XLS

