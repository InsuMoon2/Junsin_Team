#pragma once
#include <Windows.h>

class CTimerMgr
{
public:
    CTimerMgr() { m_dwLastUpdateTime = GetTickCount(); }

private:
    DWORD m_dwLastUpdateTime;
    int m_iTimeCount = 0;
    bool m_bRoop = false;

public:
    int GetCurrentTimeCount(int seconds, bool bRoop = true)
    {
        DWORD dwCurrentTime = GetTickCount();
        DWORD dwElapsedTime = dwCurrentTime - m_dwLastUpdateTime;

        if (m_iTimeCount == seconds)
        {
            m_iTimeCount++;
            m_iTimeCount = 0;

            m_dwLastUpdateTime = dwCurrentTime;
        }

        else if (m_iTimeCount <= seconds)
        {
            if (dwElapsedTime >= 1000)
            {
                m_iTimeCount++;

                if (m_iTimeCount > seconds)
                {
                    m_iTimeCount = 0;
                }
                m_dwLastUpdateTime = dwCurrentTime;
            }
        }

        return m_iTimeCount;
    }

    float GetCurrentTimeCount(float seconds, bool bRoop = true)
    {
        DWORD dwCurrentTime = GetTickCount();
        DWORD dwElapsedTime = dwCurrentTime - m_dwLastUpdateTime;

        if (m_iTimeCount == seconds)
        {
            m_iTimeCount++;
            m_iTimeCount = 0;

            m_dwLastUpdateTime = dwCurrentTime;
        }

        else if (m_iTimeCount <= seconds)
        {
            if (dwElapsedTime >= 1000)
            {
                m_iTimeCount++;

                if (m_iTimeCount > seconds)
                {
                    m_iTimeCount = 0;
                }
                m_dwLastUpdateTime = dwCurrentTime;
            }
        }

        return m_iTimeCount;
    }
};