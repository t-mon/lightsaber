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

public:
    explicit Accelerometer(QObject *parent = 0);
    enum Movement{
        MovementHit,
        MovementSwing
    };



private:
    QAccelerometer *m_sensor;
    QSettings *m_settings;

    qreal accel_x;
    qreal accel_y;
    qreal accel_z;

    int sensitivityHit;
    int sensitivitySwing;

    int accelerometerSensitivityHit() const;
    void setAccelerometerSensitivityHit(int sensitivity);

signals:
    void accelerometerDataReady(const qreal &x, const qreal &y, const qreal &z);
    void movementChanged(Accelerometer::Movement movement);
    void accelerometerSensitivityHitChanged();

private slots:
    void accelerometerChanged();
    void detectLightsaberMove(const qreal &x, const qreal &y, const qreal &z);

};

#endif // ACCELEROMETER_H
