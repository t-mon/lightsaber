#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include <QObject>
#include <QSensor>
#include <QAccelerometer>
#include <QSettings>


QTM_USE_NAMESPACE


class Accelerometer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int accelerometerSensitivityHit READ accelerometerSensitivityHit WRITE setAccelerometerSensitivityHit NOTIFY accelerometerSensitivityHitChanged())
    Q_PROPERTY(int accelerometerSensitivitySwing READ accelerometerSensitivitySwing WRITE setAccelerometerSensitivitySwing NOTIFY accelerometerSensitivitySwingChanged())

public:
    explicit Accelerometer(QObject *parent = 0);
    enum Movement{
        MovementHit,
        MovementSwing
    };

    int accelerometerSensitivityHit() const;
    void setAccelerometerSensitivityHit(int sensitivity);
    int accelerometerSensitivitySwing() const;
    void setAccelerometerSensitivitySwing(int sensitivity);

private:
    QAccelerometer *m_sensor;
    QSettings *m_settings;

    qreal accel_x;
    qreal accel_y;
    qreal accel_z;

    int sensitivityHit;
    int sensitivitySwing;


signals:
    void accelerometerDataReady(const qreal &x, const qreal &y, const qreal &z);
    void movementChanged(Accelerometer::Movement movement);
    void accelerometerSensitivityHitChanged();
    void accelerometerSensitivitySwingChanged();

private slots:
    void accelerometerChanged();
    void detectLightsaberMove(const qreal &x, const qreal &y, const qreal &z);

};

#endif // ACCELEROMETER_H
