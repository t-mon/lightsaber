/*  Lightsaber
 *
 *  Copyright (C) 2012 Simon Stuerz
 *  stuerz.simon@gmail.com
 *
 *  Lightsaber is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Lightsaber is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 */

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
