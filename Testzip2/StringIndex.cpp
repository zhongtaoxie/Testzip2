#include "StringIndex.h"

StringIndex::StringIndex(void)
{
	m_mpIndexList.empty();
}

StringIndex::~StringIndex(void)
{
	if (!m_mpIndexList.empty())
	{
		std::map<int, std::string>::iterator iterErase;
		for (iterErase = m_mpIndexList.begin(); iterErase != m_mpIndexList.end();)
			iterErase = m_mpIndexList.erase(iterErase);
	}
}



BOOL StringIndex::Append(int nIndex, std::string szIndexName)
{
	return TRUE;
}

std::string StringIndex::GetIndexName(int nIndex)
{
	return "";
}



