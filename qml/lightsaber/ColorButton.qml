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

import QtQuick 1.1
import com.nokia.meego 1.0

Item {
    id: colorButton
    property string color
    height: 90
    width: 90
    Rectangle {
        anchors.fill: parent
        radius: 30
        border.color: LightsaberSettings.lightsaberColor == colorButton.color ? "white" : "gray"
        border.width: LightsaberSettings.lightsaberColor == colorButton.color ? 7 : 5
        color: colorButton.color

        MouseArea {
            anchors.fill: parent
            onPressed: {
                LightsaberSettings.lightsaberColor = colorButton.color
            }
        }
    }
}
