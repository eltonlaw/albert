import QtQuick 2.7
import QtQuick.Controls 2.0
import QtCharts 2.15

ChartView {
    title: "Temperature"
    id: chartView
    backgroundColor: style.theme.color_300
    anchors.fill: parent

    ValueAxis {
        id: axisX
        min: 0
        max: 9
    }

    ValueAxis {
        id: axisY
        min: -5
        max: 30
    }

    Component.onCompleted:  {
        temp_sensor_mapper.series = series2
    }

    SplineSeries {
        id: series2
        axisX: axisX
        axisY: axisY
        name: "BME280"
        // FIXME: "qrc:/qml/TemperatureChart.qml:33: TypeError: Cannot read
        // property 'active1_color' of undefined"
        // color: style.theme.active1_color
        color: "#A32CC4"
    }
}
