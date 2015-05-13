#ifndef _PDF_READER_CMAP_H
#define _PDF_READER_CMAP_H

#include "CharTypes.h"
#include "GlobalParams.h"
#include "XmlUtils.h"
#include "../../DesktopEditor/graphics/TemporaryCS.h"

namespace PdfReader
{

	class StringExt;
	struct CMapVectorEntry;
	class CMapCache;

	//-------------------------------------------------------------------------------------------------------------------------------

	class CMap
	{
	public:

		// ������� ����� CMap ������������ �� <seCollection> � <seCMapName>. 
		// ������������� ������� ������ �� 1. 
		static CMap *Parse(CMapCache *pCache, StringExt *seCollection, StringExt *seCMapName, GlobalParams *pGlobalParams, wchar_t *wsFilePath = NULL);

		~CMap();

		// ������� ������
		void AddRef();
		void Release();

		// �������� ��������� ���������� � ��������� �������: registry-ordering.
		StringExt *GetCollection()
		{
			return m_seCollection;
		}

		// ���������� true, ���� ��������� CMap ��������� � ��������� <seCollection> � <seCMapName>.
		bool Match(StringExt *seCollection, StringExt *seCMapName);

		// ���������� CID ��������������� ���� �������, ������� ���������� � <sChar>, 
		// � �������� <nLen> ����. 
		CID GetCID(char *sChar, int nLen, int *pnUsed);

		// Writing mode (0 = horizontal, 1 = vertical).
		int GetWMode()
		{
			return m_nWMode;
		}
		void ToXml(std::wstring wsFilePath);

	private:

		CMap(GlobalParams *pGlobalParams, StringExt *seCollection, StringExt *seCMapName);
		CMap(GlobalParams *pGlobalParams, StringExt *seCollection, StringExt *seCMapName, int nWMode);
		void UseCMap(CMapCache *pCache, char *sUseName);
		void CopyVector(CMapVectorEntry *pDest, CMapVectorEntry *pSrc);
		void AddCodeSpace(CMapVectorEntry *pVector, unsigned int unStart, unsigned int unEnd, unsigned int unBytesCount);
		void AddCIDs(unsigned int unStart, unsigned int unEnd, unsigned int unBytesCount, CID nFirstCID);
		void FreeCMapVector(CMapVectorEntry *pVector);
		void WriteVectorToXml(CXmlWriter *pWriter, CMapVectorEntry *pVector);

	private:

		StringExt       *m_seCollection;  // 
		StringExt       *m_seCMapName;    // 
		int              m_nWMode;        // writing mode (0=horizontal, 1=vertical)
		CMapVectorEntry *m_pVector;       // vector for first byte (NULL for identity CMap)
		int              m_nRef;          // ������� ������
						
		GlobalParams    *m_pGlobalParams;

		NSCriticalSection::CRITICAL_SECTION m_oCS;
	};

	//-------------------------------------------------------------------------------------------------------------------------------

#define CMapCacheSize 4

	class CMapCache
	{
	public:

		CMapCache();
		~CMapCache();

		CMap *GetCMap(StringExt *seCollection, StringExt *seCMapName, GlobalParams *pGlobalParams, wchar_t *wsFilePath = NULL);

	private:

		CMap *m_ppCache[CMapCacheSize];
	};
}

#endif // _PDF_READER_CMAP_H
