#include <QObject>
#include "meegostuff.h"
#include <QDebug>

MeeGoStuff::MeeGoStuff(QObject *parent) :
    QObject(parent)
{
    m_keys = new MeeGo::QmKeys(this);
    m_resouceSet = new ResourcePolicy::ResourceSet("player");
    m_resouceSet->addResource(ResourcePolicy::ScaleButtonType);
    m_resouceSet->acquire();

    m_buttonsAcquired = true;

    connect(m_keys,SIGNAL(keyEvent(MeeGo::QmKeys::Key,MeeGo::QmKeys::State)),this,SLOT(keyEventHappend(MeeGo::QmKeys::Key,MeeGo::QmKeys::State)));
}

void MeeGoStuff::keyEventHappend(MeeGo::QmKeys::Key key, MeeGo::QmKeys::State state)
{
    // only handle presses, no releases for now...
     if(!m_buttonsAcquired || state != MeeGo::QmKeys::KeyDown) {
         return;
     }

     qDebug() << "keyEvent:" << key << state;
     switch(key) {
     case MeeGo::QmKeys::VolumeUp:
        emit powerStatusChangedByKey(true);
        break;
     case MeeGo::QmKeys::VolumeDown:
         emit powerStatusChangedByKey(false);
         break;
     default:
         break;
     }
}
