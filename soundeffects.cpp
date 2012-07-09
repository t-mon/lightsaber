#include "soundeffects.h"
#include <QAudioFormat>
#include <QMediaPlaylist>
#include <QMediaPlayer>



Soundeffects::Soundeffects(QObject *parent) :
    QObject(parent)
{    
    playlist = new QMediaPlaylist(this);
    playlist->addMedia(QUrl::fromLocalFile("/home/user/lightsaber/Hum 4.wav"));
    playlist->setPlaybackMode( QMediaPlaylist::Loop );
    m_player_background.setPlaylist(playlist);
    m_player_background.setVolume(100);
    lightsaberPowerStatus = false;
    swing = 0;
    hit = 1;

}

void Soundeffects::playSaberEffect(const int &swingOrHit)
{

    if(lightsaberPowerStatus){
        if(m_player.state() == QMediaPlayer::PlayingState){
            qDebug() << "still playing sound";
        }else{
            if(swingOrHit == hit){
                m_player.setMedia(QUrl::fromLocalFile("/opt/lightsaber/soundeffects/hit.wav"));
                m_player.setVolume(100);
                m_player.play();
                emit playHitsound();
            }
            if(swingOrHit == swing){
                m_player.setMedia(QUrl::fromLocalFile("/opt/lightsaber/soundeffects/swing.wav"));
                m_player.setVolume(100);
                m_player.play();
                emit playSwingsound();
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
