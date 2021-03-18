import QtQuick 2.7
import QtQuick.Window 2.7
import QtCharts 2.15
import QtQuick.Controls 2.0
import "."

// main window
Window {
    visible: true
    MouseArea {
        anchors.fill: parent
    }

    Column {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        Navbar {}
        Grid {
            columns: 2
            spacing: 5

            Grid {
                width: 400
                height: 400
                columns: 3
                spacing: 0
                Button {
                    id: btn_set
                    text: "Inc TempSensor"
                    onClicked: {
                        tempSensor.temp = tempSensor.temp + 1;
                        console.log("[TempSensor]: Inc", tempSensor.temp);
                    }
                }
                Button {
                    id: btn_start
                    text: "Start TempSensor"
                    onClicked: {
                        tempSensor.start()
                        console.log("[TempSensor]: Start", tempSensor.temp);
                    }
                }
                Button {
                    id: btn_stop
                    text: "Stop TempSensor"
                    onClicked: {
                        tempSensor.stop()
                        console.log("[TempSensor]: Stop", tempSensor.temp);
                    }
                }
                Text {
                    text: Number(tempSensor.temp).toFixed(2)
                }
            }

            Rectangle {
                width: 400
                height: 400
                ChartView {
                    anchors.fill: parent
                    theme: ChartView.ChartThemeBrownSand
                    antialiasing: true

                    PieSeries {
                        id: pieSeries
                        PieSlice { label: "Volkswagen"; value: 13.5 }
                        PieSlice { label: "Toyota"; value: 10.9 }
                        PieSlice { label: "Ford"; value: 8.6 }
                        PieSlice { label: "Skoda"; value: 8.2 }
                        PieSlice { label: "Volvo"; value: 6.8 }
                    }
                }
            }
            Rectangle {
                width: 400
                height: 400
                ChartView {
                    title: "Line"
                    anchors.fill: parent
                    antialiasing: true

                    LineSeries {
                        name: "LineSeries"
                        XYPoint { x: 0; y: 0 }
                        XYPoint { x: 1.1; y: 2.1 }
                        XYPoint { x: 1.9; y: 3.3 }
                        XYPoint { x: 2.1; y: 2.1 }
                        XYPoint { x: 2.9; y: 4.9 }
                        XYPoint { x: 3.4; y: 3.0 }
                        XYPoint { x: 4.1; y: 3.3 }
                    }
                }
            }
        }
    }
}
