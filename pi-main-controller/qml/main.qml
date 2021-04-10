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

            Grid {
                width: 400
                height: 225
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
                height: 225
                    ChartView {
                        id: chartView
                        anchors.fill: parent

                        ValueAxis {
                            id: axisX
                            min: 0
                            max: 400
                        }

                        Component.onCompleted:  {
                            mapper.series = series2
                        }

                        LineSeries {
                            id: series2
                            axisX: axisX
                            name: "From C++"
                        }
                    }
            }
            Rectangle {
                width: 400
                height: 225
                TemperatureChart {

                }
            }
        }
    }
}
