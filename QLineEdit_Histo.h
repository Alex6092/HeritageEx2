#pragma once

#include <qlineedit.h>
#include <deque>

class QLineEdit_Histo : public QLineEdit
{
	Q_OBJECT

private:
	std::deque<QString> historique;
	void ajoute(QString str)
	{
		historique.push_back(str);
	}

protected:
	virtual void keyPressEvent(QKeyEvent *e);

public:
	QLineEdit_Histo();

	std::deque<QString> getHistorique()
	{
		return historique;
	}

	void efface()
	{
		historique.clear();
		histoUpdated();
	}

signals:
	void histoUpdated();
};

