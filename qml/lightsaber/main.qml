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

PageStackWindow {
    id: appWindow

    initialPage: mainPage

    showStatusBar: LightsaberSettings.showStatusBar

    Component.onCompleted: {
            theme.inverted = true;
    }

    MainPage {
        id: mainPage
    }

    SettingsPage {
        id: settingsPage
    }

    QueryDialog {
        id: aboutDialog
        titleText: "Lightsaber"
        message: "C 2012 Simon Stürz\nV 0.1\n\nThis application turns your Nokia N9/950 into a lightsaber.\n\nMAY THE SOURCE BE WITH YOU!\ngitorious.org/lightsaberharmattan\n\nThanks to www.MediaCollege.com for the soundeffects."
    }

    Menu {
        id: myMenu
        visualParent: pageStack
        MenuLayout {
            MenuItem {
                text: qsTr("About")
                onClicked: {
                    aboutDialog.open();
                }
            }
        }

        onStatusChanged: {
            if (status === DialogStatus.Closed) {
                appWindow.showToolBar = true;
            }
        }
    }
}
