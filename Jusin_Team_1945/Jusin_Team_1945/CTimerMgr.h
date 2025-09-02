#pragma once
#include <Windows.h>

class CTimerMgr
{
public:
    CTimerMgr() { m_dwLastUpdateTime = GetTickCount64(); }

private:
<<<<<<< HEAD
    unsigned long long m_dwLastUpdateTime;
=======
    DWORD m_dwLastUpdateTime;
<<<<<<< HEAD
>>>>>>> origin/LEE
=======
>>>>>>> origin/Yurim
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
<<<<<<< HEAD
<<<<<<< HEAD
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
=======
        float dwCurrentTime = GetTickCount64();
        float dwElapsedTime = dwCurrentTime - m_dwLastUpdateTime;

        if (m_fTimeCount >= seconds)
        {
=======
        float dwCurrentTime = GetTickCount64();
        float dwElapsedTime = dwCurrentTime - m_dwLastUpdateTime;

        if (m_fTimeCount >= seconds)
        {
>>>>>>> origin/Yurim
            //m_fTimeCount += 0.1f;

            m_fTimeCount = 0.0f;

            m_dwLastUpdateTime = dwCurrentTime;
        }

        else if (m_fTimeCount <= seconds)
        {
            if (dwElapsedTime >= 100)
            {
                m_fTimeCount += 0.1f;

                if (m_fTimeCount > seconds)
                {
                    m_fTimeCount = 0.f;
                }

                m_dwLastUpdateTime = dwCurrentTime;
            }
        }

<<<<<<< HEAD
>>>>>>> origin/LEE
=======
>>>>>>> origin/Yurim
        return m_fTimeCount;
    }
};