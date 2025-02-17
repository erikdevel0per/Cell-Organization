#include "SpreadsheetApp.h"
#include <QTableWidgetItem>

SpreadsheetApp::SpreadsheetApp(QWidget *parent)
    : QWidget(parent) {
    setupUi(this);  // Carrega a interface do arquivo .ui
    setupConnections();
}

void SpreadsheetApp::setupConnections() {
    connect(sumButton, &QPushButton::clicked, this, &SpreadsheetApp::on_sumButton_clicked);
}

void SpreadsheetApp::on_sumButton_clicked() {
    double sum = 0;
    for (int row = 0; row < tableWidget->rowCount(); ++row) {
        for (int col = 0; col < tableWidget->columnCount(); ++col) {
            bool ok;
            double value = tableWidget->item(row, col) ? tableWidget->item(row, col)->text().toDouble(&ok) : 0;
            if (ok) sum += value;
        }
    }
    tableWidget->setItem(9, 9, new QTableWidgetItem(QString::number(sum)));
}