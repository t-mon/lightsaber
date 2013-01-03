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

#ifndef SOUNDEFFECTS_H
#define SOUNDEFFECTS_H

#include <QObject>
#include <QMediaPlayer>
#include <QSettings>

class Soundeffects : public QObject
{
    Q_OBJECT
public:
    explicit Soundeffects(QObject *parent = 0);

    enum SoundEffect{
        SoundEffectHit,
        SoundEffectSwing,
        SoundEffectOn,
        SoundEffectOff
    };

private:
    QMediaPlayer m_player;

    bool lightsaberPowerStatus;
    bool vibrationStatusOnOff;

signals:
    void playHitsound();
    void playSwingsound();
    
public slots:
    void playSaberEffect(SoundEffect soundEffect);
    void playOnOffSound(const bool &lightsaberPower);
};

#endif // SOUNDEFFECTS_H
