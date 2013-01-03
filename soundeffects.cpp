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

#include "soundeffects.h"
#include <QAudioFormat>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QSettings>


Soundeffects::Soundeffects(QObject *parent) :
    QObject(parent)
{    
    lightsaberPowerStatus = false;

}

void Soundeffects::playSaberEffect(SoundEffect soundEffect)
{

    if(lightsaberPowerStatus){
        if(m_player.state() == QMediaPlayer::PlayingState){
            qDebug() << "still playing sound";
        }else{
            switch(soundEffect){
            case SoundEffectHit:
                m_player.setMedia(QUrl::fromLocalFile("/opt/lightsaber/soundeffects/hit2.wav"));
                m_player.setVolume(100);
                m_player.play();
                emit playHitsound();
                break;
            case SoundEffectSwing:
                m_player.setMedia(QUrl::fromLocalFile("/opt/lightsaber/soundeffects/swing.wav"));
                m_player.setVolume(100);
                m_player.play();
                emit playSwingsound();
                break;
            }
        }
    }
}



void Soundeffects::playOnOffSound(const bool &lightsaberPower)
{
    if(lightsaberPower){
        m_player.setMedia(QUrl::fromLocalFile("/opt/lightsaber/soundeffects/on.wav"));
        m_player.setVolume(100);
        m_player.play();
        lightsaberPowerStatus = lightsaberPower;

    } else {
        m_player.setMedia(QUrl::fromLocalFile("/opt/lightsaber/soundeffects/off.wav"));
        m_player.setVolume(100);
        m_player.play();
        lightsaberPowerStatus = lightsaberPower;

    }
}

