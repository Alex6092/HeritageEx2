#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_HeritageTP2.h"
#include <qtableview.h>
#include "QLineEdit_Histo.h"

class HeritageTP2 : public QMainWindow
{
    Q_OBJECT

public:
    HeritageTP2(QWidget *parent = Q_NULLPTR);

public slots:
	void onHistoUpdated();
	void clearHistoBtnClicked();

private:
    Ui::HeritageTP2Class ui;
	QLineEdit_Histo * editHisto;
	QTableView * viewHisto;
};
