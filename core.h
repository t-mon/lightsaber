#ifndef CORE_H
#define CORE_H

#include <QObject>
#include "accelerometer.h"
#include "soundeffects.h"
#include "lightsabersettings.h"
#include "vibration.h"
#include "meegostuff.h"

class Core : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool lightsaberPower READ lightsaberPower WRITE setlightsaberPowerStatus)

public:
    explicit Core(QObject *parent = 0);
    bool lightsaberPower();

    bool lightsaberPowerStatus;

private:
    Accelerometer *m_accelerometer;
    Soundeffects *m_soundeffects;
    LightsaberSettings *m_settings;
    Vibration *m_vibration;
    MeeGoStuff *m_system;

signals:
    void lightsaberMoved(const int &swingOrHit);
    void lightsaberPowerChanged(const bool &lightsaberPower);
    
private slots:
    void lightsaberMovementRecognized(Accelerometer::Movement movement);
    void setlightsaberPowerStatus(bool status);

};

#endif // CORE_H
