import QtQuick 1.1
import com.nokia.meego 1.0
import LightsaberSettings 1.0

PageStackWindow {
    id: appWindow

    initialPage: mainPage

    showStatusBar: lightsaberSettings.showStatusBar

    Component.onCompleted: {
            theme.inverted = true;
    }

    Settings {
        id: lightsaberSettings
    }

    MainPage {
        id: mainPage
    }

    SettingsPage {
        id: settingsPage
    }

    ToolBarLayout {
        id: commonTools

        ToolIcon {
            visible: pageStack.depth > 1
            platformIconId: "toolbar-back"
            onClicked: {
                pageStack.pop();
            }
        }

        ToolIcon {
            platformIconId: "toolbar-view-menu"
            onClicked: {
                myMenu.open();
            }
        }

    }

    QueryDialog {
        id: aboutDialog
        titleText: "Lightsaber"
        message: "(C) 2012 Simon Stürz\nV 0.1"
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
            MenuItem {
                text: qsTr("Settings")
                onClicked: {
                    pageStack.push(settingsPage)
                    core.lightsaberPower = false
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
