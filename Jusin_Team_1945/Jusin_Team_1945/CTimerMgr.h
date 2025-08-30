#pragma once
class CTimerMgr
{
public:
    static int GetCurrentTimeCount(int seconds)
    {
        static DWORD g_dwLastUpdateTime = GetTickCount();
        static int   g_iTimeCount = 1;

        DWORD dwCurrentTime = GetTickCount();
        DWORD dwElapsedTime = dwCurrentTime - g_dwLastUpdateTime;

        if (dwElapsedTime >= 1000)
        {
            g_iTimeCount++;
            if (g_iTimeCount > seconds)
            {
                g_iTimeCount = 1;
            }
            g_dwLastUpdateTime = dwCurrentTime;
        }

        return g_iTimeCount;
    }
};

