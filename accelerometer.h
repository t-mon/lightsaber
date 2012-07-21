#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include <QObject>
#include <QSensor>
#include <QAccelerometer>
#include <QTimer>


QTM_USE_NAMESPACE


class Accelerometer : public QObject
{
    Q_OBJECT
public:
    explicit Accelerometer(QObject *parent = 0);
    enum Movement{
        MovementHit,
        MovementSwing
    };

private:
    QAccelerometer *m_sensor;
    qreal accel_x;
    qreal accel_y;
    qreal accel_z;
    int sensitivityHit;
    int sensitivitySwing;




signals:
    void accelerometerDataReady(const qreal &x, const qreal &y, const qreal &z);
    void MovementChanged(Movement movement);

private slots:
    void accelerometerChanged();
    void detectLightsaberMove(const qreal &x, const qreal &y, const qreal &z);

};

#endif // ACCELEROMETER_H
