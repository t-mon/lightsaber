#ifndef CORE_H
#define CORE_H

#include <QObject>
#include "accelerometer.h"
#include "soundeffects.h"
#include "lightsabersettings.h"
#include "vibration.h"

class Core : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool lightsaberPower READ getlightsaberPowerStatus WRITE setlightsaberPowerStatus)

public:
    explicit Core(QObject *parent = 0);
    void setlightsaberPowerStatus(bool status);
    bool getlightsaberPowerStatus();

    bool lightsaberPowerStatus;

private:
    Accelerometer *m_accelerometer;
    Soundeffects *m_soundeffects;
    LightsaberSettings *m_settings;
    Vibration *m_vibration;


signals:
    void lightsaberMoved(const int &swingOrHit);
    void lightsaberPowerChanged(const bool &lightsaberPower);
    
private slots:
    void lightsaberMovementRecognized(Accelerometer::Movement movement);

};

#endif // CORE_H
