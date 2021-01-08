#include "HeritageTP2.h"
#include "QLineEdit_Histo.h"
#include <qgridlayout.h>
#include <qstandarditemmodel.h>
#include <qstandarditem>
#include <qpushbutton.h>
#include <QVBoxLayout>

HeritageTP2::HeritageTP2(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	QVBoxLayout * leftColumn = new QVBoxLayout();

	editHisto = new QLineEdit_Histo();
	leftColumn->addWidget(editHisto);
	
	QGridLayout * grid = new QGridLayout();
	grid->addLayout(leftColumn, 0, 0);

	QPushButton * effaceBtn = new QPushButton();
	effaceBtn->setText("Effacer historique");
	leftColumn->addWidget(effaceBtn);

	leftColumn->setAlignment(Qt::AlignTop);

	viewHisto = new QTableView();
	grid->addWidget(viewHisto, 0, 1);

	centralWidget()->setLayout(grid);

	QObject::connect(editHisto, SIGNAL(histoUpdated()), this, SLOT(onHistoUpdated()));
	QObject::connect(effaceBtn, SIGNAL(clicked()), this, SLOT(clearHistoBtnClicked()));
}

void HeritageTP2::onHistoUpdated()
{
	std::deque<QString> histo = editHisto->getHistorique();	
	QStandardItemModel * model = new QStandardItemModel(0, 0);
	
	for (int i = 0; i < histo.size(); i++)
	{
		QList<QStandardItem*> newRow;
		QStandardItem * itm = new QStandardItem(histo[i]);
		newRow.append(itm);
		model->appendRow(newRow);
	}

	model->setHeaderData(0, Qt::Orientation::Horizontal, QObject::tr("Historique"));

	viewHisto->setModel(model);
	viewHisto->show();
}

void HeritageTP2::clearHistoBtnClicked()
{
	editHisto->efface();
}