#ifndef I_MONITOR_DISPLAY_H
#define I_MONITOR_DISPLAY_H

class IMonitorDisplay
{
    public:
        virtual void displayTime() = 0;
        virtual void displayUserName() = 0;
        virtual void displayHostName() = 0;
};

#endif