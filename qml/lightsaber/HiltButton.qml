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
    id: hiltButton
    property string character
    height: 210
    width: 90
    Rectangle {
        anchors.fill: parent
        radius: 20
        border.color: LightsaberSettings.hiltCharacter == hiltButton.character ? "white" : "gray"
        border.width: LightsaberSettings.hiltCharacter == hiltButton.character ? 7 : 5
        color: "transparent"

        Image {

            height: 180
            width: 60
            id: hiltButtonImage
            anchors.centerIn: parent
            source: "lightsaber_hilt_" + hiltButton.character + "_on.png"
        }

        MouseArea {
            anchors.fill: parent
            onPressed: {
                LightsaberSettings.hiltCharacter = hiltButton.character
            }
        }
    }
}
