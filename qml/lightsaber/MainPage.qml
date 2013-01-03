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
import QtMobility.systeminfo 1.1


Page {
    id: page
    tools: commonTools

    ScreenSaver {
        screenSaverInhibited: LightsaberSettings.keepDisplayOn
    }

    orientationLock: PageOrientation.LockPortrait

    property string lightsabercolor : LightsaberSettings.lightsaberColor

    Item{
        id:arrowsItem
        anchors.right: parent.right
        anchors.top: parent.top
        opacity: 0

        Image{
            id: firstArrow
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.topMargin: 40
            source: "image://theme/icon-m-toolbar-mediacontrol-play-white"
        }

        Image{
            id: secArrowArrow
            anchors.right: parent.right
            anchors.top: firstArrow.bottom
            anchors.topMargin: 45
            source: "image://theme/icon-m-toolbar-mediacontrol-play-white"
        }
    }



    SequentialAnimation{
        id: helpAnimation
        loops: 2
        NumberAnimation{
            target: arrowsItem
            properties: "opacity"
            duration: 700
            from: 0
            to: 0.8
        }
        NumberAnimation{
            target: arrowsItem
            properties: "opacity"
            duration: 700
            from: 0.8
            to: 0
        }
    }

    Rectangle{
        id: swordRectangle
        height: 630
        width: 140
        anchors.horizontalCenter: parent.horizontalCenter
        color: "transparent"

        BorderImage {
            id: lightsaberImage
            anchors.bottom: parent.bottom
            anchors.bottomMargin: - 45
            width: parent.width
            height: core.lightsaberPower ? parent.height : 0

            source: "lightsaber_" + lightsabercolor + ".png"

            Behavior on height{
                NumberAnimation{
                    easing.amplitude: 0.65
                    easing.period: 0.37
                    easing.type: Easing.OutExpo
                    duration: 600
                }
            }
        }
    }


    Rectangle{
        id: hiltRectangle
        height: 180
        width: 60
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: +10
        color: "transparent"

        Image {
            height: 180
            width: 60
            id: lightsaberImageOff
            anchors.centerIn: parent
            source: core.lightsaberPower ? "lightsaber_hilt_" + LightsaberSettings.hiltCharacter + "_on.png" : "lightsaber_hilt_" + LightsaberSettings.hiltCharacter + "_off.png"
        }
        MouseArea{
            id: hiltMouseArea
            anchors.fill: parent

            onClicked: helpAnimation.start()
        }
    }
    ToolBar {
        id: commonTools

        ToolIcon {
            id: backToolIcon
            platformIconId: "toolbar-settings"
            anchors.left: parent.left
            onClicked: {
                core.lightsaberPower = false;
                pageStack.push(settingsPage);
                myMenu.close();
            }
        }

        Image {
            source: "image://theme/icon-m-content-description-inverse"
            width: 48
            height: 48
            anchors.verticalCenter: backToolIcon.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 16
            MouseArea{
                anchors.fill: parent
                anchors.margins: -16
                onClicked: {
                    aboutDialog.open();
                }
            }
        }

    }
}


