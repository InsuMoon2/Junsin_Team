#pragma once
#include <Windows.h>

class CTimerMgr
{
private:
    DWORD m_dwLastUpdateTime = GetTickCount();
    int m_iTimeCount = 0;

public:
    int GetCurrentTimeCount(int seconds)
    {
        DWORD dwCurrentTime = GetTickCount();
        DWORD dwElapsedTime = dwCurrentTime - m_dwLastUpdateTime;

        // �� �ȵż� �׳� ������ ����
        if (m_iTimeCount == seconds)
        {
            m_iTimeCount++;
            m_iTimeCount = 0;

            m_dwLastUpdateTime = dwCurrentTime;

            return m_iTimeCount;
        }

        if (dwElapsedTime >= 1000)
        {
            m_iTimeCount++;

            if (m_iTimeCount > seconds)
            {
                m_iTimeCount = 0;
            }
            m_dwLastUpdateTime = dwCurrentTime;
        }

        return m_iTimeCount;
    }
};