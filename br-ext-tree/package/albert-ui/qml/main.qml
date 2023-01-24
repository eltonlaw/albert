import QtQuick 2.7
import QtQuick.Window 2.7
import QtCharts 2.15
import QtQuick.Controls 2.0

// main window
Window {
    id: root
    Style { id: style }

    // flags: Qt.FramelessWindowHint
    width: style.screen_width
    height: style.screen_height
    visible: true
    color: style.theme.background_color
    MouseArea {
        anchors.fill: parent
    }

    Column {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        Navbar {
            width: root.width
            height: 30
        }
        Grid {
            columns: 2
            spacing: 5

            component GridRect: Rectangle {
                color: style.theme.background_color
                width: 400
                height: 225
            }

            GridRect {
                TemperatureChart {

                }
            }
        }
    }
}
