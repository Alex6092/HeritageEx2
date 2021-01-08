#include "QLineEdit_Histo.h"
#include <QKeyEvent>

QLineEdit_Histo::QLineEdit_Histo()
{
}

void QLineEdit_Histo::keyPressEvent(QKeyEvent *e)
{
	if (e->key() == Qt::Key_Return || e->key() == Qt::Key_Enter) {
		if (text().length() > 0)
		{
			ajoute(text());
			clear();
			histoUpdated();
		}
	}
	else {
		QLineEdit::keyPressEvent(e);
	}
}