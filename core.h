#ifndef CORE_H
#define CORE_H

#include <QObject>
#include "accelerometer.h"
#include "soundeffects.h"
#include "lightsabersettings.h"

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
    qreal accel_x;
    qreal accel_y;
    qreal accel_z;
    int sensitivityHit;
    int sensitivitySwing;


signals:
    void lightsaberMoved(const QString &soundfile);
    void lightsaberPowerChanged(const bool &lightsaberPower);
    
private slots:
    void detectLightsaberMove(const qreal &x, const qreal &y, const qreal &z);
    void on_lightsaberPowerChanged();
    void lightsaberSensitivityHitChanged(const int &sensitivity);

};

#endif // CORE_H
