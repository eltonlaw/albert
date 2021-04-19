import QtQuick 2.7
import QtQuick.Window 2.7
import QtCharts 2.15
import QtQuick.Controls 2.0
import "."

// main window
Window {
    width: 800
    height: 480
    visible: true
    MouseArea {
        anchors.fill: parent
    }

    Column {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        Navbar {
            width: 800
            height: 30
        }
        Grid {
            columns: 2
            spacing: 5

            Rectangle {
                width: 400
                height: 225
                TemperatureChart {

                }
            }
        }
    }
}
