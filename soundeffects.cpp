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

