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

    connect(m_keys,SIGNAL(keyEvent(MeeGo::QmKeys::Key,MeeGo::QmKeys::State)),this,SLOT(keyEventHappend(MeeGo::QmKeys::Key,MeeGo::QmKeys::State)));
}

void MeeGoStuff::keyEventHappend(MeeGo::QmKeys::Key key, MeeGo::QmKeys::State state)
{
    // handels only presses, not release key
     if(state != MeeGo::QmKeys::KeyDown) {
         return;
     }

     qDebug() << "key event:" << key << state;
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
