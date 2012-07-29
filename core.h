#ifndef CORE_H
#define CORE_H

#include <QObject>
#include <QDeclarativeView>

#include "accelerometer.h"
#include "soundeffects.h"
#include "lightsabersettings.h"
#include "vibration.h"
#include "meegostuff.h"

class Core : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool lightsaberPower READ lightsaberPower WRITE setlightsaberPowerStatus NOTIFY lightsaberPowerChanged())

public:
    explicit Core(QObject *parent = 0);
    bool lightsaberPower();

    bool lightsaberPowerStatus;



private:
    Soundeffects *m_soundeffects;
    LightsaberSettings *m_settings;
    Vibration *m_vibration;
    MeeGoStuff *m_system;
    Accelerometer *m_accelerometer;
    QDeclarativeView  m_qmlDeclarativeView;

signals:
    void lightsaberMoved(const int &swingOrHit);
    void lightsaberPowerChanged(const bool &lightsaberPower);
    
private slots:
    void lightsaberMovementRecognized(Accelerometer::Movement movement);
    void setlightsaberPowerStatus(bool status);

};

#endif // CORE_H
