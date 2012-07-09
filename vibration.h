#ifndef VIBRATION_H
#define VIBRATION_H

#include <QObject>
#include <QFeedbackHapticsEffect>
#include <QSettings>

QTM_USE_NAMESPACE


class Vibration : public QObject
{
    Q_OBJECT
public:
    explicit Vibration(QObject *parent = 0);
    
    signals:

private:
    QFeedbackHapticsEffect m_rumble;
    QSettings *m_settings;
    
public slots:
    void powerOnVibration();
    void powerOffVibration();
    void swingVibration();
    void hitVibration();
    void stopVibration();
    void startstopVibration(const bool &powerstate);
    
};

#endif // VIBRATION_H
