#  Lightsaber
#
#  Copyright (C) 2012 Simon Stuerz
#  stuerz.simon@gmail.com
#
#  Lightsaber is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  Lightsaber is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with Foobar.  If not, see <http://www.gnu.org/licenses/>.


# Add more folders to ship with the application, here
folder_01.source = qml/lightsaber
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

QT += dbus
CONFIG += mobility qdeclarative-boostable qmsystem2 meego
MOBILITY += multimedia sensors feedback systeminfo

INCLUDEPATH += /usr/include/resource/qt4
LIBS += -lresourceqt

symbian:TARGET.UID3 = 0xE4566FF6


#my soundefects
INSTALLS += soundeffects
soundeffects.files = soundeffects
soundeffects.path = /opt/lightsaber


# Smart Installer package's UID
# This UID is from the protected range and therefore the package will
# fail to install if self-signed. By default qmake uses the unprotected
# range value if unprotected UID is defined for the application and
# 0x2002CCCF value if protected UID is given to the application
#symbian:DEPLOYMENT.installer_header = 0x2002CCCF

# Allow network access on Symbian
symbian:TARGET.CAPABILITY += NetworkServices

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
#CONFIG += mobility
# MOBILITY +=

# Speed up launching on MeeGo/Harmattan when using applauncherd daemon
#CONFIG += qdeclarative-boostable mobility

# Add dependency to Symbian components
# CONFIG += qt-components

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    core.cpp \
    accelerometer.cpp \
    soundeffects.cpp \
    lightsabersettings.cpp \
    vibration.cpp \
    meegostuff.cpp

# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()

OTHER_FILES += \
    qtc_packaging/debian_harmattan/rules \
    qtc_packaging/debian_harmattan/README \
    qtc_packaging/debian_harmattan/manifest.aegis \
    qtc_packaging/debian_harmattan/copyright \
    qtc_packaging/debian_harmattan/control \
    qtc_packaging/debian_harmattan/compat \
    qtc_packaging/debian_harmattan/changelog

HEADERS += \
    core.h \
    accelerometer.h \
    soundeffects.h \
    lightsabersettings.h \
    vibration.h \
    meegostuff.h
