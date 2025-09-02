#pragma once
#include <Windows.h>

class CTimerMgr
{
public:
    CTimerMgr() { m_dwLastUpdateTime = GetTickCount64(); }

private:
    unsigned long long m_dwLastUpdateTime;
    int   m_iTimeCount = 0;
    float m_fTimeCount = 0.f;
    bool  m_bRoop = false;

public:
    int GetCurrentTimeCount(int seconds)
    {
        DWORD dwCurrentTime = GetTickCount64();
        DWORD dwElapsedTime = dwCurrentTime - m_dwLastUpdateTime;

        if (m_iTimeCount >= seconds)
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

    float GetCurrentTimeCount(float seconds)
    {
        ULONGLONG now = GetTickCount64();
        ULONGLONG elapsed = now - m_dwLastUpdateTime;

        if (elapsed >= 100)
        {
            m_fTimeCount += 0.1f;
            m_dwLastUpdateTime = now;

            if (m_fTimeCount + 1e-4f >= static_cast<float>(seconds))
            {
                m_fTimeCount = 0.0f;
            }
        }
        return m_fTimeCount;
    }
};