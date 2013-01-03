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

#ifndef MEEGOSTUFF_H
#define MEEGOSTUFF_H

#include <QObject>
#include <qmsystem2/qmkeys.h>
#include <resource/qt4/policy/resource-set.h>

class MeeGoStuff : public QObject
{
    Q_OBJECT
public:
    explicit MeeGoStuff(QObject *parent = 0);

private:
    MeeGo::QmKeys *m_keys;
    ResourcePolicy::ResourceSet *m_resouceSet;

signals:
    void powerStatusChangedByKey(bool powerstatus);

public slots:
    void keyEventHappend(MeeGo::QmKeys::Key key,MeeGo::QmKeys::State state  );

};

#endif // MEEGOSTUFF_H
