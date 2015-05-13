#ifndef _PDF_READER_ARRAY_H
#define _PDF_READER_ARRAY_H

#include "Object.h"

namespace PdfReader
{
	class Object;
	class XRef;

	//------------------------------------------------------------------------
	// Array
	//------------------------------------------------------------------------

	class Array
	{
	public:

		Array(XRef *pXRef);

		~Array();

		int AddRef()
		{
			return ++m_nRef;
		}
		int Release()
		{
			return --m_nRef;
		}


		int GetCount()
		{
			return m_nCount;
		}


		void Add(Object *pItem);

		Object *Get(int nIndex, Object *pObject);
		Object *GetCopy(int nIndex, Object *pObject);

	private:

		XRef   *m_pXRef;     // ������� Xref ��� ������� PDF ���������
		Object *m_arrItems;  // ������ ���������
		int     m_nItemSize; // ������ ��������
		int     m_nCount;    // ����� ��������� � �������

		int     m_nRef;      // ������� ������
	};
}

#endif // _PDF_READER_ARRAY_H
