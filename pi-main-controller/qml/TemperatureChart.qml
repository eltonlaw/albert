import QtQuick 2.7
import QtQuick.Controls 2.0
import QtCharts 2.15
import "."

ChartView {
    title: "Temperature"
    anchors.fill: parent
    antialiasing: true

    LineSeries {
        name: "Sensor 1"
        XYPoint { x: -9.0; y: tempSensor.temps[0] }
        XYPoint { x: -8.0; y: tempSensor.temps[1] }
        XYPoint { x: -7.0; y: tempSensor.temps[2] }
        XYPoint { x: -6.0; y: tempSensor.temps[3] }
        XYPoint { x: -5.0; y: tempSensor.temps[4] }
        XYPoint { x: -4.0; y: tempSensor.temps[5] }
        XYPoint { x: -3.0; y: tempSensor.temps[6] }
        XYPoint { x: -2.0; y: tempSensor.temps[7] }
        XYPoint { x: -1.0; y: tempSensor.temps[8] }
        XYPoint { x: +0.0; y: tempSensor.temps[9] }
    }
}
