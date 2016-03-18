#pragma once

#include "BiffRecordContinued.h"
#include <Logic/Biff_structures/FtCmo.h>
#include <Logic/Biff_structures/FtCf.h>
#include <Logic/Biff_structures/FtPioGrbit.h>
#include <Logic/Biff_structures/FtSbs.h>
#include <Logic/Biff_structures/FtNts.h>
#include <Logic/Biff_structures/FtMacro.h>
#include <Logic/Biff_structures/FtPictFmla.h>
#include <Logic/Biff_structures/ObjLinkFmla.h>
#include <Logic/Biff_structures/FtCblsData.h>
#include <Logic/Biff_structures/FtRboData.h>
#include <Logic/Biff_structures/FtEdoData.h>
#include <Logic/Biff_structures/FtLbsData.h>
#include <Logic/Biff_structures/FtGboData.h>

#include <Logic/Biff_records/MsoDrawing.h>

namespace XLS
{

// Logical representation of Obj record in BIFF8
class Obj : public BiffRecordContinued
{
	BIFF_RECORD_DEFINE_TYPE_INFO(Obj)
	BASE_OBJECT_DEFINE_CLASS_NAME(Obj)
public:
	Obj(MsoDrawingPtr mso_drawing)  : mso_drawing_(mso_drawing)
	{
	}
	~Obj();

	BaseObjectPtr clone();

	void writeFields(CFRecord& record);
	void readFields(CFRecord& record);

	static const ElementType	type = typeObj;

//-----------------------------
	FtCmo			cmo;
	FtCf			pictFormat;

	FtPioGrbit		pictFlags;
	FtSbs			sbs;
	FtNts			nts;
	FtMacro			macro;
	FtPictFmla		pictFmla;
	ObjLinkFmla		linkFmla;
	FtCblsData		checkBox;
	FtRboData		radioButton;
	FtEdoData		edit;
	FtLbsData		list;
	FtGboData		gbo;

	MsoDrawingPtr	mso_drawing_;


};

} // namespace XLS

